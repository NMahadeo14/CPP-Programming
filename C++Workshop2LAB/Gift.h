#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H

namespace sdds
{
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.99;

	struct Gift
	{
		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;

		
	};

	void gifting(char*);
	void gifting(double&);
	void gifting(int&);
	void display(const Gift&);

}

#endif
