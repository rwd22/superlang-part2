#pragma once

#include <string>

class Name
{
public:
	std::string str;
};

std::ostream& operator<<(std::ostream& os, Name const& n);