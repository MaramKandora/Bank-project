#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;


class clsDepositScreen:protected clsScreen
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
		cout << "\n________________________________________\n";
	}

	static string _ReadAccountNumber()
	{
		cout << "\nPlease enter AccountNumber: ";
		return clsInputValidate::ReadString();

	}


public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t   Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with ["<<AccountNumber<<"] does not exist.\n ";
			AccountNumber =_ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease enter deposit amount? ";
		Amount = clsInputValidate::ReadNumber<double>();

		cout << "\nAre you sure you want to perform this deposit? Y or N? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			/*while (!Client1.Deposit(Amount))
			{
				cout << "\nError...Amount should be positive.\n";
				cout << "\nPlease enter deposit amount? ";
				Amount = clsInputValidate::ReadDblNumber();

			}*/
		
			cout << "\nAmount Deposited successfully.\n";
			cout << "\nNew Balance: " << Client1.AccountBalance;
			
		}

		else
		{
			cout << "\nOperation was cancelled.\n";
		}


	}


};

