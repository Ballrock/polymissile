class Fenetre
{
	public:
	static Fenetre & GetInstance(); //On recupere l'instance unique de de la classe fenetre
	void sdlinit();
	
	
	private:
	Fenetre();
	static Fenetre* window;
}

	
