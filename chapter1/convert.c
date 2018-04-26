#include <stdio.h>
#include <stdlib.h>

int main(int size, char **args)
{
    int i = 1;
    for(; i < size; ++i)
    {
        int val = atoi(args[i]);
        printf("%d\t = 0x%x\n", val, val);
        printf("0x%d\t = %d\n", val, val);
    }
    return 0;
}