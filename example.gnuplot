#!/usr/bin/env gnuplot
set term pngcairo size 1024,768 font "Fira Code, 16"
set output 'example.png'
set xlabel 'time'
set ylabel 'Counts'
set title "Gillespie Simulation of: A + B <=> C"
plot 'trajectory.txt' using 1:2 skip 1 with lines title 'A', 'trajectory.txt' using 1:4 skip 1 with lines title 'C'
set output
unset term