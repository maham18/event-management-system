
#pragma once

#include<iostream>
using namespace std;

class Reserved {
private:

	int reservedid;
	int counterreserved = 0;
public:
	Reserved()
	{
		this->reservedid = 0;
		this->counterreserved = 0;
	}
	Reserved(int tid)
	{
		this->reservedid = tid;
	}
	Reserved(Reserved &t)
	{
		this->reservedid = t.reservedid;
	}
	void setReserved(int tab)
	{
		this->reservedid = tab;
	}
	int getReserved()
	{
		return this->reservedid;
	}
	void OccupiedReserved()
	{

		if (reservedid <= 10) {
			counterreserved++;
		}

	}
	void ReleaseReserved()
	{
		if (counterreserved > 0)
		{
			counterreserved--;
		}
	}
	bool Reservedcheck()
	{
		if (reservedid > 20)
		{
			cout << "you need to wait we are busy with other events\n";
			return 0;
		}
		else
			return 1;

	}

	int getcounterreserved()
	{
		return this->counterreserved;
	}

};