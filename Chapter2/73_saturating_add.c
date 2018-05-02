#include <stdio.h>

/**
 * 对补码加法，当正溢出时，返回TMax，负溢出时，返回TMin
 */

int saturating_add(int x, int y){
    int sign = 0x80000000,ret;
    (x & sign) == 0 && (y & sign) == 0 && (x + y & sign) != 0 && (ret = (unsigned)sign - 1);
    (x & sign) != 0 && (y & sign) != 0 && (x + y & sign) == 0 && (ret = sign);
    return ret;
}

int main(){
    printf("%d\n",saturating_add(0x71234567,0x77654321));
    printf("%d\n",saturating_add(0x71234567,0x00001234));
    printf("%d\n",saturating_add(0x81234567,0x87651234));
    printf("%d\n",saturating_add(0x81234567,0xffffffff));
}