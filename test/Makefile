#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall -std=c99 -Werror -O2

#Compile
CXX=gcc

#Deps
#DEPS=sample.h

#Name of the executable file
TARGET=test

#Files
PROG1 = scope_test.c
OBJ = scope_test.o

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o
