#include <stdio.h>
#include ".\Resources\show_bytes.h"

/**
 * 调用show_bytes显示其他类型的字节值
 */

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float)ival;
    int *pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main(){
    show_short((short)23456);
    show_long((long)213543512434134);
    show_double((double)0.001);
}