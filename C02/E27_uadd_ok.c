#include <stdio.h>
#include <limits.h>

/**
 * 测试无符号数相加是否溢出
 */

int uadd_ok(unsigned x, unsigned y)
{
    return (x+y >= x && x+y >= y) ? 1 : 0;
}

int main()
{
    printf("%d\n",uadd_ok(5,10));
    printf("%d\n",uadd_ok(UINT_MAX,2000));
}