#Commande du compilateur
CPP=g++ 
#Linker
LDFLAGS=-lSDL 
#Repertoire des Binaries
DIRBIN=bin
#Nom du programme
EXEC=PolyMissileInterface


all: ${EXEC}

${EXEC}: 
	${CPP} ./main.cpp -o ${DIRBIN}/${EXEC} ${LDFLAGS}

clean:	
	rm -fr *.o

mrproper: clean
	rm -fr ${DIRBIN}/${EXEC}

