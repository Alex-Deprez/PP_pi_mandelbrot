CC = gcc
CFLAGS = -O3 -march=native -mtune=native -Wall
OMPFLAGS = -fopenmp
LDFLAGS = -lm

SRCS := $(wildcard *.c)
BINS := $(SRCS:.c=)

all: $(BINS)

%: %.c
	$(CC) $(CFLAGS) $(OMPFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -f $(BINS)
