#include <stdio.h>

/**
 * 不使用除法、模运算、乘法、任何条件语句、比较运算符、循环等，将一个int除以16
 */

int div16(int x)
{
    int val = (x >> 31) & 0xf;
    return (x + val) >> 4;
}

