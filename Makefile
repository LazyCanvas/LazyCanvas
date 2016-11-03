# Makefile to compile lazycanvas

# See man gcc(in linux) to know what means each flag
CFLAGS = -g -Wall --std=c99 -Werror

# GCC is default compiler
CC=gcc

# all source codes that will be objects
TARGET_SRC = include/*.c include/figure/*.c include/structure/*.c

EXECUTABLE = lazyc

$(EXECUTABLE): parser.l parser.y
	# Generates bison and flex files
	bison -d parser.y
	mv parser.tab.h include/syntax.h
	mv parser.tab.c include/syntax.c
	flex parser.l
	mv lex.yy.c include/lexic.c
	# Static Compile
	$(CC) -c $(TARGET_SRC)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) *.o -lm
	rm *.o
clean:
	rm include/lexic.* include/syntax.* *.o
	rm lazyc
