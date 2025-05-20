#pragma once
#include<iostream>
#include"clsScreen.h"
using namespace std;

class clsTransferLogScreen:protected clsScreen
{
	static void _PrintTransferLogRecord(clsBankClient::stTransferLogRecord Record)
	{
		cout << "\t| " << left << setw(25) << Record.Date_Time;
		cout << "| " << left << setw(12) << Record.SourceAccountNum;
		cout << "| " << left << setw(12) << Record.DestinationAccountNum;
		cout << "| " << left << setw(12) << Record.TransferAmount;
		cout << "| " << left << setw(12) << Record.SourceBalanceAfter;
		cout << "| " << left << setw(12) << Record.DestinationBalanceAfter;
		cout << "| " << left << setw(20) << Record.UserName;

	}

public:

	static void ShowTransferLogScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vTransferLogRecords =
			clsBankClient::GetTransferLogList();


		string Title = "\t Transfer Log List Screen";
		string SubTitle = "\t (" + to_string(vTransferLogRecords.size()) + ") Record(s).";
		_DrawScreenHeader(Title, SubTitle);

		cout << "\n" << setw(8) << "" << "-----------------------------------------------";
		cout << "---------------------------------------------------------\n\n";
		cout << "\t| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(12) << "S.Acct";
		cout << "| " << left << setw(12) << "D.Acct";
		cout << "| " << left << setw(12) << "Amount";
		cout << "| " << left << setw(12) << "S.Balance";
		cout << "| " << left << setw(12) << "D.Balance";
		cout << "| " << left << setw(20) << "User";
		cout << "\n" << setw(8) << "" << "-----------------------------------------------";
		cout << "---------------------------------------------------------\n\n";

		if (vTransferLogRecords.size() == 0)
		{
			cout << "\n" << setw(8) << "" << "No Transfer Operations has happened.\n ";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord Record : vTransferLogRecords)
			{
				_PrintTransferLogRecord(Record);
				
			};
		}

		cout << "\n" << setw(8) << "" << "-----------------------------------------------";
		cout << "---------------------------------------------------------\n\n";

	}



};

