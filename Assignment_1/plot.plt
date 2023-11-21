#!/usr/bin/gnuplot -persist

set title "Grapl Plot"
set xlabel "NO of Nodes"
set ylabel "Count of Searches"
set grid
plot "plot.dat" u (column(0)):2:xtic(1) w l title "","plot.dat" u (column(0)):3:xtic(1) w l title ""
