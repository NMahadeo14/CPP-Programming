#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds
{
	const int MAX_NAME = 30;
	const int MAX_DESC = 20;
	const double MAX_WEIGHT = 700.555;
	const double MIN_WEIGHT = 40.444;

	class Cargo
	{
		char m_description[MAX_DESC + 1];
		double m_weight;

	public:

		const char* getDescription() const;
		double getWeight() const;
		void init(const char*, double);
		double setWeight(double);
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
		bool swapCargo(Train&);
		bool increaseCargo(double);
		bool decreaseCargo(double);

	};


}



#endif
