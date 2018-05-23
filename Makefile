########################################################
CC=gcc
CFLAGS= -g -Wall -pedantic -ansi
EJS = p4_e1 p4_e2 p4_e3 p4_e3_bal p4_e4
########################################################
OBJECTSP4E1 = p4_e1.o deep_searchRec.o
OBJECTSP4E2 = p4_e2.o tree.o
OBJECTSP4E4 = p4_e4.o tree.o npoint.o
########################################################

include makefile_ext

all: $(EJS) clear

p4_e1: $(OBJECTSP1E1)
	$(CC) $(CFLAGS) -o p4_e1 $(OBJECTSP1E1)

p4_e2: $(OBJECTSP1E2)
	$(CC) $(CFLAGS) -o p4_e2 $(OBJECTSP1E2)
	
p4_e4: $(OBJECTSP4E4)
	$(CC) $(CFLAGS) -o p4_e4 $(OBJECTSP1E4)

p4_e1.o: p4_e1.c deep_searchRec.h
	$(CC) $(CFLAGS) -c p4_e1.c
	
p4_e2.o: p4_e2.c tree.h types.h
	$(CC) $(CFLAGS) -c p4_e2.c

p4_e4.o: p4_e4.c tree.h npoint.h types.h
	$(CC) $(CFLAGS) -c p4_e4.c

npoint.o: npoint.c npoint.h functions.h
	$(CC) $(CFLAGS) -c npoint.c

tree.o: tree.c tree.h functions.h
	$(CC) $(CFLAGS) -c tree.c

deep_searchRec.o: deep_searchRec.c deep_searchRec.h
	$(CC) $(CFLAGS) -c deep_searchRec.c

functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

map.o: map.c map.h
	$(CC) $(CFLAGS) -c map.c
	
map_solver.o: map_solver.c map_solver.h
	$(CC) $(CFLAGS) -c map_solver.c
	
point.o: point.c point.h
	$(CC) $(CFLAGS) -c point.c

clear:
	rm -rf *.o 

clean:
	rm -rf *.o $(EJS)

run:
	@echo ">>>>>>Running p4_e1"
	./p4_e1 m1.txt
	@echo ">>>>>>Running p4_e2"
	./p4_e2 numeros.txt 
	@echo ">>>>>>Running p4_e3_bal"
	./p4_e3 locations.txt
	@echo ">>>>>>Running p4_e3_bal"
	./p4_e3_bal locations.txt  
	@echo ">>>>>>Running p4_e4"
	./p4_e4 numeros.txt 

runv:
	@echo ">>>>>>Running p4_e1 with valgrind"
	valgrind --leak-check=full ./p4_e1 m1.txt
	@echo ">>>>>>Running p4_e2 with valgrind"
	valgrind --leak-check=full ./p4_e2 numeros.txt
	@echo ">>>>>>Running p4_e3 with valgrind"
	valgrind --leak-check=full ./p4_e3 locations.txt
	@echo ">>>>>>Running p4_e3_bal with valgrind"
	valgrind --leak-check=full ./p4_e3_bal locations.txt
	@echo ">>>>>>Running p4_e4 with valgrind"
	valgrind --leak-check=full ./p4_e4
	
