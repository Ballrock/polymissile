#Commande du compilateur
CPP=g++ 
#Linker
LDFLAGS=$(shell sdl-config --libs)
CFLAGS=$(shell sdl-config --cflags) -DTIXML_USE_STL
#Repertoire des Binaries
DIRBIN=bin
#Nom du programme
EXEC=PolyMissile

SRC=Utiles/Coordonnees.cpp Utiles/ObjetVolant.cpp Utiles/Missile.cpp Utiles/Vaisseau.cpp Utiles/Droite.cpp Gestion/Gestion.cpp main.cpp Interface/fenetre.cpp Interface/Sol.cpp Interface/Silo.cpp ScoreClient/ScoreClient.cpp TinyXml/tinystr.cpp TinyXml/tinyxmlerror.cpp TinyXml/tinyxmlparser.cpp TinyXml/tinyxml.cpp Constante.cpp ScoreClient/main.cpp ScoreServeur/main.cpp ScoreServeur/ScoreServeur.cpp

OBJ=$(SRC:.cpp=.o)

TinyXml=TinyXml/tinyxml.o TinyXml/tinyxmlerror.o TinyXml/tinyxmlparser.o TinyXml/tinystr.o

Utiles=Utiles/Coordonnees.o Utiles/ObjetVolant.o Utiles/Missile.o Utiles/Vaisseau.o Utiles/Droite.o

Interface=Interface/Silo.o Interface/Sol.o Interface/fenetre.o 

#all: ${EXEC}
all: ScoreClient ScoreServeur Gestion

ScoreClient: ScoreClient/main.o ScoreClient/ScoreClient.o Constante.o ${TinyXml}
	${CPP} -o bin/testScoreClient $^ ${CFLAGS} -g 

ScoreServeur: ScoreServeur/main.o ScoreServeur/ScoreServeur.o Constante.o ${TinyXml}
	${CPP} -o bin/testScoreServeur $^ ${CFLAGS} -g



Gestion: Gestion/main.o Gestion/Gestion.o Constante.o ${Utiles} ${Interface}
	${CPP} -o bin/testGestion $^ ${CFLAGS} ${LDFLAGS} -g


%.o: %.cpp
	@${CPP} -o $@ -c $< ${CFLAGS}

PolyMissile: ${OBJ}
	${CPP} -o ${DIRBIN}/${EXEC} $^ ${LDFLAGS} ${CFLAGS} -g

clean:	
	@find . -name "*.o" -exec rm -fr {} \;

mrproper: clean
	@rm -fr ${DIRBIN}/${EXEC}

