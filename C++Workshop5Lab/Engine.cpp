#include <iostream>
#include <cstring>
#include "Engine.h"

using namespace std;
namespace sdds
{
	Engine::Engine()
	{
		m_Enginesize = 0.0;
		m_type[0] = '\0';
	}

	Engine::Engine(const char* type, double EngineSize)
	{
		if (EngineSize < 0)
		{
			m_Enginesize = 0.0;
			m_type[0] = '\0';
		}
		else
		{
			strcpy(m_type, type);
			m_Enginesize = EngineSize;
		}

	}

	double Engine::get() const
	{
		return this->m_Enginesize;
	}

	void Engine::display() const
	{
		cout << this->m_Enginesize << " liters - " << this->m_type << endl;
	}

}