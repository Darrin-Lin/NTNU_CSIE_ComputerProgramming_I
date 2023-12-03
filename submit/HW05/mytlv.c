#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int32_t run(uint8_t *pByteArray, int32_t size);
static int32_t get_length(uint8_t *pByteArray, int32_t size, int32_t byte);
static int32_t get_value(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t length);
static int32_t TLV(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t skip(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t TLV1(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t TLV2(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t TLV3(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t TLV4(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t TLV5(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t TLV6(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t TLV7(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t TLV8(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t TLV9(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t TLV10(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number);
static int32_t (*TLVtype[11])(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number) = {skip, TLV1, TLV2, TLV3, TLV4, TLV5, TLV6, TLV7, TLV8, TLV9, TLV10};

static int32_t save = 0;

int32_t run(uint8_t *pByteArray, int32_t size)
{
	int32_t number = 0;
	int32_t byte = 0;
	while (byte < size)
	{
		byte = TLV(pByteArray, size, byte, &number);
		if (byte == -1)
		{
			return -1;
		}
	}
	return 0;
}
static int32_t get_length(uint8_t *pByteArray, int32_t size, int32_t byte)
{

	int32_t length = 0;
	if (size < byte + 3)
	{
		return -1;
	}
	length = pByteArray[byte + 1] + pByteArray[byte + 2] * 10; /////
	return length;
}
static int32_t get_value(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t length)
{
	int32_t value = 0;
	if (size < byte + 3 + length)
	{
		return -1;
	}
	for (int32_t i = 0; i < length; i++)
	{
		value = value * 10 + pByteArray[byte + 3 + i];
	}
	return value;
}
static int32_t TLV(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{

	if (pByteArray[byte] > 10)
	{
		return TLVtype[0](pByteArray, size, byte, p_number);
	}
	else
	{
		return TLVtype[pByteArray[byte]](pByteArray, size, byte, p_number);
	}
}
static int32_t skip(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{
	save = *p_number;
	int32_t length = get_length(pByteArray, size, byte);
	// int32_t value = get_value(pByteArray, size, byte, length);
	return (byte + 3 + length);
}

static int32_t TLV1(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{
	// number = value
	int32_t length = get_length(pByteArray, size, byte);
	int32_t value = get_value(pByteArray, size, byte, length);
	save = *p_number;
	*p_number = value;
	return (byte + 3 + length);
}
static int32_t TLV2(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{
	// number += value
	int32_t length = get_length(pByteArray, size, byte);
	int32_t value = get_value(pByteArray, size, byte, length);
	save = *p_number;
	*p_number += value;
	return byte + 3 + length;
}
static int32_t TLV3(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{
	// number *= value
	int32_t length = get_length(pByteArray, size, byte);
	int32_t value = get_value(pByteArray, size, byte, length);
	save = *p_number;
	*p_number *= value;
	return byte + 3 + length;
}
static int32_t TLV4(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{
	// number = number / 2
	// only length = 0
	int32_t length = get_length(pByteArray, size, byte);
	// int32_t value = get_value(pByteArray, size, byte, length);
	if (length != 0)
	{
		return -1;
	}
	save = *p_number;
	*p_number /= 2;
	return byte + 3;
}
static int32_t TLV5(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{
	// number = number /10
	// only length = 0
	int32_t length = get_length(pByteArray, size, byte);
	// int32_t value = get_value(pByteArray, size, byte, length);
	if (length != 0)
	{
		return -1;
	}
	save = *p_number;
	*p_number /= 10;
	return byte + 3;
}
static int32_t TLV6(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{
	// number = value || number
	int32_t length = get_length(pByteArray, size, byte);
	int32_t value = get_value(pByteArray, size, byte, length);
	save = *p_number;
	int32_t n_digit = (int32_t)log10(*p_number) + 1;
	for (int32_t i = 0; i < n_digit; i++)
	{
		value *= 10;
	}

	*p_number += value;
	return byte + 3 + length;
}
static int32_t TLV7(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{
	// number = number || value
	int32_t length = get_length(pByteArray, size, byte);
	int32_t value = get_value(pByteArray, size, byte, length);
	save = *p_number;
	int32_t n_digit = (int32_t)log10(value) + 1;
	for (int32_t i = 0; i < n_digit; i++)
	{
		*p_number *= 10;
	}
	*p_number += value;
	return byte + 3 + length;
}
static int32_t TLV8(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{
	// number = init to 0
	// only length = 0
	int32_t length = get_length(pByteArray, size, byte);
	if (length != 0)
	{
		return -1;
	}
	save = *p_number;
	*p_number = 0;
	return byte + 3;
}
static int32_t TLV9(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{
	// number = print number
	// only length = 0
	int32_t length = get_length(pByteArray, size, byte);
	if (length != 0)
	{
		return -1;
	}
	save = *p_number;
	printf("%d\n", *p_number);
	return byte + 3;
}
static int32_t TLV10(uint8_t *pByteArray, int32_t size, int32_t byte, int32_t *p_number)
{
	// cancel previous TLV
	// only length = 0
	int32_t length = get_length(pByteArray, size, byte);
	if (length != 0)
	{
		return -1;
	}
	int32_t temp = 0;
	temp = *p_number;
	*p_number = save;
	save = temp;
	return byte + 3;
}