#include <stdio.h>
#include <limits.h>
/**
在对int类型使用逻辑右移的机器上运行返回1，使用算术右移则返回0
*/
int int_shifts_are_logical(){
    int w = INT_MIN;
    return ((unsigned)w>>1) == w>>1;
}

int main(){
    printf("%d\n",int_shifts_are_logical());
}