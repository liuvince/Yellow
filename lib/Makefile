CC = g++ -std=c++11 -g
SRC = $(wildcard *.cc)
OBJ = $(SRC:.cc=.o)
CLIBS= -L/home/sasl/shared/main/c++/SFML-2.5.1/lib -lsfml-graphics  -lsfml-window -lsfml-system
INCDIR=-I//home/sasl/shared/main/c++/SFML-2.5.1/include

all: libpacmangame.a

libpacmangame.a: $(OBJ)
	ar cru $@ $(OBJ)
	ranlib $@

%.o: %.c
	$(CC) -Wall $(INCDIR) $(CLIBS) -c -o $@ $<

clean:
	-rm -f $(OBJ) libpacmangame.a

.PHONY: all clean

