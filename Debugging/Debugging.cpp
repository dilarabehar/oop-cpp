#include <iostream>

int readNumber(int x)
{
	std::cout << "Please enter a number: ";
	std::cin >> x;
	return x;
}

void writeAnswer(int x)
{
	std::cout << "The sum is: " << x << '\n';
}

int main()
{
	int x{};
	readNumber(x);
	x = x + readNumber(x);
	writeAnswer(x);
	return 0;
}

//std::cin >> std::boolalpha this expression using for input like true or false with in "cin" otherwise cin accepts only 1 or 0 as an boole input.