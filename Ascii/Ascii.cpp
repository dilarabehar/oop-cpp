
#include <iostream>

int main()
{
    std::cout << "enter a character: ";

    char chr{};
    std::cin >> chr;

    std::cout << chr << " equals in ascii table " << static_cast<int>(chr);


}


