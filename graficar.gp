# --- Configuración General ---
set datafile separator ","
set terminal pngcairo size 1024,768 font "Verdana,10" # Tamaño un poco más grande
set grid
set key outside right top  # Leyenda fuera del gráfico a la derecha para no ocultar datos
set xlabel "Tamaño del Arreglo (n)"
set ylabel "Número de Operaciones (promedio)" # Etiqueta Y más general por defecto

# Define una serie de estilos de línea/punto/color para usar en las gráficas comparativas
# Esto asegura que cada algoritmo tenga un aspecto único
# lc = linecolor, lt = linetype, pt = pointtype, ps = pointsize
styles = "lc rgb 'red' lt 1 pt 7 ps 1.5, \
          lc rgb 'blue' lt 2 pt 9 ps 1.5, \
          lc rgb 'green' lt 3 pt 5 ps 1.5, \
          lc rgb 'purple' lt 4 pt 11 ps 1.5, \
          lc rgb 'orange' lt 5 pt 13 ps 1.5, \
          lc rgb 'black' lt 6 pt 15 ps 1.5, \
          lc rgb 'dark-green' lt 7 pt 17 ps 1.5, \
          lc rgb 'dark-violet' lt 8 pt 19 ps 1.5, \
          lc rgb 'gray' lt 9 pt 21 ps 1.5, \
          lc rgb 'brown' lt 10 pt 23 ps 1.5, \
          lc rgb 'teal' lt 11 pt 25 ps 1.5"

# --- Lista de Algoritmos (para filtrado) ---
# Se asume que el nombre del algoritmo en el CSV es EXACTAMENTE igual aquí.
# Esto se usa para filtrar en lugar de 'every ::N'
algoritmos_individuales = "InsertionSort SelectionSort BubbleSort GnomeSort Heapsort MergeSort Quicksort ShellSort TimSort CountingSort RadixSort"
algoritmos_cuadraticos = "InsertionSort SelectionSort BubbleSort"
algoritmos_nlogn = "Heapsort MergeSort Quicksort"
algoritmos_otros = "ShellSort TimSort CountingSort RadixSort"


# ===================================================================
# PARTE 1: GENERAR LAS 11 GRÁFICAS INDIVIDUALES AUTOMÁTICAMENTE
# ===================================================================

print "Generando 11 gráficas individuales..."
do for [i=1:words(algoritmos_individuales)] {
    algo_name = word(algoritmos_individuales, i)
    
    set output sprintf('grafica_individual_%s.png', algo_name)
    set title sprintf('Rendimiento de %s', algo_name)

    # Restablece el rango Y si no es Counting/Radix (donde las comparaciones son 0)
    # y los otros valores (swaps/insertions) no tienen un rango grande
    if (strstr(algo_name, "CountingSort") || strstr(algo_name, "RadixSort")) {
        set ylabel "Número de Operaciones (Totales)" # Etiqueta más específica
        # Si las gráficas de CS/RS se ven vacías, puedes ajustar el yrange aquí,
        # pero para 0 comparaciones, se verá una línea en 0.
        # set yrange [0:*] # Descomenta y ajusta si quieres un rango específico
    } else {
        set ylabel "Número de Comparaciones (promedio)"
        unset yrange # Deja que Gnuplot decida el mejor rango
    }

    # Grafica filtrando por el nombre del algoritmo en la primera columna
    plot 'resultados.csv' using 2:3 every (stringcolumn(1) eq algo_name) title algo_name with linespoints pt 7 lc i
}

# Restablece la etiqueta Y general para las gráficas comparativas
set ylabel "Número de Operaciones (promedio)"
unset yrange # Restablece el rango Y automático

# ===================================================================
# PARTE 2: GENERAR LAS 3 GRÁFICAS COMPARATIVAS
# ===================================================================

print "\nGenerando 3 gráficas comparativas..."

# --- Gráfica Comparativa 1: Cuadráticos ---
set output 'comparativa_cuadraticos.png'
set title "Comparativa: Algoritmos Cuadráticos (Insertion, Selection, Bubble)"
plot for [i=1:words(algoritmos_cuadraticos)] \
     'resultados.csv' using 2:3 every (stringcolumn(1) eq word(algoritmos_cuadraticos, i)) \
     title word(algoritmos_cuadraticos, i) with linespoints @word(styles, i)

# --- Gráfica Comparativa 2: N log N ---
set output 'comparativa_nlogn.png'
set title "Comparativa: Algoritmos O(n log n) (Heap, Merge, Quick)"
# Aquí podemos usar los estilos desde un índice más alto si queremos colores distintos
plot for [i=1:words(algoritmos_nlogn)] \
     'resultados.csv' using 2:3 every (stringcolumn(1) eq word(algoritmos_nlogn, i)) \
     title word(algoritmos_nlogn, i) with linespoints @word(styles, i + 3) # Usamos colores a partir del 4º estilo

# --- Gráfica Comparativa 3: Otros ---
set output 'comparativa_otros.png'
set title "Comparativa: Algoritmos Híbridos y Lineales (Shell, Timsort, Counting, Radix)"
plot for [i=1:words(algoritmos_otros)] \
     'resultados.csv' using 2:3 every (stringcolumn(1) eq word(algoritmos_otros, i)) \
     title word(algoritmos_otros, i) with linespoints @word(styles, i + 6) # Usamos colores a partir del 7º estilo

print "\n¡Proceso completado!"