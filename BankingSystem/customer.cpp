#include "customer.h"
customer::customer()
{

}

customer::customer(int id, int balance, int amount_of_silver, int amount_of_gold, int share)
{
	id = id;
	balance = balance;
	amount_of_gold = amount_of_gold;
	amount_of_silver = amount_of_silver;
	share = share;
}

void customer::buy_gold()
{
	int amount{};
	cout << "How many grams of gold would you like to buy?"<<" ("<< gold_price<<" TL per gram of gold)\n";
	cin >> amount;
	if (balance >= gold_price * amount)
	{
		cout << "-----------------------------------------------------------------------\n";
		cout << "Amount of gold in your account: " << amount_of_gold + amount << "\n";
		cout << "\nAvailable balance: " << balance - gold_price * amount << "\n";
		amount_of_gold = amount_of_gold + amount;
		balance = balance - gold_price * amount;
	}
	else
	{
		cout << "Insufficient Balance!";
		return;
	}

}

void customer::buy_silver()
{
	int amount{};
	cout << "How many grams of silver would you like to buy?" << " (" << silver_price << " TL per gram of silver)\n";
	cin >> amount;
	if (balance >= silver_price * amount)
	{
		cout << "-----------------------------------------------------------------------\n";
		cout << "Amount of silver in your account: " << amount_of_silver + amount << "\n";
		cout << "\nAvailable balance: " << balance - silver_price * amount << "\n";
		amount_of_silver = amount_of_silver + amount;
		balance = balance - silver_price * amount;
	}
	else
	{
		cout << "Insufficient Balance!";
		return;
	}
}

void customer::buy_share()
{
	int amount{};
	cout << "How many shares would you like to buy?" << " (" << share_price << " TL per)\n";
	cin >> amount;
	if (balance >= share_price * amount)
	{
		cout << "-----------------------------------------------------------------------\n";
		//cout << "Amount of shares in your account: " << amount_of_share + amount << "\n";
		cout << "\nAvailable balance: " << balance - share_price * amount<<"\n";
		balance = balance - share_price * amount;
		amount_of_share = amount_of_share + amount;
	}
	else
	{
		cout << "Insufficient Balance!";
		return;
	}
}



void customer::sell_gold()
{
	int amount{};
	cout << "How many gold would you like to sell?" << " (" << gold_price << " TL per)\n";
	cin >> amount;
	if (amount_of_gold>=amount)
	{
		cout << "-----------------------------------------------------------------------\n";
		cout << "Amount of golds in your account: " << amount_of_gold - amount << "\n";
		cout << "\nAvailable balance: " << balance + share_price * amount << "\n";
		amount_of_gold = amount_of_gold - amount;
		balance = balance + share_price * amount;
	}
	else
	{
		cout << "Insufficient Balance!";
		return;
	}
}

void customer::sell_share()
{
	int amount{};
	cout << "How many shares would you like to sell?" << " (" << share_price << " TL per)\n";
	cin >> amount;
	if (amount_of_share >= amount)
	{
		cout << "-----------------------------------------------------------------------\n";
		//cout << "Amount of share in your account: " << amount_of_share - amount << "\n";
		cout << "\nAvailable balance: " << balance + share_price * amount << "\n";
		amount_of_share = amount_of_share - amount;
		balance = balance + share_price * amount;
	}
	else
	{
		cout << "Insufficient Balance!";
		return;
	}
}

void customer::sell_silver()
{
	int amount{};
	cout << "How many silver would you like to sell?" << " (" << silver_price << " TL per)\n";
	cin >> amount;
	if (amount_of_silver >= amount)
	{
		cout << "-----------------------------------------------------------------------\n";
		cout << "Amount of silvers in your account: " << amount_of_silver - amount << "\n";
		cout << "\nAvailable balance: " << balance + silver_price * amount << "\n";
		amount_of_silver = amount_of_silver - amount;
		balance = balance + silver_price * amount;
	}
	else
	{
		cout << "Insufficient Balance!";
		return;
	}
}




