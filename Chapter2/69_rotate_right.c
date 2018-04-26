#include <stdio.h>
/**
对数的位表示做右旋转，将低位旋转到高位上来
*/
unsigned rotate_right(unsigned x, int n){
    int mask = (1 << n) - 1;
    // printf("%x\n",mask);
    unsigned leftVal = x & mask;
    unsigned rightVal = x - leftVal;
    // printf("%x,%x\n",rightVal,leftVal);
    // printf("%d\n",sizeof(unsigned)<<3);
    // printf("%x\n",(leftVal << ((sizeof(unsigned) << 3) - n)));
    return (rightVal >> n) | (leftVal << ((sizeof(unsigned)<<3) - n));
}

int main(){
    printf("%x\n",rotate_right(0x12345678,4));
    printf("%x\n",rotate_right(0x12345678,20));
    printf("%x\n",rotate_right(0x12345678,31));
}