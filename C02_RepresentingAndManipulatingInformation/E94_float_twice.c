#include <stdio.h>
#include <limits.h>
#include <math.h>
#include ".\Resources\show_bytes.h"

/**
 * 对于浮点数f，这个函数计算2.0 * f。如果f是NaN，你的函数应该简单的返回f。
 */

typedef unsigned float_bits;

float_bits float_twice(float_bits f){
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    if(exp == 0xff)
        return f;
    else if(exp > 0){
        if(exp == 254)
            frac = 0;
        exp += 1;
    }
    else if(frac & 0x400000){
        exp = 1;
        frac = (frac << 1) & 0x7fffff;
    }
    else
        frac <<= 1;
    return (sign << 31) | (exp << 23) | frac;
}

int main(){
    for(float_bits f = 0 ; f < UINT_MAX ; ++f){
    
        float_bits ftwice = float_twice(f);
        float fl = *((float *)&f);
        float fltwice = *((float *)&ftwice);
        if(!isnan(fl) &&  (float)2 * fl!= fltwice){
            show_bytes((byte_pointer)&f,sizeof(float_bits));
            show_float(fl *(float)2);
            show_float(fltwice);
            printf("wrong!%f and %f\n",fl,fltwice);
            break;
        }
    }
}