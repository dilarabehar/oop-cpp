#include<stdio.h>
#include<iostream>
#include<sqlite3.h>
#include <string>
#include"Product.h"
#include "CPU.h"
#include "SSD.h"
#include "Licance.h"

using namespace std;


int main(int argc, char* argv[])
{





	const char* dir = "database.db";
	const char* dr = "serialkey.db";

	sqlite3* DB;
	sqlite3* db;
	string input = "dfgdz";

	string sql = "SELECT EXISTS(SELECT 1 FROM license WHERE key=" + input + ")";

	sqlite3_stmt* stmt;

	if (sqlite3_prepare_v2(DB, sql.c_str(), -1, &stmt, 0) == SQLITE_OK)
	{
		int result = sqlite3_step(stmt);
		if (result == SQLITE_ROW)
		{
			int exists = sqlite3_column_int(stmt, 0);
			if (exists == 1)
			{
				cout << "WELCOME!" << endl;
			}
			else
			{
				cout << "WRONG KEY!" << endl;
				sqlite3_finalize(stmt);
				sqlite3_close(DB);
				exit(1);
			}

		}
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);

	SYSTEM_INFO siSysInfo{};

	Licance::create_db(dr);
	int a =Licance::table4Key(dr);
	
	if (a == 0)
	{
		Licance::createKey(siSysInfo,dr);
		return 0;
	}

	int key{};
	cout << "enter the serial key before continue: ";
	cin >> key;

	if (Licance::controlKey(dr, key))
	{
		return 0;
	}

	CPU c;
	Product p;
	SSD s;

	Product::createDB(dir);


	
	c.createTable(dir);
	s.createTable(dir);
	p.createTable(dir);

	int process;
	int productNum;

	do {

		cout << "WHICH PRODUCT YOU WOULD LIKE TO TRADE?:  ";
		cin >> productNum;
		cout << "WHAT WOULD YOU LIKE TO DO ?(INSERT(1) / UPDATE(2) / DELETE(3) / SHOW(4):  ";
		cin >> process;
		
		
		if (productNum == 1)
		{
			switch (process)
			{
			case(1):
				c.insertData(dir);
				break;
			case(2):
				c.updateData(dir);
				break;
			case(3):
				c.deleteData(dir);
				break;
			case(4):
				c.selectData(dir);
				break;
			default:
				cout << "WRONG PARAMETER";
				return 0;
				break;
			}
		}
		else if (productNum == 2)
		{
			switch (process)
			{
			case(1):
				s.insertData(dir);
				break;
			case(2):
				s.updateData(dir);
				break;
			case(3):
				s.deleteData(dir);
				break;
			case(4):
				s.selectData(dir);
				break;
			default:
				cout << "WRONG PARAMETER";
				return 0;
				break;
			}
		}
		else {
			cout << "WRONG PARAMETER";
			return 0;
		}	

	} while (true);
	

	//p.insertData(dir);
	//c.insertData(dir);
	//s.insertData(dir);

	//p.selectData(dir);
	//c.selectData(dir);
	//s.selectData(dir);

	//p.updateData(dir);
	//c.updateData(dir);
	//s.updateData(dir);
	//p.selectData(dir);

	//p.deleteData(dir);
	//p.selectData(dir);
	//c.selectData(dir);
	//c.deleteData(dir);
	//c.selectData(dir);
	//s.selectData(dir);
	//s.deleteData(dir);
	//s.selectData(dir);






	
}



