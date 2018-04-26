
#include <stdio.h>
#include "show_bytes.h"
/**
按字节显示一个地址start内包含的值，以及其后len个字节的值
*/
void show_bytes(byte_pointer start, int len)
{
    int i;
    for(i = 0 ; i < len ; ++i)
        printf(" %.2x",start[i]);
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer) &x,sizeof(x));
}

void show_float(float x)
{
    show_bytes((byte_pointer) &x,sizeof(x));
}

void show_pointer(void *x)
{
    show_bytes((byte_pointer) &x,sizeof(void *));
}

void show_short(short st){
    show_bytes((byte_pointer)&st,sizeof(short));
}

void show_long(long l){
    show_bytes((byte_pointer)&l,sizeof(long));
}


void show_double(double d){
    show_bytes((byte_pointer)&d,sizeof(double));
}



// void test_shift()
// {
//     int val = 0xFEDCBA98;
//     int lval = val << 32;
//     int aval = val >> 36;
//     unsigned uval = val >> 40;

//     show_bytes((byte_pointer)&lval, 4);
//     show_bytes((byte_pointer)&aval, 4);
//     show_bytes((byte_pointer)&uval, 4);
// }

// void test_transaction()
// {
//     printf("%d",-2147483647-1 == 2147483648U);
//     printf("%d",-2147483647-1 < 2147483647);
//     printf("%d", -2147483647-1U < 2147483647);
//     printf("%d",-2147483647-1 < -2147483647);
//     printf("%d",-2147483647-1U < -2147483647);
// }

// void test_transaction2()
// {
//     short sx = -12345;
//     unsigned uy = sx;

//     printf("uy = %u:\t", uy);
//     show_bytes((byte_pointer)&uy,sizeof(unsigned));
// }


