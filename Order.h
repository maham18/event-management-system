#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"Event.h"
#include "Eventtypes.h"
#include "Menu.h"


class Order {
private:

	Menu * eventmenu;
	Eventtypes *orderevent;
	int count = 0;
	int i;
	char opt;
	//Event *control;


public:
	
	Order()
	{
		this->eventmenu = new Menu();
		this->orderevent = new Eventtypes[20];
		//this->control= new Event();
	}
	//	Order(Menu *Khaana);
	//	void displaymenu();

	void Addorder(int Eventtypesnum)
	{
		this->orderevent[count] = eventmenu->getEventtypesm(Eventtypesnum);
		count++;

		//orderFood->displayitem();

	}

	void removeevent()
	{
count--;
cout << "event has been removed" << endl;
}
	
	

	Order selectevent()
	{


		cout << "select eventnumber: ";
		cin >> i;
		i = i - 1;

		cout << endl;
		//cout << "\nChecking getcounter\n";
		//cout << khaana->getcounter();

		if (i < eventmenu->getcounter())
		{
			Addorder(i);

		}
		else
		{
			cout << "Wrong no" << endl;
			selectevent();
		}
		cout << "press y if you need to select another event or press any other key for details : ";
		cin >> opt;
		cout << endl;
		if (opt == 'y' || opt == 'Y')
		{
			selectevent();
		}
		else
		{
			
			return *this;
		}

	}
	void cancelorder()
	{
		delete[] orderevent;
		cout << "your booking has been cancelled";
		
	}
	int getcount()
	{
		return this->count;
	}
	Eventtypes* getorder()

	{
		return orderevent;
	}
	~Order() {

	}

};
