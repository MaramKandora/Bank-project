#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"clsString.h"

using namespace std;

class clsCurrency
{
	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	enMode _Mode;

	static vector <clsCurrency> _LoadCurrenciesDataFromFile()
	{

		vector <clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				vCurrencies.push_back(_ConvertLineToCurrencyObject(Line));
			}

			MyFile.close();
		}

		return vCurrencies;

	}

	static clsCurrency _ConvertLineToCurrencyObject(string LineDate,string Seperator="#//#")
	{
		vector<string> vCurrency = clsString::Split(LineDate, Seperator);

		return clsCurrency(enMode::UpdateMode,vCurrency[0], vCurrency[1], vCurrency[2], stof(vCurrency[3]));

	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string Line = "";

		Line += Currency.Country() + Seperator;
		Line += Currency.CurrencyCode() + Seperator;
		Line += Currency.CurrencyName() + Seperator;
		Line += to_string(Currency.GetRate());

		return Line;

	}


	static void _SaveCurrenciesDataToFile(vector <clsCurrency>vCurrencies)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsCurrency& C : vCurrencies)
			{
				MyFile << _ConvertCurrencyObjectToLine(C) << endl;

			}

			MyFile.close();
		}

	}

	 void _Update()
	{
		vector<clsCurrency> _vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : _vCurrencies)
		{
			if (C.CurrencyCode() == _CurrencyCode)
			{
				C._Rate = this->_Rate;
				break;
			}

		}

		_SaveCurrenciesDataToFile(_vCurrencies);
		
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}


	
public:

	

	clsCurrency(enMode Mode, string Country, string Code, string Name, float Rate)
	{
		_Country = Country;
		_CurrencyCode = Code;
		_CurrencyName = Name;
		_Rate = Rate;
		_Mode = Mode;
	}


	string Country()
	{
		return _Country;
	}



	string CurrencyCode()
	{
		return _CurrencyCode;
	}


	string CurrencyName()
	{
		return _CurrencyName;
	}

	

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float GetRate()
	{
		return _Rate;
	}



	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}


	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllLetters(CurrencyCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency1 = _ConvertLineToCurrencyObject(Line);

				if (Currency1.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency1;
				}
			}

			MyFile.close();

			return _GetEmptyCurrencyObject();

		}


	}


	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllLetters(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsCurrency Currency1 = _ConvertLineToCurrencyObject(Line);

				if (clsString::UpperAllLetters(Currency1.Country()) == Country)
				{
					MyFile.close();
					return Currency1;
				}
			}

			MyFile.close();

			return _GetEmptyCurrencyObject();

		}


	}


	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);
		return !Currency.IsEmpty();
	}


	 float ConvertToUSD(float Amont)
	{
	
		 return float(Amont / GetRate());
	

	}



	float ConvertToOtherCurrency(clsCurrency CurrencyTo, float Amount)
	{

		if (this->CurrencyCode() == CurrencyTo.CurrencyCode())
		{
			return Amount;
		}

		
		float AmountInUSD;
		AmountInUSD = ConvertToUSD(Amount);

		if (CurrencyTo.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}
		

		return(float)(AmountInUSD * CurrencyTo.GetRate());

	

	}


	static vector<clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}
};

