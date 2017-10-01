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
		
		void affiche(void);
		bool estHorsJeux(void) { return _estHorsJeux; }
		unsigned int getCumulDesLances(void) const { return _cumulDesLances; }
		unsigned int getNbLances(void) const { return _nbLances; }
		std::string getPseudo(void) const { return _pseudo; }
		void setPseudo(std::string pseudo);
		//unsigned int cumulerDesPoints(unsigned int points) { return (_cumulDesLances += points); }
		void plusUnLance(unsigned int points) { _suiteDeLances[_nbLances] = points; _cumulDesLances += points; ++_nbLances; }
		void passeUnTour(void){_suiteDeLances[_nbLances] = 0; ++_nbLances;}
	private :
		std::string _pseudo;
		bool _estHorsJeux;
		int _suiteDeLances[7];
		unsigned int _nbLances;  // ... de lancés du dé
		unsigned int _cumulDesLances; 
	};
}

namespace re_7_partie
{
	class Partie
	{
	public :
		void initDefault(void);
		void PartieCopyData(const Partie & p);

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
			bool estTerminee = true;
			for (unsigned int i = 0; i < _nbJoueurs; ++i)
			{
				if (_Joueurs[i].getCumulDesLances() == 7)
				{
					estTerminee = true;
					break; // return true;
				}
				else {
					if (!_Joueurs[i].estHorsJeux()
						&& _Joueurs[i].getCumulDesLances() < 7
						&& _Joueurs[i].getNbLances() < 7
						)
					{
						estTerminee = false;
					}
				}
			}
			return estTerminee;
		}
	private :
		unsigned int _nbJoueurs;
		re_7_joueur::Joueur* _Joueurs;
		re_7_le_de::LeDe _leDe;

		bool _terminee;
	};
}
# endif // PARTIE_H
