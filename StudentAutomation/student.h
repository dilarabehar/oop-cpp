#pragma once
#include<iostream>
#include<fstream>

using namespace std;

unsigned int LCG16();

enum class gender
{
    boy,
    girl,
};

enum class sclub {
    nof_them,
    chess,
    science,
    literature,
    math,
};

struct student {
    int num;
    string first_name;
    string last_name;
    sclub sclub_name;
    gender g;
};








