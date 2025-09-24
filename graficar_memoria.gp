# --- Configuración General ---
set datafile separator ","
set terminal pngcairo size 1200,800 font "Verdana,12"
set grid
set key outside right top
set xlabel "Tamaño del Arreglo (n)"
set title font ",14"

print "Generando 3 gráficas de memoria/mixtas..."

# --- Gráfica 1: Uso de Memoria de CountingSort ---
set output 'grafica_memoria_CountingSort.png'
set title 'Uso de Memoria de CountingSort'
set ylabel "Bytes de Memoria Utilizados"
set key top left
plot 'resultados.csv' using 2:(stringcolumn(1) eq "CountingSort" ? $6 : 1/0) title "CountingSort" with linespoints pt 7 lc 10

# --- Gráfica 2: Uso de Memoria de RadixSort ---
set output 'grafica_memoria_RadixSort.png'
set title 'Uso de Memoria de RadixSort'
set ylabel "Bytes de Memoria Utilizados"
plot 'resultados.csv' using 2:(stringcolumn(1) eq "RadixSort" ? $6 : 1/0) title "RadixSort" with linespoints pt 7 lc 11

# --- Gráfica 3: Comparativa Mixta (Híbridos y Lineales) ---
set output 'comparativa_otros.png'
set title "Comparativa: Algoritmos Híbridos y Lineales"
set ylabel "Costo Computacional (Operaciones o Bytes)"
set key outside right top
plot 'resultados.csv' using 2:(stringcolumn(1) eq "ShellSort" ? ($3+$4+$5) : 1/0) title "ShellSort (Operaciones)" with linespoints lc rgb '#46F0F0' lw 2 pt 17 ps 1.5, \
     '' using 2:(stringcolumn(1) eq "TimSort" ? ($3+$4+$5) : 1/0) title "TimSort (Operaciones)" with linespoints lc rgb '#f032e6' lw 2 pt 19 ps 1.5, \
     '' using 2:(stringcolumn(1) eq "CountingSort" ? $6 : 1/0) title "CountingSort (Bytes)" with linespoints lc rgb '#bcf60c' lw 2 pt 21 ps 1.5, \
     '' using 2:(stringcolumn(1) eq "RadixSort" ? $6 : 1/0) title "RadixSort (Bytes)" with linespoints lc rgb '#fabebe' lw 2 pt 23 ps 1.5

print "\n¡Proceso de gráficas de memoria completado!"