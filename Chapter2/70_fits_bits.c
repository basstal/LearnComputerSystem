#include <stdio.h>
/**
 * 对于数x，可以用n位补码数来表示
 */
int fits_bits(int x, int n){
    int mask = (1 << n) - 1;
    return (x & mask) == x || (x >> n-1) == - 1;
}


int main(){
    printf("%d\n",fits_bits(32,2));
    printf("%d\n",fits_bits(127,8));
    printf("%d\n",fits_bits(-127,7));
    printf("%d\n",fits_bits(-127,8));
    printf("%d\n",fits_bits(255,15));
}