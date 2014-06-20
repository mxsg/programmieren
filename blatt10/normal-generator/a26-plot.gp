set terminal postscript eps enhanced
set output 'a26-plot-bins.eps'

set style line 1 lc rgb 'black' lt 1 lw 1 pt 7 ps 1
set style line 2 lc rgb 'red' lt 1 lw 1 pt 7 ps 1
set style fill solid 0.25 border

set xlabel 'value'
set ylabel 'number of random numbers in bin'

plot 'a26-result-binned.dat' using 1:2 with boxes ls 1
