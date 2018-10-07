#include "name.hpp"

#include <string>
#include <iostream>

std::ostream&
operator<<(std::ostream& os, Name const& n)
{

  return os << n.str;
}