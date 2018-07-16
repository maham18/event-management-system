
#pragma once
#include<iostream>
#include <string>
using namespace std;

class Admin {

private:
	string username;
	string password;
	bool loginsuccess = false;


public:
	Admin()
	{
		username = "";
		password = "";


	}
	bool Open() {
		do {
			cout << "******************************************\n";
			cout << "     EVENT MANAGEMENT SYSTEM\n";
			cout << "******************************************\n";
			cout << "Username: ";
			cin >> username;
			cout << "Password: ";
			cin >> password;

			if (username == "Admin"&&password == "eventplanner")
			{
				cout << "Login succesful\n";
				loginsuccess == true;
				return 1;
			}
			else
			{
				cout << "Incorrect username and password\n";
				cout << "Try again\n";
			}
			//system("pause");
		} while (loginsuccess == false);

	}

};

