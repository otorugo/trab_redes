all:
	gcc lib/*.c -g -c
	gcc main.c *.o -o program
run:
	./program
clean:
	rm *.o