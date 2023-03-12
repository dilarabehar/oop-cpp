#pragma once
#include <string>
using namespace std;

class Product
{
public:
	
	int productID{};
	string name;
	string store;
	int amount{};
	int price{};
	int capacity{};
	
	

	static int createDB(const char* s);
	virtual int createTable(const char* s);
	virtual int insertData(const char* s);
	virtual int selectData(const char* s);
	static int callback(void* NotUsed, int argc, char** argv, char** ColName);
	virtual int updateData(const char* s);
	virtual int deleteData(const char* s);
};

