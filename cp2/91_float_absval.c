#include <stdio.h>
#include <limits.h>
#include <math.h>
/**
对于浮点数f，函数计算|f|。如果f是NaN，直接返回f
*/
typedef unsigned float_bits;


float_bits float_absval(float_bits f){
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    if( exp == 0xff && frac != 0)
        return f;
    return (exp << 23) | frac;
}


int main(){
    for(float_bits f = 0; f < UINT_MAX ; ++f){
        float_bits fabs = float_absval(f);
        float fl = *((float *)&f);
        if(fl < 0)
            fl = -fl;
        float flabs = *((float *)&fabs);
        if(!isnan(fl) && fl != flabs){
            printf("wrong!%f and %f\n",fl,flabs);
            break;
        }
    }
}