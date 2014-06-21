set terminal postscript eps enhanced
set output 'a26-plot-bins.eps'

set style line 1 lc rgb 'black' lt 1 lw 1 pt 7 ps 1
set style line 2 lc rgb 'red' lt 1 lw 2 pt 7 ps 1
set style fill solid 0.25 border

set xlabel 'Value'
set ylabel 'Probability Density'

set samples 1000

mean = 0
deviation = 1

# load constants from file
load 'a26-result-const.dat'

density(x) = 1/(sqrt(2*pi)*deviation)*exp(-(x-mean)**2/(2*deviation**2))

plot 'a26-result-binned.dat' using 1:2 with boxes ls 1 title "Histogram", \
density(x) with lines ls 2 title "Expected normal distribution"
