CFLAGS= -Wall -O3 -fsanitize=address
all:
	@clang $(CFLAGS) main.c -o main.out
	@cat data.txt | ./main.out
