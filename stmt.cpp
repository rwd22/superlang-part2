#include "type.hpp"
#include "name.hpp"
#include "stmt.hpp"
#include "expr.hpp"
#include "decl.hpp"

#include <iostream>
#include <iterator>

static void
print_str(std::ostream& os, char const* str)
{
  os << str;
}

static void
print_while(std::ostream& os, While_stmt const* s)
{
  os << "While " << *s->get_expr() << " do " << *s->get_stmt();
}

static void
print_return(std::ostream& os, Return_stmt const* s)
{
  os << "Return " << *s->get_expr();
}

static void
print_expr(std::ostream& os, Expr_stmt const* s)
{
  os << *s->get_expr();
}

static void
print_decl(std::ostream& os, Loc_def_stmt const* s)
{
  os << *s->get_decl();
}


static void
print_block(std::ostream& os, Block_stmt const* s)
{
  if(s->get_param_stmts().size() == 0 )
  {
    os << "( )";
  }
  else
  {
    os <<"( ";

    auto params = s->get_param_stmts();

    for(int i = 0; i < params.size(); i++)
    {
      os << *params[i];

      if (i == params.size()- 1)
        os << " )";
      else 
        os << ", ";
    }

  }
}

static void
print_if(std::ostream& os, Ternary_stmt const* s)
{
  os << "if " << *s->get_expr1() << " then " << *s->get_stmt1() << " else " << *s->get_stmt2();
}


void
print(std::ostream& os, Stmt const* s)
{
  switch (s->get_kind()) {
  case Stmt::break_stmt:
    return print_str(os, "break");

  case Stmt::cont_stmt:
    return print_str(os, "Continue");

  case Stmt::while_stmt:
    return print_while(os, static_cast<While_stmt const*>(s));

  case Stmt::return_stmt:
    return print_return(os, static_cast<Return_stmt const*>(s));

  case Stmt::expr_stmt:
    return print_expr(os, static_cast<Expr_stmt const*>(s));
  
  case Stmt::loc_def_stmt:
    return print_decl(os, static_cast<Loc_def_stmt const*>(s));

  case Stmt::block_stmt:
    return print_block(os, static_cast<Block_stmt const*>(s));

    
  case Stmt::ternary_stmt:
    return print_if(os, static_cast<Ternary_stmt const*>(s));






  

  }
}

std::ostream&
operator<<(std::ostream& os, Stmt const& s)
{
  print(os, &s);
  return os;
}




























/*static void
print_str_sexpr(std::ostream& os, char const* str)
{
  os << "( " << str << " )";
}

static void
print_ref_sexpr(std::ostream& os, Ref_type const* t)
{
  os << "( ref " << *t->get_referent_type() << " )";
}

static void
print_fun_sexpr(std::ostream& os, Fun_type const* t)
{
  if(t->get_param_types().size() == 0 )
  {
    os << "(( )" << "-> " << *t->get_ret_type() << " )";
  }
  else
  {
    os <<"((";

    auto params = t->get_param_types();

    for(int i = 0; i < params.size(); i++)
    {
      os << *params[i];

      if (i == params.size()- 1)
        os << ") ->"<< *t->get_ret_type() << " )";
      else 
        os << ",";
    }

  }
}


void
sexpr(std::ostream& os, Type const* t)
{
  switch (t->get_kind()) {
  case Type::bool_type:
    return print_str_sexpr(os, "bool");
  
  case Type::int_type:
    return print_str_sexpr(os, "int");

  case Type::float_type:
    return print_str_sexpr(os, "float");
  
  case Type::ref_type:
    return print_ref_sexpr(os, static_cast<Ref_type const*>(t));

  case Type::fun_type:
    return print_fun_sexpr(os, static_cast<Fun_type const*>(t));
  }
}

static bool
equal_ref(Ref_type const* a, Ref_type const* b)
{
  return equal(a->get_referent_type(), b->get_referent_type());
}

static bool
equal_fun(Fun_type const* a, Fun_type const* b)
{
  if(a->get_ret_type() == b->get_ret_type())
  {
    auto paramsOne = a->get_param_types();
    auto paramsTwo = b->get_param_types();

    if(paramsOne.size() != paramsTwo.size())
    {
      return false;
    }

    for (int i = 0; i < paramsOne.size(); ++i)
    {
      if(paramsOne[i] != paramsTwo[i] )
      {
        return false;
      }
    }



    return true;
  }
  else
  {
    return false;
  }
}


bool
equal(Type const* a, Type const* b)
{
  // Different kinds of types are not equal.
  if (a->get_kind() != b->get_kind())
    return false;

  // Compare similar types.
  switch (a->get_kind()) {
  case Type::bool_type:
    return true;
  
  case Type::int_type:
    return true;
  
  case Type::float_type:
    return true;

  case Type::ref_type:
    return equal_ref(static_cast<Ref_type const*>(a), 
                     static_cast<Ref_type const*>(b));
  case Type::fun_type:
    return equal_fun(static_cast<Fun_type const*>(a), 
                     static_cast<Fun_type const*>(b));
  }
}*/
