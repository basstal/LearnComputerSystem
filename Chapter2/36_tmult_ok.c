#include <stdio.h>
#include "show_bytes.h"

/**
 * 测试乘法是否溢出，两种方法
 */

int tmult_ok(int x, int y)
{
    long long val = (long long)x * y;
    return (int)val == val;
}

int tmult_ok_book(int x, int y)
{
    int val = x * y;
    return !x || val/x == y;
}

int main()
{
    printf("%d,%d\n",tmult_ok(0xaaaaaaaa,0xbbbbbbbb),tmult_ok_book(0xaaaaaaaa,0xbbbbbbbb));
    printf("%d,%d\n",tmult_ok(0xffffffff,0xbbbbbbbb),tmult_ok_book(0xffffffff,0xbbbbbbbb));
    printf("%d,%d\n",tmult_ok(0xcccccccc,0xbbbbbbbb),tmult_ok_book(0xcccccccc,0xbbbbbbbb));
    printf("%d,%d\n",tmult_ok(0x00001111,0xbbbbbbbb),tmult_ok_book(0x00001111,0xbbbbbbbb));
    printf("%d,%d\n",tmult_ok(0x00008888,0xbbbbbbbb),tmult_ok_book(0x00008888,0xbbbbbbbb));
}