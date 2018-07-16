#pragma once
#include<iostream>
#include "admin.h"
#include "Person.h"
#include <string>
using namespace std;

class Manager :public Person {
private:
	Admin admin;
public:
	Manager(string name) :Person(name)
	{

		opening_event();


	}

	void opening_event()
	{
		admin.Open();
	}

	void Persondisplay()
	{
		cout << "Managers name: " << this->name;
	}
	void recieve_bill() {}
};

