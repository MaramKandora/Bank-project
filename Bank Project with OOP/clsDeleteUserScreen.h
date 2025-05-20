#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsUtil.h"

using namespace std;

class clsDeleteUserScreen:protected clsScreen
{
	static void _PrintUser(clsUser User)
	{

		
		cout << "\nUser Card: ";
		cout << "\n________________________________________";
		cout << "\nFirstName   :" << User.FirstName;
		cout << "\nLastName    :" << User.LastName;
		cout << "\nFullName    :" << User.FullName();
		cout << "\nEmail       :" << User.Email;
		cout << "\nPhone       :" << User.Phone;
		cout << "\nUserName    :" << User.UserName;
		cout << "\nPassword    :" << User.Password;
		cout << "\nPermissions :" << User.Permissions;
		cout << "\n________________________________________\n";
	}


public:

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("\t Delete User Screen");

		string UserName = "";
		cout << "\nPlease Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::isUserExit(UserName))
		{
			cout << "\nUserName is Not Found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		cout << "\nAre you sure you want to delete this user? Y/N? ";
		char Answer = clsInputValidate::ReadChar();

		if (Answer == 'y' || Answer == 'Y')
		{
			if (User.Delete())
			{

				cout << "\nUser Deleted Successfully.\n\n";
				_PrintUser(User);

			}

			else
			{
				cout << "\n\nError, account was not deleted.\n";

			}
			
			



		}


	}

};

