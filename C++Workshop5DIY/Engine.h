#ifndef SDDS_ENGINE_H
#define SDDS_ENGINE_H

namespace sdds
{
	class Engine
	{
		double m_Enginesize;
		char m_type[30];

	public:

		Engine();
		Engine(const char*, double);
		double get() const;
		void display() const;
	};
}



#endif
