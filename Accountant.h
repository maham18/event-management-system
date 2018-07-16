#pragma once
#include<iostream>
using namespace std;
#include <string>
#include "Person.h"


class Accountant :public Person {
private:

public:
	
		
		Accountant(string name) :Person(name)
	{
		cout << "\n amount should be paid on time\n ";
		
	}

	void Persondisplay()
	{
		cout << this->name;
	}

	void recieve_bill()
	{
		cout << "Amount has been recieved";
	}
};