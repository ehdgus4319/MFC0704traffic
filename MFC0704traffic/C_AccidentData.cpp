#include "pch.h"
#include "C_AccidentData.h"


C_AccidentData::C_AccidentData(string _state, string _city, string _data_list[])
{
	state = _state;
	city = _city;
	for (int i = 0; i < 11; i++)
	{
		if (*(_data_list + i) == "-")
		{
			data_list[i] = 0;
		}
		else
		{
			data_list[i] = stoi(*(_data_list + i));
		}
	}
}
int* C_AccidentData::get_data_list()
{
	return data_list;
}