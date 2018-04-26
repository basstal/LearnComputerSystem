#include <stdio.h>

void expression4(int x){
    //A
    printf("A:%d\n",(x & -1) == -1);
    //B
    printf("B:%d\n",(x | 0) == 0);


    //C
    printf("C:%d\n",(x & 0xff000000) == 0xff000000);
    //D
    printf("D:%d\n",(x & 0xff) == 0);
}
int main(){
    printf("0xffffffff:\n");
    expression4(0xffffffff);
    printf("0x00000000:\n");
    expression4(0);
    printf("0xf7000101:\n");
    expression4(0xf7000101);
    printf("0x12345600:\n");
    expression4(0x12345600);
}