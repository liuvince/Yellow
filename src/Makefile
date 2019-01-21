EXEC=play
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
CC=g++ -std=c++11 -g
CLIBS= -lsfml-graphics -lsfml-window -lsfml-system
LDFLAGS = -L../lib
LDLIBS = -lpacmangame
INCDIR = ../lib/

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) $(CLIBS) $(LDFLAGS)  -o $(EXEC) $(LDLIBS)

%.o: %.cc
	$(CC) -Wall -I$(INCDIR)  -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXEC)

install: play
	mkdir -p $(BINDIR)
	cp $(EXEC) $(BINDIR)

.PHONY: all clean install
