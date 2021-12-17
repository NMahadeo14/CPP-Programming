#include <iostream>
#include <iomanip>
#include <cstring>
#include "Car.h"

using namespace std;

namespace sdds
{
	Car::Car()
	{
		m_carType[0] = '\0';
		m_regYear = 2000;
	}

	Car::Car(const char* type, int registrationYear, int speed, int seats) : Vehicle(speed,seats)
	{
		if ((type[0] != '\0') || (registrationYear <= 2000))
		{
		    strcpy(m_carType, type);
			m_regYear = registrationYear;
		}
		else
		{
			m_carType[0] = 0;
			m_regYear = 0;
		}
	}

	void Car::finetune()
	{
		if (this->m_regYear < MIN_YEAR)
		{
			cout << "Car cannot be tuned and has to be scraped\n";
		}

		if (this->m_regYear >= MIN_YEAR)
		{

			if (Vehicle::finetune())
			{
				cout << "This car is finely tuned to default speed" << endl;
			}
		}
	}

	ostream& Car::display(ostream& os) const
	{
		if ((m_carType[0] == '\0') || (m_regYear < 2000))
		{
			cout << "Car is not initiated yet" << endl;
		}
		else
		{
			os.width(20);
			os.setf(ios::left);
			os << this->m_carType;
			os << this->m_regYear;
			Vehicle::display(os);
			os << endl;
		}

		return os;

	}

	istream& Car::input(istream& in)
	{
		char tempchatType[MAX_CHAR + 1];
		int tempRegYear;

		cout << "Enter the car type: ";
		in >> tempchatType;

		cout << "Enter the car registration year: ";
		in >> tempRegYear;

		if (tempchatType != nullptr && tempRegYear >= 2000)
		{
			m_regYear = tempRegYear;
			strcpy(m_carType, tempchatType);
		}

		Vehicle::input(in);

		return in;
	}

	ostream& operator<<(ostream& os, const Car& C)
	{
		C.display(os);
		return os;
	}

	istream& operator>>(istream& in, Car& C)
	{
		C.input(in);
		return in;
	}
}