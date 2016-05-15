
\\



#include "stdafx.h"
#include<iostream>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
class account {
private:
	int money;
	string nameUser;
	int password;
	string Statement;

public:
	account(string name, int initMoney, int pwdPin);
	//void createAccount();
	int CheckMoney(void);
	void addToMoney(int amount);
	void SubtractMoney(int amount);
	int pwdCompare(int p);
	string BankStatement(void);
};
int account::pwdCompare(int p) {
	if (this->password == p) {
		return 1;
	
	}
	else {
		return 0;
	}
}
account::account(string name, int initMoney, int pwdPin) {
	this->nameUser = name;
	this->money = initMoney;
	this->password = pwdPin;
}
int account::CheckMoney(void) {
	return this->money;
}
void account::addToMoney(int amount) {
	this->money += amount;
}
void account::SubtractMoney(int amount) {
	this->money -= amount;
}
string account::BankStatement(void) {
	this->Statement = "Name : ";
	this->Statement.append(this->nameUser);
	this->Statement.append("\n");
	this->Statement.append("Money : ");
	this->Statement = Statement + to_string(this->money);
	this->Statement.append("\n----------\n");
	return this->Statement;
}
class atm {
private:
	int temp;

public:
	void transfer(account &a1, account &a2, int amount,int pwd);
	int withDraw(int amount, account &a, int pwd);
	int payBill(int amount, account &a, int pwd);
	string PrintBankStatement(account &a,int pwd);
};
void atm::transfer(account &a1, account &a2, int amount,int pwd) {
	if (a1.pwdCompare(pwd)==1){
		a1.SubtractMoney(amount);
		a2.addToMoney(amount);
	}
	
	cout << "\n"  << "Amount Transfered" << endl;
}
int atm::withDraw(int amount, account &a, int pwd) {
	if (a.pwdCompare(pwd) == 1) {
		a.SubtractMoney(amount);
		cout << "\n"  << "Amount Withdrawed" << endl;
		return amount;
	}
}
int atm::payBill(int amount, account &a, int pwd) {
	if (a.pwdCompare(pwd) == 1) {
		a.SubtractMoney(amount);
		cout << "\n"  << "Bill Payed" << endl;
		return  amount;
	}
}
string atm::PrintBankStatement(account &a,int pwd){
	if (a.pwdCompare(pwd) == 1) {
		cout << a.BankStatement();
		return a.BankStatement();
	}
}

int main()
{
	account a1("Ali",32,1122);
	account a2("Kashif",990,911);
	atm atmMachine;
	atmMachine.PrintBankStatement(a1, 1122);
	a1.addToMoney(12);
	atmMachine.PrintBankStatement(a1, 1122);
	a1.SubtractMoney(1);
	atmMachine.PrintBankStatement(a1, 1122);
	atmMachine.PrintBankStatement(a2, 911);

	atmMachine.transfer(a1, a2, 3, 1122);
	//atmMachine.payBill(12, a1, 1122);
	atmMachine.PrintBankStatement(a1, 1122);
	atmMachine.PrintBankStatement(a2, 911);

	int a;
	cin >> a;
	return 0;
}


