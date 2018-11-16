all: main.o
	@gcc -o forkin.out main.o

main.o: main.c
	@gcc -c main.c

run:
	@./forkin.out

clean:
	@rm *.o*
