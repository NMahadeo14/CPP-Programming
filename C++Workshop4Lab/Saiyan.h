#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds
{
	class Saiyan
	{
		char m_name[30];
		int m_dob;
		int m_power;
		bool m_super;

	public:

		Saiyan();
		Saiyan(const char* name, int dob, int power, bool super = false);
		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, bool super = false);
		bool hasLost(const Saiyan& other) const;
	};
		
}
#endif // !SDDS_SAIYAN_H
