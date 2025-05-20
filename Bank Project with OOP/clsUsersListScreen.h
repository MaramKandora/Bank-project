#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include<string>
#include"clsUtil.h"
using namespace std;


class clsUsersListScreen:protected clsScreen
{
	static void _PrintUserRecordLine(clsUser User)
	{


		cout << "\t| " << setw(15) << left << User.UserName;
		cout << "| " << setw(25) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;


	}

public:

	static void ShowUsersListScreen()
	{
		vector <clsUser>vUsers = clsUser::GetUsersList();

		_DrawScreenHeader("\t   Users List Screen", "\t   (" + to_string(vUsers.size()) + ") User(s).");

		cout <<"\n"<< setw(8) << "" << "-----------------------------------------------";
		cout << "---------------------------------------------------------\n\n";
		cout << "\t| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(25) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permisions";
		cout <<"\n\n"<< setw(8) << "" << "-----------------------------------------------";
		cout << "---------------------------------------------------------\n\n";

		if (vUsers.size() == 0)
			cout << setw(30) << "" << "No Users availavle in the system.\n";

		else
			for (clsUser U : vUsers)
			{
				_PrintUserRecordLine(U);
				cout << endl;

			}

		cout <<"\n"<< setw(8) << "" << "-----------------------------------------------";
		cout << "---------------------------------------------------------\n\n";
	}

};

