#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition;
int start = 1;
int count = 0;
void print2Binary(int val, int last)
{
    if(val != 0)
    {
        count += 1;
        print2Binary(val / 2, 0);
        if(start)
        {
            start = 0;
            partition = count % 4 == 0 ? 4 : count % 4;
        }
        printf("%d", val % 2);
        if(last)
            partition = -1;
        partition -= 1;
        if(partition == 0)
        {
            partition = 4;
            printf(",");
        }
    }
}
int main()
{   
    srand((unsigned)time(0));
    int a = rand() % 0x1f;
    // printf("%x\n", a);
    // print2Binary(a, 1);
    // printf("\n");
    printf("%d\n", a);
    return 0;
}