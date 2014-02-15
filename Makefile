# Variables
MESA = /usr/bin/Mesa-5.0
PATH = examples/environment/main
EXAMPLE_ENVIRONMENT = examples/environment/main.c
INCPATH = -I$(MESA)/include
LIBPATH = -L$(MESA)/lib
LIBS        = -lglut -lGLU -lGL -lm
CFLAGS  = $(INCPATH) -g
LFLAGS  = $(LIBPATH) $(LIBS)

# Main targets
all: main.o
    $(CC) -o $(PATH) main.o $(LFLAGS)

# Source targets
main.o: $(EXAMPLE_ENVIRONMENT)
    $(CC) -c -pendantic $(EXAMPLE_ENVIRONMENT) $(CFLAGS)