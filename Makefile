CFLAGS=-MD -Gy -Z7 -W4
LFLAGS=-incremental:no

all: fpraise.exe cos.exe status_invalid.exe integer_divide_overflow.exe

.SUFFIXES:
.SUFFIXES: .c .exe

.c.exe:
	cl $(CFLAGS) $< -link $(LFLAGS)

clean:
	-del *.exe *.obj *.pdb *.ilk a.out *.o
