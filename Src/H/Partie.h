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
		bool operator < (const Joueur& j) { return (_estHorsJeu ? 0 : _cumulDesLances) < (j._estHorsJeu ? 0 : j._cumulDesLances); }
		bool operator > (const Joueur& j) { return (_estHorsJeu ? 0 : _cumulDesLances) > (j._estHorsJeu ? 0 : j._cumulDesLances); }
		bool operator == (const Joueur& j) { return (_estHorsJeu ? 0 : _cumulDesLances) == (j._estHorsJeu ? 0 : j._cumulDesLances); }
		
		void affiche(void);
		int compare(const Joueur& j) const;
		bool estHorsJeu(void) { return _estHorsJeu; }
		unsigned int incrementeClassement(unsigned int borneMax) { return (borneMax > _classement ? ++_classement : _classement); }
		unsigned int getClassement(void) const { return _classement; }
		unsigned int getCumulDesLances(void) const { return _cumulDesLances; }
		int getDernierLance(void);
		unsigned int getNbLances(void) const { return _nbLances; }
		std::string getPseudo(void) const { return _pseudo; }
		void setClassement(const unsigned int& classement) { _classement = classement; }
		void setPseudo(std::string pseudo);
		void plusUnLance(unsigned int points);
		void passeUnTour(void);
	private :
		std::string _pseudo;
		bool _estHorsJeu;
		int _suiteDeLances[7];
		unsigned int _nbLances;  // ... de lanc�s du d�
		unsigned int _cumulDesLances;
		unsigned int _classement;
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
		unsigned int calculeHorsJeu(void);
		void classement(void);
		void derouler(void);
		bool partieTerminee(void);
	private :
		unsigned int _nbJoueurs;
		unsigned int _nbJoueursHorsJeu;
		re_7_joueur::Joueur* _Joueurs;
		re_7_le_de::LeDe _leDe;

		bool _terminee;
	};
}
# endif // PARTIE_H
