#
# Makefile
#

#Flags used to compile files
CFLAGS = -g -Wall -std=c99 -Werror -O2

#Compile
CXX=gcc

#Deps
DEPS=../include/figure/print.c

#Name of the executable file
TARGET=test

#Files
PROG1 = print_test.c
OBJ = print_test.o

all: $(TARGET)

%.o: %.c $(DEPS)
	$(CXX) $(CFLAGS) -c -o $@ $<

$(TARGET): $(OBJ)
	$(CXX) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) *.o
