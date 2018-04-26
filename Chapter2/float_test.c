#include <stdio.h>
int main()
{
    float a,b;
    a = 1e20;
    b = 1.0f;
    printf("%f\n", a + b);
    printf("%d", (a + b) - a == a + (b - a));
    return 0;
}