// Partie.h

# ifndef PARTIE_H
# define PARTIE_H  (1)

# include <iostream>

namespace re_7_joueur
{
	class Joueur
	{
	public :
		Joueur() : _pseudo(""), _estHorsJeux(false) 
		{
			for (int i = 0; i < 7; ++i) 
			{ 
				_suiteDeLances[i] = -1; 
			}
		}
		~Joueur() = default;
		Joueur(const Joueur& j) = default;
		Joueur& operator = (const Joueur& j) = default;
		
		void setPseudo(std::string pseudo) { _pseudo = pseudo; }
		void affiche(void) 
		{ 
			std::cout << "Pseudo : " << _pseudo.c_str() << std::endl; 
		}
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
		Partie(int nbJoueurs = 2) : _nbJoueurs(nbJoueurs) { _Joueurs = new re_7_joueur::Joueur[_nbJoueurs]; _Joueurs[0].setPseudo("Joueur 1"); _Joueurs[1].setPseudo("Joueur 2"); }
		Partie(int nbJoueurs, std::string* listePseudos) : _nbJoueurs(nbJoueurs) 
		{
			_Joueurs = new re_7_joueur::Joueur[_nbJoueurs];
			for (unsigned int i = 0; i < _nbJoueurs; ++i) 
			{ 
				_Joueurs[i].setPseudo(listePseudos[i]); 
			}
		}
		~Partie() { delete[] _Joueurs; }
		Partie(const Partie& p) = default;
		Partie& operator = (const Partie& p) = default;

		inline void classement(void) { std::cout << " ... Todo : re_7_partie::Partie.classement () ..." << std::endl; }
		inline void affiche(void)
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
