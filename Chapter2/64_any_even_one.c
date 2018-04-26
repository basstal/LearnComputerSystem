#include <stdio.h>
/**
判断一个数的位表示中所有偶数位都为1
*/
int any_even_one(unsigned x){
    return (x & 0xAAAAAAAA) == 0xAAAAAAAA;
}

int main(){
    printf("%d\n",any_even_one(0xffffffff));
    printf("%d\n",any_even_one(0xabcdef99));
}