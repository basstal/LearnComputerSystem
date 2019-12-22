#include <stdio.h>
#include <limits.h>

/**
 * 写一个C表达式，在下列描述的条件下产生1，而在其他情况下得到0.假设x是int类型。
 * A.x的任何位都等于1
 * B.x的任何位都等于0
 * C.x的最低有效字节中的位都等于1
 * D.x的最高有效字节中的位都等于0
 */
int w1 = (sizeof(int) - 1) << 3;

void expression4(int x){
    //A
    int a = !((x & -1)^-1);
    int atest = (x & 0xFFFFFFFF) == 0xFFFFFFFF;
    if (a != atest)
        printf("A test failed! value : %08x", x);

    //B
    int b = !x;
    int btest = x == 0;
    if (b != btest)
        printf("B test failed! value : %08x ", x);

    //C
    int c = !((x & 0xFF)^ 0xFF);
    int ctest = (x & 0xFF) == 0xFF;
    if (c != ctest)
        printf("C test failed! value : %08x", x);

    //D
    int d = !(x & (0xFF << w1));
    int dtest = (unsigned)x >> w1 == 0;
    if (d != dtest)
        printf("D test failed! value : %08x", x);
}

int main(){
    for (int i = INT_MIN; i < INT_MAX; ++i)
    {
        expression4(i);
    }
}