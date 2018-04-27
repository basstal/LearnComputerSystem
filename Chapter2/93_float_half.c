#include <stdio.h>
#include <math.h>
#include <limits.h>
#include "show_bytes.h"
/**
 * 对于浮点数f，函数计算0.5*f。如果f是NaN，直接返回f
 */
typedef unsigned float_bits;


float_bits float_half(float_bits f){
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    if(exp == 0xff)
        return f;
    else if(exp > 1)
        exp -= 1;
    else if(exp == 1){
        if(frac == 0x7fffff)
            frac = 0;
        else{
            exp = 0;
            //发生最低位舍入
            if(frac & 0x1 && frac & 0x2)
                frac = (frac >> 1) + 1;
            else
                frac >>= 1;
            //最高位添加一个1,这个1来自规格数多出的那个1
            frac |= 0x400000;
        }
    }
    else{
        //发生最低位舍入
        if(frac & 0x1 && frac & 0x2)
            frac = (frac >> 1) + 1;
        else
            frac >>= 1;
    }
    return (sign << 31) | (exp << 23) | frac;
}


int main(){
    for(float_bits f = 0 ; f < UINT_MAX ; ++f){
    
        float_bits fhalf = float_half(f);
        float fl = *((float *)&f);
        float flhalf = *((float *)&fhalf);
        if(!isnan(fl) &&  (float)0.5 * fl!= flhalf){
            show_bytes((byte_pointer)&f,sizeof(float_bits));
            show_float(fl * (float)0.5);
            show_float(flhalf);
            printf("wrong!%f and %f\n",fl,flhalf);
            break;
        }
    }

}