#include "stdio.h"
#include "stdlib.h"

int addx(int x, int y);

// 函数指针
int *add(int x, int y);

// 指针函数
int (*addy)(int x, int y);

int main()
{
    int x = 2, y = 5;

    printf("====>%d\n", addx(x, y));

    int *ptr = add(x, y);
    printf("====>%d\n", *ptr);

    addy = &addx;

    printf("addy ===>%p\n",addy);

    printf("====>%d\n", addy(x, y));

    free(ptr);
    return 0;
}

int addx(int x, int y)
{
    return x + y;
}

int *add(int x, int y)
{
    int *prt = (int *)malloc(sizeof(int));
    *prt = x + y;
    return prt;
}