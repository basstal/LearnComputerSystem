#include <stdio.h>
#include <limits.h>

/**
 * 对于整数参数x，计算5*x/8
 */

int mul5div8(int x){
    int bias = (1 << 3) - 1;
    ((x = (x << 2) + x) & 0x80000000) && (x += bias);
    return x >> 3;
}


int main(){
    printf("%d\n",mul5div8(15));
    printf("%d\n",mul5div8(22));
    printf("%d\n",mul5div8(INT_MAX));
    printf("%d\n",mul5div8(INT_MIN));
}