#include <stdio.h>

/**
测试有符号数相加是否溢出
*/

int tadd_ok(int x, int y)
{
    if(x > 0 && y > 0 && x+y <0)
        return 0;
    if(x < 0 && y < 0 && x+y >= 0)
        return 0;
    return 1;
}

int main(){
    int sum = 0x7fffffff+0x7fffffff;
    int y = 0x80000000;
    printf("%d\n",tadd_ok(0x8000000a,0x8000000b));
    printf("%d\n",tadd_ok(0x7fffffff,0x7fffffff));
    printf("-y = %d\n",-y);
    printf("%d\n",tadd_ok(0x00000001,-y));
    printf("%d\n",sum - 0x7fffffff);
    printf("%d\n",0x8000000a+0x8000000b);
    printf("%d\n",0x8000000a);
}