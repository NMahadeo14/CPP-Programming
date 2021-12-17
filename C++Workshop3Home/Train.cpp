#include <iostream>
#include <cstring>
#include <iomanip>
#include "Train.h"

using namespace std;

namespace sdds
{

	void Train::setTrain(const char* trainName, int trainID)
	{
		if (trainName == nullptr || !strcmp(trainName, "") || trainID < 1)
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
		if (Train::m_id == 0 || Train::m_name[0] == '\0')
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
				cout << fixed;
				cout << setprecision(2);
				cout << "Cargo: " << cargo->getDescription() << " Weight: " << cargo->getWeight() << endl;
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
		delete cargo;
		cargo = nullptr;
	}

	void Cargo::init(const char* desc, double weight)
	{
		strcpy(m_description, desc);

		if ((desc[0] > MAX_DESC && weight > MAX_WEIGHT) || (weight < MIN_WEIGHT))
		{
			Cargo::m_weight = MIN_WEIGHT;
		}
		else
		{
			Cargo::m_weight = weight;
			strcpy(m_description, desc);
		}
	}

	const char* Cargo::getDescription() const
	{
		
		return this->m_description;
	}

	double Cargo::getWeight() const
	{
		return this->m_weight;
	}

	bool Train::swapCargo(Train& TrainB)
	{
		bool swapCargo = false;

		if (this->cargo != nullptr && TrainB.cargo != nullptr)
		{
			Cargo* tempCargo;

			tempCargo = this->cargo;
			this->cargo = TrainB.cargo;
			TrainB.cargo = tempCargo;

			swapCargo = true;
		}

		return swapCargo;
	}

	double Cargo::setWeight(double val) 
	{
		m_weight = val;

		return val;
	}

	bool Train::increaseCargo(double cargoIncrease)
	{
		bool didChange = false;

		if (cargo != nullptr)
		{
			double originalWeight = this->cargo->getWeight();
			double tempWeight = this->cargo->getWeight() + cargoIncrease;
			
			if (tempWeight > MAX_WEIGHT)
			{
				this->cargo->setWeight(MAX_WEIGHT);
			}
			else if (tempWeight > originalWeight)
			{
				this->cargo->setWeight(tempWeight);
			}

			if (this->cargo->getWeight() > originalWeight)
			{
				didChange = true;
			}

		}

		return didChange;
		
	}

	bool Train::decreaseCargo(double cargoDecrease)
	{
		bool decrease = false;
		
		if (cargo != nullptr)
		{
			double originalWeight = this->cargo->getWeight();
			double tempWeight = this->cargo->getWeight() - cargoDecrease;

			if (tempWeight < MIN_WEIGHT)
			{
				this->cargo->setWeight(MIN_WEIGHT);
			}
			else if (tempWeight < originalWeight)
			{
				this->cargo->setWeight(tempWeight);
			}

			if (this->cargo->getWeight() < originalWeight)
			{
				decrease = true;
			}
		}

		return decrease;
	}



}