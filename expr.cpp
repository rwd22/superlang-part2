#include "expr.hpp"
#include "name.hpp"
#include "type.hpp"

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
  os << "(" << *e->get_expr1() << " + " << *e->get_expr2() << ")";
}

static void
print_sub(std::ostream& os, Sub_expr const* e)
{
  os << "(" << *e->get_expr1() << " - " << *e->get_expr2() << ")";
}

static void
print_mul(std::ostream& os, Mul_expr const* e)
{
  os << "(" << *e->get_expr1() << " * " << *e->get_expr2() << ")";
}

static void
print_div(std::ostream& os, Div_expr const* e)
{
  os << "(" << *e->get_expr1() << " div " << *e->get_expr2() << ")";
}

static void
print_rem(std::ostream& os, Rem_expr const* e)
{
  os << "(" << *e->get_expr1() << " rem " << *e->get_expr2() << ")";
}

static void
print_gt(std::ostream& os, Gt_expr const* e)
{
  os << "(" << *e->get_expr1() << " > " << *e->get_expr2() << ")";
}

static void
print_lt(std::ostream& os, Lt_expr const* e)
{
  os << "(" << *e->get_expr1() << " < " << *e->get_expr2() << ")";
}

static void
print_gte(std::ostream& os, Gte_expr const* e)
{
  os << "(" << *e->get_expr1() << " >= " << *e->get_expr2() << ")";
}

static void
print_lte(std::ostream& os, Lte_expr const* e)
{
  os << "(" << *e->get_expr1() << " <= " << *e->get_expr2() << ")";
}

static void
print_eq(std::ostream& os, Eq_expr const* e)
{
  os << "(" << *e->get_expr1() << " = " << *e->get_expr2() << ")";
}

static void
print_ne(std::ostream& os, Ne_expr const* e)
{
  os << "(" << *e->get_expr1() << " != " << *e->get_expr2() << ")";
}

static void
print_and(std::ostream& os, And_expr const* e)
{
  os << "(" << *e->get_expr1() << " AND " << *e->get_expr2() << ")";
}

static void
print_or(std::ostream& os, Or_expr const* e)
{
  os << "(" << *e->get_expr1() << " OR " << *e->get_expr2() << ")";
}

static void
print_neg(std::ostream& os, Neg_expr const* e)
{
  os << "(" <<  "-" << *e->get_expr1() << ")";
}

static void
print_rec(std::ostream& os, Rec_expr const* e)
{
  os << "(" << "/" << *e->get_expr1() << ")";
}

static void
print_not(std::ostream& os, Not_expr const* e)
{
  os << "(" << "NOT " << *e->get_expr1() << ")";
}

static void
print_id(std::ostream& os, Id_expr const* e)
{
  os << "("  << *e->get_id() << ")";
}

static void
print_con(std::ostream& os, Con_expr const* e)
{
  os << "(If" << *e->get_expr1() << " Then " << *e->get_expr2() << " Else " << *e->get_expr3() << ")";
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

  case Expr::sub_expr:
    return print_sub(os, static_cast<Sub_expr const*>(e));

  case Expr::mul_expr:
    return print_mul(os, static_cast<Mul_expr const*>(e));

  case Expr::div_expr:
    return print_div(os, static_cast<Div_expr const*>(e));

  case Expr::rem_expr:
    return print_rem(os, static_cast<Rem_expr const*>(e));

  case Expr::gt_expr:
    return print_gt(os, static_cast<Gt_expr const*>(e));

  case Expr::lt_expr:
    return print_lt(os, static_cast<Lt_expr const*>(e));

  case Expr::gte_expr:
    return print_gte(os, static_cast<Gte_expr const*>(e));

  case Expr::lte_expr:
    return print_lte(os, static_cast<Lte_expr const*>(e));

  case Expr::eq_expr:
    return print_eq(os, static_cast<Eq_expr const*>(e));

  case Expr::ne_expr:
    return print_ne(os, static_cast<Ne_expr const*>(e));

  case Expr::and_expr:
    return print_and(os, static_cast<And_expr const*>(e));

  case Expr::or_expr:
    return print_or(os, static_cast<Or_expr const*>(e));

  case Expr::neg_expr:
    return print_neg(os, static_cast<Neg_expr const*>(e));

  case Expr::rec_expr:
    return print_rec(os, static_cast<Rec_expr const*>(e));

  case Expr::not_expr:
    return print_not(os, static_cast<Not_expr const*>(e));

  case Expr::id_expr:
    return print_id(os, static_cast<Id_expr const*>(e));

  case Expr::con_expr:
    return print_con(os, static_cast<Con_expr const*>(e));

  }
}








std::ostream&
operator<<(std::ostream& os, Expr const& e)
{
  print(os, &e);
  return os;
}

std::ostream&
sexpr_r(std::ostream& os, Expr const& e)
{
  sexpr(os, &e);
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
  os << "(" << "+ ";
  sexpr_r(os, *e->get_expr1()) << " ";
  sexpr_r(os, *e->get_expr2()) << ")";
}

static void
print_sub_sexpr(std::ostream& os, Sub_expr const* e)
{
  os << "(" << "- "; 
  sexpr_r(os, *e->get_expr1()) << " " ;
   sexpr_r(os, *e->get_expr2())  << ")";
}

static void
print_mul_sexpr(std::ostream& os, Mul_expr const* e)
{
  os << "(" << "* ";
   sexpr_r(os, *e->get_expr1()) << " " ;
   sexpr_r(os, *e->get_expr2())  << ")";
}

