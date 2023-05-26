CFLAGS = -O3 --std=c99 -Wall -lm

all: main.o src/hachage.o src/markov.o src/repertoire.o src/sauvegarde.o
	gcc main.o src/hachage.o src/markov.o src/repertoire.o src/sauvegarde.o -o projet $(CFLAGS) 

test_hachage: tests/test_hachage.o src/hachage.o
	gcc tests/test_hachage.o src/hachage.o -o tests/test_hachage $(CFLAGS)
	./tests/test_hachage
	rm tests/test_hachage

test_markov: tests/test_markov.o src/markov.o
	gcc tests/test_markov.o src/markov.o -o tests/test_markov $(CFLAGS)
	./tests/test_markov
	rm tests/test_markov

test_repertoire: tests/test_repertoire.o src/repertoire.o
	gcc tests/test_repertoire.o src/repertoire.o -o tests/test_repertoire $(CFLAGS)
	./tests/test_repertoire
	rm tests/test_repertoire

test_sauvegarde: tests/test_sauvegarde.o src/sauvegarde.o
	gcc tests/test_sauvegarde.o src/sauvegarde.o -o tests/test_sauvegarde $(CFLAGS)
	./tests/test_sauvegarde
	rm tests/test_sauvegarde

test: test_hachage test_markov test_repertoire test_sauvegarde
	rm tests/*.o

clean:
	rm -f *.o *~ 
	rm -f src/*.o src/*~  
	rm -f tests/*.o test/*~ 

