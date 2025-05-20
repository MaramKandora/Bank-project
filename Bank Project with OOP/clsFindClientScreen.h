#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"

using namespace std;

class clsFindClientScreen :protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card: ";
		cout << "\n____________________________";
		cout << "\nFirstName   :" << Client.FirstName;
		cout << "\nLastName    :" << Client.LastName;
		cout << "\nFullName    :" << Client.FullName();
		cout << "\nEmail       :" << Client.Email;
		cout << "\nPhone       :" << Client.Phone;
		cout << "\nAcc.Number  :" << Client.AccountNumber();
		cout << "\nPassword    :" << Client.PinCode;
		cout << "\nBalance     :" << Client.AccountBalance;
		cout << "\n\n___________________________\n";
	}

public:
	static void ShowFindClientScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}

		_DrawScreenHeader("\t Find Client Screen");

		string AccountNumber = "";
		cout << "Please Enter AccountNumber: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
		{
			cout << "\nClient Found :-)\n\n";
		}
		else
		{
			cout << "\nClient was not found :-(\n\n";
		}

		
		_PrintClient(Client1);


	}

};

