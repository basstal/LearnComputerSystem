#include <stdio.h>

/**
 * 生成一个字，由x的最低有效字节和y中剩下的字节组成
 */

int generate_word(int x,int y){
    return ((unsigned)x & 0xff) + ((unsigned)y & 0xffffff00);
}

int main(){
    printf("0x%X\n",generate_word(0x89ABCDEF,0x76543210));
}