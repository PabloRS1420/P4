# include this file in your main Makefile as
# include makefile_ext

p4_e3: p4_e3.o tree.o npoint.o
	gcc -o p4_e3 p4_e3.o tree.o npoint.o

p4_e3_bal: p4_e3
	gcc -o p4_e3_bal p4_e3.o tree.o npoint.o

p4_e3.o: p4_e3.c
	gcc -g -Wall -pedantic -ansi -c p4_e3.c
	
# Rules for tree, npoint, ... in main Makefile
