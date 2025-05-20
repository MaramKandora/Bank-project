#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUtil.h"

using namespace std;

class clsAddNewClientScreen:protected clsScreen
{
	static void _ReadClientInfo(clsBankClient& Client)
	{

		cout <<  "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();
		cout <<  "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();
		cout <<  "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();
		cout <<  "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();
		cout <<  "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();
		cout <<  "\nEnter Account Balance: ";
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


	static void ShowAddNewClientScreen()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("\t Add New Client Screen");

		string AccountNumber = "";
		cout << "\nPlease Enter AccountNumber: ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is already Used, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		//add permisions

		clsBankClient::enSaveResults SaveResult = NewClient.Save();
		switch (SaveResult)
		{
		case clsBankClient::svSucceeded:
		{
			cout << "\n\nAccount Added Successfully.\n";
			_PrintClient(NewClient);
			break;
		}

		case clsBankClient::svFaildEmptyObject:
		{
			cout << "\nError, Account was not saved because it`s Empty.\n";
			break;
		}

		case clsBankClient::svFaildAccountNumberExists:
		{
			cout << "\nError, Account was not saved because account number is used.\n";
			break;
		}

		}

	}

};

