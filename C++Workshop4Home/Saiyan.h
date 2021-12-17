#ifndef SDDS_SAIYAN_H
#define SDDS_SAIYAN_H

namespace sdds
{
	class Saiyan
	{
		char* m_name;
		int m_dob;
		int m_power;
		bool m_super;
		int m_level;

	public:

		Saiyan();
		Saiyan(const char* name, int dob, int power, int level = 0, bool super = false);
		~Saiyan();
		bool isSuper() const;
		bool isValid() const;
		void setEmpty();
		void display() const;
		void set(const char* name, int dob, int power, int level = 0, bool super = false);
		bool hasLost(Saiyan& other);
		void powerup();

	};

}
#endif // !SDDS_SAIYAN_H

