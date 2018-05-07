########################################################
CC=gcc
CFLAGS= -g -Wall -pedantic -ansi
EJS = p1_e1 p1_e2
########################################################
OBJECTSP1E1 = p1_e1.o point.o
OBJECTSP1E2 = p1_e2.o map.o point.o utils.o
########################################################

all: $(EJS) clear

p1_e1: $(OBJECTSP1E1)
	$(CC) $(CFLAGS) -o p1_e1 $(OBJECTSP1E1)

p1_e2: $(OBJECTSP1E2)
	$(CC) $(CFLAGS) -o p1_e2 $(OBJECTSP1E2)

p1_e1.o: p1_e1.c point.h
	$(CC) $(CFLAGS) -c p1_e1.c

p1_e2.o: p1_e2.c map.h
	$(CC) $(CFLAGS) -c p1_e2.c

point.o: point.c point.h
	$(CC) $(CFLAGS) -c point.c

map.o: map.c map.h
	$(CC) $(CFLAGS) -c map.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clear:
	rm -rf *.o 

clean:
	rm -rf *.o $(EJS)

run:
	@echo ">>>>>>Running p1_e1"
	./p1_e1
	@echo ">>>>>>Running p1_e2"
	./p1_e2 m1.txt

runv:
	@echo ">>>>>>Running p1_e1 with valgrind"
	valgrind --leak-check=full ./p1_e1
	@echo ">>>>>>Running p1_e2 with valgrind"
	valgrind --leak-check=full ./p1_e2 m1.txt
	