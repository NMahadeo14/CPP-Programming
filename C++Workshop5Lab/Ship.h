#ifndef SDDS_SHIP_H
#define SDDS_SHIP_H
#include "Engine.h"


namespace sdds
{
	class Ship
	{
		Engine m_arrayofEngines[10];
		char m_shipType[7];
		int m_numOfEngines;
		float m_distance;

	public:

		Ship();
		Ship(const char*, Engine[], int);

		bool empty() const;
		float calculatePower() const;
		void display() const;

		Ship& operator+=(const Engine& e);
		friend bool operator==(const Ship&, const Ship&);
	};

	bool operator<(const Ship&, double);



}

#endif // !SDDS_SHIP_H
