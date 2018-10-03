#include "decl.hpp"
#include "name.hpp"
#include "type.hpp"
#include "expr.hpp"
#include "stmt.hpp"
#include "printer.hpp"

#include <iostream>

template<typename T>
void
print_var(Printer& p, T const* d)
{
  if (d->is_object())
    p.get_stream() << "var ";
  else
    p.get_stream() << "ref ";

  if (Name const* n = d->get_name())
    print(p, n);

  if (Type const* t = d->get_type())
    print(p, t);

  if (Expr const* e = d->get_initializer())
    print(p, e);
}

void
print_fn(Printer& p, Fn_decl const* d)
{
  p.get_stream() << "fun ";

  if (Name const* n = d->get_name())
    print(p, n);

  // FIXME: Print the parameters and return type.

  if (Stmt* s = d->get_body())
    print(p, s);
}

void
print_prog(Printer& p, Prog_decl const* d)
{
  for (Decl* member : *d)
    print(p, member);
}

void
print(Printer& p, Decl const* d)
{
  switch (d->get_kind()) {
  case Decl::obj_decl:
    return print_var(p, static_cast<Obj_decl const*>(d));
  case Decl::ref_decl:
    return print_var(p, static_cast<Ref_decl const*>(d));
  case Decl::fn_decl:
    return print_fn(p, static_cast<Fn_decl const*>(d));
  case Decl::prog_decl:
    return print_prog(p, static_cast<Prog_decl const*>(d));
  }
}

std::ostream&
operator<<(std::ostream& os, Decl const& d)
{
  Printer p(os);
  print(p, &d);
  return os;
}