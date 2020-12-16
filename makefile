		CC     = gcc -std=c11 -g -fopenmp -D PAR
		CFLAGS = -Wall

			PROG = parallelImdb
			OBJS = read.o \
						 $(PROG).o

.PHONY: limpa faxina clean distclean purge all

$(PROG):  $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS) $(CFLAGS)

all: $(PROG)

clean:
	@rm -f *.o

purge:   clean
	@rm -f *.csv
	@rm -f *.o core a.out
	@rm -f $(PROG)
