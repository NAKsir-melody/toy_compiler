sigmoidc: main.o lex.o syntax.o ast.o codegen.o
	g++ -g -o sigmoidc main.o lex.o syntax.o ast.o codegen.o
main.o:
	g++ -g -o main.o -c main.cpp 
lex.o:
	g++ -g -o lex.o -c lex.cpp 
syntax.o:
	g++ -g -o syntax.o -c syntax.cpp 
ast.o:
	g++ -g -o ast.o -c ast.cpp 
codegen.o:
	g++ -g -o codegen.o -c codegen.cpp 
clean:
	rm sigmoidc *.o a.out
