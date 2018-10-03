#pragma once

#include <iosfwd>

/// Supports printing to an output stream.
class Printer
{
public:
  Printer(std::ostream& os);

  std::ostream& get_stream() { return m_os; }
  /// Returns the underlying output stream.

  void indent() { ++m_indent; }
  /// Increase the level of indentation.

  void undent() { --m_indent; }
  /// Decrease the level of indentation.

  // Printing

  void print_indentation();
  /// Prints the indentation.

  void print_newline();
  /// Prints a newline character.

  void print_string(char const* str);
  /// Prints the given `str`.

  void print_address(void const* ptr);
  /// Prints the given address.

private:
  std::ostream& m_os;
  /// The underlying output stream.

  int m_indent;
  /// The current indentation level.
};

inline
Printer::Printer(std::ostream& os)
  : m_os(os), m_indent()
{ }


/// An RAII class to print indented text.
class Print_indented
{
public:
  Print_indented(Printer& p);
  ~Print_indented();

private:
  Printer& m_printer;  
};

inline
Print_indented::Print_indented(Printer& p)
  : m_printer(p)
{
  m_printer.indent();  
}

inline
Print_indented::~Print_indented()
{
  m_printer.undent();
}
