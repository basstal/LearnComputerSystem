#include <stdio.h>

/**
 * 将数组前后两部分的元素互换位置
 */

void inplace_swap(int *x, int *y)
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void reverse_array(int a[], int cnt)
{
    int first,last;
    for(first = 0, last = cnt-1; first < last ; first ++, last--)
        inplace_swap(&a[first],&a[last]);
}

void print_arr(int a[],int cnt)
{
    int i = 0;
    for(; i < cnt; ++i)
        printf("%d",a[i]);
    printf("\n");
}

int main()
{
    int arr1[4] = {1,2,3,4};
    int arr2[5] = {1,2,3,4,5};
    reverse_array(arr1,4);
    reverse_array(arr2,5);
    print_arr(arr1,4);
    print_arr(arr2,5);
    return 0;
}