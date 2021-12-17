#include <iostream>
#include <iomanip>
#include <cstring>
#include "Ship.h"
#include "Engine.h"

using namespace std;

namespace sdds
{

	Ship::Ship()
	{
		m_arrayofEngines = nullptr;
		m_shipType = nullptr;
		m_numOfEngines = 0;
		m_distance = 0.0;
	}

	Ship::Ship(const char* Shiptype, Engine ArrayEngine[], int numofE)
	{
		
		if ((Shiptype != nullptr) && (ArrayEngine > 0))
		{
			m_shipType = new char[strlen(Shiptype) + 1];
			strcpy(m_shipType, Shiptype);

			m_arrayofEngines = new Engine[numofE];

			for (int i = 0; i < numofE; i++)
			{
				m_arrayofEngines[i] = ArrayEngine[i];
			}


			m_numOfEngines = numofE;

			m_distance = 0.0;
		}
		else
		{
			m_arrayofEngines = nullptr;
			m_shipType = nullptr;
			m_numOfEngines = 0;
			m_distance = 0.0;
		}	

	}

	bool Ship::empty() const
	{
		bool isEmpty = true;

		if ((m_arrayofEngines < 0) && (m_shipType[0] == '\0') && (m_numOfEngines == 0) && (m_distance == 0.0))
		{
			isEmpty = true;
		}
		else
		{
			isEmpty = false;
		}

		return isEmpty;
	}

	float Ship::calculatePower() const
	{
		float shipOutputpower = 0.0;
		float SumofEngine = 0.0;

		for (int i = 0; i < m_numOfEngines; i++)
		{
			SumofEngine = float((this->m_arrayofEngines[i].get() * 5));
			shipOutputpower += SumofEngine;
		}

		return shipOutputpower;

	}

	void Ship::display() const
	{
		if (this->m_shipType == nullptr)
		{
			cout << "No available data" << endl;
		}
		else
		{
			cout << fixed;
			cout << setprecision(2);
			cout << this->m_shipType << "-" << setw(6) << this->calculatePower() << endl;
		}

		for (int i = 0; i < m_numOfEngines; i++)
		{
			m_arrayofEngines[i].display();
		}


	}


	Ship& Ship::operator+=(const Engine& e)
	{
		if (m_numOfEngines != 0 && m_shipType != nullptr)
		{
			Engine* tempArray = new Engine[m_numOfEngines + 1];

			for (int i = 0; i < m_numOfEngines; i++)
			{
				tempArray[i] = m_arrayofEngines[i];

			}

			tempArray[m_numOfEngines] = e;
			m_numOfEngines++;

			delete[] m_arrayofEngines;

			m_arrayofEngines = tempArray;

		}
		else
		{
			cout << "The ship doesn't have a type! Engine cannot be added!" << endl;
			this->~Ship();
		}

		return *this;
	}

	bool operator==(const Ship& lhs, const Ship& rhs)
	{
		if (lhs.calculatePower() == rhs.calculatePower())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<(const Ship& lhs, double rhs)
	{
		if (lhs.calculatePower() < rhs)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	Ship::~Ship()
	{
		delete[] m_arrayofEngines;
		m_arrayofEngines = nullptr;

		delete[] m_shipType;
		m_shipType = nullptr;
	}

}

