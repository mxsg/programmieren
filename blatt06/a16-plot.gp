set terminal postscript eps enhanced


set output 'a16-plot.eps'

set style line 1 lc rgb 'black' lw 7 pt 7 ps 1
set style line 2 lc rgb 'red'  lw 7 pt 7 ps 1

set xlabel 'x'
set ylabel 'f(x)'

plot 'a16-interpol.dat' using 1:2 with points ls 1 title "Stuetzstellen", \
'a16-interpol-res.dat' using 1:2 with points ls 2 title "Berechnete Werte"
