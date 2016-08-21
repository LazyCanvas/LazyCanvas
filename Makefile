calc: exemplo01.l exemplo01.y
	bison -d exemplo01.y
	mv exemplo01.tab.h include/sintatico.h
	mv exemplo01.tab.c include/sintatico.c
	flex exemplo01.l
	mv lex.yy.c include/lexico.c
	gcc -o calc include/sintatico.c include/lexico.c -lm

clean:
	rm lexico.* sintatico.* calc.exe
