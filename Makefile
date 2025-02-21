CFLAGS = -O2 -march=native `pkg-config --cflags gsl`
LIBS = `pkg-config --libs gsl`

.PHONY: all


all: g


g: gillespie.c model.c
	cc $(CFLAGS) -o $@ $^ $(LIBS)
