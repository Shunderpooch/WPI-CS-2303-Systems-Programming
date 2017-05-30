##Start of the Makefile
make: main clean

main: main.o motion.o print_field.o
	gcc -o Lab2 main.o motion.o print_field.o

main.o: main.c motion.h
	gcc -Wall -c main.c -std=c99

motion.o: motion.c motion.h
	gcc -Wall -c motion.c -std=c99

print_field.o: print_field.c motion.h
	gcc -Wall -c print_field.c -std=c99

clean:
	rm *.o

## End of Makefile
