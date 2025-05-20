#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
using namespace std;


class clsWithdrawScreen :protected clsScreen
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

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t   Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease enter Withdraw Amount? ";
		Amount = clsInputValidate::ReadNumber<double>();

		cout << "\nAre you sure you want to perform this transaction? Y or N? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			if (Client1.Withdraw(Amount))
			{
				cout << "\nAmount Withdrew successfully.\n";
				cout << "\nNew Balance: " << Client1.AccountBalance;
			}

			else
			{

				cout << "\nCannot withdraw, Insufficient Balance!\n";
				cout << "\nAmount to withdraw: " << Amount;
				cout << "\n\nYour Balance is: " << Client1.AccountBalance;
			}

		}

		else
		{
			cout << "\nOperation was cancelled.\n";
		}


	}


};

