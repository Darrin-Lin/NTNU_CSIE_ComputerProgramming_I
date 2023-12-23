#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct player
{
    int32_t x;
    int32_t y;
    int8_t alive;
    int8_t cannon;
    int8_t bullet;
    int32_t bullet_x;
    int32_t bullet_y;
};

static int32_t width = 0, height = 0;
static int8_t show_cannon(int32_t x, int32_t y, int8_t cannon, int32_t map[height][width]);
static void show_map(int32_t map[height][width]);
static void shot(int32_t x, int32_t y, int8_t cannon, int32_t map[height][width]);

int main()
{
    srand(time(NULL));
    printf("Please input the height of the map: ");
    scanf("%d", &height);
    if (height < 0)
    {
        perror("Invalid height.\n");
        return -1;
    }
    printf("Please input the width of the map: ");
    scanf("%d", &width);
    if (width < 0)
    {
        perror("Invalid width.\n");
        return -1;
    }
    struct player human = {rand() % width, rand() % height, 1, 1, 1, 0, 0};
    struct player computer1 = {rand() % width, rand() % height, 1, 1, 1, 0, 0};
    struct player computer2 = {rand() % width, rand() % height, 1, 1, 1, 0, 0};
    struct player computer3 = {rand() % width, rand() % height, 1, 1, 1, 0, 0};
    int32_t map[height][width];
    for (int32_t i = 0; i < height; i++)
    {
        for (int32_t j = 0; j < width; j++)
        {
            map[i][j] = 0;
        }
    }
    for (int32_t i = 0; i < height * width / 40; i++)
    {
        int32_t Rx = rand() % width;
        int32_t Ry = rand() % height;
        if (map[Ry][Rx] == 0)
        {
            map[Ry][Rx] = -1;
        }
        else
        {
            i--;
        }
    }
    map[human.y][human.x] = 1;
    map[computer1.y][computer1.x] = 2;
    map[computer2.y][computer2.x] = 3;
    map[computer3.y][computer3.x] = 4;
    show_cannon(human.x, human.y, human.cannon, map);
    show_cannon(computer1.x, computer1.y, computer1.cannon, map);
    show_cannon(computer2.x, computer2.y, computer2.cannon, map);
    show_cannon(computer3.x, computer3.y, computer3.cannon, map);
    char action;
    show_map(map);

    while (human.alive && (computer1.alive || computer2.alive || computer3.alive))
    {
        printf("Please input the action: ");
        scanf("%c\n", &action);
        human.cannon == 8 ? human.cannon = 1 : human.cannon++;
        computer1.cannon == 8 ? computer1.cannon = 1 : computer1.cannon++;
        computer2.cannon == 8 ? computer2.cannon = 1 : computer2.cannon++;
        computer3.cannon == 8 ? computer3.cannon = 1 : computer3.cannon++;
        switch (action)
        {
        case 'W':
            if (human.y - 1 >= 0 && map[human.y - 1][human.x] != -1)
            {
                map[human.y][human.x] = 0;
                human.y--;
                map[human.y][human.x] = 1;
            }
            break;
        case 'D':
            if (human.x + 1 < width && map[human.y][human.x + 1] != -1)
            {
                map[human.y][human.x] = 0;
                human.x++;
                map[human.y][human.x] = 1;
            }
            break;
        case 'S':
            if (human.y + 1 < height && map[human.y + 1][human.x] != -1)
            {
                map[human.y][human.x] = 0;
                human.y++;
                map[human.y][human.x] = 1;
            }
            break;
        case 'A':
            if (human.x - 1 >= 0 && map[human.y][human.x - 1] != -1)
            {
                map[human.y][human.x] = 0;
                human.x--;
                map[human.y][human.x] = 1;
            }
            break;
        case 'R':

            break;

        case 'Q':
            if (human.bullet)
            {
                shot(human.x, human.y, human.cannon, map);
            }
            break;
        default:
            break;
        }
        show_cannon(human.x, human.y, human.cannon, map);
        show_cannon(computer1.x, computer1.y, computer1.cannon, map);
        show_cannon(computer2.x, computer2.y, computer2.cannon, map);
        show_cannon(computer3.x, computer3.y, computer3.cannon, map);
        if(computer1.alive)
        {
            map[computer1.y][computer1.x] = 2;
        }
        if(computer2.alive)
        {
            map[computer2.y][computer2.x] = 3;
        }
        if(computer3.alive)
        {
            map[computer3.y][computer3.x] = 4;
        }
        
        show_map(map);
    }

    return 0;
}
static int8_t show_cannon(int32_t x, int32_t y, int8_t cannon, int32_t map[height][width])
{
    switch (cannon)
    {
    case 1:
        if (y - 1 >= 0)
            if (map[y - 1][x] == 0)
                map[y - 1][x] = 5;
        break;
    case 2:
        if (y - 1 >= 0 && x + 1 < width)
            if (map[y - 1][x + 1] == 0)
                map[y - 1][x + 1] = 5;
        break;
    case 3:
        if (x + 1 < width)
            if (map[y][x + 1] == 0)
                map[y][x + 1] = 5;
        break;
    case 4:
        if (y + 1 < height && x + 1 < width)
            if (map[y + 1][x + 1] == 0)
                map[y + 1][x + 1] = 5;
        break;
    case 5:
        if (y + 1 < height)
            if (map[y + 1][x] == 0)
                map[y + 1][x] = 5;
        break;
    case 6:
        if (y + 1 < height && x - 1 >= 0)
            if (map[y + 1][x - 1] == 0)
                map[y + 1][x - 1] = 5;
        break;
    case 7:
        if (x - 1 >= 0)
            if (map[y][x - 1] == 0)
                map[y][x - 1] = 5;
        break;
    case 8:
        if (y - 1 >= 0 && x - 1 >= 0)
            if (map[y - 1][x - 1] == 0)
                map[y - 1][x - 1] = 5;
        break;
    default:
        break;
    }
    return 0;
}
static void show_map(int32_t map[height][width])
{
    for (int32_t i = 0; i < width + 2; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int32_t i = 0; i < height; i++)
    {
        printf("|");
        for (int32_t j = 0; j < width; j++)
        {

            if (map[i][j])
            {
                if (map[i][j] == 1)
                {
                    printf("\033[96mP\033[0m");
                }
                else if (map[i][j] == 2)
                {
                    printf("\033[91mC\033[0m");
                }
                else if (map[i][j] == 3)
                {
                    printf("\033[92mC\033[0m");
                }
                else if (map[i][j] == 4)
                {
                    printf("\033[93mC\033[0m");
                }
                else if (map[i][j] == 5)
                {
                    printf("I");
                    map[i][j] = 0;
                }
                if (map[i][j] == -1)
                {
                    printf("\033[90mR\033[0m");
                }
                if (map[i][j] == -2)
                {
                    printf("o");
                    map[i][j] = 0;
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("|\n");
    }
    for (int32_t i = 0; i < width + 2; i++)
    {
        printf("-");
    }
    printf("\n");
    return;
}
static void shot(int32_t x, int32_t y, int8_t cannon, int32_t map[height][width])
{
    switch (cannon)
    {
    case 1:
        if (y - 2 >= 0)
        {
            map[y - 2][x] = -2;
        }
        break;
    case 2:
        if (y - 2 >= 0 && x + 2 < width)
        {
            map[y - 2][x + 2] = -2;
        }
        break;
    case 3:
        if (x + 2 < width)
        {
            map[y][x + 2] = -2;
        }
        break;
    case 4:
        if (y + 2 < height && x + 2 < width)
        {
            map[y + 2][x + 2] = -2;
        }
        break;
    case 5:
        if (y + 2 < height)
        {
            map[y + 2][x] = -2;
        }
        break;
    case 6:
        if (y + 2 < height && x - 2 >= 0)
        {
            map[y + 2][x - 2] = -2;
        }
        break;
    case 7:
        if (x - 2 >= 0)
        {
            map[y][x - 2] = -2;
        }
        break;
    case 8:
        if (y - 2 >= 0 && x - 2 >= 0)
        {
            map[y - 2][x - 2] = -2;
        }
        break;
    }
}