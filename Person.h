#pragma once
#include<iostream>
#include<string>

using namespace std;

class Person {
protected:
	string name;
public:
	Person()
	{
		this->name = "";
	}
	Person(string n)
	{
		this->name = n;
	}
	void setname(string n)
	{
		this->name = n;
	}
	string getname()
	{
		return this->name;
	}
	//	virtual void Open() = 0;
	virtual void Persondisplay() = 0;
	virtual void recieve_bill() = 0;

};
