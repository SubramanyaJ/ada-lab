all:
	clang main.c graph.c -o main.out -Wall -O3 -fsanitize=address
	cat graph.txt | ./main.out
