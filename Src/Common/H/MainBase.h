// MainBase.h

# ifndef MAIN_BASE
# define MAIN_BASE   (1)

# include <iostream>

namespace main_base
{
	class MainBase
	{
	public:
		MainBase() :_argc(0), _argv(nullptr) {}
		MainBase(int argc, char** argv);
		virtual ~MainBase();
		MainBase(const MainBase& m);
		MainBase& operator = (const MainBase& m);

		virtual void affiche(void) = 0;
		int getArgc(void);
		std::string getArgv(int rang);
		std::string* getArgv(void);
	protected:
	private:
		int _argc;
		std::string* _argv;
	};

	class Le7;
}
# endif // MAIN_BASE
