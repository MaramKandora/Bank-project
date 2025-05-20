#pragma once
#include<iostream>
#include"clsPerson.h"
#include<vector>
#include<fstream>
#include<string>
#include"clsString.h"
#include"clsDate.h"
#include"clsUtil.h"

using namespace std;



class clsUser :public clsPerson
{
	enum enMode { enEmptyMode = 0, enUpdateMode = 1, enAddNewMode = 2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	short _Permissions;

	bool _MarkForDelete = false;

	static clsUser _ConvertLineToUserObject(string Line, string Seperator = "#//#")
	{
		vector<string>vUserData = clsString::Split(Line, Seperator);

		//Decrypt password after take it from file
	
		return clsUser(enMode::enUpdateMode, vUserData[0], vUserData[1],
			vUserData[2], vUserData[3], vUserData[4], clsUtil::DecryptText(vUserData[5]), stoi(vUserData[6]));

	}

	static string _ConvertUserObjectToLine(clsUser User, string Seperator = "#//#")
	{
		string UserRecord = "";

		//encrypt password before save it in the file

		UserRecord += User.FirstName + Seperator;
		UserRecord += User.LastName + Seperator;
		UserRecord += User.Email + Seperator;
		UserRecord += User.Phone + Seperator;
		UserRecord += User.UserName + Seperator;
		UserRecord += clsUtil::EncryptText(User.Password) + Seperator;
		UserRecord += to_string(User.Permissions);

		return UserRecord;

	}


	static vector<clsUser> _LoadUsersDataFromFile()
	{
		fstream MyFile;
		vector<clsUser>vUsers;

		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				vUsers.push_back(_ConvertLineToUserObject(Line));
			}

			MyFile.close();
		}

		return vUsers;

	}

	static void _SaveUserDataToFile(vector<clsUser> vUsers)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsUser U : vUsers)
			{
				if (U._MarkForDelete == false)
				{
					MyFile << _ConvertUserObjectToLine(U) << endl;
				}
			}

			MyFile.close();
		}


	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::enEmptyMode, "", "", "", "", "", "", 0);
	}

	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;
		vector<clsUser>vUsers;

		MyFile.open("Users.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;

			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	void _Update()
	{

		vector <clsUser>vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == _UserName)
			{
				
				U = *this;


				break;
			}
		}

		_SaveUserDataToFile(vUsers);


	}

	string _PrepareLoginRecord(string Seperator = "#//#")
	{

		return clsDate::GetSystemDateTimeString() + Seperator
			+ _UserName + Seperator
			+ clsUtil::EncryptText(_Password) + Seperator
			+ to_string(_Permissions);

	}

	struct stLoginRegisterRecord;

	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#")
	{
		stLoginRegisterRecord LoginRecord;

		vector <string> vLoginRegisterLine = clsString::Split(Line, Seperator);

		LoginRecord.Date_Time = vLoginRegisterLine[0];
		LoginRecord.UserName = vLoginRegisterLine[1];
		LoginRecord.Password = clsUtil::DecryptText(vLoginRegisterLine[2]);
		LoginRecord.Permissions = stoi(vLoginRegisterLine[3]);

		return LoginRecord;
	}





public:

	enum enPermissions {
		pAll = -1, pClientsList = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8,
		pFindClient = 16, pTransactionsMenue = 32, pManageUsers = 64, pLoginRegister = 128
	};

	struct stLoginRegisterRecord
	{
		string Date_Time;
		string UserName;
		string Password;
		short Permissions;

	};




	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Password, short Permissions)
		:clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;

	}


	void SetUserName(string UserName)
	{
		_UserName = UserName;

	}

	string GetUserName()
	{
		return _UserName;
	}

	__declspec(property(get = GetUserName, put = SetUserName))string UserName;


	void SetPermissions(short Permissions)
	{
		_Permissions = Permissions;

	}

	short GetPermissions()
	{
		return _Permissions;
	}

	__declspec(property(get = GetPermissions, put = SetPermissions))short Permissions;

	void SetPassword(string Password)
	{
		_Password = Password;
	}

	string GetPassword()
	{
		return _Password;
	}

	__declspec(property(get = GetPassword, put = SetPassword))string Password;

	bool isEmpty()
	{
		return(_Mode == enEmptyMode);
	}

	bool MarkedForDelete()
	{
		return _MarkForDelete;
	}

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if (User.UserName == UserName)
				{

					MyFile.close();
					return User;

				}


			}

			MyFile.close();

			return _GetEmptyUserObject();
		}

	}

	static clsUser Find(string UserName, string Password)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);

				if ((User.UserName == UserName) && (User._Password == Password))
				{

					MyFile.close();
					return User;

				}


			}

			MyFile.close();

			return _GetEmptyUserObject();
		}

	}

	static bool isUserExit(string UserName)
	{
		clsUser User = clsUser::Find(UserName);

		return !User.isEmpty();
	}




	bool Delete()
	{
		vector <clsUser>vUsers = _LoadUsersDataFromFile();

		for (clsUser& U : vUsers)
		{
			if (U.UserName == _UserName)
			{
				U._MarkForDelete = true;
				break;
			}
		}

		_SaveUserDataToFile(vUsers);

		*this = _GetEmptyUserObject();

		return true;

	}


	enum enSave { svFailedEmptyObject = 0, svSucceeded = 1, svFailedUserExists = 2 };

	enSave Save()
	{
		switch (_Mode)
		{

		case enMode::enEmptyMode:
		{
			if (isEmpty())
				return enSave::svFailedEmptyObject;
		}

		case enMode::enUpdateMode:
		{
			_Update();
			return enSave::svSucceeded;

		}


		case enMode::enAddNewMode:
		{
			if (isUserExit(_UserName))
			{
				return enSave::svFailedUserExists;
			}
			else
			{
				_AddNew();
				_Mode = enUpdateMode;
				return enSave::svSucceeded;
			}
			break;
		}

		}


	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::enAddNewMode, "", "", "", "", UserName, "", 0);
	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}


	bool CheckAccessPermissions(enPermissions MainMenuePermission)
	{
		if (this->Permissions == enPermissions::pAll)
		{
			return true;
		}

		return (this->Permissions & MainMenuePermission) == MainMenuePermission;

	}


	void LoginRegister()
	{
		string LoginRecordLine = _PrepareLoginRecord();


		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << LoginRecordLine << endl;
		}

		MyFile.close();

	}

	static vector<stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector<stLoginRegisterRecord> vLoginRegisterRecord;

		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;

			while (getline(MyFile, Line))
			{
				vLoginRegisterRecord.push_back(_ConvertLoginRegisterLineToRecord(Line));
			}

			MyFile.close();

		}

		return vLoginRegisterRecord;

	}


};

