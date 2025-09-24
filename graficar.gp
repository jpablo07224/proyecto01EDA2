# ===================================================================
# GRUPO 1: GRÁFICAS COMPARATIVAS
# ===================================================================
# --- Configuración General ---
set datafile separator ","
set terminal pngcairo size 1200,800 font "Verdana,12"
set grid
set key outside right top
set xlabel "Tamaño del Arreglo (n)"
set ylabel "Suma de Operaciones (promedio)"
set title font ",14"

print "Generando 2 gráficas comparativas..."

# --- Gráfica Comparativa 1: Cuadráticos ---
set output 'comparativa_cuadraticos.png'
set title "Comparativa: Algoritmos Cuadráticos (Suma de Operaciones)"
plot 'resultados.csv' using 2:(stringcolumn(1) eq "InsertionSort" ? ($3+$4+$5) : 1/0) title "InsertionSort" with linespoints lc rgb '#E6194B' lw 2 pt 7 ps 1.5, \
     '' using 2:(stringcolumn(1) eq "SelectionSort" ? ($3+$4+$5) : 1/0) title "SelectionSort" with linespoints lc rgb '#3CB44B' lw 2 pt 9 ps 1.5, \
     '' using 2:(stringcolumn(1) eq "BubbleSort" ? ($3+$4+$5) : 1/0) title "BubbleSort" with linespoints lc rgb '#4363D8' lw 2 pt 5 ps 1.5

# --- Gráfica Comparativa 2: N log N ---
set output 'comparativa_nlogn.png'
set title "Comparativa: Algoritmos O(n log n) (Suma de Operaciones)"
plot 'resultados.csv' using 2:(stringcolumn(1) eq "HeapSort" ? ($3+$4+$5) : 1/0) title "HeapSort" with linespoints lc rgb '#F58231' lw 2 pt 11 ps 1.5, \
     '' using 2:(stringcolumn(1) eq "MergeSort" ? ($3+$4+$5) : 1/0) title "MergeSort" with linespoints lc rgb '#911EB4' lw 2 pt 13 ps 1.5, \
     '' using 2:(stringcolumn(1) eq "QuickSort" ? ($3+$4+$5) : 1/0) title "QuickSort" with linespoints lc rgb '#000000' lw 2 pt 15 ps 1.5

# ===================================================================
# GRUPO 2: GRÁFICAS INDIVIDUALES (AHORA CON LA SINTAXIS CORRECTA)
# ===================================================================
print "\nGenerando 9 gráficas individuales..."
set key top left

# --- Gráfica 1: InsertionSort ---
set output 'grafica_individual_InsertionSort.png'
set title 'Rendimiento de InsertionSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "InsertionSort" ? ($3+$4+$5) : 1/0) title "InsertionSort" with linespoints pt 7 lc 1

# --- Gráfica 2: SelectionSort ---
set output 'grafica_individual_SelectionSort.png'
set title 'Rendimiento de SelectionSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "SelectionSort" ? ($3+$4+$5) : 1/0) title "SelectionSort" with linespoints pt 7 lc 2

# --- Gráfica 3: BubbleSort ---
set output 'grafica_individual_BubbleSort.png'
set title 'Rendimiento de BubbleSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "BubbleSort" ? ($3+$4+$5) : 1/0) title "BubbleSort" with linespoints pt 7 lc 3

# --- Gráfica 4: GnomeSort ---
set output 'grafica_individual_GnomeSort.png'
set title 'Rendimiento de GnomeSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "GnomeSort" ? ($3+$4+$5) : 1/0) title "GnomeSort" with linespoints pt 7 lc 4

# --- Gráfica 5: HeapSort ---
set output 'grafica_individual_HeapSort.png'
set title 'Rendimiento de HeapSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "HeapSort" ? ($3+$4+$5) : 1/0) title "HeapSort" with linespoints pt 7 lc 5

# --- Gráfica 6: MergeSort ---
set output 'grafica_individual_MergeSort.png'
set title 'Rendimiento de MergeSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "MergeSort" ? ($3+$4+$5) : 1/0) title "MergeSort" with linespoints pt 7 lc 6

# --- Gráfica 7: QuickSort ---
set output 'grafica_individual_QuickSort.png'
set title 'Rendimiento de QuickSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "QuickSort" ? ($3+$4+$5) : 1/0) title "QuickSort" with linespoints pt 7 lc 7

# --- Gráfica 8: ShellSort ---
set output 'grafica_individual_ShellSort.png'
set title 'Rendimiento de ShellSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "ShellSort" ? ($3+$4+$5) : 1/0) title "ShellSort" with linespoints pt 7 lc 8

# --- Gráfica 9: TimSort ---
set output 'grafica_individual_TimSort.png'
set title 'Rendimiento de TimSort'
plot 'resultados.csv' using 2:(stringcolumn(1) eq "TimSort" ? ($3+$4+$5) : 1/0) title "TimSort" with linespoints pt 7 lc 9

print "\n¡Proceso completado! Se generaron 11 gráficas."