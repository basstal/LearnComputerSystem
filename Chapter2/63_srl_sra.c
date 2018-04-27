#include <stdio.h>
#include <limits.h>

/**
 * srl用算术右移完成逻辑右移，sra用逻辑右移完成算术右移
 */

int sra(int x,int k){
    int xsrl = (unsigned) x >> k;
    //...
    int maxw = 8 * sizeof(int);
    (x &( 1 << (maxw - 1))) && (xsrl |= ~(( 1 << (maxw - k)) -1));
    return xsrl;
}


unsigned srl(unsigned x, int k){
    unsigned xsra = (int)x >> k;
    int w = sizeof(int) << 3;
    unsigned mask = (unsigned)-1;
    k == 0 || (mask >>= k);
    return xsra & mask;
}

int main(){
    int w = sizeof(int) << 3;
    for (int n = INT_MIN; n < INT_MAX; ++n)
    {
        for (int i = 0; i < w; ++i)
        {
            if (srl(n, i) != (unsigned)n >> i)
            {
                printf("test failed! x, i : %08x, %d\n ", n, i);
                printf("%08x \n", srl(n, i));
                printf("%08x \n", (unsigned)n >> i);

            }
        }
    }

    // for (int n = INT_MIN; n < INT_MAX; ++n)
    // {
    //     for (int i = 0; i < w; ++i)
    //     {
    //         if (sra(n, i) != n >> i)
    //             printf("test failed! x, i : %08x, %d\n ", n, i);
    //     }
    // }
}