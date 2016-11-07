# Makefile
# gcc -Wall -Werror -Isrc -Iunity/Unity-2.4.0/src unity/Unity-2.4.0/src/unity.c scope_test.c scope_test_Runner.c
UNIT_SOURCE=unity/Unity-2.4.0

# Flags used to compile files
CFLAGS = -g -Wall -std=c99 -Werror -Isrc -I$(UNIT_SOURCE)/src -o

# Compile
CXX=gcc

# Deps
DEPS=$(UNIT_SOURCE)/src/unity.c ../include/structure/objects.c

# Name of the executable file
EXECUTABLE=test

# Files
SRC=$(DEPS) $(wildcard *.c)
OBJECTS = $(SRC:.c=.o)

all:
	$(CXX) $(CFLAGS) $(EXECUTABLE) $(SRC)

clean:
	rm -f $(EXECUTABLE) *.o a.out