static void
print_div_sexpr(std::ostream& os, Div_expr const* e)
{
  os << "(" << "div "; 
  sexpr_r(os, *e->get_expr1()) << " " ;
  sexpr_r(os, *e->get_expr2())  << ")";
}

static void
print_rem_sexpr(std::ostream& os, Rem_expr const* e)
{
  os << "(" << "rem ";
   sexpr_r(os, *e->get_expr1()) << " ";
    sexpr_r(os, *e->get_expr2())  << ")";
}

static void
print_gt_sexpr(std::ostream& os, Gt_expr const* e)
{
  os << "(" << "> ";
  sexpr_r(os, *e->get_expr1()) << " ";
  sexpr_r(os, *e->get_expr2())  << ")";
}

static void
print_lt_sexpr(std::ostream& os, Lt_expr const* e)
{
  os << "(" << "< ";
  sexpr_r(os, *e->get_expr1()) << " ";
  sexpr_r(os, *e->get_expr2())  << ")";
}

static void
print_gte_sexpr(std::ostream& os, Gte_expr const* e)
{
  os << "(" << ">= "; 
  sexpr_r(os, *e->get_expr1()) << " ";
  sexpr_r(os, *e->get_expr2())  << ")";
}

static void
print_lte_sexpr(std::ostream& os, Lte_expr const* e)
{
  os << "(" << "<= ";
 sexpr_r(os, *e->get_expr1()) << " " ;
 sexpr_r(os, *e->get_expr2()) << ")";
}

static void
print_eq_sexpr(std::ostream& os, Eq_expr const* e)
{
  os << "(" << "= ";
  sexpr_r(os, *e->get_expr1()) << " " ;
  sexpr_r(os, *e->get_expr2())  << ")";
}

static void
print_ne_sexpr(std::ostream& os, Ne_expr const* e)
{
  os << "(" << "!= ";
  sexpr_r(os, *e->get_expr1()) << " " ;
  sexpr_r(os, *e->get_expr2()) << ")";
}

static void
print_and_sexpr(std::ostream& os, And_expr const* e)
{
  os << "(" << "AND ";
  sexpr_r(os, *e->get_expr1()) << " ";
  sexpr_r(os, *e->get_expr2())  << ")";
}

static void
print_or_sexpr(std::ostream& os, Or_expr const* e)
{
  os << "(" << "OR ";
  sexpr_r(os, *e->get_expr1()) << " " ;
  sexpr_r(os, *e->get_expr2()) << ")";
}

static void
print_neg_sexpr(std::ostream& os, Neg_expr const* e)
{
  os << "(" <<  "-";
  sexpr_r(os, *e->get_expr1()) << ")";
}

static void
print_rec_sexpr(std::ostream& os, Rec_expr const* e)
{
  os << "(" << "/";
  sexpr_r(os, *e->get_expr1()) << ")";
}

static void
print_not_sexpr(std::ostream& os, Not_expr const* e)
{
  os << "(" << "NOT ";
  sexpr_r(os, *e->get_expr1()) << ")";
}

static void
print_id_sexpr(std::ostream& os, Id_expr const* e)
{
  os << "("  << *e->get_id() << ")";
}

static void
print_con_sexpr(std::ostream& os, Con_expr const* e)
{
  os << "(Con " ;
  sexpr_r(os, *e->get_expr1()) << " ";
  sexpr_r(os, *e->get_expr2()) << " ";
  sexpr_r(os, *e->get_expr3()) << ")";
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

  case Expr::sub_expr:
    return print_sub_sexpr(os, static_cast<Sub_expr const*>(e));

  case Expr::mul_expr:
    return print_mul_sexpr(os, static_cast<Mul_expr const*>(e));

  case Expr::div_expr:
    return print_div_sexpr(os, static_cast<Div_expr const*>(e));

  case Expr::rem_expr:
    return print_rem_sexpr(os, static_cast<Rem_expr const*>(e));

  case Expr::gt_expr:
    return print_gt_sexpr(os, static_cast<Gt_expr const*>(e));

  case Expr::lt_expr:
    return print_lt_sexpr(os, static_cast<Lt_expr const*>(e));

  case Expr::gte_expr:
    return print_gte_sexpr(os, static_cast<Gte_expr const*>(e));

  case Expr::lte_expr:
    return print_lte_sexpr(os, static_cast<Lte_expr const*>(e));

  case Expr::eq_expr:
    return print_eq_sexpr(os, static_cast<Eq_expr const*>(e));

  case Expr::ne_expr:
    return print_ne_sexpr(os, static_cast<Ne_expr const*>(e));

  case Expr::and_expr:
    return print_and_sexpr(os, static_cast<And_expr const*>(e));

  case Expr::or_expr:
    return print_or_sexpr(os, static_cast<Or_expr const*>(e));

  case Expr::neg_expr:
    return print_neg_sexpr(os, static_cast<Neg_expr const*>(e));

  case Expr::rec_expr:
    return print_rec_sexpr(os, static_cast<Rec_expr const*>(e));

  case Expr::not_expr:
    return print_not_sexpr(os, static_cast<Not_expr const*>(e));

  case Expr::id_expr:
    return print_id_sexpr(os, static_cast<Id_expr const*>(e));

  case Expr::con_expr:
    return print_con_sexpr(os, static_cast<Con_expr const*>(e));

  }
}
