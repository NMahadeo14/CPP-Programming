#ifndef SDDS_GIFT_H
#define SDDS_GIFT_H

namespace sdds
{
	const int MAX_DESC = 15;
	const double MAX_PRICE = 999.99;
	const int MAX_PATTERN = 20;

	struct Wrapping
	{
		char* m_pattern;
	};
	struct Gift
	{

		char g_description[MAX_DESC + 1];
		double g_price;
		int g_units;
		int wrap_layers;
		Wrapping* wrap;

	};

	

	void gifting(char*);
	void gifting(double&);
	void gifting(int&);
	void gifting(Gift&);
	void display(const Gift&);
	bool wrap(Gift&);
	bool unwrap(Gift&);

}

#endif
