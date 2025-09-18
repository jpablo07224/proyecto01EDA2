# --- Variables ---
# Compilador a usar
CC = gcc
# Flags (opciones) para el compilador. -g para debug, -Wall para warnings, -I para decirle dónde buscar los .h
CFLAGS = -g -Wall -Iinclude
# Nombre del programa ejecutable final
TARGET = bin/mi_programa

# Directorios
SRCDIR = src
OBJDIR = obj
BINDIR = bin

# Encuentra automáticamente todos los archivos .c en el directorio src y crea una lista de archivos .o correspondientes
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))


# --- Reglas ---

# La primera regla es la que se ejecuta por defecto al escribir "make"
# Se le llama "phony" (falsa) porque "all" no es un archivo real.
.PHONY: all
all: $(TARGET)

# Regla para crear el programa ejecutable final (el objetivo)
# Depende de todos los archivos objeto.
$(TARGET): $(OBJECTS)
	@mkdir -p $(BINDIR) # Crea el directorio bin/ si no existe
	$(CC) $(OBJECTS) -o $(TARGET)
	@echo "Programa compilado exitosamente: $(TARGET)"

# Regla genérica para crear cualquier archivo objeto (.o) a partir de un .c
# Depende de su archivo .c correspondiente.
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR) # Crea el directorio obj/ si no existe
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para limpiar los archivos generados
# .PHONY indica que "clean" es un comando, no un archivo.
.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(BINDIR)
	@echo "Archivos generados eliminados."