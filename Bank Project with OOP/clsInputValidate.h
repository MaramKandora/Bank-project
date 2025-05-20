#pragma once
#include<iostream>
#include "clsDate.h"
#include"clsPeriod.h"
using namespace std;

class clsInputValidate
{
public:


	template<typename T>

	static T IsNumberBetween(T Num, T From, T To)
	{

		return ((Num >= From) && (Num <= To)) ? true : false;

	}

	

	static bool IsDateBetween(clsDate Date, clsDate DateFrom, clsDate DateTo)
	{

		if (clsDate::isDate1AfterDate2(DateFrom, DateTo))
		{
			clsDate::Swap2Dates(DateFrom, DateTo);
		}

		return clsPeriod::IsDateWithinPeriod(Date, clsPeriod(DateFrom, DateTo));

	}


	template<typename T>
	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again: ")
	{
		T Number;

		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << ErrorMessage;
		}

		return Number;
	}

	
	template<typename T>

	static T ReadNumberBetween(T From, T To, string OutOfRangeMessage)
	{
		T Number = ReadNumber<T>();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << OutOfRangeMessage;
			cin >> Number;
		}

		return Number;
	}

	

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);

	}


	static string ReadString()
	{
		string S1;
		getline(cin >> ws, S1);

		return S1;
	}

	static char ReadChar()
	{
		char Ch;
		cin >> Ch;

		return Ch;
	}


};

