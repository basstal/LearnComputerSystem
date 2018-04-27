#include <stdio.h>

/**
一些表达式的测试
*/

int main(){
    int x = 0x40000001;
    double d = 0.001;
    printf("%d\n",x == (int)(float)x);
    printf("%lf,%d\n",d,d == (double)(float)d);
}