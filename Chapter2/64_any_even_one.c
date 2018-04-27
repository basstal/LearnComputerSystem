#include <stdio.h>

/**
 * 判断一个数的位表示中所有偶数位都为1
 * 第三版：
 * 判断一个数的位表示中任意奇数位为1
 */

int any_even_one(unsigned x){
    return (x & 0xAAAAAAAA) == 0xAAAAAAAA;
}

int any_odd_one(unsigned x){
    return !!(x & 0x55555555);
}

int main(){
    // printf("%d\n",any_even_one(0xffffffff));
    // printf("%d\n",any_even_one(0xabcdef99));
}