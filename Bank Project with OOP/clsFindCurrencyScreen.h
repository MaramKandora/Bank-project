#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
using namespace std;


class clsFindCurrencyScreen:protected clsScreen
{
	enum enFindBy { enCode = 1, enCountry = 2 };

	static clsCurrency _FindAccordingToFindBy(enFindBy FindBy)
	{


		switch (FindBy)
		{
		case enFindBy::enCode:
		{
			cout << "\nPlease Enter CurrencyCode: ";
			string Code = clsInputValidate::ReadString();

			return clsCurrency::FindByCode(Code);
			break;
		}

		case enFindBy::enCountry:
		{
			cout << "\nPlease Enter Country Name: ";
			string Country = clsInputValidate::ReadString();

			return clsCurrency::FindByCountry(Country);
		}


		}


	}


	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card: \n";
		cout << "\n--------------------------------\n\n";
		cout << "Country     : " << Currency.Country() << "\n";
		cout << "Code        : " << Currency.CurrencyCode() << "\n";
		cout << "Name        : " << Currency.CurrencyName() << "\n";
		cout << "Rate/($1) = : " << Currency.GetRate() << "\n";
		cout << "\n--------------------------------\n";
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");

		cout << "\nFind By: [1] Code or [2] Country? ";
		short FindBy = clsInputValidate::ReadNumberBetween<short>(1, 2, "Enter Number Between 1 and 2 ? ");

		clsCurrency Currency1 = _FindAccordingToFindBy((enFindBy)FindBy);


		if (!Currency1.IsEmpty())
		{
			cout << "\n\nCurrency Found :-)\n ";
			_PrintCurrencyCard(Currency1);

		}

		else
		{
			cout << "\n\nCurrency was Not Found :-(\n ";
		}

	}
};

