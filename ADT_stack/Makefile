chart.o : chart.c
	g++ -c chart.c

ADT_stack.o : ADT_stack.c
	g++ -c ADT_stack.c

main.o: main.c
	g++ -c main.c

all: ADT_stack.o  chart.o main.o
	g++ -o stack main.o ADT_stack.o  chart.o

run: all
	./stack > chart.html

clean:
		rm -rf *.o stack