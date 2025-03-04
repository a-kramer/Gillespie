CFLAGS = -O2 -march=native `pkg-config --cflags gsl`
LIBS = `pkg-config --libs gsl`

.PHONY: all


all: g example.png


g: gillespie.c model.c
	cc $(CFLAGS) -o $@ $^ $(LIBS)

akap79: gillespie.c AKAP79_stochastic.c
	cc $(CFLAGS) -o $@ $^ $(LIBS)

trajectory.txt: g
	./g 0 1 > $@

example.png: example.gnuplot trajectory.txt
	gnuplot $<
