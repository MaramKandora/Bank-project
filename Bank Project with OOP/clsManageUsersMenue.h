#pragma once
#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsUpdateUserScreen.h"
#include"clsInputValidate.h"
#include"clsUsersListScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsFindUserScreen.h"
using namespace std;


class clsManageUsersMenue:protected clsScreen
{
	enum enManageUsersOptions { eUsersList = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenue = 7
	};

	static short _ReadManageUsersOption()
	{
		cout << setw(37) << "" << "Choose what do you want to do? [1 to 7]? ";
		return clsInputValidate::ReadNumberBetween<short>(1, 7, "Enter Number between 1 and 7: ");

	}

	static void _GoBackToManageUsersMenue()
	{
		cout <<"\n\n"<< setw(37) << "" << "Press any key to go back to manage users menue...\n";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}

	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static void _ShowUsersListScreen()
	{
		clsUsersListScreen::ShowUsersListScreen();
	}



	static void _PerformMangeUsersOption(enManageUsersOptions Option)
	{
		switch (Option)
		{
		case enManageUsersOptions::eUsersList:
			system("cls");
			_ShowUsersListScreen();
			_GoBackToManageUsersMenue();
			break;

		case enManageUsersOptions::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
			
		case enManageUsersOptions::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case enManageUsersOptions::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case enManageUsersOptions::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;

		case enManageUsersOptions::eMainMenue:
		{
			//main menue will handle it
		}

		}


	}


public:

	static void ShowManageUsersMenue()
	{
		if (!_CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		system("cls");

		_DrawScreenHeader("\t Manage Users Screen");

		cout << "\n" << setw(37) << "" << "============================================\n";
		cout << setw(37) << "" << "\t\t  Manage Users Menue\n";
		cout << setw(37) << "" << "============================================\n";
		cout << setw(37) << "" << "   [1] Users List.\n";
		cout << setw(37) << "" << "   [2] Add New user.\n";
		cout << setw(37) << "" << "   [3] Delete User.\n";
		cout << setw(37) << "" << "   [4] Update User.\n";
		cout << setw(37) << "" << "   [5] Find User.\n";
		cout << setw(37) << "" << "   [6] Login Register.\n";
		cout << setw(37) << "" << "   [7] Main Menue.\n";
		cout << setw(37) << "" << "============================================\n";
		_PerformMangeUsersOption((enManageUsersOptions)_ReadManageUsersOption());
	}

};

