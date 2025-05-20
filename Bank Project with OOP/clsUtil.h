#pragma once
#include<iostream>
#include"clsDate.h"
#include"fstream"
using namespace std;


class clsUtil
{
public:

	enum enCharType { CapitalLetter = 1, SmallLetter = 2, Digit = 3, SpecialCharacter = 4, MixChars = 5 };

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{

		return rand() % (To - From + 1) + From;

	}

	static char GetRandomChar(enCharType CharType)
	{
		if (CharType == enCharType::CapitalLetter)
		{
			CharType = (enCharType)RandomNumber(1, 3);
		}


		switch (CharType)
		{
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));

		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));

		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
	defualt:
		{
			return char(RandomNumber(65, 90));
			break;
		}

		}


	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		string Word = "";

		for (short i = 0; i < Length; i++)
		{
			Word += GetRandomChar(CharType);
		}

		return Word;
	}

	static string GenerateKey(enCharType CharType = CapitalLetter)
	{
		string Key = "";
		Key = GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4) + "-";
		Key += GenerateWord(CharType, 4);

		return Key;

	}

	static void GenerateKeys(short NumberOfKeys, enCharType CharType)
	{
		for (short i = 0; i < NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey(CharType) << endl;
		}

	}

	static void Swap(int& Num1, int& Num2)
	{
		int temp;
		temp = Num1;
		Num1 = Num2;
		Num2 = temp;

	}

	static void Swap(double& Num1, double& Num2)
	{
		double temp;
		temp = Num1;
		Num1 = Num2;
		Num2 = temp;

	}

	static void Swap(string& S1, string& S2)
	{
		string temp;
		temp = S1;
		S1 = S2;
		S2 = temp;

	}

	static void Swap(char& Char1, char& Char2)
	{
		char temp;
		temp = Char1;
		Char1 = Char2;
		Char2 = temp;

	}

	static void Swap(bool& A, bool& B)
	{
		bool temp;
		temp = A;
		A = B;
		B = temp;

	}

	static void Swap(clsDate& Date1, clsDate& Date2)
	{
		clsDate::Swap2Dates(Date1, Date2);

	}

	static void ShuffleArray(int arr[], int ArrLength)
	{

		for (int i = 0; i < ArrLength; i++)
			Swap(arr[RandomNumber(0, ArrLength) - 1], arr[RandomNumber(0, ArrLength - 1)]);


	}

	static void ShuffleArray(string arr[], int ArrLength)
	{

		for (int i = 0; i < ArrLength; i++)
			Swap(arr[RandomNumber(1, ArrLength) - 1], arr[RandomNumber(0, ArrLength - 1)]);


	}

	static void PrintArray(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{

			cout << arr[i] << " ";

		}

		cout << endl;


	}

	static void PrintArray(string  arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{

			cout << arr[i] << " ";

		}

		cout << endl;


	}

	static void FillArrayWithRandomNumbers(int Arr[], int& ArrLength, int From, int To)
	{
		cout << "Enter Number Of Elements?\n";
		cin >> ArrLength;

		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = RandomNumber(From, To);

		}


	}

	static void FillArrayWithRandomWords(string Arr[], int& ArrLength, enCharType CharType, short Length)
	{
		cout << "Enter Number Of Elements?\n";
		cin >> ArrLength;

		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = GenerateWord(CharType, Length);

		}


	}

	static void FillArrayWithRandomKeys(string Arr[], int& ArrLength, enCharType CharType)
	{
		cout << "Enter Number Of Elements?\n";
		cin >> ArrLength;

		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = GenerateKey(CharType);

		}


	}

	static string Tabs(short NumberOfTabs)
	{
		string Tabs;
		for (short i = 1; i <= NumberOfTabs; i++)
		{
			Tabs += "\t";
		}
		return Tabs;
	}

	static string EncryptText(string Text, short EncryptionKey = 3)
	{

		for (int i = 0; i < Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);

		}

		return Text;

	}

	static string DecryptText(string Text, short EncryptionKey = 3)
	{
		for (int i = 0; i < Text.length(); i++)
		{

			Text[i] = char((int)Text[i] - EncryptionKey);

		}

		return Text;

	}



	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}


};

