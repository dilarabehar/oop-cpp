#include "Licance.h"
#include <windows.h>
#include <tchar.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include<sqlite3.h>

#pragma comment(lib, "user32.lib")

#define  ENV_VAR_STRING_COUNT  (sizeof(envVarStrings)/sizeof(TCHAR*))
#define INFO_BUFFER_SIZE 32767

using namespace std;

int Licance::createKey(SYSTEM_INFO siSysInfo, const char* s)
{
    

    // Copy the hardware information to the SYSTEM_INFO structure. 

    GetSystemInfo(&siSysInfo);
    TCHAR  infoBuf[INFO_BUFFER_SIZE];
    DWORD  bufCharCount = INFO_BUFFER_SIZE;

    // Get and display the name of the computer. 
    bufCharCount = INFO_BUFFER_SIZE;
    if (GetComputerName(infoBuf, &bufCharCount) != 0)
    {
        int k{};

      
                k = *infoBuf +siSysInfo.dwPageSize;
				

		cout << "your serial key : " << k;

		sqlite3* db;

		char* messageError;

		int exit = sqlite3_open(s, &db);

		string sql("INSERT INTO SERIAL_KEY (KEY) VALUES('" + to_string(k) + "')");



		exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageError);
		if (exit != SQLITE_OK)
		{
			cerr << "error insert";
			sqlite3_free(messageError);

		}
		else
			cout << "records created succesfully" << endl;


		return 0;
		
    }

   
}

int Licance::create_db(const char* s)
{
	sqlite3* DB;  //database handle
	int exit = 0;  //for return values

	//goes to directory and create the database
	exit = sqlite3_open(s, &DB);

	sqlite3_close(DB); //connection close

	return 0;
}

int Licance::table4Key(const char* s)
{
	sqlite3* DB;

	string sql = "CREATE TABLE SERIAL_KEY (KEY int); ";

	try
	{
		int exit = 0;
		exit = sqlite3_open(s, &DB);

		char* messageError;
		exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

		cout << exit;

		if (exit != SQLITE_OK)
		{
			cerr << "Error Create Table" << endl;
			sqlite3_free(messageError);
			return 1;
		}
		else
		{
			cout << "Table created succesfully." << endl;
			return 0;
		}

		sqlite3_close(DB);

	}
	catch (const std::exception& e)
	{
		cerr << e.what();
	}

	
}

int Licance::controlKey(const char* s,int key)
{
	sqlite3* DB;


	int exit = sqlite3_open(s, &DB);
	
	string sql = "SELECT EXISTS(SELECT 1 FROM SERIAL_KEY WHERE KEY=" + to_string(key) + ")";

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
				return 1;
			}
			
		}
	}
	sqlite3_finalize(stmt);
	sqlite3_close(DB);

	return 0;


}

int Licance::callback(void* NotUsed, int argc, char** argv, char** ColName)
{
	for (int i = 0; i < argc; i++)
	{
		cout << ColName[i] << ": " << argv[i] << endl;
		
	}

	cout << endl;
	return (int)argv[0];
}