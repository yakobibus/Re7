// Re7.c

# include "Re7.h"
# include "Partie.h"

namespace re_7
{
	inline void MainRe7::Re7(void) 
	{
		re_7_partie::Partie partie (getArgc(), getArgv());

		// .ici. todo : partie._Joueurs[0].lanceDe();
		// .ici. todo : partie._Joueurs[1].lanceDe();
		
		// .ici. todo : partie.classement();

		partie.affiche();
	}
}

int main(int argc, char** argv)
{
	re_7::MainRe7 m7(argc, argv);
	m7.Re7();
	return 0;
}
