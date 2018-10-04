#include "stmt.hpp"
#include "expr.hpp"
#include "decl.hpp"
#include "printer.hpp"

#include <iostream>

static void
print_block(Printer& p, Block_stmt const* s)
{
  // FIXME: Indent this.
  p.get_stream() << '{';
  for (Stmt* sub : *s) {
    print(p, sub);
    p.print_newline();
  }
  p.get_stream() << '}';
}

static void
print_expr(Printer& p, Expr_stmt const* s)
{
  print(p, s->get_expression());
}

static void
print_ret(Printer& p, Ret_stmt const* s)
{
  p.get_stream() << "return ";
  print(p, s->get_return_value());
}

void
print(Printer& p, Stmt const* s)
{
  switch (s->get_kind()) {
  case Stmt::block_stmt:
    return print_block(p, static_cast<Block_stmt const*>(s));
  case Stmt::if_stmt:
  case Stmt::while_stmt:
  case Stmt::break_stmt:
  case Stmt::cont_stmt:
    break;
  case Stmt::ret_stmt:
    return print_ret(p, static_cast<Ret_stmt const*>(s));
  case Stmt::expr_stmt:
    return print_expr(p, static_cast<Expr_stmt const*>(s));
  case Stmt::decl_stmt:
    break;
  }
  assert(false);
}

std::ostream&
operator<<(std::ostream& os, Stmt const& s)
{
  Printer p(os);
  print(p, &s);
  return os;  
}
