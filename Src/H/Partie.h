// Partie.h

# ifndef PARTIE_H
# define PARTIE_H  (1)

# include <iostream>

namespace re_7_joueur
{
	class Joueur
	{
	public :
	private :
	};
}

namespace re_7_partie
{
	class Partie
	{
	public :
		Partie(int nbJoueurs = 2) : _nbJoueurs(nbJoueurs) {}
		~Partie() = default;
		Partie(const Partie& p) = default;
		Partie& operator = (const Partie& p) = default;

		inline void classement(void) { std::cout << " ... Todo : re_7_partie::Partie.classement () ..." << std::endl; }
	private :
		unsigned int _nbJoueurs;
		re_7_joueur::Joueur* _Joueurs;
	};
}
# endif // PARTIE_H
