#pragma once
#include<iostream>
using namespace std;

class InterfaceCommunication
{
public:
	virtual void SendEmail(string Tiltle, string Body) = 0;
	virtual void SendFax(string Tiltle, string Body) = 0;
	virtual void SendSMS(string Tiltle, string Body) = 0;

};

