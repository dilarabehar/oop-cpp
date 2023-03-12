#include "SSD.h"
#include<sqlite3.h>
#include<iostream>
#include<string>

using namespace std;

int SSD::createTable(const char* s)
{
	sqlite3* DB;

	string sql = "CREATE TABLE IF NOT EXISTS SSD("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"P_NAME		TEXT NOT NULL,"
		"STORE		CHAR(50),"
		"AMOUNT		INT NOT NULL,"
		"PRICE		INT NOT NULL,"
		"CAPACITY		INT NOT NULL,"
		"SIZE		INT NOT NULL,"
		"R_RATE		INT NOT NULL,"
		"W_RATE		INT NOT NULL,"
		"C_TYPE		CHAR(15));";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		char* messageError;
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

		if (exit != SQLITE_OK)
		{
			cerr << "Error Create Table" << endl;
			sqlite3_free(messageError);
		}
		else
		{
			cout << "Table created succesfully." << endl;
		}

		sqlite3_close(DB);

	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}

	return 0;
}

int SSD::insertData(const char* s)
{
	sqlite3* DB;
	sqlite3_stmt* st;

	SSD p;
	char* messageError;

	int exit = sqlite3_open(s, &DB);
	//insert into persons_info(firstName,lastName,id) values(@firstName,@lastName,@id)

	cout << "Enter the name of product" << endl;
	cin >> p.name;
	cout << "Enter the name of store" << endl;
	cin >> p.store;
	cout << "Enter the price" << endl;
	cin >> p.price;
	cout << "Enter the amount" << endl;
	cin >> p.amount;
	cout << "Enter the capacity" << endl;
	cin >> p.capacity;
	cout << "Enter the size of ssd" << endl;
	cin >> p.size;
	cout << "Enter the velocity of read" << endl;
	cin >> p.readRate;
	cout << "Enter the velocity of write" << endl;
	cin >> p.writeRate;
	cout << "Enter the connection type" << endl;
	cin >> p.connectionType;
	



	string sql("INSERT INTO SSD (P_NAME, STORE, AMOUNT, PRICE, CAPACITY, SIZE, R_RATE, W_RATE, C_TYPE) VALUES('" + p.name + "','" + p.store + "'," + to_string(p.amount) + "," + to_string(p.price) + "," + to_string(p.capacity) + "," + to_string(p.size) + "," + to_string(p.readRate) + "," + to_string(p.writeRate) + ",'" + p.connectionType + "')");



	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "error insert";
		sqlite3_free(messageError);

	}
	else
		cout << "records created succesfully"<<endl;


	return 0;
}

int SSD::selectData(const char* s)
{
	sqlite3* DB;
	
	SSD p;
	cout << "Enter the id that u want to show" << endl;
	cin >> p.productID;
	
	


	int exit = sqlite3_open(s, &DB);

	string sql = "SELECT * FROM SSD;";
	//string sql = "SELECT * FROM PRODUCTS WHERE ID=" + to_string(p.productID) + ";";

	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;
}

int SSD::updateData(const char* s)
{
	sqlite3* DB;
	SSD p;

	cout << "Enter the id of the product " << endl;
	cin >> p.productID;
	cout << "Enter the address of new store";
	cin >> p.store;

	char* messageError;

	int exit = sqlite3_open(s, &DB);

	string sql("UPDATE SSD SET STORE = '" + p.store + "' WHERE ID= " + to_string(p.productID) + "  ");

	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "ERROR UPDATE" << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Updated succesfully" << endl;

	return 0;
}

int SSD::deleteData(const char* s)
{
	sqlite3* DB;
	SSD p;

	cout << "Enter the id of the product " << endl;
	cin >> p.productID;

	int exit = sqlite3_open(s, &DB);

	string sql("DELETE FROM SSD WHERE ID= " + to_string(p.productID) + ";");

	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;
}