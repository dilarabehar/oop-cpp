#include <iostream>

enum Animal :int  //using with its number :int or static_cast<Animal>(0)
{
    dog,
    cat,
    whale,
    pig,
};
int main()
{
    Animal pet{ static_cast<Animal>(1) }; //pet is a cat.
    Animal pet2{ dog };
    std::cout << pet<<pet2;
    std::cout <<dog;  //prints zero 
}


