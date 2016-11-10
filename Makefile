# Makefile pour INF3105 / TP1

#OPTIONS = -Wall           # option standard
#OPTIONS = -g -O0 -Wall    # pour rouler dans gdb
OPTIONS = -O2 -Wall    # pour optimiser

all : tp1

tp1 : tp1.cpp personne.h personne.o coordonnee.h coordonnee.o ecole.h ecole.o
	g++ ${OPTIONS} -o tp1 tp1.cpp coordonnee.o personne.o ecole.o
	
personne.o : personne.cpp personne.h
	g++ ${OPTIONS} -c -o personne.o personne.cpp

coordonnee.o : coordonnee.cpp coordonnee.h
	g++ ${OPTIONS} -c -o coordonnee.o coordonnee.cpp

ecole.o : ecole.cpp ecole.h
	g++ ${OPTIONS} -c -o ecole.o ecole.cpp

clean:
	rm -rf tp1 *~ *.o

