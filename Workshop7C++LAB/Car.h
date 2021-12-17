#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include "Vehicle.h"

using namespace std;

namespace sdds
{

	const int MAX_CHAR = 20;
	const int MIN_YEAR = 2000;

	class Car : public Vehicle
	{
		char m_carType[MAX_CHAR + 1];
		int m_regYear;

	public:

		Car();
		Car(const char*, int, int, int);
		void finetune();
		ostream& display(ostream& os) const;
		istream& input(istream& in);
	};

	ostream& operator<<(ostream& os, const Car& C);
	istream& operator>>(istream& in, Car& C);
}



#endif

