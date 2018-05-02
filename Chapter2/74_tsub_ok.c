#include <limits.h>

/**
 * 如果计算x-y导致溢出，则返回1
 */

int tadd_ok(int x, int y)
{
    if(x > 0 && y > 0 && x+y <0)
        return 0;
    if(x < 0 && y < 0 && x+y >= 0)
        return 0;
    return 1;
}

int tsub_ok(int x, int y)
{
    if(y == INT_MIN)
    {
        if(tadd_ok(x,1) != 0)
            return tadd_ok(x+1 , -(INT_MIN + 1));
        else
            return 0;
    }
    else
        return tadd_ok(x,-y);
}