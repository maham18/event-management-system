#pragma once
#include<iostream>
using namespace std;
#include<string>

#include "Person.h"
#include "Order.h"
#include "Bill.h"
#include"Menu.h"



class Customer :public Person {
private:
	int Eventtypesnumber;
	Order * holdOrder;
	int id;
	Menu *m;
	Order *rdx;

    Bill *bill;
public:
	Customer()
	{

	}

	Customer(int i, string name) :Person(name)
	{
		
		this->id = i;
		this->rdx = new Order();
		this->m = new Menu();

		orderControl();
		Paybill();
		

	}

	//Order giveorder(Item *le)

	void orderControl()
	{
		int a;


		do {
			cout << "\nPress 1 to book an event\n";
			cout << "Press 2 to remove an event\n";
			cout << "Press 3 to cancel event booking\n";
			cout << "press 4 to search a event by name\n";
			cout << "press 5 to search a event by number\n";
			cout << "press 6 to delete a event by name\n";
			cout << "press 7 to delete a event by number\n";
			cout << "Press 8 If selection of event is completed...\n";


			cin >> a;
			if (a == 1)
			{
				giveorder();
			}

			else if (a == 2)
			{

				rdx->removeevent();
			}

			else if (a == 3)
			{

				rdx->cancelorder();
				
			}
			else if (a == 4)
			{
			m->searchevent();
			}
			else if (a == 5)
			{
				m->searchevent(Eventtypesnumber);//maham
			}
			else if (a == 6)
			{
				m->deleteevent();
			}
			else if (a == 7)
			{
				m->deleteevent(Eventtypesnumber);//maham
			}
			
			else if (a == 8)
			{
				exit;
			}
		} while (a != 8);
	}

	Order giveorder()
	{


		//this->holdOrder = new Order();


		*rdx = rdx->selectevent();
		return *rdx;

	}
	

	void Paybill()
	{
		int sendcount = rdx->getcount();
		this->bill = new Bill();
		Eventtypes *temp;
		temp = new Eventtypes();
		temp = rdx->getorder();
            bill->GenerateBill(temp, sendcount);

	}
	void Persondisplay()
	{
		cout << this->name;
		cout << this->id;
	}

	void recieve_bill() {}
	~Customer()
	{
	}
};
