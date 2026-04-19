comedie : main.o chargement.o consultation.o
	cc -o comedie main.o chargement.o consultation.o

main.o : main.c donnees.h
	cc -c main.c

chargement.o : chargement.c donnees.h
	cc -c chargement.c

consultation.o : consultation.c donnees.h
	cc -c consultation.c

clean :
	rm -f *.o comedie
