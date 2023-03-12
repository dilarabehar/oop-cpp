#include <iostream>
#include<vector>
#include<fstream>
#include"student.h"
#include<string>

using namespace std;

static vector<student>v;  

int main(int argc, char* argv[])
{
	if (argc !=3)     //controlling command line arguments counter.
	{
		cout << "error";
		return 1;
	}

	student temp;
	int num_of_st;
	int i = 0;
	

	fstream file("students.txt", ios::in | ios::out | ios::trunc);   //files that can do read,write.

	if (!file) {
		cout << "students.txt can not opened!" << endl;
		exit(1);
	}
	else
	{
		file << "NAME	SURNAME	STUDENT_NUM	CLUB\tGENDER" << endl;
	}

	cout << "ENTER THE NUMBER OF STUDENT THAT U WANT TO ADD: ";
	cin >> num_of_st;
	do {
		cout << "-----------------------------------------------------";

		cout << "\nNAME: ";
		cin >> temp.first_name;

		cout << "LAST NAME: ";
		cin >> temp.last_name;

		int club_no;
		cout << "ENTER A NUMBER FOR THE CLUB: 1)CHESS\t2)SCIENCE\t3)LITERATURE\t4)MATH : ";
		cin >> club_no;
		sclub s = static_cast<sclub>(club_no);
		temp.sclub_name = s;

		cout << "ENTER A NUMBER FOR THE CLUB: 1)BOY\t2)GIRL : ";
		int gender1;
		cin >> gender1;
		gender gender11 = static_cast<gender>(gender1); 
		temp.g = gender11;

	
		temp.num = LCG16();
		
		v.push_back(temp);       //adding to vector.

		file << v[i].first_name << "	" << v[i].last_name << "	" << v[i].num << "	" <<(int)v[i].sclub_name<< (int)v[i].g << endl;

		i++;
	} while (i != num_of_st);
	
		string file_name = argv[2];  //our file is in the second index.
		fstream f;
		f.open(file_name);
		string line;
		while (!f.eof())
		{
			getline(f, line);
			cout << line<<"\n";
		}
		f.close();

		
		
		
		
	
}
