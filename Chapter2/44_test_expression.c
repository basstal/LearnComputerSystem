#include <stdio.h>

/**
一些表达式的测试
*/

void test_expression(int x, int y)
{
    // printf("%d\n",(x * x ) >= 0);     
    // printf("%d\n", x < 0 || -x >= 0); 
    // printf("%d\n", x > 0 || -x >= 0); 
    printf("%d\n", (x > 0) || (x - 1 < 0));  
}

int main()
{
    // test_expression(0x0fffffff,0); 
    // test_expression(0x80000000,0); 
    // test_expression(0x80000000,0);
    // printf("%d\n" ,0x80000000);
    // unsigned u = 8;
    // printf("%d\n", -u);
    test_expression(0x80000000,0);
    unsigned long long i = 0x01000000;
    printf("%lf", (double)1/i);
}