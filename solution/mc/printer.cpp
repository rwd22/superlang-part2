#include "printer.hpp"

#include <iostream>

void
Printer::print_indentation()
{
  for (int i = 0; i < m_indent; ++i)
    m_os << "  ";
}

void
Printer::print_newline()
{
  m_os << '\n';
}

void
Printer::print_string(char const* str)
{
  m_os << str;
}

void
Printer::print_address(void const* ptr)
{
  m_os << ptr;
}