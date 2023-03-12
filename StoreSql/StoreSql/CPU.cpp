#include "CPU.h"
#include "Product.h"
#include <string>
#include<sqlite3.h>
#include<iostream>

using namespace std;

int CPU::createTable(const char* s)
{
	sqlite3* DB;

	string sql = "CREATE TABLE IF NOT EXISTS CPU("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"P_NAME		TEXT NOT NULL,"
		"STORE		CHAR(50),"
		"AMOUNT		INT NOT NULL,"
		"PRICE		INT NOT NULL,"
		"CAPACITY		INT NOT NULL,"
		"NANOMETRE		INT NOT NULL,"
		"C_RATE		INT NOT NULL,"
		"C_SIZE		INT NOT NULL);";

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

int CPU::insertData(const char* s)
{
	sqlite3* DB;
	sqlite3_stmt* st;

	CPU p;
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
	cout << "Nanometre" << endl;
	cin >> p.nanometre;
	cout << "Enter the velocity of clock" << endl;
	cin >> p.clockRate;
	cout << "Enter the size of cache" << endl;
	cin >> p.cacheSize;


	string sql("INSERT INTO CPU (P_NAME, STORE, AMOUNT, PRICE, CAPACITY, NANOMETRE, C_RATE, C_SIZE) VALUES('" + p.name + "','" + p.store + "'," + to_string(p.amount) + "," + to_string(p.price) + "," + to_string(p.capacity) + "," + to_string(p.nanometre) + "," + to_string(p.clockRate) + "," + to_string(p.cacheSize) + ")");



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

int CPU::selectData(const char* s)
{
	sqlite3* DB;

	
	CPU p;
	cout << "Enter the id that u want to show" << endl;
	cin >> p.productID;
	


	int exit = sqlite3_open(s, &DB);

	string sql = "SELECT * FROM CPU;";
	//string sql = "SELECT * FROM PRODUCTS WHERE ID= " + to_string(p.productID) + ";";

	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;
}

int CPU::updateData(const char* s)
{
	sqlite3* DB;
	CPU p;

	cout << "Enter the id of the product " << endl;
	cin >> p.productID;
	cout << "Enter the address of new store"<<endl;
	cin >> p.store;

	char* messageError;

	int exit = sqlite3_open(s, &DB);

	string sql("UPDATE CPU SET STORE = '" + p.store + "' WHERE ID= " + to_string(p.productID) + "  ");

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

int CPU::deleteData(const char* s)
{
	sqlite3* DB;
	CPU p;

	cout << "Enter the id of the product " << endl;
	cin >> p.productID;

	int exit = sqlite3_open(s, &DB);

	string sql("DELETE FROM CPU WHERE ID= " + to_string(p.productID) + ";");

	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;
}
