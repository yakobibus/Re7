// MainBase.c

# include <iostream>
# include <cassert>

# include "MainBase.h"

namespace main_base
{
MainBase::MainBase(int argc, char** argv)
	: _argc(argc)
	, _argv(nullptr)
{
	if (_argc > 0)
	{
		_argv = new std::string[_argc];
		for (int i = 0; i < _argc; ++i)
		{
			_argv[i] = argv[i];
		}
	}
}


MainBase::~MainBase() {
	if (_argc > 0)
	{
		delete[] _argv;
		_argv = nullptr;
	}
}


MainBase::MainBase(const MainBase& m) {
	if (this != &m)
	{
		if (_argc > 0)
		{
			delete[] _argv;
			_argv = nullptr;
		}

		_argc = m._argc;

		if (_argc > 0)
		{
			_argv = new std::string[_argc];
			for (int i = 0; i < _argc; ++i)
			{
				_argv[i] = m._argv[i];
				std::cout << "(" << i << ") <" << _argv[i].c_str() << ">" << std::endl;
			}
		}
	}
}


MainBase& MainBase::operator = (const MainBase& m) {
	if (this != &m)
	{
		if (_argc > 0)
		{
			delete[] _argv;
			_argv = nullptr;
		}

		_argc = m._argc;

		if (_argc > 0)
		{
			_argv = new std::string[_argc];
			for (int i = 0; i < _argc; ++i)
			{
				_argv[i] = m._argv[i];
				std::cout << "(" << i << ") <" << _argv[i].c_str() << ">" << std::endl;
			}
		}
	}

	return *this;
}


int MainBase::getArgc(void) { return _argc; }

std::string * MainBase::getArgv(void) { return _argv; }

std::string MainBase::getArgv(int rang) { assert(rang >= 0 && rang < _argc); return _argv[rang]; }
}
