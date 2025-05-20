#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;


class clsUpdateClientScreen :protected clsScreen
{

	static void _ReadClientInfo(clsBankClient &Client)
	{

		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadNumber<float>();


	}

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


	static void ShowUpdateClientScreen()
	{

		if (!_CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}

		_DrawScreenHeader("\t Update Client Screen");

		string AccountNumber = "";
		cout << "Please Enter AccountNumber: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccountNumber is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char answer = 'n';
		cout << "\nAre you sure do you want to update this User? Y/N? ";
		answer = clsInputValidate::ReadChar();

		if (answer == 'y' || answer == 'Y')
		{


			cout << "\n\nUpdate Client Info:";
			cout << "\n---------------------------\n";


			_ReadClientInfo(Client);

			clsBankClient::enSaveResults SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsBankClient::svSucceeded:
			{
				cout << "\n\nAccount Updated Successfully.\n";
				_PrintClient(Client);
				break;
			}

			case clsBankClient::svFaildEmptyObject:
				cout << "\nError, Account was not saved because it`s Empty.\n";
				break;
			}

		}
	}
};

