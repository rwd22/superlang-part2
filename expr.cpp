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
  os << e->get_val();
}

static void
print_int_lit(std::ostream& os, Int_lit const* e)
{
  os << e->get_val();
}

static void
print_add(std::ostream& os, Add_expr const* e)
{
  os << *e->get_expr1() << " + " << *e->get_expr2();
}



void
print(std::ostream& os, Expr const* e)
{
  switch (e->get_kind()) {
  case Expr::bool_lit:
    return print_bool_lit(os, static_cast<Bool_lit const*>(e));
  
  case Expr::int_lit:
    return print_int_lit(os, static_cast<Int_lit const*>(e));

  case Expr::add_expr:
    return print_add(os, static_cast<Add_expr const*>(e));


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









static void
print_bool_sexpr(std::ostream& os, Bool_lit const* e)
{
  os << "(" << *e->get_type() << " " << e->get_val() << ")";
}

static void
print_int_sexpr(std::ostream& os, Int_lit const* e)
{
  os << "(" << *e->get_type() << " " << e->get_val() << ")";
}

static void
print_add_sexpr(std::ostream& os, Add_expr const* e)
{
  os << "(" << "+ "<< *e->get_expr1() << " " << *e->get_expr2() << ")";
}







void
sexpr(std::ostream& os, Expr const* e)
{
  switch (e->get_kind()) {
  case Expr::bool_lit:
    return print_bool_sexpr(os, static_cast<Bool_lit const*>(e));
  
  case Expr::int_lit:
    return print_int_sexpr(os, static_cast<Int_lit const*>(e));

  case Expr::add_expr:
    return print_add_sexpr(os, static_cast<Add_expr const*>(e));

  }
}
