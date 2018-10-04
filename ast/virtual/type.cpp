#include "type.hpp"

#include <iostream>

void
Bool_type::print(std::ostream& os) const
{
  os << "bool";
}

void
Int_type::print(std::ostream& os) const
{
  os << "int";
}

void
Ref_type::print(std::ostream& os) const
{
  os << "ref " << *m_ref;
}

std::ostream&
operator<<(std::ostream& os, Type const& t)
{
  t.print(os);
  return os;
}
