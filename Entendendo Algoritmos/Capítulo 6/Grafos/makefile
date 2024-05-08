# Nome do executável final
TARGET = meu_programa

# Diretórios
SRCDIR = src
INCDIR = lib
BUILDDIR = build
TARGETDIR = bin

# Compilador
CC = gcc
CFLAGS = -Wall -I$(INCDIR)

# Arquivos fonte e objetos
SRCEXT = c
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# Nome do binário final
EXECUTABLE := $(TARGETDIR)/$(TARGET)

# Comando para limpar arquivos
RM = rm -rf

# Comando padrão
all: directories $(EXECUTABLE)

# Compilação
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	$(CC) $^ -o $(EXECUTABLE)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Limpar
clean:
	$(RM) $(BUILDDIR) $(TARGETDIR)

# Criar diretórios necessários
directories:
	@mkdir -p $(BUILDDIR) $(TARGETDIR)

# Fazer o makefile não se confundir com os diretórios de mesmo nome
.PHONY: all clean directories
