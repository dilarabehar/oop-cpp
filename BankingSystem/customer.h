#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>


using namespace std;

class customer
{
public:
	int gold_price = 500;
	int silver_price = 300;
	int share_price = 900;
	int id;
	bool exist = false;
	string first_name;
	string last_name;
	int balance;
	int amount_of_silver;
	int amount_of_gold;
	int amount_of_share;
	int share;
	customer();
	customer(int id, int balance, int amount_of_silver, int amount_of_gold, int percente);
	void buy_gold();
	void sell_gold();
	void buy_silver();
	void sell_silver();
	void buy_share();
	void sell_share();
	

};
#endif // !CUSTOMER_H




