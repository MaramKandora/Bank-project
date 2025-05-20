#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"Global.h"
using namespace std;


class clsTransferScreen:protected clsScreen
{
	static void _PrintClientBalanceCard(clsBankClient Client)
	{
		cout << "\nClient Card: \n";
		cout << "\n-------------------------\n";
		cout << "\nFull Name   :" << Client.FullName();
		cout << "\nAcc.Number  :" << Client.AccountNumber();
		cout << "\nBalance     :" << Client.AccountBalance;
		cout << "\n\n-------------------------\n";

	}

	static string _ReadAccountNumber()
	{
		string AccountNum;
	
		AccountNum = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNum))
		{
			cout << "\nClient with AccountNumber [" << AccountNum << "] is Not Found..Choose another one: ";
			AccountNum = clsInputValidate::ReadString();
		}

		return AccountNum;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		cout << "\nEnter Transfer Amount? ";
		float Amount = clsInputValidate::ReadNumber<float>();

		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the Avialable Balance...Enter another Amount? ";
			Amount = clsInputValidate::ReadNumber<float>();
		}

		return Amount;


	}

public:
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen");

		cout << "\nPlease Enter Account Number to Transfer From: ";
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClientBalanceCard(SourceClient);


		cout << "\nPlease Enter Account Number to Transfer To: ";

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		
		while (SourceClient.AccountNumber() == DestinationClient.AccountNumber())
		{
			cout << "\nYou can`t Transfer Money To The Same Account!\n";

			cout << "\nPlease Enter Account Number to Transfer To: ";
			DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		}


		_PrintClientBalanceCard(DestinationClient);

		float Amount = ReadAmount(SourceClient);
	
		char answer = 'n';
		cout << "\nAre you sure do you want to perform this Transfer Operation? Y/N? ";
		answer = clsInputValidate::ReadChar();

		if (answer == 'y' || answer == 'Y')
		{

			if (SourceClient.Transfer(Amount, DestinationClient))
			{

				cout << "\n\nTransfer Done Successfuly.\n";


			}

			else
			{
				cout << "\n\nTransfer Failed.\n";
			}

			_PrintClientBalanceCard(SourceClient);
			_PrintClientBalanceCard(DestinationClient);
		}
		


	}

};

