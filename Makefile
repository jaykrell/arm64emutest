CFLAGS=-MD -Gy -Z7 -W4
LFLAGS=-incremental:no

all: fpraise.exe cos.exe

.SUFFIXES: .c .exe

.c.exe:
	cl $(CFLAGS) $< -link $(LFLAGS)

clean:
	-del *.exe *.obj *.pdb *.ilk a.out *.o
