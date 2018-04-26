#include <stdio.h>

/**
对于整数参数x，计算5/8x的值，向零舍入

*/

int fiveeighths(int x){
    x & 0x80000000 && (x += 0x7);
    x >>= 3;
    return (x << 2) + x;
}


int main(){
    printf("%d\n",fiveeighths(16));
    printf("%d\n",fiveeighths(8));
    printf("%d\n",fiveeighths(-12));
    printf("%d\n",fiveeighths(-24));
}