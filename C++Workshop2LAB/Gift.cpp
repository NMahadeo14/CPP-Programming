#include <iostream>
#include "Gift.h"

using namespace std;

namespace sdds
{
	void gifting(char* desc)
	{
		cout << "Enter gift description: ";
		cin.width(MAX_DESC + 1);
		cin >> desc;
	}

	void gifting(double& price)
	{
		price = -1;

		while (price == -1)
		{
			cout << "Enter gift price: ";
			cin >> price;

			if (price < 0 || price > MAX_PRICE)
			{
				cout << "Gift price must be between 0 and " << MAX_PRICE << endl;
				price = -1;
			}

		}
		
	}

	void gifting(int& units)
	{
		units = 0;

		while (units == 0)
		{
			cout << "Enter gift units: ";
			cin >> units;

			if (units < 1)
			{
				cout << "Gift units must be at least 1" << endl;
				units = 0;
			}
		}
	}

	void display(const Gift& aGift)
	{
		cout << "Gift Details:" << endl;
		cout << "Description: " << aGift.g_description << endl;
		cout << "Price: " << aGift.g_price << endl;
		cout << "Units: " << aGift.g_units << endl;
	}


}



