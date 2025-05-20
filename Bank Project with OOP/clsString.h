#pragma once

#include <iostream>
#include<string>
#include <vector>
using namespace std;

class clsString
{
private:
	string _Value;

public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;

	}

	void SetValue(string Value)
	{
		_Value = Value;
	}

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(get = GetValue, put = SetValue))string Value;

	static short Length(string S1)
	{
		return S1.length();
	}
	short Length()
	{
		return _Value.length();
	}

	static short CountWords(string S1)
	{
		short Counter = 0;

		string delim = " ", sWord;

		short Pos = 0;

		while ((Pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, Pos);
			if (sWord != "")
			{
				Counter++;
			}
			S1.erase(0, Pos + delim.length());
		}
		if (S1 != "")
		{
			Counter++;

		}
		return Counter;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}

	static void PrintFirstLetterOfEachWord(string MyString)
	{
		bool isFirstLetter = true;

		cout << "\nFirst Letter of this string:\n";

		for (short i = 0; i < MyString.length(); i++)
		{
			if (MyString[i] != ' ' && isFirstLetter)
			{
				cout << MyString[i] << endl;
			}

			isFirstLetter = (MyString[i] == ' ') ? true : false;

		}



	}
	void PrintFirstLetterOfEachWord()
	{
		PrintFirstLetterOfEachWord(_Value);
	}

	static string UpperFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;


		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = toupper(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ') ? true : false;

		}

		return S1;

	}
	void UpperFirstLetterOfEachWord()
	{
		_Value = UpperFirstLetterOfEachWord(_Value);
	}

	static string LowerFirstLetterOfEachWord(string S1)
	{
		bool isFirstLetter = true;


		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && isFirstLetter)
			{
				S1[i] = tolower(S1[i]);

			}

			isFirstLetter = (S1[i] == ' ') ? true : false;

		}

		return S1;


	}
	void LowerFirstLetterOfEachWord()
	{
		_Value = LowerFirstLetterOfEachWord(_Value);
	}

	static string UpperAllLetters(string S1)
	{

		for (short i = 0; i < S1.length(); i++)
		{

			S1[i] = toupper(S1[i]);
		}

		return S1;

	}
	void UpperAllLetters()
	{
		_Value = UpperAllLetters(_Value);

	}

	static string LowerAllLetters(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = tolower(S1[i]);
		}
		return S1;
	}
	void LowerAllLetters()
	{
		_Value = LowerAllLetters(_Value);
	}

	static char InvertLetterCase(char Ch1)
	{

		return isupper(Ch1) ? tolower(Ch1) : toupper(Ch1);

	}

	static string InvertAllLettersCase(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	void InvertAllLettersCase()
	{
		_Value = InvertAllLettersCase(_Value);
	}

	static short CountCapitalLettersInString(string S1)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isupper(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountCapitalLettersInString()
	{
		return CountCapitalLettersInString(_Value);
	}

	static short CountSmallLettersInString(string S1)
	{
		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{
			if (islower(S1[i]))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountSmallLettersInString()
	{
		return CountSmallLettersInString(_Value);
	}

	enum enWhatToCount { SmallLetters = 1, CapitalLetters = 2, Punctuation = 3, Digit = 4, All = 5 };

	static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
	{

		short Counter = 0;

		for (short i = 0; i < S1.length(); i++)
		{

			if (S1[i] != ' ' && WhatToCount == enWhatToCount::All)
			{

				Counter++;

			}


			else if (isupper(S1[i]) && WhatToCount == enWhatToCount::CapitalLetters)
			{
				Counter++;

			}

			else if (islower(S1[i]) && WhatToCount == enWhatToCount::SmallLetters)
			{

				Counter++;

			}

			else if (ispunct(S1[i]) && WhatToCount == enWhatToCount::Punctuation)
			{

				Counter++;

			}

			else if (isdigit(S1[i]) && WhatToCount == enWhatToCount::Digit)
			{
				Counter++;

			}



		}

		return Counter;


	}
	short CountLetters(enWhatToCount WhatToCount)
	{
		return CountLetters(_Value, WhatToCount);
	}

	static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
	{
		short Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (MatchCase)
			{
				if (S1[i] == Letter)
				{
					Counter++;
				}
			}
			else
			{
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}
		}
		return Counter;
	}
	short CountSpecificLetter(char Letter, bool MatchCase = true)
	{
		return CountSpecificLetter(_Value, Letter, MatchCase);
	}

	static bool isVowel(char Letter)
	{
		Letter = tolower(Letter);

		return (Letter == 'a') || (Letter == 'o') || (Letter == 'i')
			|| (Letter == 'u') || (Letter == 'e');
	}

	static short CountVowels(string S1)
	{
		int Counter = 0;
		for (short i = 0; i < S1.length(); i++)
		{
			if (isVowel(S1[i]))
				Counter++;
		}
		return Counter;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static void PrintVowels(string S1)
	{
		cout << "\nVowels in the string are : ";
		for (short i = 0; i < S1.length(); i++)
		{
			if (isVowel(S1[i]))
				cout << S1[i] << "   ";
		}
		cout << endl;
	}
	void PrintVowels()
	{
		PrintVowels(_Value);
	}

	static void PrintEachWordInString(string S1)
	{
		string Delim = " ";

		cout << "\nYour String Words are: \n";

		string Sword = "";

		short pos = 0;

		while ((pos = S1.find(Delim)) != S1.npos)
		{
			Sword = S1.substr(0, pos);
			if (Sword != "")
			{
				cout << Sword << endl;
			}
			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
		{
			cout << S1 << endl;
		}
	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	static vector <string> Split(string S1, string delim)
	{
		vector <string> vS1;

		string sWord = "";
		short pos = 0;

		while ((pos = S1.find(delim)) != S1.npos)
		{
			sWord = S1.substr(0, pos);
			//if (sWord != "")
			//{
				vS1.push_back(sWord);
			//}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			vS1.push_back(S1);
		}
		return vS1;
	}
	vector <string> Split(string delim)
	{
		return Split(_Value, delim);
	}

	static string TrimLeft(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(i, S1.length() - i);

			}
		}
		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string S1)
	{
		for (short i = S1.length() - 1; i >= 0; i--)
		{
			if (S1[i] != ' ')
			{
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string S1)
	{
		return TrimLeft(TrimRight(S1));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}

	static string JoinString(vector<string>& vString, string delim)
	{
		string S1 = "";
		for (string& S : vString)
		{
			S1 = S1 + delim + S;
		}
		return S1.substr(delim.length(), S1.length() - delim.length());
	}

	static string JoinString(string arr[100], short arrLength, string delim)
	{
		string S1 = "";
		for (short i = 0; i < arrLength; i++)
		{
			S1 = S1 + arr[i] + delim;
		}
		return S1.substr(0, S1.length() - delim.length());
	}

	void Swap(string& S1, string& S2)
	{
		string temp = "";
		temp = S1;
		S1 = S2;
		S2 = temp;
	}

	static string ReverseWords(string S1)
	{
		vector<string>vString = Split(S1, " ");

		vector<string>::iterator iter = vString.end();

		string S2 = "";

		while (iter != vString.begin())
		{
			--iter;
			S2 += *iter + " ";
		}
		return (S2.substr(0, S2.length() - 1));
	}
	void ReverseWords()
	{
		_Value = ReverseWords(_Value);
	}

	////static string ReplaceWord(string S1, string StringToReplace, string SReplaceTo)
	//{
	//	short pos = S1.find(StringToReplace);

	//	while (pos != std::string::npos)
	//	{
	//		S1 = S1.replace(pos, StringToReplace.length(), SReplaceTo);
	//		pos = S1.find(StringToReplace);
	//	}
	//	return S1;
	//}
	////string ReplaceWord(string StringToReplace, string SReplaceTo)
	//{
	//	ReplaceWord(_Value, StringToReplace, SReplaceTo);
	//}

	static string ReplaceWord(string S1, string StringToReplace, string sReplaceTo, bool isMatchCase = true)

	{
		short pos = 0;

		pos = S1.find(StringToReplace);
		while (pos != std::string::npos)
		{
			S1.erase(pos, StringToReplace.length());
			S1.insert(pos, sReplaceTo);

			pos = S1.find(StringToReplace);
		}
		if (pos == std::string::npos && isMatchCase == false)
		{
			StringToReplace[0] = InvertLetterCase(StringToReplace[0]);

			pos = S1.find(StringToReplace);

			while (pos != std::string::npos)
			{
				S1.erase(pos, StringToReplace.length());
				S1.insert(pos, sReplaceTo);
				pos = S1.find(StringToReplace);
			}
		}
		return S1;
	}
	string ReplaceWord(string StringToReplace, string sReplaceTo, bool isMatchCase = true)
	{
		return ReplaceWord(_Value, StringToReplace, sReplaceTo, isMatchCase);
	}

	/*static string ReplaceStringUsingSplitFunction(string S1, string StringToReplace, string sReplaceTo, bool MatchCase = true)
	{
		vector<string>vString = SplitStringInVector(S1, " ");
		if (MatchCase)
		{
			for (string& S : vString)
			{
				if (S == StringToReplace)
					S = sReplaceTo;
			}
		}
		else
		{
			for (string& S : vString)
			{
				if (UpperFirstLettersOfEachWord(S) == UpperFirstLettersOfEachWord(StringToReplace))
					S = sReplaceTo;
			}

		}
		return JoinString(vString, " ");
	}
	string ReplaceStringUsingSplitFunction(string StringToReplace, string sReplaceTo, bool MatchCase = true)
	{
		return ReplaceStringUsingSplitFunction(_Value, StringToReplace, sReplaceTo, MatchCase);
	}*/

	static string RemovePunts(string S1)
	{
		for (short i = 0; i < S1.length(); i++)
		{
			if (ispunct(S1[i]))
			{
				S1.erase(i, 1);
			}
		}
		return S1;

	}
	void RemovePunts()
	{
		_Value = RemovePunts(_Value);
	}
};



