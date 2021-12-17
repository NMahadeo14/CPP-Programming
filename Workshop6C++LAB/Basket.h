#ifndef SDDS_BASKET_H
#define SDDS_BASKET_H

#include <iostream>

using namespace std;

namespace sdds
{
	class Basket
	{
		char* m_basketName;
		int m_quantityBasket;
		double m_basketPrice;

	public:

		Basket();
		Basket(const char*, int, double);
		Basket(const Basket&);
		Basket& operator=(const Basket&);
		~Basket();

		void setName(const char* theName);
		void setqty(int);
		void setPrice(double);
		bool isEmpty() const;
		bool addPrice(double);
		ostream& display(ostream& os) const;

		bool operator==(const Basket&) const;
		bool operator!=(const Basket&) const;

	};

	ostream& operator<<(ostream& os, const Basket& bsk);
}


#endif // !SDDS_BASKET_H

