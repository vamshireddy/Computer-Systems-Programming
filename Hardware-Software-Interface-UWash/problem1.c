#include <stdio.h>

int main()
{
    int x = -0x4;
    int y = 0x80000000;
    printf("x: %x\n", x);
    printf("y: %x\n", y);
    int z = x & y;
    printf("z: %x\n", z); //expecting binary 10000000, but actual value is 80000000
    return 0;
}
