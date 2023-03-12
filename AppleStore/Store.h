#pragma once
#include<iostream>
#include<vector>
using namespace std;

class Store
{
	int ID{};

public:
	string location;
	int rent{};
	int capacity{};

	void setID(int id);
	int getID();
	static void createStore(vector<Store>*v);
	
	

};



