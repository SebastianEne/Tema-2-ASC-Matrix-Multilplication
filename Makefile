
GCC=gcc
SRC=main.c

CFLAGS_NEHALEM_I="/opt/tools/libraries/atlas/3.10.1-nehalem-gcc-4.4.6/include"
CFLAGS_OPTERON_I="/opt/tools/libraries/atlas/3.10.1-opteron-gcc-4.4.6/include"
CFLAGS_QUAD_I="/opt/tools/libraries/atlas/3.10.1-quad-gcc-4.4.6/include"

LINK_FLAGS =-Bstatic -lcblas -latlas -Bdynamic
OPTIMIZE_FLAGS = -O2

CFLAGS_NEHALEM_L="/opt/tools/libraries/atlas/3.10.1-nehalem-gcc-4.4.6/lib"
CFLAGS_OPTERON_L="/opt/tools/libraries/atlas/3.10.1-opteron-gcc-4.4.6/lib"
CFLAGS_QUAD_L="/opt/tools/libraries/atlas/3.10.1-quad-gcc-4.4.6/lib"

compile: nehalem opteron quad 

nehalem: libutils.a
	gcc main.c libutils.a -I $(CFLAGS_NEHALEM_I) -L $(CFLAGS_NEHALEM_L) $(LINK_FLAGS) -o $@ -O2

opteron: libutils.a
	gcc main.c libutils.a -I $(CFLAGS_OPTERON_I) -L $(CFLAGS_OPTERON_L) $(LINK_FLAGS) -o $@ -O2

quad: libutils.a
	gcc main.c libutils.a -I $(CFLAGS_QUAD_I) -L $(CFLAGS_QUAD_L) $(LINK_FLAGS) -o $@ -O2

libutils.a: utils.o
	ar rc libutils.a utils.o

utils.o: utils.c utils.h
	gcc -c utils.c utils.h -O2

clean:
	rm nehalem opteron quad libutils.a utils.o -r out/

