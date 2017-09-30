// Partie.h

# ifndef PARTIE_H
# define PARTIE_H  (1)

# include <iostream>
# include "LeDe.h"

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
		unsigned int _nbLances;  // ... de lancés du dé
		unsigned int _cumulDesLances; // .. ici .. : ajouter au constructeur
	};
}

namespace re_7_partie
{
	class Partie
	{
	public :
		void initDefault(void);
		void PartieCopyData(const re_7_partie::Partie & p);

		Partie(unsigned int nbJoueurs = 2);

		Partie(unsigned int nbJoueurs, std::string* listePseudos);
		~Partie();
		Partie(const Partie& p);
		Partie& operator = (const Partie& p);

		void affiche(void);
		void classement(void) { std::cout << " ... Todo : re_7_partie::Partie.classement () ..." << std::endl; }
		void derouler(void);
		bool partieTerminee(void)
		{
			for (unsigned int i = 0; i < _nbJoueurs; ++i)
			{
				if (!_Joueurs[i].estHorsJeux() && _Joueurs[i].getCumulDesLances() < 7 && _Joueurs[i].getNbLances() < 7) { return false; }
			}
			return true;
		}
	private :
		unsigned int _nbJoueurs;
		re_7_joueur::Joueur* _Joueurs;
		re_7_le_de::LeDe _leDe;

		bool _terminee;
	};
}
# endif // PARTIE_H
