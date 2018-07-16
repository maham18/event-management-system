#pragma once
#include<iostream>
using namespace std;
#include<string>
#include "Eventtypes.h"


class Menu
{
private:
	string  Eventtypesname;
	Eventtypes * MenuList;
	int size;
	Eventtypes *Menulist2;
	int counteritm;
	


public:
	Menu()
	{
		this->counteritm = 10;
		this->size = 10;
		this->MenuList = new Eventtypes[this->size];
		

		MenuList[0].setEventtypesname("Wedding");
		MenuList[0].setEventtypesprice(50000000000000000);
		MenuList[0].setEventtypesnumber(1);


		MenuList[1].setEventtypesname("Birthday");
		MenuList[1].setEventtypesprice(250000000000);
		MenuList[1].setEventtypesnumber(2);

		MenuList[2].setEventtypesname("Reception");
		MenuList[2].setEventtypesprice(45000000);
		MenuList[2].setEventtypesnumber(3);


		MenuList[3].setEventtypesname("Wedding Anniversary");
		MenuList[3].setEventtypesprice(873000);
		MenuList[3].setEventtypesnumber(4);


		MenuList[4].setEventtypesname("Musical Concert");
		MenuList[4].setEventtypesprice(5000000);
		MenuList[4].setEventtypesnumber(5);


		MenuList[5].setEventtypesname("Mehndi");
		MenuList[5].setEventtypesprice(500440);
		MenuList[5].setEventtypesnumber(6);


		MenuList[6].setEventtypesname("Nikkah");
		MenuList[6].setEventtypesprice(25000);
		MenuList[6].setEventtypesnumber(7);

		MenuList[7].setEventtypesname("Aqiqa");
		MenuList[7].setEventtypesprice(507880);
		MenuList[7].setEventtypesnumber(8);

		MenuList[8].setEventtypesname("Family Gathering");
		MenuList[8].setEventtypesprice(50000);
		MenuList[8].setEventtypesnumber(9);


		MenuList[9].setEventtypesname("Any Customised Event");
		MenuList[9].setEventtypesprice(800000);
		MenuList[9].setEventtypesnumber(10);

	}

	void addEventtypes(Eventtypes &event)
	{
		if (counteritm < size) {
			this->MenuList[counteritm] = event;
			counteritm++;
		}
		else
		{
			increasesize();
			addEventtypes(event);
		}

	}



	void ShowMenu()
	{
		cout << "\n\n***************EVENT CHOICES****************\n\n";
		for (int i = 0; i < size; i++)
		{
			cout << this->MenuList[i].getEventtypesnumber() << "**************";
			cout << this->MenuList[i].getEventtypesname();
			cout << "*************\n price:";
			cout << this->MenuList[i].getEventtypesprice();

			cout << endl;
		}
	}
	void ShowMenu(int i)
	{
		cout << "\n\n***************EVENT CHOICES****************\n\n";
		for ( i = 0; i < size-1; i++)
		{
			cout << this->MenuList[i].getEventtypesnumber() << "**************";
			cout << this->MenuList[i].getEventtypesname();
			cout << "*************\n price:";
			cout << this->MenuList[i].getEventtypesprice();

			cout << endl;
		}
	}

	Eventtypes increasesize()
	{

		this->size = this->size * 2;
		this->Menulist2 = new Eventtypes();
		for (int i = 0; i <= counteritm; i++)
		{
			this->Menulist2[i] = this->MenuList[i];
		}
		delete[] MenuList;
		this->MenuList = this->Menulist2;
		return *MenuList;

	}
	int getcounter()
	{
		return this->counteritm;
	}

	Eventtypes getEventtypesm(int i)
	{
		return this->MenuList[i];
	}
	void searchevent() //maham
	{
		cout << "name of event you want to search:" << endl;
		cin >> Eventtypesname;
		for (int i = 0; i < size; i++)
			if (this->MenuList[i].getEventtypesname() == Eventtypesname)
				cout << this->MenuList[i];

	}

	void searchevent(int Eventtypesnumber) //maham
	{
		cout << "number of event you want to search:" << endl;
		cin >> Eventtypesnumber;
		for (int i = 0; i < size; i++)
			if (this->MenuList[i].getEventtypesnumber() == Eventtypesnumber)
				cout << this->MenuList[i];

	}
	void deleteevent() //For deleting collection
	{

		cout << "name of event you want to delete:" << endl;
		cin >> Eventtypesname;
		for (int i = 0; i < size - 1; i++)
			if (this->MenuList[i].getEventtypesname() == Eventtypesname)
			{
				this->MenuList[i] = Eventtypes();
				for (int j = i; j < size - 1; j++)

					this->MenuList[j] = this->MenuList[j + 1];
			this->counteritm--;
			
			 ShowMenu(i);
			}
	}
	void deleteevent(int Eventtypesnumber) //For deleting collection
	{


		cout << "number of event you want to delete:" << endl;
		cin >> Eventtypesnumber;
		for (int i = 0; i < size - 1; i++)
			if (this->MenuList[i].getEventtypesnumber() == Eventtypesnumber)
			{
				this->MenuList[i] = Eventtypes();
				for (int j = i; j < size - 1; j++)
					this->MenuList[j]=this->MenuList[j+1];
				this->counteritm--;
				 ShowMenu( i);

			}
	}
	~Menu()
	{

	}
	
};


