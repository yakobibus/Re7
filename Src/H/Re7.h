// Re7.h

# ifndef RE7_H
# define RE7_H   (1)

# include <iostream>

# include "MainBase.h"
# include "Partie.h"

namespace re_7
{
	class MainRe7 : public main_base::MainBase, public re_7_partie::Partie
	{
	public:
		MainRe7() : MainBase(0, nullptr), Partie() {}
		MainRe7(int argc, char** argv) : MainBase(argc, argv) {}
		~MainRe7() = default ;
		MainRe7(const MainRe7& m) = default;
		MainRe7& operator = (const MainRe7& m) = default ;

		virtual void affiche(void) {}
		inline void Re7(void);
	private:
		re_7_partie::Partie _partie;
	};
}

# endif  // RE7_H
