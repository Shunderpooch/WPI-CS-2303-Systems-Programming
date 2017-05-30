##Start of the Makefile
make: main clean

main: main.o Round.o Print_Field.o GenerateBoard.o
	gcc -o Program2 main.o Round.o Print_Field.o GenerateBoard.o

main.o: main.c BoardPlayersMore.h
	gcc -Wall -c main.c -std=c99

Round.o: Round.c BoardPlayersMore.h
	gcc -Wall -c Round.c -std=c99

Print_Field.o: Print_Field.c BoardPlayersMore.h
	gcc -Wall -c Print_Field.c -std=c99

GenerateBoard.o: GenerateBoard.c BoardPlayersMore.h
	gcc -Wall -c GenerateBoard.c -std=c99

clean:
	rm *.o
##End of the Makefile
