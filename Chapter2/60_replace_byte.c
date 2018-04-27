#include <stdio.h>

/**
 * 返回无符号值，其中参数x的字节i被替换成字节b
 */

unsigned replace_byte(unsigned x, int i, unsigned char b){
    unsigned leftMove = i << 3;
    unsigned mask = 0xff << leftMove;
    return (x & ~mask) + ((unsigned)b << leftMove);
}

int main(){
    printf("0x%x\n",replace_byte(0x12345678, 2, 0xAB));
    printf("0x%x\n",replace_byte(0x12345678, 0, 0xAB));
}