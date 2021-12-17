#include <iostream>
#include <cstring>
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
		if (aGift.wrap == nullptr) // While the current gift is not wrapped and has no layers
		{
			cout << "Gift Details:" << endl;
			cout << "Description: " << aGift.g_description << endl;
			cout << "Price: " << aGift.g_price << endl;
			cout << "Units: " << aGift.g_units << endl;
			cout << "Unwrapped" << endl;
		}
		else
		{
			// While the current gift is wrapped and has layers

			cout << "Gift Details:" << endl;
			cout << "Description: " << aGift.g_description << endl;
			cout << "Price: " << aGift.g_price << endl;
			cout << "Units: " << aGift.g_units << endl;
			cout << "Wrap Layers: " << aGift.wrap_layers << endl;
			for (int i = 0; i < aGift.wrap_layers; i++)
				cout << "Wrap #" << i + 1 << ": " << aGift.wrap[i].m_pattern << endl;
		}
			



		
	}

	bool wrap(Gift& wrapped)
	{
		char pattern[MAX_PATTERN + 1];
		int patternlen;

		while (wrapped.wrap_layers != 0) // Error msg (if layers = 0 the gift is already wrapped)
		{
			cout << "Gift is already wrapped!" << endl;

			return false;

		}

		wrapped.wrap_layers = 0;

		cout << "Wrapping gifts..." << endl;
		
		
		while (wrapped.wrap_layers == 0)  // While there are no layers of wrap on gift enter while loop
		{
			cout << "Enter the number of wrapping layers for the Gift: ";  
			cin >> wrapped.wrap_layers; // Enter amount of layers for current Gift


			if (wrapped.wrap_layers < 1) // If entered amount less then 1 Enters if statement
			{
				cout << "Layers at minimum must be 1, try again." << endl; // Error msg
				wrapped.wrap_layers = 0; // Sets layers to 0 so that the while loop repeats
			}
		
		}

		
		wrapped.wrap = new Wrapping[wrapped.wrap_layers]; // Dynamic allocated memory for the amount of layers that are being wrapped on the current Gift

		for (int i = 0; i < wrapped.wrap_layers; i++) //Enter Loop for the pattern on X layer
		{
			cout << "Enter wrapping pattern #" << i + 1 << ": ";
			cin >> pattern;

			patternlen = strlen(pattern); 

			if (patternlen < MAX_PATTERN)
			{
				wrapped.wrap[i].m_pattern = new char[patternlen];
			}
			for (int j = 0; j < patternlen; j++)
			{
				wrapped.wrap[i].m_pattern[j] = pattern[j];
			}

			wrapped.wrap[i].m_pattern[patternlen] = '\0';
	
		}

		
	}

	bool unwrap(Gift& unwrapped)
	{

		while (unwrapped.wrap_layers > 0) // Gift has layers and is able to be unwrapped
		{
			cout << "Gift being unwrapped." << endl;
			unwrapped.wrap_layers = 0; // set the state of the gift to that of one that has no layers
			unwrapped.wrap = nullptr; // set the state of the gift to that of one that has no layers 

			return true;
		}

		delete[] unwrapped.wrap;  // Clear the memory that was allocated to store the wrappings of the gift 
		unwrapped.wrap = nullptr; // ensure no garbage values after the memory has been deallocated
			
		while (unwrapped.wrap_layers <= 0) // while the layers of the current object are less then or = to 0 there are no layers and cannot be unwrapped 
		{
			cout << "Gift isn't wrapped! Can't unwrap." << endl; // Error msg

			return false;
		}

	}

	void gifting(Gift& aGift)
	{
		cout << "Preparing a gift..." << endl;

		gifting(aGift.g_description);      
		gifting(aGift.g_price);	//	Uses the previous gifting functions from the in lab to get the description price and units of the gift.
		gifting(aGift.g_units);		

		wrap(aGift); // the attemps to wrap the gift if it is possible to do so 

	}


}