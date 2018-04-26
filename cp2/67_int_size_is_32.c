#include <stdio.h>

/**
当在一个int是32位的机器上运行时，程序产生1，而其他情况产生0
*/
int int_size_is_32(){
    int set_msb = 1 << 31;
    int beyond_msb = (long long)1 << 32;
    return set_msb && !beyond_msb;
}

int int_size_is_32_1(){
    int set_msb_short = 1 << 15;
    int set_msb = (long long) 1 << 31;
    int beyond_msb = (long long) 1 << 32;
    return set_msb_short && set_msb && !beyond_msb;
}

int main(){
    printf("%d\n",int_size_is_32());
    printf("%d\n",int_size_is_32_1());
}