#include "Product.h"
#include<iostream>
#include<sqlite3.h>
#include <string>

using namespace std;

int Product::createDB(const char* s)
{
	sqlite3* DB;  //database handle
	int exit = 0;  //for return values

	//goes to directory and create the database
	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB); //connection close

	return 0;
}

int Product::createTable(const char* s)
{
	sqlite3* DB;

	string sql = "CREATE TABLE IF NOT EXISTS PRODUCTS("
		"ID INTEGER PRIMARY KEY AUTOINCREMENT, "
		"P_NAME		TEXT NOT NULL,"
		"STORE		CHAR(50),"
		"AMOUNT		INT NOT NULL,"
		"PRICE		INT NOT NULL,"
		"CAPACITY		INT NOT NULL);";

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

int Product::insertData(const char* s)
{
	sqlite3* DB;
	sqlite3_stmt* st;

	Product p;
	char* messageError;

	int exit = sqlite3_open(s, &DB);
	//insert into persons_info(firstName,lastName,id) values(@firstName,@lastName,@id)

	cout << "Enter the name of product"<<endl;
	cin >> p.name;
	cout << "Enter the name of store" << endl;
	cin >> p.store;
	cout << "Enter the price"<<endl;
	cin >> p.price;
	cout << "Enter the amount"<<endl;
	cin >> p.amount;
	cout << "Enter the capacity"<<endl;
	cin >> p.capacity;


	
	//"INSERT INTO expenses(desc, price, satisf) VALUES ('" + saleDesc + "', "
	// "" + to_string(price) + ", " + to_string(satisf) + ")";

	string sql("INSERT INTO PRODUCTS (P_NAME, STORE, AMOUNT, PRICE, CAPACITY) VALUES('"+ p.name + "','"+p.store+"',"+to_string(p.amount)+","+to_string(p.price)+","+to_string(p.capacity)+")") ;

	

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

int Product::selectData(const char* s)
{
	sqlite3* DB;

	
	Product p;
	cout << "Enter the id that u want to show" << endl;
	cin >> p.productID;
	
	


	int exit = sqlite3_open(s, &DB);

	string sql = "SELECT * FROM PRODUCTS;";
	//string sql = "SELECT * FROM PRODUCTS WHERE ID=" + to_string(p.productID) + ";";

	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;
}

int Product::callback(void* NotUsed, int argc, char** argv, char** ColName)
{
	for (int i = 0; i < argc; i++)
	{
		cout << ColName[i] << ": " << argv[i] << endl;
	}

	cout << endl;
	return 0;
}

int Product::updateData(const char* s)
{
	sqlite3* DB;
	Product p;

	cout << "Enter the id of the product " << endl;
	cin >> p.productID;
	cout << "Enter the address of new store";
	cin >> p.store;

	char* messageError;

	int exit = sqlite3_open(s, &DB);

	string sql("UPDATE PRODUCTS SET STORE = '" + p.store + "' WHERE ID= "+to_string(p.productID)+"  ");
	
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);
	if (exit != SQLITE_OK)
	{
		cerr << "ERROR UPDATE" << endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Updated succesfully"<<endl;

	return 0;
}

int Product::deleteData(const char* s)
{	
	sqlite3* DB;
	Product p;

	cout << "Enter the id of the product " << endl;
	cin >> p.productID;

	int exit = sqlite3_open(s, &DB);

	string sql("DELETE FROM PRODUCTS WHERE ID= " + to_string(p.productID) + ";");

	sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL);

	return 0;
}





