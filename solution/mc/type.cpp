#include "type.hpp"
#include "printer.hpp"

#include <algorithm>
#include <iostream>

/// A helper function.
static bool
is_same(Type const* a, Type const* b)
{
  return a->is_same_as(b);
}

static bool
is_same_ref(Ref_type const* a, Ref_type const* b)
{
  return is_same(a->get_child(), b->get_child());
}

static bool
is_same_fn(Fn_type const* a, Fn_type const* b)
{
  return std::equal(a->begin(), a->end(), b->begin(), b->end(), is_same);
}

bool
Type::is_same_as(Type const* that) const
{
  if (m_kind != that->m_kind)
    return false;

  switch (m_kind) {
  case bool_type:
  case int_type:
  case float_type:
    return true;

  case ref_type:
    return is_same_ref(static_cast<Ref_type const*>(this),
                       static_cast<Ref_type const*>(that));
  case fn_type:
    return is_same_fn(static_cast<Fn_type const*>(this),
                      static_cast<Fn_type const*>(that));
  }
}

static void
print_type(Printer& p, char const* str)
{
  p.get_stream() << str << '\n';
}

void
print(Printer& p, Type const* t)
{
  switch (t->get_kind()) {
  case Type::bool_type:
    return print_type(p, "bool");
  case Type::int_type:
    return print_type(p, "int");
  case Type::float_type:
    return print_type(p, "float");
  case Type::ref_type:
  case Type::fn_type:
    break;
  }
  assert(false);
}

std::ostream&
operator<<(std::ostream& os, Type const& t)
{
  Printer p(os);
  print(p, &t);
  return os;
}
