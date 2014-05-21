# Makefile

CC	 	= gcc
CFLAGS	 	= -O2 -Wall -fopenmp
LDFLAGS		= -O2 -Wall -fopenmp
INCLUDES 	= -I.
LIBS 		= -lm
GEN_OBJS	= matfunc.o genmat_main.o mulmat.o
BENCHMUL_OBJS	= matfunc.o benchmul_main.o mulmat.o

all: genmat benchmul

genmat:	$(GEN_OBJS)
	$(CC) $(LDFLAGS) -o $@ $(GEN_OBJS) $(LIBS)

benchmul: $(BENCHMUL_OBJS)
	$(CC) $(LDFLAGS) -o $@ $(BENCHMUL_OBJS) $(LIBS)

clean:
	rm -f $(GEN_OBJS) *~ \#*

matfunc.o: matfunc.h
genmat_main.o: matfunc.h
benchmul_main.o: matfunc.h mulmat.h
mulmat.o: mulmat.h
