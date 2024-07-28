// This program produces a different results under ARM64 emulation than AMD64 native.
// It uses floating point status after invalid operation.

#pragma fenv_access(on)
#pragma fp_contract (off)
#include <float.h>
#include <assert.h>
#include <stdio.h>

volatile double a;
volatile double zero;
volatile double inf;

int main()
{
    unsigned initial_status = _clearfp();
    inf = 1.0 / zero;
    _clearfp();
    a = inf * zero;
    unsigned status_invalid = _clearfp();

    printf("%s\n", (initial_status == 0) ? "pass" : "fail");
    printf("%s\n", (status_invalid == 0x10) ? "pass" : "fail");
}
