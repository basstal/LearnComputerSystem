#include <stdio.h>
/**
产生如下位模式：a.1(w-n)0(n)   b.0(w-n-m)1(n)0(m)
*/


int bits1(int n){
    int bits = (long long)(1 << n) - 1;
    return ~bits;
}

int bits2(int m, int n){
    int bits = (long long) (1 << m) - 1;
    int mask = (long long) (1 << m + n) -1;
    mask -= bits;
    return 0^mask;
}

int main(){
    printf("%x\n",bits1(10));
    printf("%x\n",bits2(9,9));
}