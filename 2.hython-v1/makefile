all: grammer main.cpp
	g++ -std=c++11 -I./include -I./include/antlr -L./lib -o ./bin/hython main.cpp ./src/*.c -lantlr3c

debug: grammer main.cpp
	g++ -DDEBUG -std=c++11 -I./include -I./include/antlr -L./lib -o ./bin/hython main.cpp ./src/*.c -lantlr3c

grammer: ./thirdpart/hython.g
	java -jar ./thirdpart/antlr-3.4-complete.jar ./thirdpart/hython.g
	mv ./hython.tokens ./thirdpart/
	mv ./thirdpart/*.c src/
	mv ./thirdpart/*.h include/

run:
	./bin/hython ./testdata/input1

