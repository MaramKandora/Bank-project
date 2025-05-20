#pragma once
#pragma warning (disable : 4996)
#include <iostream>
#include<string>
#include"clsString.h"
using namespace std;

class clsDate
{

private:

	
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:

	clsDate()
	{

		time_t t = time(0);

		tm* Now = localtime(&t);

		_Day = Now->tm_mday;
		_Month = Now->tm_mon + 1;
		_Year = Now->tm_year + 1900;
		
	}

	clsDate(string Date)
	{
		*this = StringToDate(Date);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;

	}

	clsDate(short DayOrder, short Year)
	{
		*this = GetDateFromDayOrderInYear(DayOrder, Year);
	}





	void SetDay(short Day)
	{
		_Day = Day;

	}
	short GetDay()
	{
		return _Day;
	}

	__declspec(property(get = GetDay, put = SetDay))short Day;

	void SetMonth(short Month)
	{
		_Month = Month;

	}
	short GetMonth()
	{
		return _Month;
	}

	__declspec(property(get = GetMonth, put = SetMonth))short Month;

	void SetYear(short Year)
	{
		_Year = Year;

	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear))short Year;





	static short ReadNumber(string Message)
	{
		short Year;
		cout << Message;
		cin >> Year;

		return Year;

	}

	static clsDate ReadFullDate()
	{

		short Day, Month, Year;

		Day = ReadNumber("\nPlease enter a Day ? ");
		Month = ReadNumber("Please enter a Month ? ");
		Year = ReadNumber("Please enter a year? ");


		return clsDate(Day, Month, Year);

	}


	static void Print(clsDate Date)
	{
		cout << DateToString(Date) << endl;
	}
	void Print()
	{
		Print(*this);
	}


	static clsDate GetSystemDate()
	{
		short Day, Month, Year;

		time_t t = time(0);

		tm* Now = localtime(&t);

		Day = Now->tm_mday;
		Month = Now->tm_mon + 1;
		Year = Now->tm_year + 1900;


		return clsDate(Day, Month, Year);

	}

	static bool isLeapYear(short Year)
	{
		//we say year is leap when its perfectly divisible by 400, or Perfectlty divisible by 4 provided that its not a century year
		return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
	}
	bool isLeapYear()
	{
		return isLeapYear(_Year);

	}

	static int NumberOfDaysInYear(short Year)
	{

		return (isLeapYear(Year) ? 366 : 365);

	}
	int NumberOfDaysInYear()
	{

		return NumberOfDaysInYear(_Year);

	}

	static int NumberOfHoursInYear(short Year)
	{

		return NumberOfDaysInYear(Year) * 24;

	}
	int NumberOfHoursInYear()
	{

		return NumberOfHoursInYear(_Year);

	}

	static int NumberOfMinutesInYear(short Year)
	{

		return NumberOfHoursInYear(Year) * 60;

	}
	int NumberOfMinutesInYear()
	{

		return NumberOfMinutesInYear(_Year);

	}

	static int NumberOfSecondsInYear(short Year)
	{

		return NumberOfMinutesInYear(Year) * 60;

	}
	int NumberOfSecondsInYear()
	{

		return NumberOfSecondsInYear(_Year);

	}

	static short NumberOfDaysInMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;

		int NumberOfDays[12] = { 31,28,30,31,30,31,30,31,30,31,30,31 };



		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : (NumberOfDays[Month - 1]);

	}
	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static short NumberOfHoursInMonth(short Month, short Year)
	{
		return NumberOfDaysInMonth(Month, Year) * 24;

	}
	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Month, _Year);

	}


	static int NumberOfMinutesInMonth(short Month, short Year)
	{
		return NumberOfHoursInMonth(Month, Year) * 60;

	}
	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Month, _Year);

	}

	static int NumberOfSecondsInMonth(short Month, short Year)
	{
		return NumberOfMinutesInMonth(Month, Year) * 60;

	}
	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Month, _Year);

	}

	static short CalculateDayOrderInWeek(short NumberOfDay, short NumberOfMonth, short NumberOfYear)
	{
		short a = (14 - NumberOfMonth) / 12;
		short y = NumberOfYear - a;
		short m = NumberOfMonth + 12 * a - 2;

		//For the Gregorian calender

		short d = (NumberOfDay + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		//the value of d is 0 for sunday,1 for monday,3 for tuesday...etc

		return d;

	}
	short CalculateDayOrderInWeek()
	{
		return CalculateDayOrderInWeek(_Day, _Month, _Year);

	}

	static string GetDayShortName(short DayOrderInWeek)
	{

		string arrDayName[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };


		return arrDayName[DayOrderInWeek];



	}
	string GetDayShortName()
	{

		return GetDayShortName(CalculateDayOrderInWeek());



	}

	static string GetMonthName(short Month)
	{

		string arrDayName[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };


		return arrDayName[Month - 1];



	}
	string GetMonthName()
	{

		return GetMonthName(_Month);

	}

	static void PrintMonthCalender(short Month, short Year)
	{
		//get the order of the first day in the month 0 to 6 (Sun to Sat)
		short Current = CalculateDayOrderInWeek(1, Month, Year);

		short MonthDays = NumberOfDaysInMonth(Month, Year);

		cout << "\n--------------------" << GetMonthName(Month) << "---------------------\n\n";

		printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");

		//print appropriate distance according to day order
		short i;
		for (i = 0; i < Current; i++)
		{
			printf("     ");

		}


		for (short j = 1; j <= MonthDays; j++)
		{

			printf("%5d", j);


			if ((i++) == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		cout << "\n\n-----------------------------------------------\n";




	}
	void PrintMonthCalender()
	{
		PrintMonthCalender(_Month, _Year);


	}

	static void PrintYearCalender(short Year)
	{
		printf("-----------------------------------------\n\n");
		printf("            Calender - %d\n\n", Year);
		printf("-----------------------------------------\n\n");


		for (short i = 1; i <= 12; i++)
		{

			PrintMonthCalender(i, Year);

		}



	}
	void PrintYearCalender()
	{
		PrintYearCalender(_Year);

	}

	static unsigned int NumberOfDaysFromTheBegenningOfYear(short Day, short Month, short Year)
	{

		unsigned int Counter = 0;

		for (short i = 1; i <= Month - 1; i++)
		{
			Counter += NumberOfDaysInMonth(i, Year);

		}


		if (Day >= 1 && Day <= 31)
			return Counter + Day;

		else
			return Counter;

	}
	unsigned int NumberOfDaysFromTheBegenningOfYear()
	{

		return NumberOfDaysFromTheBegenningOfYear(_Day, _Month, _Year);

	}


	clsDate GetDateFromDayOrderInYear(short DayOrderInYear, short Year)
	{

		clsDate Date;
		short RemainingDays = DayOrderInYear;
		short MonthDays;


		Date.Year = Year;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Date.Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}

			else
			{
				Date.Day = RemainingDays;
				break;

			}



		}

		return Date;

	}



	static clsDate DateAddDays(short Days, clsDate& Date)
	{
		short RemainingDays = Days + NumberOfDaysFromTheBegenningOfYear(Date.Day, Date.Month, Date.Year);

		short MonthDays = 0;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;

				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;

				}

			}

			else
			{
				Date.Day = RemainingDays;
				break;

			}




		}


		return Date;


	}
	void DateAddDays(short Days)
	{
		DateAddDays(Days, *this);

	}

	static bool isDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{

		return (Date1.Year < Date2.Year) ? true :
			(Date1.Year == Date2.Year ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? (Date1.Day < Date2.Day) : false)) : false);

	}
	bool isDateBeforeDate2(clsDate Date2)
	{
		return isDate1BeforeDate2(*this, Date2);
	}


	static bool isDate1EqualsDate2(clsDate Date1, clsDate Date2)
	{


		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false) : false;


	}
	bool isDateEqualsDate2(clsDate Date2)
	{
		return isDate1BeforeDate2(*this, Date2);
	}

	static bool isLastDayInMonth(clsDate Date)
	{


		return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));


	}
	bool isLastDayInMonth()
	{
		return isLastDayInMonth(*this);
	}


	static bool isLastMonthInYear(short Month)
	{
		return (Month == 12);
	}
	bool isLastMonthInYear()
	{
		return isLastMonthInYear(_Month);
	}

	static clsDate IncreaseDateByOneDay(clsDate Date)
	{

		if (isLastDayInMonth(Date))
		{
			if (isLastMonthInYear(Date.Month))
			{

				Date.Day = 1;
				Date.Month = 1;
				Date.Year++;


			}

			else
			{
				Date.Day = 1;
				Date.Month++;


			}

		}
		else
		{
			Date.Day++;

		}


		return Date;
	}
	void IncreaseDateByOneDay()
	{
		*this = IncreaseDateByOneDay(*this);

	}


	static void Swap2Dates(clsDate& Date1, clsDate& Date2)
	{
		clsDate DateTemp;

		DateTemp.Day = Date1.Day;
		DateTemp.Month = Date1.Month;
		DateTemp.Year = Date1.Year;

		Date1.Day = Date2.Day;
		Date1.Month = Date2.Month;
		Date1.Year = Date2.Year;

		Date2.Day = DateTemp.Day;
		Date2.Month = DateTemp.Month;
		Date2.Year = DateTemp.Year;
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludingEndDay = false)
	{
		int Days = 0;
		int SwapFlagValue = 1;

		if (!isDate1BeforeDate2(Date1, Date2))
		{
			Swap2Dates(Date1, Date2);

			SwapFlagValue = -1;

		}

		while (isDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);

		}

		return (IncludingEndDay) ? ((Days >= 0) ? ++Days : --Days) : Days;


	}
	int GetDifferenceInDays(clsDate Date2, bool IncludingEndDay = false)
	{
		return GetDifferenceInDays(*this, Date2, IncludingEndDay);
	}

	static short CalculateMyAgeInDays(clsDate DateOfBirt)
	{
		return GetDifferenceInDays(GetSystemDate(), DateOfBirt, true);

	}

	static clsDate IncreaseDateByXDays(clsDate Date, short DaysToAdd)
	{
		for (short i = 1; i <= DaysToAdd; i++)
		{
			Date = IncreaseDateByOneDay(Date);

		}

		return Date;

	}
	void IncreaseDateByXDays(short DaysToAdd)
	{
		*this = IncreaseDateByXDays(*this, DaysToAdd);
	}


	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		for (short i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}

		return Date;

	}
	void IncreaseDateByOneWeek()
	{
		*this = IncreaseDateByOneWeek(*this);
	}


	static clsDate IncreaseDateByXWeeks(clsDate Date, short WeeksToAdd)
	{
		for (short i = 1; i <= WeeksToAdd; i++)
		{
			Date = IncreaseDateByOneWeek(Date);

		}

		return Date;

	}
	void IncreaseDateByXWeeks(short WeeksToAdd)
	{
		*this = IncreaseDateByXWeeks(*this, WeeksToAdd);
	}


	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{

		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;

		}
		else
		{
			Date.Month++;
		}


		//adding one month to for exapmle 31/1/2001 would be 31/2/2001 and thats wrong so we should fix that with the follows code

		short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (Date.Day > NumberOfDaysInCurrentMonth)
		{
			Date.Day = NumberOfDaysInCurrentMonth;
		}



		return Date;
	}
	void IncreaseDateByOneMonth()
	{
		*this = IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate Date, short MonthsToAdd)
	{
		for (short i = 1; i <= MonthsToAdd; i++)
		{

			Date = IncreaseDateByOneMonth(Date);

		}

		return Date;
	}
	void IncreaseDateByXMonths(short MonthsToAdd)
	{
		*this = IncreaseDateByXMonths(*this, MonthsToAdd);
	}

	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date.Year++;

		return Date;


	}
	void IncreaseDateByOneYear()
	{
		*this = IncreaseDateByOneYear(*this);
	}



	static clsDate IncreaseDateByXYears(clsDate Date, short YearsToAdd)
	{


		Date.Year += YearsToAdd;

		return Date;

	}
	void IncreaseDateByXYears(short YearsToAdd)
	{
		*this = IncreaseDateByXYears(*this, YearsToAdd);

	}

	static clsDate IncreaseDateByOneDecade(clsDate Date)
	{

		Date.Year += 10;

		return Date;

	}
	void IncreaseDateByOneDecade()
	{
		*this = IncreaseDateByOneDecade(*this);
	}


	static clsDate IncreaseDateByXDecades(clsDate Date, short DecadesToAdd)
	{

		Date.Year += DecadesToAdd * 10;

		return Date;

	}
	void IncreaseDateByXDecades(short DecadesToAdd)
	{
		*this = IncreaseDateByXDecades(*this, DecadesToAdd);
	}

	static clsDate IncreaseDateByOneCentury(clsDate Date)
	{
		Date.Year += 100;

		return Date;

	}
	void IncreaseDateByOneCentury()
	{
		*this = IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillinnium(clsDate Date)
	{

		Date.Year += 1000;

		return Date;

	}
	void IncreaseDateByOneMillinnium()
	{
		*this = IncreaseDateByOneMillinnium(*this);
	}


	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date.Day == 1)
		{
			if (Date.Month == 1)
			{
				Date.Year--;
				Date.Month = 12;
				Date.Day = 31;

			}
			else
			{
				Date.Month--;
				Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
			}

		}
		else
		{
			Date.Day--;
		}


		return Date;

	}
	void DecreaseDateByOneDay()
	{
		*this = DecreaseDateByOneDay(*this);
	}


	static clsDate DecreaseDateByXDay(clsDate Date, short DaysToSubtract)
	{

		for (short i = 1; i <= DaysToSubtract; i++)
		{
			Date = DecreaseDateByOneDay(Date);

		}

		return Date;


	}
	void DecreaseDateByXDay(short DaysToSubtract)
	{
		*this = DecreaseDateByXDay(*this, DaysToSubtract);

	}


	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{

		for (short i = 1; i <= 7; i++)
		{

			Date = DecreaseDateByOneDay(Date);

		}

		return Date;
	}
	void DecreaseDateByOneWeek()
	{

		*this = DecreaseDateByOneWeek(*this);


	}



	static clsDate DecreaseDateByXWeeks(clsDate Date, short WeeksToSubtract)
	{

		for (short i = 1; i <= WeeksToSubtract; i++)
		{

			Date = DecreaseDateByOneWeek(Date);

		}

		return Date;

	}
	void DecreaseDateByXWeeks(short WeeksToSubtract)
	{

		*this = DecreaseDateByXWeeks(*this, WeeksToSubtract);


	}


	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{

		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;

		}
		else
		{
			Date.Month--;


			short DaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);


			if (Date.Day > DaysInCurrentMonth)
			{
				Date.Day = DaysInCurrentMonth;

			}
		}

		return Date;


	}
	void DecreaseDateByOneMonth()
	{
		*this = DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate Date, short MonthToSubtract)
	{
		for (short i = 1; i <= MonthToSubtract; i++)
		{
			Date = DecreaseDateByOneMonth(Date);

		}

		return Date;

	}
	void DecreaseDateByXMonths(short MonthToSubtract)
	{
		*this = DecreaseDateByXMonths(*this, MonthToSubtract);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date)
	{


		Date.Year--;

		if (Date.Month == 2 && Date.Day == 29 && !isLeapYear(Date.Year))
		{
			Date.Day = 28;
		}

		return Date;


	}
	void DecreaseDateByOneYear()
	{
		*this = DecreaseDateByOneYear(*this);

	}


	static clsDate DecreaseDateByXYears(clsDate Date, short YearsToSubtract)
	{


		Date.Year -= YearsToSubtract;

		if (Date.Month == 2 && Date.Day == 29 && !isLeapYear(Date.Year))
		{
			Date.Day = 28;
		}

		return Date;

	}
	void DecreaseDateByXYears(short YearsToSubtract)
	{
		*this = DecreaseDateByXYears(*this, YearsToSubtract);

	}


	static clsDate DecreaseDateByOneDecade(clsDate Date)
	{
		Date.Year -= 10;

		if (Date.Month == 2 && Date.Day == 29 && !isLeapYear(Date.Year))
		{
			Date.Day = 28;
		}

		return Date;



	}
	void DecreaseDateByOneDecade()
	{
		*this = DecreaseDateByOneDecade(*this);

	}



	static clsDate DecreaseDateByXDecades(clsDate Date, short DecadesToSubtract)
	{
		Date.Year -= DecadesToSubtract * 10;

		if (Date.Month == 2 && Date.Day == 29 && !isLeapYear(Date.Year))
		{
			Date.Day = 28;
		}

		return Date;

	}
	void DecreaseDateByXDecades(short DecadesToSubtract)
	{
		*this = DecreaseDateByXDecades(*this, DecadesToSubtract);


	}




	static clsDate DecreaseDateByOneCentury(clsDate Date)
	{
		Date.Year -= 100;

		if (Date.Month == 2 && Date.Day == 29 && !isLeapYear(Date.Year))
		{
			Date.Day = 28;
		}

		return Date;



	}
	void DecreaseDateByOneCentury()
	{
		*this = DecreaseDateByOneCentury(*this);

	}

	static clsDate DecreaseDateByOneMillinnium(clsDate Date)
	{

		Date.Year -= 1000;

		if (Date.Month == 2 && Date.Day == 29 && !isLeapYear(Date.Year))
		{
			Date.Day = 28;
		}

		return Date;


	}
	void DecreaseDateByOneMillinnium()
	{
		*this = DecreaseDateByOneMillinnium(*this);


	}

	static short CalculateDayOrderInWeek(clsDate Date)
	{
		return  CalculateDayOrderInWeek(Date.Day, Date.Month, Date.Year);
	}

	static bool isWeekend(clsDate Date)
	{
		//weekend are Fri and Sat
		short DayOrder = CalculateDayOrderInWeek(Date);

		return DayOrder == 6 || DayOrder == 5;


	}

	bool isWeekend()
	{
		return isWeekend(*this);

	}

	static bool isBusinessDay(clsDate Date)
	{

		return !isWeekend(Date);

	}
	bool isBusinessDay()
	{
		return isBusinessDay(*this);
	}

	static short DaysUntilEndOfWeek(clsDate Date)
	{

		return 6 - CalculateDayOrderInWeek(Date);


	}
	short DaysUntilEndOfWeek()
	{
		return DaysUntilEndOfWeek(*this);
	}

	static short DaysUntilEndOfMonth(clsDate Date)
	{

		clsDate EndOfMontDate;
		EndOfMontDate.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		EndOfMontDate.Month = Date.Month;
		EndOfMontDate.Year = Date.Year;
		return GetDifferenceInDays(Date, EndOfMontDate, true);

	}
	short DaysUntilEndOfMonth()
	{
		return DaysUntilEndOfMonth(*this);
	}

	static short DaysUntilEndOfYear(clsDate Date)
	{
		clsDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;
		return GetDifferenceInDays(Date, EndOfYearDate, true);

	}

	short DaysUntilEndOfYear()
	{
		return DaysUntilEndOfYear(*this);
	}

	static short VacationActualDays(clsDate StartDate, clsDate EndDate)
	{
		short DaysCounter = 0;


		if (!isDate1BeforeDate2(StartDate, EndDate))
		{
			Swap2Dates(StartDate, EndDate);

		}



		while (!isDate1EqualsDate2(StartDate, EndDate))
		{

			if (isBusinessDay(StartDate))
			{
				DaysCounter++;

			}

			StartDate = DateAddDays(1, StartDate);

		}

		return DaysCounter;

	}



	static clsDate VacationReturnDate(clsDate StartDate, short VacationDays)
	{

		while (VacationDays > 0)
		{
			if (isBusinessDay(StartDate))
			{
				VacationDays--;
			}

			StartDate = DateAddDays(1, StartDate);

		}

		return StartDate;

	}


	static clsDate CalculateVacationReturnDate(clsDate StartDate, short VacationDays)
	{
		short WeekendCounter = 0;

		//in case Date is weekend we keep adding one day until we reach the first business day
		//we get rid of all weekends befor the first business day
		while (isWeekend(StartDate))
		{
			StartDate = DateAddDays(1, StartDate);
		}


		//here we increase the vacation date to add all weekends to it
		for (short i = 1; i <= VacationDays + WeekendCounter; i++)
		{
			if (isWeekend(StartDate))
				WeekendCounter++;

			StartDate = DateAddDays(1, StartDate);
		}

		//if the return date is weekend we should keep adding days until we reach business day
		while (isWeekend(StartDate))
		{
			StartDate = DateAddDays(1, StartDate);
		}



		return StartDate;
	}

	static bool isDate1AfterDate2(clsDate Date1, clsDate Date2)
	{

		return (!isDate1BeforeDate2(Date1, Date2) && !isDate1EqualsDate2(Date1, Date2));


	}
	bool isDateAfterDate2(clsDate Date2)
	{
		return isDate1AfterDate2(*this, Date2);
	}


	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);

	}
	string DateToString()
	{
		return DateToString(*this);
	}

	static clsDate StringToDate(string DateText, string Delim = "/")
	{
		vector <string> vDate = clsString::Split(DateText, Delim);

		clsDate Date;

		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;

	}


	static bool IsValidDate(clsDate Date)
	{

		return (Date.Day <= 0 || Date.Month <= 0 || Date.Year <= 0) ? false : ((Date.Month > 12) ? false :
			(Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year) ? false : true));


	}
	bool IsValid()
	{
		return IsValidDate(*this);
	}


	enum enCompare2Dates { Before = -1, Equals = 0, After = 1 };


	static enCompare2Dates Compare2Dates(clsDate Date1, clsDate Date2)
	{
		//return values: 1 if Date1 Before Date2 , -1 if Date1 After Date2 , 0 if Date1 Equals Date2

		return isDate1BeforeDate2(Date1, Date2) ? enCompare2Dates::Before : (isDate1AfterDate2(Date1, Date2) ? enCompare2Dates::After : enCompare2Dates::Equals);


	}

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* Now = localtime(&t);

		short Second, Minute, Hour, Day, Month, Year;

		Second = Now->tm_sec;
		Minute = Now->tm_min;
		Hour = Now->tm_hour;
		Day = Now->tm_mday;
		Month = Now->tm_mon + 1;
		Year = Now->tm_year + 1900;


		return to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year)
			+ " - " +
			to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second);


	}
	

};

