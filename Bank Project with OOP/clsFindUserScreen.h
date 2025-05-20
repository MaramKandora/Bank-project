#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

using namespace std;
class clsFindUserScreen:protected clsScreen
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

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\t Find User Screen");

		string UserName = "";
		cout << "Please Enter UserName: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::isUserExit(UserName))
		{
			cout << "\nUserName is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);

		if (!User1.isEmpty())
		{
			cout << "\nUser Found :-)\n\n";
		}
		else
		{
			cout << "\nUser was not found :-(\n\n";
		}
		
		_PrintUser(User1);


	}

};

