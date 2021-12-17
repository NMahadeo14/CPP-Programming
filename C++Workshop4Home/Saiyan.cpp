#include <iostream>
#include <cstring>
#include "Saiyan.h"

using namespace std;

namespace sdds
{
	Saiyan::Saiyan()
	{
		setEmpty();
	}

	Saiyan::Saiyan(const char* name, int dob, int power, int level, bool super)
	{
		set(name, dob, power, level, super);
	}

	bool Saiyan::isSuper() const
	{

		if (this->m_super == false)
		{
			cout << "Super Saiyan Ability: Not super Saiyan." << endl;
		}
		else
		{
			cout << "Super Saiyan Ability: Super Saiyan." << endl;
			cout << "Super Saiyan level is: " << this->m_level;
		}

		return m_super;
	}

	bool Saiyan::isValid() const
	{
		bool valid = true;

		if ((m_name == nullptr) || (m_name[0] == '\0') || (!strcmp("", m_name)) || (m_dob > 2020) || (m_power < 0))
		{
			valid = false;
		}

		return valid;
	}

	void Saiyan::setEmpty()
	{
		m_name = nullptr;
		m_dob = 0;
		m_power = 0;
		m_super = false;
		m_level = 0;
	}

	void Saiyan::display() const
	{
		if (!isValid())
		{
			cout << "Invalid Saiyan!" << endl;
		}
		else
		{
			cout << this->m_name << endl;
			cout << "DOB: " << this->m_dob << " Power: " << this->m_power << endl;
			this->isSuper();
			cout << endl;
		}

	}

	void Saiyan::set(const char* name, int dob, int power, int level, bool super)
	{
		if ((name != nullptr) && (name[0] != '\0') && (strcmp("", name)) && (dob < 2020) && (power > 0))
		{
			m_name = new char[strlen(name) + 1];

			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;

			if (super == true)
			{
				m_level = level;
			}
			
		}
		else
		{
			setEmpty();
		}
	}

	void Saiyan::powerup()
	{
		if (this->m_super == true)
		{
			this->m_power = this->m_power * (this->m_level + 1);
		}

	}

	bool Saiyan::hasLost(Saiyan& other)
	{
		bool didWin = false; 
		this->powerup();
		other.powerup();

		// get data from current object and other object
		// store values into temp variables 

		if (this->m_power < other.m_power && isValid())
		{
			didWin = true;
		}
		else
		{
			didWin = false;
		}

		return didWin;

	}

	Saiyan::~Saiyan()
	{
		delete[] m_name;
		m_name = nullptr;
	}



}
