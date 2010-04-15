#Commande du compilateur
CPP=g++ 
#Linker
LDFLAGS=$(shell sdl-config --libs)
CFLAGS=$(shell sdl-config --cflags)
#Repertoire des Binaries
DIRBIN=bin
#Nom du programme
EXEC=PolyMissile

SRC=Utiles/coordonnees.cpp Interface/main.cpp Utiles/ObjetVolant.cpp Utiles/Missile.cpp Utiles/Vaisseau.cpp Utiles/Droite.cpp gestion/gestion.cpp
OBJ=$(SRC:.c=.o)

all: ${EXEC}

%.o: %.c
	@${CPP} -o $@ -c $< ${CFLAGS}

PolyMissile: ${OBJ}
	@${CPP} -o ${DIRBIN}/${EXEC} $^ ${LDFLAGS} ${CFLAGS}

clean:	
	@rm -fr *.o

mrproper: clean
	@rm -fr ${DIRBIN}/${EXEC}

