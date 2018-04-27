#include <stdio.h>

/**
 * 小端机器上运行返回1，大端返回0
 */

int is_little_endian(){
    short st = 0x4567;
    char *pc = (char *)&st;
    return *pc == 0x67;
}


int main(){
    printf("%d\n",is_little_endian());
}