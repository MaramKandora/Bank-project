#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include<iomanip>
using namespace std;

class clsListCurrencies :protected clsScreen
{

	static void _PrintCurrencyLine(clsCurrency Currency)
	{
		cout << setw(6) << "" << "| " << left << setw(35) << Currency.Country();
		cout << "| " << left << setw(8) << Currency.CurrencyCode();
		cout << "| " << left << setw(45) << Currency.CurrencyName();
		cout << "| " << left << setw(10) << Currency.GetRate();

	}

public:
	static void ShowListCurrencies()
	{
		vector<clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();

		string Tiltle = "\t Currencies List Screen";
		string SubTitle = "\t   (" + to_string(vCurrencies.size()) + ") Currency.";
		_DrawScreenHeader(Tiltle, SubTitle);

		cout << setw(6) << "" << "-----------------------------------------------------------";
		cout << "------------------------------------------------\n\n";
		cout << setw(6) << "" << "| " << left << setw(35) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/($1)";
		cout << "\n\n" << setw(6) << "" << "-----------------------------------------------------------";
		cout << "------------------------------------------------\n\n";
		
		if (vCurrencies.size() == 0)
		{
			cout << setw(20) << "" << "There Are No Currencies Avaialable in the System!.\n";
		}

		else
		{
			for (clsCurrency C : vCurrencies)
			{
				_PrintCurrencyLine(C);
				cout << endl;;

			}
		}

		cout << "\n" << setw(6) << "" << "-----------------------------------------------------------";
		cout << "------------------------------------------------\n\n";

	}

};

