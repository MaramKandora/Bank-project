#pragma once
#include <iostream>
#include"clsDate.h"
using namespace std;
class clsPeriod
{
	clsDate _StartDate;
	clsDate _EndDate;

public:

	clsPeriod()
	{

	}

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		_StartDate = StartDate;
		_EndDate = EndDate;
	}

	void SetStartDate(clsDate StartDate)
	{
		_StartDate = StartDate;

	}

	clsDate GetStartDate()
	{
		return _StartDate;
	}

	__declspec(property(get = GetStartDate, put = SetStartDate))clsDate StartDate;


	void SetEndDate(clsDate EndDate)
	{
		_EndDate = EndDate;

	}

	clsDate GetEndDate()
	{
		return _EndDate;
	}

	__declspec(property(get = GetEndDate, put = SetEndDate))clsDate EndDate;


	static clsPeriod ReadPeriod()
	{
		clsDate StartDate, EndDate;
		cout << "\nEnter Start Date:\n";
		StartDate = clsDate::ReadFullDate();

		cout << "\nEnter end date: \n";
		EndDate = clsDate::ReadFullDate();

		return clsPeriod(StartDate, EndDate);

	}

	void ReadP()
	{
		*this = ReadPeriod();
	}

	static void Print(clsPeriod Period)
	{
		cout << "Period Start: \n";
		clsDate::Print(Period.StartDate);
		cout << "\nPeriod End: \n";
		clsDate::Print(Period.EndDate);
	}
	void Print()
	{
		Print(*this);

		/*cout << "Period Start: \n";
		_StartDate.Print();
		cout << "\nPeriod End: \n";
		_EndDate.Print();*/

	}


	static bool isPeriodsOverlap(clsPeriod Period1, clsPeriod Period2)
	{


		if (
			clsDate::Compare2Dates(Period2.EndDate, Period1.StartDate) ==
			clsDate::Before
			||
			clsDate::Compare2Dates(Period2.StartDate, Period1.EndDate) ==
			clsDate::After
			)
			return false;
		else
			return true;


	}

	bool isPeriodsOverlap(clsPeriod Period2)
	{
		return isPeriodsOverlap(*this, Period2);
	}

	static int PeriodLengthInDays(clsPeriod Period, bool IncludingEndDay = false)
	{

		return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludingEndDay);

	}

	int LengthInDays(bool IncludingEndDay = false)
	{
		return PeriodLengthInDays(*this, IncludingEndDay);

	}



	static bool IsDateWithinPeriod(clsDate Date, clsPeriod Period)
	{

		return !(clsDate::Compare2Dates(Date, Period.StartDate) == clsDate::enCompare2Dates::Before
			|| clsDate::Compare2Dates(Date, Period.EndDate) == clsDate::enCompare2Dates::After);

	}

	bool IsDateWithinPeriod(clsDate Date)
	{
		return IsDateWithinPeriod(Date, *this);
	}


	static int CountOverlapingDays(clsPeriod Period1, clsPeriod Period2)
	{


		int Period1Length = PeriodLengthInDays(Period1, true);
		int Period2Length = PeriodLengthInDays(Period2, true);
		int DaysCount = 0;


		if (!isPeriodsOverlap(Period1, Period2))
		{
			return 0;
		}



		if (Period1Length < Period2Length)
		{
			while (clsDate::isDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
			{
				if (IsDateWithinPeriod(Period1.StartDate, Period2))
					DaysCount++;

				Period1.StartDate = clsDate::IncreaseDateByOneDay(Period1.StartDate);

			}


		}
		else
		{
			while (clsDate::isDate1BeforeDate2(Period2.StartDate, Period2.EndDate))
			{
				if (IsDateWithinPeriod(Period2.StartDate, Period1))
					DaysCount++;

				Period2.StartDate = clsDate::IncreaseDateByOneDay(Period2.StartDate);

			}


		}

		return DaysCount;

	}

	int CountOverlapingDays(clsPeriod Period2)
	{
		return CountOverlapingDays(*this, Period2);
	}



};

