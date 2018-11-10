help:
	@echo "make help"
	@echo "make all:"

AVL_tree.o : AVL_tree.c
	g++ -c AVL_tree.c

main.o: main.c
	g++ -c main.c

all: AVL_tree.o main.o
	g++ -o avl_tree main.o AVL_tree.o

run: all
	./avl_tree

clean:
	rm *.o

cleanup: clean
	rm avl_tree