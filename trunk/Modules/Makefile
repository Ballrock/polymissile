#Commande du compilateur
CPP=g++ 
#Linker
LDFLAGS=$(shell sdl-config --libs)
CFLAGS=$(shell sdl-config --cflags)
#Repertoire des Binaries
DIRBIN=bin
#Nom du programme
EXEC=PolyMissile

SRC=Utiles/Coordonnees.cpp Utiles/ObjetVolant.cpp Utiles/Missile.cpp Utiles/Vaisseau.cpp Utiles/Droite.cpp Gestion/Gestion.cpp main.cpp Interface/fenetre.cpp

OBJ=$(SRC:.c=.o)

all: ${EXEC}

%.o: %.c
	@${CPP} -o $@ -c $< ${CFLAGS}

PolyMissile: ${OBJ}
	@${CPP} -o ${DIRBIN}/${EXEC} $^ ${LDFLAGS} ${CFLAGS} -g

clean:	
	@rm -fr *.o

mrproper: clean
	@rm -fr ${DIRBIN}/${EXEC}

