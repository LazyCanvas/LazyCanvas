calc: canvas_lexic.l canvas_syntax.y
	bison -d canvas_syntax.y
	mv canvas_syntax.tab.h include/syntax.h
	mv canvas_syntax.tab.c include/syntax.c
	flex canvas_lexic.l
	mv lex.yy.c include/lexic.c
	gcc -o calc include/syntax.c include/lexic.c -lm

clean:
	rm lexic.* syntax.* calc.exe
