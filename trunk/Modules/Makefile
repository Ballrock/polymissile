#Commande du compilateur
CPP=g++ 
#Linker
LDFLAGS=$(shell sdl-config --libs)
CFLAGS=$(shell sdl-config --cflags) -DTIXML_USE_STL
#Repertoire des Binaries
DIRBIN=bin
#Nom du programme
EXEC=PolyMissile

SRC=Utiles/Coordonnees.cpp Utiles/ObjetVolant.cpp Utiles/Missile.cpp Utiles/Vaisseau.cpp Utiles/Droite.cpp Gestion/Gestion.cpp main.cpp Interface/fenetre.cpp Interface/Sol.cpp Interface/Silo.cpp ScoreClient/ScoreClient.cpp Utiles/GestionSockets.cpp TinyXml/tinystr.cpp TinyXml/tinyxmlerror.cpp TinyXml/tinyxmlparser.cpp TinyXml/tinyxml.cpp Constante.cpp ScoreClient/main.cpp

OBJ=$(SRC:.cpp=.o)

all: ${EXEC}

ScoreClient: ScoreClient/main.o ScoreClient/ScoreClient.o Constante.o ${TinyXml} ${Utiles}
	${CPP} -o bin/testScoreClient $^ ${CFLAGS} -g 

TinyXml=TinyXml/tinyxml.o TinyXml/tinyxmlerror.o TinyXml/tinyxmlparser.o TinyXml/tinystr.o

Utiles=Utiles/Coordonnees.o Utiles/ObjetVolant.o Utiles/Missile.o Utiles/Vaisseau.o Utiles/Droite.o Utiles/GestionSockets.o 

Gestion: Gestion/main.o Gestion/Gestion.o Constante.o ${Utiles} ${Interface}
	${CPP} -o bin/testGestion $^ ${CFLAGS} ${LDFLAGS} -g

Interface=Interface/Silo.o Interface/Sol.o Interface/fenetre.o 

%.o: %.cpp
	@${CPP} -o $@ -c $< ${CFLAGS}

PolyMissile: ${OBJ}
	${CPP} -o ${DIRBIN}/${EXEC} $^ ${LDFLAGS} ${CFLAGS} -g

clean:	
	@find . -name "*.o" -exec rm -fr {} \;

mrproper: clean
	@rm -fr ${DIRBIN}/${EXEC}

