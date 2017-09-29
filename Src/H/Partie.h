// Partie.h

# ifndef PARTIE_H
# define PARTIE_H  (1)

# include <iostream>

namespace re_7_joueur
{
	class Joueur
	{
	public :
		Joueur();
		~Joueur() = default;
		Joueur(const Joueur& j) = default;
		Joueur& operator = (const Joueur& j) = default;
		
		void setPseudo(std::string pseudo);
		void affiche(void);
	private :
		std::string _pseudo;
		bool _estHorsJeux;
		int _suiteDeLances[7];
	};
}

namespace re_7_partie
{
	class Partie
	{
	public :
		void initDefault(void);

		Partie(unsigned int nbJoueurs = 2);

		Partie(unsigned int nbJoueurs, std::string* listePseudos);
		~Partie();
		Partie(const Partie& p);
		Partie& operator = (const Partie& p);

		void PartieCopyData(const re_7_partie::Partie & p);

		void classement(void) { std::cout << " ... Todo : re_7_partie::Partie.classement () ..." << std::endl; }
		void affiche(void)
		{
			for (unsigned int i = 0; i < _nbJoueurs; ++i)
			{
				_Joueurs [i].affiche();
			}
		}
	private :
		unsigned int _nbJoueurs;
		re_7_joueur::Joueur* _Joueurs;
	};
}
# endif // PARTIE_H
