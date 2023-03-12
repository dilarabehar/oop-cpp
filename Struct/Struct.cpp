#include <iostream>
using namespace std;

struct girsl
{
    int age{};
    int year;
   
};
struct student
{
    int num{};
    string name{};
    girsl st{};
    struct boys
    {
        int age{};
       
    };
    boys ahmet{};
};

void printInfo(struct student& student) //passing by referance.
{
    cout << "student's name : " << student.name<<"\n";
}

student initialize() //return value is struct.
{
    //student temp{ 0,"initialized" };
    //return temp;
    
    //improving our function using with returning unnamed struct.
    // return student{ 0,"initiliazed" };  
    //return {0," "};
    return {};
}
int main()
{
    student dilara{ 1,"dilara"};
    printInfo(dilara);

    //lets we initialize our dilara
    dilara = initialize();
    printInfo(dilara);

    student test{ 1,"ayse",{12,2016} };
    printInfo(test);


    student student1{ 1,"ahmet",{12},{15} };
    printInfo(student1);
    cout << student1.ahmet.age;

}
