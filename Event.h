#pragma once
#include<iostream>
#include <fstream>
using namespace std;
#include<string>
#include "Order.h"
#include "Reserved.h"
#include "Manager.h"
#include "Customer.h"
#include "Accountant.h"

class Event {
private:

	Reserved * jaga;
	Menu *taqreeb;
	Person *p[3];
	int id;
	string name;
	int n;

public:
	Event()

	{

		this->jaga
			= new Reserved();

		this->taqreeb
			= new Menu();
		cout << endl;
		cout << "Enter managers name: ";
		cin >> name;
		p[1] = new Manager(name);
		//admin.Open();
		//p[1]->Persondisplay();
		//cout << endl;

		cout << "Enter Accountant name: ";
		cin >> name;

		p[2] = new Accountant(name);
		system("cls");
		control();


	}

	void control()
	{
		cout << "************************************************\n";
		cout << "     Welcome to customer information corner\n";
		cout << "************************************************\n";

		int a;

		do {
			cout << "\nPress 1 to enter a customer\n";
			cout << "press 2 to display all customers\n";
			cout << "Press 3 to pay the bill\n";
			cout << "press 4 to delete all data on file\n";
			cout << "Press 5 Exit\n";


			cin >> a;
			if (a == 1)
			{
				customerentered();
			}
			else if (a == 2)
			{
				display();
			}

			else if (a == 3)
			{

				checkout();
			}

		
			else if (a == 4)
			{
				deletedata();
			}
		
			else if (a == 5)
			{
				if (jaga->getcounterreserved() == 0)
				{
					cout << "no more managers avaliable to handle the event contact us later thank u.....\n closed\n";
					break;
				}

				else
				{
					cout << "There are events which need to complete first...";
					cout << "\nFirst finish events that are pending\n";
					control();
				}
			}
		} while (a != 5);
	}

	void customerentered()
	{
		if (jaga->Reservedcheck() == 1) {
			jaga->OccupiedReserved();

			cout << "\n\nCustomers Information\n";
			cout << "********************************\n";
			cout << "Your name: ";
			cin >> name;
			cout << "Your id:";
			cin >> id;
			cout << endl;
			ofstream outfile;
			outfile.open("cust_info.txt", ios::app);
			outfile << "*********************************************************\n";
			outfile << "     Welcome to customer information corner\n";
			outfile << "*********************************************************\n";

			outfile << "Customer Id: " << id;
			outfile << endl;
			outfile << "Name: " << name << endl;

			outfile.close();


			taqreeb->ShowMenu();
			cout << endl;
			p[3] = new Customer(id, name);


			//p[2]->Persondisplay();

		}


	}
	void display()		//maham
	{
		string line;
		ifstream File("cust_info.txt");
		if (File.is_open())
		{
			while (getline(File, line))
			{
				cout << line << endl;
			}
			File.close();
		}
		else
		{
			cout << "Error! File not found!";

		}
	}
	void deletedata()
	{

		static int totrec = 0;
		ofstream outfile;
		outfile.open("cust_info.txt", ios::ate);
	
			totrec = totrec + 1;

		outfile.close();
	}



	void checkout()
	{
		p[2]->recieve_bill();
		jaga->ReleaseReserved();
		cout << "\nThanks for visiting...\n";

	}

	~Event()
	{

	}
};
