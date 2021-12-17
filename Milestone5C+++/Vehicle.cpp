#include <iostream>
#include <cstring>
#include <cctype>
#include "Vehicle.h"
#include "ReadWritable.h"

using namespace std;

namespace sdds
{
	Vehicle::Vehicle()
	{
		m_licensePlate = nullptr;
		m_makeModel = nullptr;
		m_parkingNumber = 0;
	}

	Vehicle::Vehicle(const char* plate, const char* makeModel)
	{
		if ((plate != nullptr && strlen(plate) < 8 && strlen(plate) > 1) && (makeModel != nullptr) && (strlen(makeModel) > 2))
		{
			m_licensePlate = new char[strlen(plate) + 1];
			strcpy(m_licensePlate, plate);
			m_makeModel = new char[strlen(makeModel) + 1];
			strcpy(m_makeModel, makeModel);
			m_parkingNumber = 0;
		}
		else
		{
			setEmpty();
		}

	}

	Vehicle::~Vehicle()
	{
		delete[] m_makeModel;
		m_makeModel = nullptr;
	}

	void Vehicle::setEmpty()
	{
		m_licensePlate = nullptr;
		m_makeModel = nullptr;
		m_parkingNumber = 0;
	}

	bool Vehicle::isEmpty() const
	{
		if (m_makeModel == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	istream& Vehicle::getLicensePlate(istream& plate) const
	{
		return plate;
	}

	istream& Vehicle::getMakeModel(istream& makeModel) const
	{
		return makeModel;
	}

	void Vehicle::setMakeModel(const char* newMakeModel)
	{
		if (newMakeModel != nullptr)
		{
			m_makeModel = nullptr;
			m_makeModel = new char[strlen(newMakeModel) + 1];
			strcpy(m_makeModel, newMakeModel);
		}
		else
		{
			setEmpty();
		}
	}

	int Vehicle::getParkingSpot() const
	{
		return this->m_parkingNumber;
	}

	void Vehicle::setParkingSpot(int newParkingSpot)
	{
		if (newParkingSpot >= 0)
		{
			m_parkingNumber = -1;
			m_parkingNumber = newParkingSpot;
		}
		else
		{
			setEmpty();
		}
	}

	bool operator==(const Vehicle& lhs, const char* plate)
	{
		if (strcmp(lhs.m_licensePlate, plate))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator==(const Vehicle& lhs, const Vehicle& rhs)
	{
		if (strcmp(lhs.m_licensePlate, rhs.m_licensePlate))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	istream& Vehicle::read(istream& istr)
	{
		if (this->isCsv() == true)
		{
			istr >> m_parkingNumber;
			istr.ignore(1, ',');
			istr.get(m_licensePlate, 10, ',');

			for (unsigned int i = 0; i < strlen(m_licensePlate) ; i++)
			{
				m_licensePlate[i] = toupper(m_licensePlate[i]);
			}

			istr.ignore(1, ',');
			istr.getline(m_makeModel, 60 , ',');
			setMakeModel(m_makeModel);


		}
		else
		{
			cout << "Enter Licence Plate Number: ";
			m_licensePlate = new char[60];
			istr >> m_licensePlate;

			if (strlen(m_licensePlate) > 8)
			{
				istr.clear();
				istr.ignore(100, '\n');
				cout << "Invalid Licence Plate, try again: ";
				istr.getline(m_licensePlate, 10);
			}


			cout << "Enter Make and Model: ";
			m_makeModel = new char[60];
			istr.clear();
			istr.ignore(100, '\n');
			istr.getline(m_makeModel, 60, '\n');


			if (strlen(m_makeModel) < 2 || strlen(m_makeModel) > 60)
			{
				istr.clear();
				istr.ignore(100, '\n');
				cout << "Invalid Make and model, try again: ";
				istr >> m_makeModel;
			};

			if (istr.fail())
			{
				setEmpty();
			}


		}

		return istr;
	}

	ostream& Vehicle::write(std::ostream& ostr) const
	{
		if (isEmpty())
		{
			ostr << "Invalid Vehicle Object" << endl;
		}
		else if (this->isCsv() == true)
		{
			ostr << m_parkingNumber << ",";
			
			for (unsigned int i = 0; i < strlen(m_licensePlate); i++)
			{
				putchar(toupper(m_licensePlate[i]));
			}

			ostr << ",";

			ostr << m_makeModel << ",";
		}
		else if (this->isCsv() == false)
		{
			ostr << "Parking Spot Number: ";

			if (m_parkingNumber == 0)
			{
				ostr << "N/A" << endl;
			}
			else
			{
				ostr << m_parkingNumber << endl;
			}

			ostr << "Licence Plate: ";

			for (unsigned int i = 0; i < strlen(m_licensePlate); i++)
			{
				putchar(toupper(m_licensePlate[i]));
			}
			ostr << endl;

			ostr << "Make and Model: ";
			ostr << m_makeModel << endl;

		}

		return ostr;

	}
}