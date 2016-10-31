lazyc: parser.l parser.y
	bison -d parser.y
	mv parser.tab.h include/syntax.h
	mv parser.tab.c include/syntax.c
	flex parser.l
	mv lex.yy.c include/lexic.c
	gcc -g -o lazyc include/syntax.c include/lexic.c -lm
clean:
	rm include/lexic.* include/syntax.* lazyc
