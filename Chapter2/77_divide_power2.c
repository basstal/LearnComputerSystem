#include <stdio.h>
/**
用正确的舍入方式计算x除以2的k次幂
*/

int divide_power2(int x, int k){
    int fix = 0;
    x >> 31 && (fix = ((x>>31)&((1 << k) - 1)));
    return (x + fix) >> k;
}

int main(){
    printf("%d\n",divide_power2(-16,3));
    printf("%d\n",divide_power2(-34,2));
    printf("%d\n",divide_power2(-77,5));
    printf("%d\n",divide_power2(-128,4));
}
