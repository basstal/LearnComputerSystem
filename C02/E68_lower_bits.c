#include <stdio.h>

/**
 * 将数x的低n位设置为1
 */

int lower_bits(int x, int n){
    long long l = (1 << n) - 1;
    return l | x;
}

int main(){
    printf("%x\n",lower_bits(0,6));
    printf("%x\n",lower_bits(0,17));
    printf("%x\n",lower_bits(0,32));
}