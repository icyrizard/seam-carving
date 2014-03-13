CC := gcc
CFLAGS := -Wall -Wextra
CPPLIB := -lstdc++
#COMMANDER := commander.o
OBJECTS := image.o commander.o

all: main $(OBJECTS) $(SUBMODULES)

main: main.cpp $(OBJECTS) $(COMMANDER)
	$(CC) $(CFLAGS) $^ -o $@ $(CPPLIB)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $^ -o $@

## compilation is subject to change the external library
## see https://github.com/clibs/commander
commander.o: commander/src/commander.c
	$(CC) -std=c99 -c $(CFLAGS) $< -o $@

clean:
	rm -rf main *.o
