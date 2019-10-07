#include "pch.h"
#include "Section.h"

Section StringSplit_class(const std::string &str, char sep)
{
	std::stringstream ss(str);
	std::string name;
	std::string time;
	std::string pass;
	int i;

	getline(ss, name, sep);
	getline(ss, time, sep);
	getline(ss, pass, sep);

	i = atoi(time.c_str());

	return 	Section(name, i, pass, 0);

}
