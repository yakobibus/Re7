// Partie.c

# include "Partie.h"

namespace re_7_partie
{
	inline void Partie::initDefault(void)
	{
		_nbJoueurs = 2;
		_Joueurs = new re_7_joueur::Joueur[_nbJoueurs];
		_Joueurs[0].setPseudo("Joueur 1");
		_Joueurs[1].setPseudo("Joueur 2");
	}

	Partie::Partie(unsigned int nbJoueurs) 
		: _nbJoueurs(nbJoueurs)
		, _terminee(false)
	{
		initDefault();
	}

	Partie::Partie(unsigned int nbJoueurs, std::string * listePseudos) 
		: _nbJoueurs(nbJoueurs)
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
		for (unsigned int i = 0; i < _nbJoueurs; ++i)
		{
			_Joueurs[i].affiche();
		}
		std::cout << "Partie " << (_terminee == true ? "terminEe" : "en cours ...") << std::endl;
	}

	void Partie::derouler(void) 
	{
		while (_terminee == true)
		{
			for (unsigned int i = 0; i < _nbJoueurs; ++i)
			{

			}
			// ...ici... : todo
		}
	}
}

namespace re_7_joueur
{
	Joueur::Joueur() 
		: _pseudo("")
		, _estHorsJeux(false)
		, _nbLances(0)
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

	void re_7_joueur::Joueur::affiche(void)
	{
		std::cout << "Pseudo : " << _pseudo.c_str() << std::endl;
	}
}
