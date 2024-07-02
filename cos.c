// This program produces a different results under ARM64 emulation than AMD64 native.
// It calls cos() and expects an exact result. There are many such cases.

#include <stdio.h>
#include <math.h>

int main()
{
    union {
        double d;
        __int64 i;
    } a = {cos(-1)};

    printf("%s\n", (a.i == 0x3FE14A280FB5068C) ? "pass" : "fail");
}
