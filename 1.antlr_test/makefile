all: ./ExprCppTree.g main.cpp
	java -jar ./antlr-3.4-complete.jar ExprCppTree.g
	g++ -std=c++11 -L./libs main.cpp ./ExprCppTreeLexer.c ./ExprCppTreeParser.c -lantlr3c

debug: ./ExprCppTree.g main.cpp
	java -jar ./antlr-3.4-complete.jar ExprCppTree.g
	g++ -std=c++11 -DDEBUG -L./libs main.cpp ./ExprCppTreeLexer.c ./ExprCppTreeParser.c -lantlr3c

run:
	./a.out input

