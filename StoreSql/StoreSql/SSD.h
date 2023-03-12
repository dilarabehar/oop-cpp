#pragma once
#include "Product.h"
#include <string>
using namespace std;

class SSD :public Product
{
public:
	int size;
	int readRate{};
	int writeRate{};
	string connectionType;

	 int createTable(const char* s);
	 int insertData(const char* s);
	 int selectData(const char* s);
	 int updateData(const char* s);
	 int deleteData(const char* s);
};

