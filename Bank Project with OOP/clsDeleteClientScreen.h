#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;


class clsDeleteClientScreen :protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card: ";
		cout << "\n________________________________________";
		cout << "\nFirstName   :" << Client.FirstName;
		cout << "\nLastName    :" << Client.LastName;
		cout << "\nFullName    :" << Client.FullName();
		cout << "\nEmail       :" << Client.Email;
		cout << "\nPhone       :" << Client.Phone;
		cout << "\nAcc.Number  :" << Client.AccountNumber();
		cout << "\nPassword    :" << Client.PinCode;
		cout << "\nBalance     :" << Client.AccountBalance;
		cout << "\n________________________________________";
	}
public: 

	static void ShowDeleteClientScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("\t Delete Client Screen");

		string AccountNumber = "";
		cout << "\nPlease Enter AccountNumber: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		char answer = 'n';
		cout << "\nAre you sure do you want to delete this client? Y/N? ";
		answer = clsInputValidate::ReadChar();

		if (answer == 'y' || answer == 'Y')
		{

			if (Client1.Delete())
			{
				cout << "\n\nAccount Deleted Successfully.\n";
				//Client1.Print();
			}
			else
			{
				cout << "\n\nError, account was not deleted.\n";
			}
		}
	}
};

