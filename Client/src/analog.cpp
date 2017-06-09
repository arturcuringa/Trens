#include "analog.h"



int readAnalog(int pnumber)
{
	std::fstream f;
	f.open("/sys/bus/iio/devices/iio:device0/in_voltage" + std::to_string(pnumber)+"_raw", std::fstream::in );
	std::string line;
	getline(f,line);
	return std::stoi(line);
}
