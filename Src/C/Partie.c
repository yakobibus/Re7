// Partie.c

# include <iostream>
# include <string>

# include "Partie.h"

namespace re_7_partie
{
	inline void Partie::initDefault(void)
	{
		_nbJoueurs = 2;
		_nbJoueursHorsJeu = 0;
		_Joueurs = new re_7_joueur::Joueur[_nbJoueurs];
		_Joueurs[0].setPseudo("Joueur 1");
		_Joueurs[1].setPseudo("Joueur 2");
	}

	Partie::Partie(unsigned int nbJoueurs) 
		: _nbJoueurs(nbJoueurs)
		, _nbJoueursHorsJeu(0)
		, _terminee(false)
	{
		initDefault();
	}

	Partie::Partie(unsigned int nbJoueurs, std::string * listePseudos) 
		: _nbJoueurs(nbJoueurs)
		, _nbJoueursHorsJeu(0)
		, _terminee(false)
	{
		switch (_nbJoueurs)
		{
		case 0:
			initDefault();
			break;
		case 1:
			initDefault();
			_Joueurs[0].setPseudo(listePseudos[0]);
			break;
		default:
			_Joueurs = new re_7_joueur::Joueur[_nbJoueurs];
			for (unsigned int i = 0; i < _nbJoueurs; ++i)
			{
				_Joueurs[i].setPseudo(listePseudos[i]);
			}
			break;
		}
	}

	Partie::~Partie() { delete[] _Joueurs; }

	Partie::Partie(const Partie& p)
	{
		PartieCopyData(p);
	}

	Partie& Partie::operator = (const Partie& p) {
		PartieCopyData(p);
	
		return *this;
	}

	inline void Partie::PartieCopyData(const re_7_partie::Partie & p)
	{
		if (this != &p)
		{
			delete[] _Joueurs;
			_nbJoueurs = p._nbJoueurs;
			_nbJoueursHorsJeu = p._nbJoueursHorsJeu;
			_leDe = p._leDe;

			_Joueurs = new re_7_joueur::Joueur[_nbJoueurs];
			for (unsigned int i = 0; i < _nbJoueurs; ++i)
			{
				_Joueurs[i] = p._Joueurs[i];
			}

			_terminee = p._terminee;
		}
	}

	void Partie::affiche(void)
	{
		classement();

		for (unsigned int i = 0; i < _nbJoueurs; ++i)
		{
			_Joueurs[i].affiche();
		}
		std::cout << "Partie " << (_terminee == true ? "terminEe" : "en cours ...") << std::endl;
		std::cout << std::endl;
	}

	void Partie::classement(void) 
	{
		for (unsigned int i = 0; i < _nbJoueurs; ++i) // RAZ du classement existant
		{
			_Joueurs[i].setClassement(0);
		}

		for (unsigned int i = 0; i < _nbJoueurs; ++i)
		{
			{
				if (_Joueurs[i].estHorsJeu())
				{
					_Joueurs[i].setClassement(_nbJoueurs);
				}
				else
				{
					unsigned int dummyClassement = 1 + i;
					for (unsigned int ii = 0 ; ii < i ; ++ii)
					{
						int comparaison = _Joueurs[i].compare(_Joueurs[ii]);
						if (comparaison == 0)
						{
							_Joueurs[i].setClassement(_Joueurs[ii].getClassement());
						}
						else
						{
							if (comparaison > 0)
							{
								_Joueurs[ii].incrementeClassement(_nbJoueurs);
								--dummyClassement;
							}
							else
							{
								// Il est mieux classé, rien à faire
							}
						}
					}
					if (0 == _Joueurs[i].getClassement())
					{
						_Joueurs[i].setClassement(dummyClassement);
					}
				}
			}
		}
	}

