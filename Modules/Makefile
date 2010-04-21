#Commande du compilateur
CPP=g++ 
#Linker
LDFLAGS=$(shell sdl-config --libs)
CFLAGS=$(shell sdl-config --cflags) -DTIXML_USE_STL
#Repertoire des Binaries
DIRBIN=bin
#Nom du programme
EXEC=PolyMissile

SRC=Utiles/Coordonnees.cpp Utiles/ObjetVolant.cpp Utiles/Missile.cpp Utiles/Vaisseau.cpp Utiles/Droite.cpp Gestion/Gestion.cpp main.cpp Interface/fenetre.cpp Interface/Sol.cpp Interface/Silo.cpp ScoreClient/ScoreClient.cpp Utiles/GestionSockets.cpp TinyXml/tinystr.cpp TinyXml/tinyxmlerror.cpp TinyXml/tinyxmlparser.cpp TinyXml/tinyxml.cpp Constante.cpp

OBJ=$(SRC:.cpp=.o)

all: ${EXEC}

%.o: %.c
	@${CPP} -o $@ -c $< ${CFLAGS}

PolyMissile: ${OBJ}
	${CPP} -o ${DIRBIN}/${EXEC} $^ ${LDFLAGS} ${CFLAGS} -g

clean:	
	@find . -name "*.o" -exec rm -fr {} \;

mrproper: clean
	@rm -fr ${DIRBIN}/${EXEC}

