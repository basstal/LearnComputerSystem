#include <stdio.h>
#include "show_bytes.h"
#include <string.h>

/**
对show_bytes的测试，显示c字符串型
*/

void test(){
    const char *s = "abcdef";
    show_bytes((byte_pointer)s,strlen(s));
}

int main(){
    test();
}