#pragma once
#include<iostream>
#include "clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
using namespace std;

class clsCurrecncyCalculatorScreen:protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card: ")
	{
		cout << "\n" << Title << "\n";
		cout << "\n--------------------------------\n\n";
		cout << "Country     : " << Currency.Country() << "\n";
		cout << "Code        : " << Currency.CurrencyCode() << "\n";
		cout << "Name        : " << Currency.CurrencyName() << "\n";
		cout << "Rate/($1) = : " << Currency.GetRate() << "\n";
		cout << "\n--------------------------------\n\n";
	}


	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;

		cout << Message;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency with code [" << CurrencyCode << "] was Not Found\n";
			cout << "Enter another Currency Code: ";
			CurrencyCode = clsInputValidate::ReadString();

		}

		return clsCurrency::FindByCode(CurrencyCode);

	}

	static float _ReadAmount()
	{
		float Amount;

		cout << "\nEnter Amount To Exchange: ";
		Amount = clsInputValidate::ReadNumber<float>();

		return Amount;
	}


	static void _PrintCalculationResult(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{

		_PrintCurrencyCard(CurrencyFrom, "Convert From: ");


		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< AmountInUSD << " USD\n";

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return;
		}

	
		cout << "\n\nConverting From USD to:\n";
		
		_PrintCurrencyCard(CurrencyTo, "To: ");

		float AmountInCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(CurrencyTo, Amount);

		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< AmountInCurrencyTo << " " << CurrencyTo.CurrencyCode() << "\n";




	}


public: 
	static void ShowCurrencyCalculatorScreen()
	{
		char Continue = 'N';

		do
		{
			system("cls");

			_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code: ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code: ");
			float Amount = _ReadAmount();

			
			_PrintCalculationResult(CurrencyFrom, CurrencyTo, Amount);

			cout << "\n\nDo you want to perform another Calculation? Y/N? ";
			cin >> Continue;

		} while (Continue == 'y' || Continue == 'Y');
	}
};

