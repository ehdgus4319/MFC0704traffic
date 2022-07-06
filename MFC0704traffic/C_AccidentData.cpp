#include "pch.h"
#include "C_AccidentData.h"


C_AccidentData::C_AccidentData()
{
	state = "";
	city = "";
	for (int i = 0; i < 11; i++) data_list[i] = "";
}
