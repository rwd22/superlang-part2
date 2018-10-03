#include "expr.hpp"

#include <iostream>
#include <iomanip>

void
Boolean_literal::to_sexpr() const
{
  std::cout << std::boolalpha << get_value();
}

void
Integer_literal::to_sexpr() const
{
  std::cout << get_value();
}

static void
print_sexpr(Binary_expression const* expr, char const* op)
{
  std::cout << '(' << op << ' ';
  expr->get_operand(0)->to_sexpr();
  std::cout << ' ';
  expr->get_operand(1)->to_sexpr();
  std::cout << ')';
}

/// Prints '(+ e1 e2)'
void
Add_expression::to_sexpr() const
{
  print_sexpr(this, "+");
}

void
Sub_expression::to_sexpr() const
{
  print_sexpr(this, "-");
}

void
Mul_expression::to_sexpr() const
{
  print_sexpr(this, "*");
}

void
Quo_expression::to_sexpr() const
{
  print_sexpr(this, "/");
}

void
Rem_expression::to_sexpr() const
{
  print_sexpr(this, "%");
}
