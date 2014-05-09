set grid
set title 'Opteron computation performance(stress test)'
set xlabel 'Numar elemente:'
set ylabel 'timp(s)'

set xrange [0:*]
set yrange [0:2]

plot 'opt_neoptim' using 1:2 with lines\
		  title 'cblas_neoptim',\
     'opt_atlas'   using 1:2 with lines\
                  title 'cblas_atlas'

set terminal png
set output "opt.png"
replot
