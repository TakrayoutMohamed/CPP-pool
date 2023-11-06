#include <iostream>

int main(void)
{
    int a = 10;
    printf("a = %d\n", a);
    printf("a << 8 = %d\n", a << 8);
    printf("a >> 8 = %d\n", a >> 8);
    return (0);
}
/*
10 = 1010
a << 8 = 101000000000 = a * 2^8
a >> 8 = 0.0000101 = a / 2^8

*/