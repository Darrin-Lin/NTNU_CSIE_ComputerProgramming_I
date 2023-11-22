#include <stdint.h>
#include <stdio.h>
// Sort array according to the given policies .
void mysort(int32_t array[], int32_t size);
// Print array elements in order .
void myprint(int32_t array[], int32_t size);

void mysort(int32_t array[], int32_t size)
{
	if (array == NULL)
		if (size <= 0)
		{
			return;
		}
	int32_t even = 0; // odd=size-even
	// fprintf(stderr,"%d",*(arr+1));
	for (int32_t i = 0; i < size; i++) // sort even odd
	{
		if (array[i] % 2 == 0)
		{ ////////////////////maybe have error
			int32_t save = 0;
			save = array[i];
			array[i] = array[even];
			array[even] = save;
			even++;
		}
	}
	for (int32_t i = 0; i < even; i++)
	{
		for (int32_t j = i; j < even; j++)
		{
			if (array[i] < array[j])
			{
				int32_t save = 0;
				save = array[i];
				array[i] = array[j];
				array[j] = save;
			}
		}
	}
	for (int32_t i = even; i < size; i++)
	{
		for (int32_t j = i; j < size; j++)
		{
			if (array[i] > array[j])
			{
				int32_t save = 0;
				save = array[i];
				array[i] = array[j];
				array[j] = save;
			}
		}
	}
	return;
}
void myprint(int32_t array[], int32_t size)
{
	if (array == NULL)
	{
		return;
	}
	if (size <= 0)
	{
		return;
	}
	printf("%d", array[0]);
	for (int32_t i = 1; i < size; i++)
	{
		printf(" %d", array[i]);
	}
	printf("\n");
	return;
}
