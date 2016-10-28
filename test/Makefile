# Makefile
# gcc -Wall -Werror -Isrc -Iunity/Unity-2.4.0/src unity/Unity-2.4.0/src/unity.c scope_test.c scope_test_Runner.c

# Flags used to compile files
CFLAGS = -g -Wall -std=c99 -Werror -O2

# Compile
CXX=gcc

# Deps
DEPS=unity/unity.c

# Name of the executable file
EXECUTABLE=test

# Files
SRC=$(wildcard *.c) $(DEPS)
OBJECTS = $(SRC:.c=.o)

all: $(EXECUTABLE)

%.o: %.c $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	rm -f $(EXECUTABLE) *.o unity/unity.o
