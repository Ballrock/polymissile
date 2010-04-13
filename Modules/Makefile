#Commande du compilateur
CPP=g++ 
#Linker
LDFLAGS=$(shell sdl-config --libs)
CFLAGS=$(shell sdl-config --cflags)
#Repertoire des Binaries
DIRBIN=bin
#Nom du programme
OUT=PolyMissileInterface


all: ${EXEC}

${EXEC}: 
	${CPP} ./main.cpp -o ${DIRBIN}/${OUT} ${LDFLAGS} 

clean:	
	rm -fr *.o

mrproper: clean
	rm -fr ${DIRBIN}/${EXEC}

