#include "expr.hpp"
#include "name.hpp"

#include <iostream>
#include <iterator>




static void
print_str(std::ostream& os, char const* str)
{
  os << str;
}

static void
print_bool_lit(std::ostream& os, Bool_lit const* e)
{
  os << "Bool Literal " << e->get_val();
}





void
print(std::ostream& os, Expr const* e)
{
  switch (e->get_kind()) {
  case Expr::bool_lit:
    return print_bool_lit(os, static_cast<Bool_lit const*>(e));
  
  case Expr::int_lit:
    return print_str(os, "int literal");

  /*case Type::float_type:
    return print_str(os, "float");
  
  case Type::ref_type:
    return print_ref(os, static_cast<Ref_type const*>(t));

  case Type::fun_type:
    return print_fun(os, static_cast<Fun_type const*>(t));*/
  }
}

std::ostream&
operator<<(std::ostream& os, Expr const& e)
{
  print(os, &e);
  return os;
}




bool
equal(Expr const* e1, Expr const* e2)
{
 
  if (e1->get_kind() != e2->get_kind())
    return false;

  switch (e1->get_kind()) {
  case Expr::bool_lit:
    return true;
  
  case Expr::int_lit:
    return true;
  
  /*case Type::float_type:
    return true;

  case Type::ref_type:
    return equal_ref(static_cast<Ref_type const*>(a), 
                     static_cast<Ref_type const*>(b));
  case Type::fun_type:
    return equal_fun(static_cast<Fun_type const*>(a), 
                     static_cast<Fun_type const*>(b));*/
  }
}
