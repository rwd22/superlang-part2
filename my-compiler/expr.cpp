#include "expr.hpp"
#include "value.hpp"
#include "printer.hpp"

#include <iostream>

void
Expression::dump() const
{
  Printer p(std::cerr);
  dump(p);
}

void
Expression::dump_node(Printer& p, char const* name) const
{
  p.print_indentation();
  p.get_stream() << name << ' ' << this << '\n';
}

template<typename T>
void
dump_nested(Printer& p, T const* node)
{
  Print_indented pi(p);
  for (Expression* e : *node)
    e->dump(p);
}

Value
Boolean_literal::evaluate() const
{
  return Value(get_value());
}

void
Boolean_literal::dump(Printer& p) const
{
  dump_node(p, "Boolean_literal");
}

Value
Integer_literal::evaluate() const
{
  return Value(get_value());
}

void
Integer_literal::dump(Printer& p) const
{
  dump_node(p, "Integer_literal");
}

Value
Add_expression::evaluate() const
{
  Value v1 = get_operand(0)->evaluate();
  Value v2 = get_operand(1)->evaluate();
  return Value(v1.get_integer() + v2.get_integer());
}

void
Add_expression::dump(Printer& p) const
{
  dump_node(p, "Add_expression");
  dump_nested(p, this);
}

Value
Sub_expression::evaluate() const
{
  Value v1 = get_operand(0)->evaluate();
  Value v2 = get_operand(1)->evaluate();
  return Value(v1.get_integer() - v2.get_integer());
}

void
Sub_expression::dump(Printer& p) const
{
  dump_node(p, "Sub_expression");
  dump_nested(p, this);
}

Value
Mul_expression::evaluate() const
{
  Value v1 = get_operand(0)->evaluate();
  Value v2 = get_operand(1)->evaluate();
  return Value(v1.get_integer() * v2.get_integer());
}

void
Mul_expression::dump(Printer& p) const
{
  dump_node(p, "Mul_expression");
  dump_nested(p, this);
}

Value
Quo_expression::evaluate() const
{
  Value v1 = get_operand(0)->evaluate();
  Value v2 = get_operand(1)->evaluate();
  return Value(v1.get_integer() / v2.get_integer());
}

void
Quo_expression::dump(Printer& p) const
{
  dump_node(p, "Quo_expression");
  dump_nested(p, this);
}

Value
Rem_expression::evaluate() const
{
  Value v1 = get_operand(0)->evaluate();
  Value v2 = get_operand(1)->evaluate();
  return Value(v1.get_integer() % v2.get_integer());
}

void
Rem_expression::dump(Printer& p) const
{
  dump_node(p, "Rem_expression");
  dump_nested(p, this);
}

Value
Neg_expression::evaluate() const
{
  Value v1 = get_operand(0)->evaluate();
  return Value(0 - v1.get_integer());
}

void
Neg_expression::dump(Printer& p) const
{
  dump_node(p, "Neg_expression");
  dump_nested(p, this);
}

Value
Rec_expression::evaluate() const
{
  Value v1 = get_operand(0)->evaluate();
  return Value(1 / v1.get_integer());
}

void
Rec_expression::dump(Printer& p) const
{
  dump_node(p, "Rec_expression");
  dump_nested(p, this);
}

Value
Call_expression::evaluate() const
{
  throw std::logic_error("not implemented");
}

void
Call_expression::dump(Printer& p) const
{
  dump_node(p, "Rec_expression");
  dump_nested(p, this);
}