#include<stdio.h>
#include<limits.h>

/**
 * 指出表达式是否总是为true（数学原理），否则举出反例
 * 
 * A.( x < y ) == ( -x > -y )
 * 反例：x为INT_MIN,y为INT_MAX
 * 
 * B.(( x + y ) << 4) + y - x == 17 * y + 15 * x
 * 正确：x + y的和左移4位与x左移4位 + y左移4位的结果相同，整数加减法满足交换律和结合律
 * 
 * C.~x + ~y + 1 == ~( x + y )
 * D.( ux - uy ) == - (unsigned) (y - x)
 * E.(( x >> 2 ) << 2 ) <= x
 */

int main()
{
    int x = INT_MIN, y = INT_MAX;
    printf("%d\n", (x < y) == (-x > -y));
    x = INT_MAX, y = INT_MAX;
    printf("%d\n", ((x+y) << 4) + y - x == 17 * y + 15 * x);
    return 0;
}
