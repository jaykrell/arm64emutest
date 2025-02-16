/* This works under emulation but not as native ARM64.
 * ARM64 integer division does not overflow like x86 does.
 */
#include <windows.h>
#include <limits.h>
#include <stdio.h>
__declspec(dllexport)volatile int a = INT_MIN;
__declspec(dllexport)volatile int b = -1;
__declspec(dllexport)volatile int c;
int main()
{
    int eh = 0;
    __try { c = a / b; } __except(1) { eh = GetExceptionCode(); }
    printf("%x\n", eh);
}
