#include <stdio.h>
#include <math.h>
#include <limits.h>
/**
对于浮点数f，函数计算-f。如果f是NaN，直接返回f
*/
typedef unsigned float_bits;

float_bits float_negate(float_bits f){
    unsigned sign = f >> 31;
    unsigned exp = f>>23 & 0xff;
    unsigned frac = f & 0x7fffff;
    if(exp == 0xff && frac != 0)
        return f;
    return ((sign ^ 0x1) <<31) | (exp << 23) | frac;
}

int main(){
    for(float_bits f = 0 ; f < UINT_MAX ; ++f){
        float_bits fneg = float_negate(f);
        float fl = *((float *)&f);
        float flneg = *((float *)&fneg);
        if(!isnan(fl) && fl != -flneg){
            printf("wrong!%f and %f\n",fl,flneg);
            break;
        }
    }

}