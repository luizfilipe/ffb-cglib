# Variables
MESA = /usr/bin/Mesa-5.0
PROJECT_PATH = examples/environment/main
EXAMPLE_ENVIRONMENT = examples/environment/main.c
INCPATH = -I$(MESA)/include
LIBPATH = -L$(MESA)/lib
LIBS = -lglut -lGLU -lGL -lm
CFLAGS  = $(INCPATH) -g
LFLAGS  = $(LIBPATH) $(LIBS)

# Main targets
all: main.o
	$(CC) -std=c11 -o $(PROJECT_PATH) main.o $(LFLAGS)

# Source targets
main.o: $(EXAMPLE_ENVIRONMENT)
	$(CC) -c -pedantic $(EXAMPLE_ENVIRONMENT) $(CFLAGS)