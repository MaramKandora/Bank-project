#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
using namespace std;


class clsUpdateUserScreen :protected clsScreen
{

	static short _ReadPermissionsToSet()
	{
		char Answer = 'n';
		short Permissions = 0;
		cout << "\nDo you want to give full access? y/n?";
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			return -1;


		}
		else
		{
			cout << "\nDo you want to give access to: \n";

			cout << "\nShow Clients List? Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
				Permissions += clsUser::enPermissions::pClientsList;

			cout << "\nAdd New Client? Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
				Permissions += clsUser::enPermissions::pAddNewClient;

			cout << "\nDelete Client? Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
				Permissions += clsUser::enPermissions::pDeleteClient;

			cout << "\nUpdate Client? Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
				Permissions += clsUser::enPermissions::pUpdateClient;

			cout << "\nFind Client? Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
				Permissions += clsUser::enPermissions::pFindClient;

			cout << "\nTransactions? Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
				Permissions += clsUser::enPermissions::pTransactionsMenue;

			cout << "\nManage Users? Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
				Permissions += clsUser::enPermissions::pManageUsers;

			cout << "\nShow Login Register? Y/N? ";
			cin >> Answer;
			if (Answer == 'y' || Answer == 'Y')
				Permissions += clsUser::enPermissions::pLoginRegister;

		}

		return Permissions;

	}

	static void _ReadUserInfo(clsUser& User)
	{


		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		User.Permissions = _ReadPermissionsToSet();


	}

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


	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t Update User Screen");

		string UserName = "";
		cout << "Please Enter AccountNumber: ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::isUserExit(UserName))
		{
			cout << "\nUserName is not found, choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		char answer = 'n';
		cout << "\nAre you sure do you want to update this User? Y/N? ";
		answer = clsInputValidate::ReadChar();

		if (answer == 'y' || answer == 'Y')
		{


			cout << "\n\nUpdate User Info:";
			cout << "\n---------------------------\n";


			_ReadUserInfo(User);

			clsUser::enSave SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::svSucceeded:
			{
				cout << "\n\nAccount Updated Successfully.\n\n";
				_PrintUser(User);
				break;
			}

			case clsUser::svFailedEmptyObject:
				cout << "\nError, Account was not saved because it`s Empty.\n";
				break;
			}

		}
	}
};

