// This program produces a different results under ARM64 emulation than AMD64 native.
// It uses floating point traps.

#pragma fenv_access(on)
#include <windows.h>
#include <stdio.h>
#include <fenv.h>
#include "excpt.h"

int main()
{
    int status = 0;

    __try
    {
        _control87(0, _MCW_EM);
        feraiseexcept(FE_DIVBYZERO);
    }
    __except(1)
    {
        status = GetExceptionCode();
    }

    printf("%s\n", (status == STATUS_FLOAT_DIVIDE_BY_ZERO) ? "pass" : "fail");
}
