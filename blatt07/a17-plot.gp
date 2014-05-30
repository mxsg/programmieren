set terminal postscript eps enhanced


set output 'a17-plot.eps'

set style line 1 lc rgb 'black' lw 7 pt 7 ps 1
set style line 2 lc rgb 'red'  lt 1 lw 1 pt 7 ps 1

set xlabel 'x'
set ylabel 'f(x)'


plot 'a17-result.dat' using 1:2 with lines ls 2 title "Berechnete Werte", \
'a16-interpol.dat' using 1:2 with points ls 1 title "Stuetzstellen"