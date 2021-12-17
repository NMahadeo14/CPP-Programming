#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds
{
	const int MAX_NAME = 30;
	const int MAX_DESC = 20;

	struct Cargo
	{
		char m_description[MAX_DESC + 1];
		double m_weight;
	};

	class Train
	{
		char m_name[MAX_NAME + 1];
		int m_id;
		Cargo* cargo;

	public:

		void setTrain(const char*, int);
		bool isEmpty() const;
		void display() const;
		void loadCargo(Cargo);
		void unloadCargo();

	};


}



#endif
