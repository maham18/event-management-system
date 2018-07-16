#pragma once
#include<iostream>
using namespace std;
#include<string>
#include "Order.h"
#include "Accountant.h"

class Bill {
private:
	
	int billno;
	int totalbill = 0;

public:
	Bill()
	{
		this->billno = 0;
		
	}
	Bill(int bill)
	{
		this->billno = bill;
	}
	int CalculateTotal(Eventtypes *parchi, int countt)
	{
		int count = countt;
		for (int i = 0; i < count; i++)
		{

			this->totalbill = this->totalbill + parchi[i].getEventtypesprice();

		}

		return totalbill;

	}
	void GenerateBill(Eventtypes*parchi, int countt)
	{
		int t_bill = CalculateTotal(parchi, countt);

		cout << "\n\n*********** Event Order by the Customer****************\n\n";

		for (int i = 0; i < countt; i++)
		{
			
			cout << parchi[i].getEventtypesnumber() << "  " << parchi[i].getEventtypesname() << "  " << parchi[i].getEventtypesprice();
			cout << endl;

		}

		cout << "\n***********************\n";
		cout << "Total expenses of event:";
		cout << t_bill << endl;

		cout << "\nthank you for choosing us! \n*****we will try our best to make your event memorable******\n";

		ofstream outfile;
		outfile.open("cust_info.txt", ios::app);
		outfile << "Order: ";
		for (int i = 0; i < countt; i++)
		{

			outfile << parchi[i].getEventtypesnumber() << "--" << parchi[i].getEventtypesname() << "--" << parchi[i].getEventtypesprice();
			outfile << endl;

		}

		outfile << endl << "Total Bill: " << t_bill << endl << "-----------------------------------------" << endl;



		outfile.close();


	}

	~Bill() {

	}
};
