#pragma once

#include <iostream>
#include <sstream>
#include <string>


using namespace std;

class C_AccidentData
{
private:
	string state;
	string city;
	int data_list[11];

public:
	C_AccidentData(string _state, string _city, string _data_list[]);

	int* get_data_list();

	CString get_state() const
	{
		return state;
	}


	CString get_city() const
	{
		return city;
	}

	~C_AccidentData(){};
};

