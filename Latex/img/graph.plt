set xlabel 'Listenlänge'
set ylabel 'Laufzeit in Millisekunden'
set xrange [0:5010000]
set yrange [0:50000]
set title 'sequentieller und paralleler Mergesort'
set datafile separator ","
plot 'results_sequential.csv' using 1:2 title 'sequentiell' with lines, 'results_parallel.csv' using 1:2 title 'parallel' with lines
