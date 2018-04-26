#include <stdio.h>
int main()
{
    printf("hello world\n");
    // int a = 0xfffffe58;
    int a = 0x80000000;
    // printf("%d\n", a);
    printf("%d\n", -a);
    return 0;
}