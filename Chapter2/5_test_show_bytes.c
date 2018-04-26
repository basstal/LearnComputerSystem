#include <stdio.h>
#include "show_bytes.h"
/**
对show_bytes的测试，显示int型
*/
void test()
{
    int val = 0x87654321;
    byte_pointer ival = (byte_pointer) &val;
    show_bytes(ival,1);
    show_bytes(ival,2);
    show_bytes(ival,3);
}

int main(){
    test();
}