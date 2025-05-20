#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"
using namespace std;


class clsScreen
{
protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        
        cout << "\n\tUser: "
            << CurrentUser.UserName;
        clsDate Date;
        cout << "\n\tDate: ";
        Date.Print();

        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
    }

    static bool _CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermissions(Permission))
        {

            cout << "\n" << setw(37) << "" << "----------------------------------------------------\n";
            cout << setw(37) << "" << "\t\t\tAccess Denied\n";
            cout << setw(37) << "" << "\t\tYou don`t have permission to this\n";
            cout << setw(37) << "" << "\t\t   Please contact your Admin.\n";
            cout << setw(37) << "" << "----------------------------------------------------\n";

            return false;
        }
        else
        {
            return true;
        }

    }

    


};

