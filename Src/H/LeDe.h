//LeDe.h

# ifndef LE_DE_H
# define LE_DE_H   (1)

# include "UI_distribution_randomizer.h"

namespace re_7_le_de
{
	class LeDe : public ui_dist_rand::UI_Distributed_Rand
	{
	public :
		LeDe() : UI_Distributed_Rand(1, 6) {}
		~LeDe() = default;
		LeDe(const LeDe& d) = default;
		LeDe& operator = (const LeDe& d) = default;

		int Lancer(void);
	private :
	};
}

# endif // vLE_DE_H
