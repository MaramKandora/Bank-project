#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"Global.h"
using namespace std;

class clsUpdateCurrencyRateScreen:protected clsScreen
{

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

	static float _ReadRate()
	{
		float NewRate = 0;

		cout << "Enter New Rate: ";
		NewRate = clsInputValidate::ReadNumber<float>();

		 return NewRate;


	}


public:

	static void _ShowUpdateCurrencyRateScreen()
	{
		if (CurrentUser.UserName != "Admin")
		{
			cout << "\n" << setw(35) << "" << "Only Admins have permission to this.";
			return;
		}


		_DrawScreenHeader("\t Update Currency Screen");
	
		cout << "\nPlease Enter Currency Code? ";
		string Code = clsInputValidate::ReadString();

		

		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "\nCurrency is not found, choose another one: ";
			Code = clsInputValidate::ReadString();

		}

		clsCurrency Currency1 = clsCurrency::FindByCode(Code);

		
		_PrintCurrencyCard(Currency1);

		cout << "\nAre you sure do you want to update the rate of this Currency? Y/N? ";
		char Answer = clsInputValidate::ReadChar();

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n\nUpdate Currency Rate: \n";
			cout << "\n----------------------\n\n";
			Currency1.UpdateRate(_ReadRate());

			cout << "\n\nCurrency Rate Updated Seccessfully.\n";
			_PrintCurrencyCard(Currency1);
		}



	}
};

