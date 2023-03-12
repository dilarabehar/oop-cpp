#include"io.h"
#include<iostream>

int readNumber()
{
	int num{};

	std::cout << "enter an integer: ";
	std::cin >> num;

	return num;
}

int add(int x, int y)
{
	return x + y;
}

void writeAnswer(int sum)
{
	std::cout << "Answer is: " << sum;
}