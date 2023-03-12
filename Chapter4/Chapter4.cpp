#include<iostream>

int readNum()
{
	int num{};
	std::cout << "enter an intereger in range zero to ten: ";
	std::cin >> num;
	if (num < 0 || num>9)
	{
		std::cout << "please enter in wanted range!\n";
		return 0;
	}
	else {
		return num;
	}
		
}
bool isPrime(int x)
{
	bool a{};

	if (x == 1 || x == 0)
	{
		return false;
	}
	else
	{
		for (int i = 2; i < x; i++)
		{
			if (x % i == 0)
				a = false;
			else
				a = true;
		}
	}
	return a;
}

int main()
{
	int num{ readNum()};

	if (isPrime(num))
	{
		std::cout << "prime number.";
	}
	else
	{
		std::cout << "is not a prime number.";
	}
		


}
