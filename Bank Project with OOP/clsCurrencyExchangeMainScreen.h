#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"
#include"clsListCurrencies.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrecncyCalculatorScreen.h"
using namespace std;

class clsCurrencyExchangeMainScreen :protected clsScreen
{
	enum enCurrencyMenueOption {
		enListCurrencies = 1, enFindCurrency = 2, enUpdateCurrencyRate = 3,
		enCurrencyCalculator = 4, enMainMenue = 5
	};

	static short _ReadCurrencyMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you wany to do? [1 to 5]? ";

		return clsInputValidate::ReadNumberBetween<short>(1, 5, "Enter Number Between 1 and 5? ");


	}

	static void _GoBackToCurrencyExchangeMenue()
	{

		cout << " \n\n" << setw(37) << left << "" << "Press any key to go back to currency exchange menue...";
		system("pause>0");

		ShowCurrencyExchangeMenue();

	}

	static void _ShowListCurrencuiesScreen()
	{
		//cout << "\nCurrencies List Screen will be here...";

		clsListCurrencies::ShowListCurrencies();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency Screen will be here...";

		clsFindCurrencyScreen::ShowFindCurrencyScreen();

	}

	static void _ShowUpdateCurrencyRateScreen()
	{
		//cout << "\nUpdate Rate Screen will be here...";

		clsUpdateCurrencyRateScreen::_ShowUpdateCurrencyRateScreen();
	}


	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrecncyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}




	static void _PerformCurrencyMenueOption(enCurrencyMenueOption Optin)
	{
		switch (Optin)
		{
		case enCurrencyMenueOption::enListCurrencies:
			system("cls");
			_ShowListCurrencuiesScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		case enCurrencyMenueOption::enFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		case enCurrencyMenueOption::enUpdateCurrencyRate:
			system("cls");
			_ShowUpdateCurrencyRateScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		case enCurrencyMenueOption::enCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeMenue();
			break;

		case enCurrencyMenueOption::enMainMenue:
		{
			//main menue will handle it

		}


		};


	}

public:

	static void ShowCurrencyExchangeMenue()
	{
		system("cls");

		_DrawScreenHeader("   Currency Exchange Menue Screen");

		cout << setw(37) << left << "" << "============================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "=============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "=============================================\n";

		_PerformCurrencyMenueOption((enCurrencyMenueOption)_ReadCurrencyMenueOption());

	}

};

