#pragma once
#include "Product.h"

class CPU :public Product
{
public:
	int nanometre{};
	int clockRate{};
	int cacheSize{};
	
	int createTable(const char* s);
	int insertData(const char* s);
	int selectData(const char* s);
	int updateData(const char* s);
	int deleteData(const char* s);
};

