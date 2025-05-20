#pragma once
#include<iostream>
#include"clsUtil.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsScreen.h"
#include"clsClientsListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionsScreen.h"
#include"clsManageUsersMenue.h"
#include"clsLoginScreen.h"
#include"Global.h"
#include"clsLoginRegister.h"
#include"clsCurrencyExchangeMainScreen.h"
using namespace std;


class clsMainScreen:protected clsScreen
{
	enum enMainMenueOption {
		enShowClients = 1, enAddNewClient = 2, enDeleteClient = 3,
		enUpdateClient = 4, enFindClient = 5, enTransactions = 6,
		enMangeUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
	};

	static enMainMenueOption _MainOption;

	static short _ReadMainMenueOption()
	{
		short Option;
		cout <<setw(37)<<"" << "Choose what do you want to do? [1 to 10]? ";
		
		Option = clsInputValidate::ReadNumberBetween<short>(1, 10, "Enter Number Between 1 and 10: ");
		
		return Option;
	}


	static void _GoBackToMainMenue()
	{
		
		cout << "\n\n" << setw(37) << "" << "Press any key to go back to main menue...";

		system("pause>0");
		ShowMainMenue();

	}

	static void _ShowAccessDeniedMessage()
	{
		system("cls");

		cout <<"\n"<< setw(37) << "" << "----------------------------------------------------\n";
		cout << setw(37) << "" << "\t\t\tAccess Denied\n";
		cout << setw(37) << "" << "\t\tYou don`t have permission to this\n";
		cout << setw(37) << "" << "\t\tPlease contact your Admin.\n";
		cout << setw(37) << "" << "----------------------------------------------------\n";

	}

	static void _ShowAllClientsScreen()
	{
		//cout << "\nClients List Screen will be here...\n";
		ClientsListScreen::ShowClientsList();
		
	}


	static void _ShowAddNewClientScreen()
	{
		//cout << "\nAdd New Client Screen will be here...\n";

		clsAddNewClientScreen::ShowAddNewClientScreen();
		
	}

	static void _ShowDeleteClientScreen()
	{
		//cout << "\nDelete Client Screen will be here...\n";
		
		clsDeleteClientScreen::ShowDeleteClientScreen();
		

	}


	static void _ShowUpdateClientScreen()
	{
		//cout << "\nUpdate Client Screen will be here...\n";

		clsUpdateClientScreen::ShowUpdateClientScreen();
		
	}

	static void _ShowFindClientscreen()
	{

		//cout << "\nFind Client Screen will be here...\n";

		clsFindClientScreen::ShowFindClientScreen();
		
	}

	static void _ShowTransactionsScreen()
	{
		//cout << "\nTransactions Menue Screen will be here...\n";

		clsTransactionsScreen::ShowTransactionsMenue();
		
		
	}

	static void _ShowManageUsersMenue()
	{
		//cout << "\nManage Users Screen will be here...\n";
		
		clsManageUsersMenue::ShowManageUsersMenue();

		
	}

	static void _ShowLoginRegisterScreen()
	{
		clsLoginRegister::ShowLoginRegisterScreen();
	}

	static void _ShowCurrencyExchangeMenue()
	{
		clsCurrencyExchangeMainScreen::ShowCurrencyExchangeMenue();
	}


	static void _Logout()
	{
		//cout << "\nLogut Screen will be here...\n";
		CurrentUser = clsUser::Find("", "");

	}



	static void _PerformMainMenueOption(enMainMenueOption Option)
	{
		switch (Option)
		{
		case enMainMenueOption::enShowClients:
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOption::enAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOption::enDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOption::enUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOption::enFindClient:
			system("cls");
			_ShowFindClientscreen();
			_GoBackToMainMenue();
			break;

		case enMainMenueOption::enTransactions:
			system("cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenue();
			break;


		case enMainMenueOption::enMangeUsers:
			system("cls");
			_ShowManageUsersMenue();
			_GoBackToMainMenue();
			break;

		case enMainMenueOption::eLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break; 

		case enMainMenueOption::eCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeMenue();
			_GoBackToMainMenue();


		case enMainMenueOption::eExit:
			system("cls");
			_Logout();
			
			break;

		}


	}


public:


	static void ShowMainMenue()
	{
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");


		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "\t[10] Logout.\n";
		cout << setw(37) << left << "" << "=============================================\n";

		_PerformMainMenueOption((enMainMenueOption)_ReadMainMenueOption());

	}



};

