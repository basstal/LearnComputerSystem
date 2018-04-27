#include <stdio.h>
#include <limits.h>
/**
 * 一些表达式测试
 */
int main(){

    int x = INT_MAX;
    int y = INT_MAX;
    int z = -3;
    double dx = (double) x;
    double dy = (double) y;
    double dz = (double) z;
    printf("%d\n",(double)(float) x == dx);
    printf("%d\n", dx + dy == (double)(x+y));
    printf("%d\n",dx + dy + dz == dz + dy + dx);
    printf("%d\n",dx * dy * dz == dz * dy * dx);
    // printf("0x80000000 + 0x80000000 = %d\n",0x80000000+0x80000000);
}