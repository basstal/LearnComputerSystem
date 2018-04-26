#include <stdio.h>
/**
srl用算术右移完成逻辑右移，sra用逻辑右移完成算术右移
*/
int sra(int x,int k){
    int xsrl = (unsigned) x >> k;
    //...
    int maxw = 8 * sizeof(int);
    (x &( 1 << (maxw - 1))) && (xsrl |= ~(( 1 << (maxw - k)) -1));
    return xsrl;
}


unsigned srl(unsigned x, int k){
    unsigned xsra = (int)x >> k;
    unsigned mask = (1 << (8*sizeof(int) -k)) -1;
    return xsra & mask;
}

int main(){
    printf("%x\n",sra(0x12345678,8));
    printf("%x\n",sra(0x82345678,8));
    printf("%x\n",srl(0x12345678,8));
    printf("%x\n",srl(0x82345678,8));
}