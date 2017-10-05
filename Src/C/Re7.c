// Re7.c

# include "Re7.h"
# include "Partie.h"

namespace re_7
{
	inline void MainRe7::Re7(void) 
	{
		unsigned int tmpNbJoueurs = -1 + getArgc();
		re_7_partie::Partie partie (tmpNbJoueurs, (tmpNbJoueurs == 0 ? nullptr : &getArgv()[1]));

		partie.derouler();
	}
}

int main(int argc, char** argv)
{
	re_7::MainRe7 m7(argc, argv);
	m7.Re7();
	return 0;
}