	void Partie::derouler(void) 
	{
		while (_terminee == false)
		{
			std::cout << "=======================" << std::endl;
			std::cout << "P : passe son tour" << std::endl;
			std::cout << "L : lance le dE" << std::endl;
			std::cout << "A/Q : Abandonne/Quitte la partie" << std::endl;
			std::cout << std::endl;
			for (unsigned int i = 0; ! _terminee && ! partieTerminee() && i < _nbJoueurs; ++i)
			{
				if (_Joueurs[i].getCumulDesLances() < 7) 
				{
					std::string reponse;
					std::cout << "La main est A " << _Joueurs[i].getPseudo().c_str() << " Re7 > " ;
					getline(std::cin, reponse);
					if (reponse == "P" || reponse == "p")
					{
						std::cout << _Joueurs[i].getPseudo().c_str() << " passe son tour" << std::endl;
						_Joueurs[i].passeUnTour();
					}
					else
					{
						if(reponse == "A" || reponse == "a" || reponse == "Q" || reponse == "q") 
						{
							std::cout << "Abandon de la partie en cours ..." << std::endl;
							_terminee = true;
							break;
						}
						else
						{
							if (reponse == "L" || reponse == "l")
							{
								_Joueurs[i].plusUnLance(static_cast <unsigned int> (_leDe.Lancer())); 
							}
						}
					}
				}
			}

			std::cout << "  --Redultats--" << std::endl;
			affiche();
		}
	}

	bool Partie::partieTerminee(void)
	{
		for (unsigned int i = 0; _terminee == false && i < _nbJoueurs; ++i)
		{
			if (_Joueurs[i].getCumulDesLances() == 7)
			{
				_terminee = true;
				break;
			}
			else {
				// Tous les joueurs (ou tous sauf un seul) sont hors jeu
				if(calculeHorsJeu() >= -1 + _nbJoueurs)
				{ 
					_terminee = true;
				}
				if (!_Joueurs[i].estHorsJeu()
					&& _Joueurs[i].getCumulDesLances() < 7
					&& _Joueurs[i].getNbLances() < 7
					)
				{
					continue ;
				}
			}
		}

		return _terminee;
	}

	unsigned int Partie::calculeHorsJeu(void)
	{
		unsigned int dummy = 0;
		for (unsigned int i = 0; i < _nbJoueurs; ++i)
		{
			if (_Joueurs[i].estHorsJeu())
			{
				++dummy;
			}
		}
		_nbJoueursHorsJeu = dummy;

		return _nbJoueursHorsJeu;
	}
}

namespace re_7_joueur
{
	Joueur::Joueur() 
		: _pseudo("")
		, _estHorsJeu(false)
		, _nbLances(0)
		, _cumulDesLances(0)
		, _classement (0)
	{
		for (int i = 0; i < 7; ++i)
		{
			_suiteDeLances[i] = -1;
		}
	}

	inline void Joueur::setPseudo(std::string pseudo) 
	{ 
		_pseudo = pseudo; 
	}

	void Joueur::plusUnLance(unsigned int points)
	{ 
		_suiteDeLances[_nbLances] = points; 
		_cumulDesLances += points; 
		++_nbLances; 
		if (_nbLances >= 7 || _cumulDesLances > 7) 
		{ 
			_estHorsJeu = true; 
		} 
	}

	void Joueur::passeUnTour(void) 
	{ 
		_suiteDeLances[_nbLances] = 0;
		++_nbLances; 
		if (_nbLances >= 7) 
		{ 
			_estHorsJeu = true; 
		} 
	}

	void re_7_joueur::Joueur::affiche(void)
	{
		std::cout << "  Classement : " << (_estHorsJeu ? "Hors-jeu" : std::to_string(_classement) ) << (_estHorsJeu ? "" : (_classement == 1 ? "er" : (_classement == 0 ? "" : "e"))) << std::endl;
		std::cout << "      Pseudo : " << _pseudo.c_str() << (_classement == 1 ? " (*)" : "") << std::endl;
		std::cout << "      LancEs : " << _nbLances << std::endl;
		std::cout << "      Points : " << _cumulDesLances << std::endl;
		std::cout << "  < " ;

		for (unsigned int i = 0 ; i < _nbLances ; ++i)
		{
			std::cout << "[" << (_suiteDeLances[i] < 0 ? "-" : (_suiteDeLances[i] == 0 ? "P" : std::to_string( _suiteDeLances[i] ) ) ) << "] ";
		}
		std::cout << ">" << std::endl;
		std::cout << std::endl;
	}

	int Joueur::compare(const Joueur & j) const 
	{ 
		return (_estHorsJeu ? 0 : _cumulDesLances) - (j._estHorsJeu ? 0 : j._cumulDesLances); 
	}

	int Joueur::getDernierLance(void) 
	{ 
		return (_nbLances > 0 ? _suiteDeLances[-1 + _nbLances ] : -1); 
	}
}
