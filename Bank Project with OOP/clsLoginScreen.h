#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsMainScreen.h"

using namespace std;

class clsLoginScreen :protected clsScreen
{

	static bool _Login()
	{
		string UserName, Password;
		bool LoginFailed = false;
		short LoginFailedCounts = 0;

		do
		{
			system("cls");
			_DrawScreenHeader("\t    Login Screen");

			if (LoginFailed)
			{
				LoginFailedCounts++;

				cout << "\nInvalid UserName/Password!\n";
				cout << "You have " << 3 - LoginFailedCounts
					<< " Trials to Login.\n";
			}

			if (LoginFailedCounts == 3)
			{
				cout << "\nYou are Locked after 3 failed trials.\n";
				return false;
			}

			cout << "\nEnter UserName? ";
			UserName = clsInputValidate::ReadString();

			cout << "\nEnter Password? ";
			Password = clsInputValidate::ReadString();


			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailed = CurrentUser.isEmpty();
			

		} while (LoginFailed);

		CurrentUser.LoginRegister();

		clsMainScreen::ShowMainMenue();
		

	}



public:

	static bool ShowLoginScreen()
	{

		return _Login();

	}

};

