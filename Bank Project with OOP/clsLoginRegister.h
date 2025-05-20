#pragma once
#include<iostream>
#include"clsScreen.h"
#include"fstream"
#include"clsString.h"
using namespace std;


class clsLoginRegister :protected clsScreen
{
	

	static void _PrintLoginRegistorRecordLine(clsUser::stLoginRegisterRecord LoginRegistorRecord)
	{


		cout << "\t| " << left << setw(35) << LoginRegistorRecord.Date_Time;
		cout << "| " << left << setw(25) << LoginRegistorRecord.UserName;
		cout << "| " << left << setw(12) << LoginRegistorRecord.Password;
		cout << "| " << left << setw(12) << LoginRegistorRecord.Permissions;
	}

public:

	static void ShowLoginRegisterScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}


		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord
			= clsUser::GetLoginRegisterList();


		_DrawScreenHeader("\tLogin Register List Screen",
			"\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).");


		cout << "\n" << setw(8) << "" << "-----------------------------------------------";
		cout << "---------------------------------------------------------\n\n";
		cout << "\t| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(25) << "UserName";
		cout << "| " << left << setw(12) << "Password";
		cout << "| " << left << setw(12) << "Permisions";
		cout << "\n\n" << setw(8) << "" << "-----------------------------------------------";
		cout << "---------------------------------------------------------\n\n";

		if (vLoginRegisterRecord.size()==0)
		{
			cout << "\t\t\t\tNo Logins Available In the System!";

		}
		else
		{
			for (clsUser::stLoginRegisterRecord S : vLoginRegisterRecord)
			{
				_PrintLoginRegistorRecordLine(S);

				cout << endl;
			}
		}


		cout << "\n\n" << setw(8) << "" << "-----------------------------------------------";
		cout << "---------------------------------------------------------\n\n";

	}

};

