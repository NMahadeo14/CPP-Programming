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

	Saiyan::Saiyan(const char* name, int dob, int power, bool super)
	{
		set(name, dob, power, super);
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
		m_name[0] = '\0';
		m_dob = 0;
		m_power = 0;
		m_super = false;
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

	void Saiyan::set(const char* name, int dob, int power, bool super)
	{
		if ((name != nullptr) && (name[0] != '\0') && (strcmp("", name)) && (dob < 2020) && (power > 0))
		{
			strcpy(m_name, name);
			m_dob = dob;
			m_power = power;
			m_super = super;
		}
		else
		{
			setEmpty();
		}
	}

	bool Saiyan::hasLost(const Saiyan& other) const
	{
		bool didWin = false;

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


}
