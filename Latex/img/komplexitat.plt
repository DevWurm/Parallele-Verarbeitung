# Darstellung der Zeitkomplexität der Algorithmen
m(x)=x*log(x)
p(x)=(x*log(x))/4
b(x)=x**2
set title 'Zeitkomplexität'
set xlabel 'n'
set ylabel 'T(n)'
set xrange[0:50]
set yrange[0:500]
unset xtics
unset ytics
plot m(x) title 'Mergesort', \
p(x) title 'Paralleler Mergesort (p=4)', \
b(x) title 'Bubblesort'
