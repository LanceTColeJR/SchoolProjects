# Compiler and tools
CC = g++ -c -Wall -ansi -std=c++20
LN = g++

# Target executable
Proj2: main.o Parser.o myScanner.o Token.o
	$(LN) -o Proj2 main.o Parser.o myScanner.o Token.o

main.o: main.cpp Parser.hpp myScanner.hpp
	$(CC) main.cpp

Parser.o: Parser.cpp Parser.hpp myScanner.hpp
	$(CC) Parser.cpp

MyScanner.o: myScanner.cpp Parser.hpp myScanner.hpp
	$(CC) myScanner.cpp

myScanner.cpp: proj1-2.l myScanner.hpp
	flex++ proj1-2.l

Parser.hpp: bison.bis myScanner.hpp
	bison bison.bis

Parser.cpp: proj1-2.l myScanner.hpp
	bison proj1-2.l

Token.o: Token.cpp Token.hpp
	$(CC) Token.cpp

clean:
	/bin/rm -f *~ *.o Proj2 Parser.cpp Parser.hpp myScanner.cpp
