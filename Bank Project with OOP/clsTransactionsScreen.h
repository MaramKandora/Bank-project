#pragma once
#include<iostream>
#include"clsScreen.h"
#include <iomanip>
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"
using namespace std;

class clsTransactionsScreen:protected clsScreen
{

	enum enTransactionsMenueOption { enDeposit = 1, enWithraw = 2, enShowTotalBalances = 3,
		enTransfer = 4, enTransferLog = 5, enShowMainMenue = 6
	};

	static short _ReadTransactionsMenueChoice()
	{
		cout << setw(37) << "" << "Choose what do you want to do? [1 to 6]? ";
		return clsInputValidate::ReadNumberBetween<short>(1, 6, "Enter number between [1 and 6]: ");

	}

	static void _GoBackToTransactionsMenue()
	{
		cout << "\n\n" << setw(37) << "" << "Press any key to go back to transactions menue...";
		system("pause>0");

		ShowTransactionsMenue();

	}

	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();

	}

	static void _ShowWithdrawScreen()
	{

		clsWithdrawScreen::ShowWithdrawScreen();

	}

	static void _ShowTotalBalancesScreen()
	{

		clsTotalBalancesScreen::ShowTotalBalancesScreen();

	}

	static void _ShowTransferScreen()
	{
		clsTransferScreen::ShowTransferScreen();

	}


	static void _ShowTransferLogScreen()
	{
		clsTransferLogScreen::ShowTransferLogScreen();

	}

	static void _PerformTransactionsMenueOption(enTransactionsMenueOption TransactionsMenueOption)
	{
		switch (TransactionsMenueOption)
		{
		case enTransactionsMenueOption::enDeposit:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsMenueOption::enWithraw:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsMenueOption::enShowTotalBalances:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsMenueOption::enTransfer:
			system("cls");
			_ShowTransferScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsMenueOption::enTransferLog:
			system("cls");
			_ShowTransferLogScreen();
			_GoBackToTransactionsMenue();
			break;

		case enTransactionsMenueOption::enShowMainMenue:
		{
		// main menue will handle it.
		}


		}
	}

public:

	static void ShowTransactionsMenue()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pTransactionsMenue))
		{
			return;
		}

		system("cls");

		_DrawScreenHeader("\t Transactions Screen");

		cout <<"\n"<< setw(37) << "" << "============================================\n";
		cout << setw(37) << "" << "\t\t Transactions Menue\n";
		cout << setw(37) << "" << "============================================\n\n";
		cout << setw(37) << "" << "   [1] Deposit.\n";
		cout << setw(37) << "" << "   [2] Withdraw.\n";
		cout << setw(37) << "" << "   [3] Total Balances.\n";
		cout << setw(37) << "" << "   [4] Transfer.\n";
		cout << setw(37) << "" << "   [5] Transfer Log.\n";
		cout << setw(37) << "" << "   [6] Main Menue.\n\n";
		cout << setw(37) << "" << "============================================\n";

		_PerformTransactionsMenueOption((enTransactionsMenueOption)_ReadTransactionsMenueChoice());

	}

};

