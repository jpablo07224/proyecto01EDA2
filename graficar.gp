# ===================================================================
# GRUPO 1: GRÁFICAS COMPARATIVAS (LAS MÁS IMPORTANTES)
# ===================================================================
# --- Configuración General ---
set datafile separator ","
set terminal pngcairo size 1024,768 font "Verdana,10"
set grid
set key outside right top
set xlabel "Tamaño del Arreglo (n)"
set ylabel "Número de Operaciones (promedio)"

print "Generando 3 gráficas comparativas..."

# --- Gráfica Comparativa 1: Cuadráticos ---
set output 'comparativa_cuadraticos.png'
set title "Comparativa: Algoritmos Cuadráticos"
plot 'resultados.csv' using 2:(stringcolumn(1) eq "InsertionSort" ? $3 : 1/0) title "InsertionSort" with linespoints lc rgb 'red' pt 7, \
     '' using 2:(stringcolumn(1) eq "SelectionSort" ? $3 : 1/0) title "SelectionSort" with linespoints lc rgb 'blue' pt 9, \
     '' using 2:(stringcolumn(1) eq "BubbleSort" ? $3 : 1/0) title "BubbleSort" with linespoints lc rgb 'green' pt 5

# --- Gráfica Comparativa 2: N log N ---
set output 'comparativa_nlogn.png'
set title "Comparativa: Algoritmos O(n log n)"
plot 'resultados.csv' using 2:(stringcolumn(1) eq "HeapSort" ? $3 : 1/0) title "HeapSort" with linespoints lc rgb 'purple' pt 11, \
     '' using 2:(stringcolumn(1) eq "MergeSort" ? $3 : 1/0) title "MergeSort" with linespoints lc rgb 'orange' pt 13, \
     '' using 2:(stringcolumn(1) eq "QuickSort" ? $3 : 1/0) title "QuickSort" with linespoints lc rgb 'black' pt 15

# --- Gráfica Comparativa 3: Otros ---
set output 'comparativa_otros.png'
set title "Comparativa: Algoritmos Híbridos y Lineales"
plot 'resultados.csv' using 2:(stringcolumn(1) eq "ShellSort" ? $3 : 1/0) title "ShellSort" with linespoints lc rgb 'dark-green' pt 17, \
     '' using 2:(stringcolumn(1) eq "TimSort" ? $3 : 1/0) title "TimSort" with linespoints lc rgb 'dark-violet' pt 19, \
     '' using 2:(stringcolumn(1) eq "CountingSort" ? $3 : 1/0) title "CountingSort" with linespoints lc rgb 'gray' pt 21, \
     '' using 2:(stringcolumn(1) eq "RadixSort" ? $3 : 1/0) title "RadixSort" with linespoints lc rgb 'brown' pt 23


# ===================================================================
# GRUPO 2: GRÁFICAS INDIVIDUALES (REPETITIVO PERO SEGURO)
# ===================================================================
print "\nGenerando 11 gráficas individuales..."

# --- Gráfica 1: InsertionSort ---
set output 'grafica_individual_InsertionSort.png'
set title 'Rendimiento de InsertionSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "InsertionSort" ? $3 : 1/0) title "InsertionSort" with linespoints pt 7 lc 1

# --- Gráfica 2: SelectionSort ---
set output 'grafica_individual_SelectionSort.png'
set title 'Rendimiento de SelectionSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "SelectionSort" ? $3 : 1/0) title "SelectionSort" with linespoints pt 7 lc 2

# --- Gráfica 3: BubbleSort ---
set output 'grafica_individual_BubbleSort.png'
set title 'Rendimiento de BubbleSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "BubbleSort" ? $3 : 1/0) title "BubbleSort" with linespoints pt 7 lc 3

# --- Gráfica 4: GnomeSort ---
set output 'grafica_individual_GnomeSort.png'
set title 'Rendimiento de GnomeSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "GnomeSort" ? $3 : 1/0) title "GnomeSort" with linespoints pt 7 lc 4

# --- Gráfica 5: HeapSort ---
set output 'grafica_individual_HeapSort.png'
set title 'Rendimiento de HeapSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "HeapSort" ? $3 : 1/0) title "HeapSort" with linespoints pt 7 lc 5

# --- Gráfica 6: MergeSort ---
set output 'grafica_individual_MergeSort.png'
set title 'Rendimiento de MergeSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "MergeSort" ? $3 : 1/0) title "MergeSort" with linespoints pt 7 lc 6

# --- Gráfica 7: QuickSort ---
set output 'grafica_individual_QuickSort.png'
set title 'Rendimiento de QuickSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "QuickSort" ? $3 : 1/0) title "QuickSort" with linespoints pt 7 lc 7

# --- Gráfica 8: ShellSort ---
set output 'grafica_individual_ShellSort.png'
set title 'Rendimiento de ShellSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "ShellSort" ? $3 : 1/0) title "ShellSort" with linespoints pt 7 lc 8

# --- Gráfica 9: TimSort ---
set output 'grafica_individual_TimSort.png'
set title 'Rendimiento de TimSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "TimSort" ? $3 : 1/0) title "TimSort" with linespoints pt 7 lc 9

# --- Gráfica 10: CountingSort ---
set output 'grafica_individual_CountingSort.png'
set title 'Rendimiento de CountingSort'
set yrange [0:1]
plot 'resultados.csv' using 2:(stringcolumn(1) eq "CountingSort" ? $3 : 1/0) title "CountingSort" with linespoints pt 7 lc 10
unset yrange

# --- Gráfica 11: RadixSort ---
set output 'grafica_individual_RadixSort.png'
set title 'Rendimiento de RadixSort'
set yrange [0:1]
plot 'resultados.csv' using 2:(stringcolumn(1) eq "RadixSort" ? $3 : 1/0) title "RadixSort" with linespoints pt 7 lc 11
unset yrange

print "\n¡Proceso completado! Se generaron 14 gráficas."