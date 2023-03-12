#include "student.h"
#include<vector>

unsigned int LCG16() // our PRNG
{
	static unsigned int s_state{ 5323 };

	// Generate the next number

	// Due to our use of large constants and overflow, it would be
	// hard for someone to casually predict what the next number is
	// going to be from the previous one.
	s_state = 8253729 * s_state + 2396403; // first we modify the state

	return s_state % 32768; // then we use the new state to generate the next number in the sequence
}

/*
template<typename T>
void print(vector<T>& v)
{
	typename vector<T>::iterator i = v.begin();
	while (i != v.end())
	{

	}
}

*/

/*

std::istream& operator>> (std::istream& in, sclub& sclub_name)
{
	int input{};
	in >> input; // input an integer

	sclub_name = static_cast<sclub>(input);
	return in;
}


*/

