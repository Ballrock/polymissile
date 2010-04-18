#ifndef _DEF_FENETRE
#define _DEF_FENETRE

class Fenetre
{
	public:
	Fenetre();
	~Fenetre();
	Fenetre & getInstance(); //On recupere l'instance unique de de la classe fenetre
	void sdlInit();
	void newWindows(int, int, int);	
	
	private:
	Fenetre* window;
};


#endif

	
