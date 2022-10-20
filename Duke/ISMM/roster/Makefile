cc = gcc
CFLAGS = -std=gnu99 -Wall -Werror -ggdb3 -pedantic

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

test-roster:  $(OBJS)
	gcc -g -o  $@ -O3 $(OBJS)
.PHONY: clean
clean:
	rm -f test-roster *.o *~
	
# DO NOT DELETE
test-roster.o: test-roster.c roster.c roster.h