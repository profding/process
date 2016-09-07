CC = gcc

all: vfork_test1
.PHONY:all clean

vfork_test1: vfork_test1.c
	$(CC)  vfork_test1.c -o  vfork_test1



clean:
	rm  vfork_test1 
