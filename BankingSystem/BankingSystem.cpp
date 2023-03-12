#include <iostream>
#include"customer.h"


int main()
{
	customer customer1;
	customer1.amount_of_gold = 5;
	customer1.balance = 99999;
	customer1.amount_of_silver = 10;
	customer1.amount_of_share = 100;

	customer reg_customer1;
	reg_customer1.exist = true;
	reg_customer1.first_name = "fakir";
	reg_customer1.id = 1;
	reg_customer1.balance = 5;

	customer reg_customer2;
	reg_customer2.exist = true;
	reg_customer2.first_name = "cok fakir";
	reg_customer2.id = 2;
	reg_customer2.balance = 3;

	customer reg_customer3;
	reg_customer3.exist = true;
	reg_customer3.first_name = "zengin";
	reg_customer3.id = 3;
	reg_customer3.balance = 99999;

	customer cus[] = { reg_customer1,reg_customer2,reg_customer3 };
	
	do {
		cout << "SELECT A TRANSACTION NUMBER: \n";
		cout << "-----------------------------------------------------------------------\n";
		cout << "1)BUYING GOLD\n2)BUYING SILVER\n3)BUYING SHARES\n4)SELLING GOLD\n5)SELLING SILVER\n6)SELLING SHARES\n7)MONEY TRANSFER\n";
		cout << "-----------------------------------------------------------------------\n";
		int tr_num{};
		cin >> tr_num;
		switch (tr_num)
		{
		case(1):
			customer1.buy_gold();
			break;
		case(2):
			customer1.buy_silver();
			break;
		case(3):
			customer1.buy_share();
			break;
		case(4):
			customer1.sell_gold();
			break;
		case(5):
			customer1.sell_silver();
			break;
		case(6):
			customer1.sell_share();
			break;
		case(7):
			int id;
			cout << "Enter the registered id of the person you want to send: ";
			cin >> id;
			for (auto var : cus)
			{
				if (var.id == id)
				{
					cout << "\nHow much money do you want to send ?" << "\n";
					int amount{};
					cin >> amount;
					if (customer1.balance >= amount)
					{
						cout << "Available balance: " << customer1.balance - amount << "\n";
						cout << var.first_name << "'s balance: " << var.balance + amount << "\n";
						customer1.balance = customer1.balance - amount;
						var.balance = var.balance + amount;
					}
					
				}
			}
		default:
			break;
		}
		cout << "\n";

	} while (exit);
	
}

