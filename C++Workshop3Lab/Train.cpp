#include <iostream>
#include <cstring>
#include "Train.h"

using namespace std;

namespace sdds
{

	void Train::setTrain(const char* trainName, int trainID)
	{
		if (trainName == nullptr || trainName == "" || trainID < 1)
		{
			Train::m_name[0] = '\0';
			Train::m_id = 0;
			
		}
		else
		{
			Train::m_id = trainID;
			strcpy(m_name, trainName);
		}

		cargo = nullptr;	

	}

	bool Train::isEmpty() const
	{
		if (Train::m_id == 0 ||Train::m_name[0] == '\0')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void Train::display() const
	{
		cout << "***Train Summary***" << endl;

		if (Train::isEmpty())
		{
			cout << "This is an empty train." << endl;
		}
		else
		{
			cout << "Name: " << m_name << " ID: " << m_id << endl;

			if (cargo != nullptr)
			{
				cout << "Cargo: " << cargo->m_description << " Weight: " << cargo->m_weight << endl;
			}
			else
			{
				cout << "No cargo on this train." << endl;
			}
		}

		
	
	}

	void Train::loadCargo(Cargo tCargo)
	{
		cargo = new Cargo;
		*cargo = tCargo;
	}

	void Train::unloadCargo()
	{
		delete[] cargo;
		cargo = nullptr;
	}

}