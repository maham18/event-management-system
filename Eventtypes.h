#pragma once
#include<iostream>
#include<string>
using namespace std;

class Eventtypes {
private:
	string  Eventtypesname;
	int Eventtypesprice;
	int Eventtypesnumber;
public:
	Eventtypes()
	{

	}
	Eventtypes(string Eventtypesn, int Eventtypesp, int Eventtypesnum)
	{
		this->Eventtypesname = Eventtypesn;
		this->Eventtypesprice = Eventtypesp;
		this->Eventtypesnumber = Eventtypesnum;

	}
	Eventtypes(Eventtypes &I)
	{

		this->Eventtypesname = I.Eventtypesname;
		this->Eventtypesprice = I.Eventtypesprice;
		this->Eventtypesnumber = I.Eventtypesnumber;

	}
	void setEventtypesname(string Eventtypesn)
	{
		this->Eventtypesname = Eventtypesn;

	}
	string getEventtypesname()
	{
		return this->Eventtypesname;
	}
	void setEventtypesprice(int itemp)
	{
		this->Eventtypesprice = itemp;
	}
	int getEventtypesprice()
	{
		return this->Eventtypesprice;
	}

	void setEventtypesnumber(int Eventtypesnum)
	{
		this->Eventtypesnumber = Eventtypesnum;
	}
	int getEventtypesnumber()
	{
		return this->Eventtypesnumber;
	}
	void displayitem()
	{
		cout << "Eventtypes name: " << this->Eventtypesname << endl;
		cout << "Eventtypes price: " << this->Eventtypesprice << endl;

	}
	~Eventtypes()
	{

	}
};
ostream& operator<<(ostream& out, Eventtypes& obj)
{
	out << obj.getEventtypesname() << "\t" << obj.getEventtypesnumber() << "\t" << obj.getEventtypesprice() << "\t" << endl;
	return out;
}
