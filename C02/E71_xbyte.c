#include <stdio.h>

/**
 * 从一个由4个字节组装的类型中提取每个字节值，并转换为一个int型（需要符号扩展）
 */

typedef unsigned packed_t;

int xbyte(packed_t word, int bytenum){
    int val = (word >> (bytenum << 3)) & 0xff;
    return (val << 24) >> 24;
}

int main(){
    printf("%d\n",xbyte(0x801012a4,0));
    printf("%d\n",xbyte(0x801012a4,1));
    printf("%d\n",xbyte(0x801012a4,2));
    printf("%d\n",xbyte(0x801012a4,3));
}