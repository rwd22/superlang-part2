#include "type.hpp"
#include "name.hpp"
#include "stmt.hpp"
#include "expr.hpp"
#include "decl.hpp"

#include <iostream>
#include <iterator>

//basic prints

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

//operators

std::ostream&
operator<<(std::ostream& os, Stmt const& s)
{
  print(os, &s);
  return os;
}

std::ostream&
sexpr_s(std::ostream& os, Stmt const& s)
{
  sexpr(os, &s);
  return os;
}

std::ostream&
debug_s(std::ostream& os, Stmt const& s)
{
  debug(os, &s);
  return os;
}

//sexpression prints

static void
print_str_sexpr(std::ostream& os, char const* str)
{
  os << "( " << str << " )";
}

static void
print_block_sexpr(std::ostream& os, Block_stmt const* s)
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
print_while_sexpr(std::ostream& os, While_stmt const* s)
{
  os << "While ";
  sexpr_r(os, *s->get_expr()) << " do ";
  sexpr_s(os, *s->get_stmt());
}

static void
print_if_sexpr(std::ostream& os, Ternary_stmt const* s)
{
  os << "(if ";
  sexpr_r(os, *s->get_expr1()) << " then ";
  sexpr_s(os, *s->get_stmt1()) << " else ";
  sexpr_s(os, *s->get_stmt2()) <<" )";
}

static void
print_return_sexpr(std::ostream& os, Return_stmt const* s)
{
  os << "(Return "; 
  sexpr_r(os,*s->get_expr()) << " )";
}

static void
print_expr_sexpr(std::ostream& os, Expr_stmt const* s)
{
  sexpr_r(os, *s->get_expr());
}

static void
print_decl_sexpr(std::ostream& os, Loc_def_stmt const* s)
{
  sexpr_d(os,*s->get_decl());
}





void
sexpr(std::ostream& os, Stmt const* s)
{
  switch (s->get_kind()) {
  case Stmt::break_stmt:
    return print_str_sexpr(os, "Break");

  case Stmt::cont_stmt:
    return print_str_sexpr(os, "Continue");

  case Stmt::block_stmt:
    return print_block_sexpr(os, static_cast<Block_stmt const*>(s));

  case Stmt::while_stmt:
    return print_while_sexpr(os, static_cast<While_stmt const*>(s));

  case Stmt::ternary_stmt:
    return print_if_sexpr(os, static_cast<Ternary_stmt const*>(s));

 case Stmt::return_stmt:
    return print_return_sexpr(os, static_cast<Return_stmt const*>(s));

 case Stmt::expr_stmt:
    return print_expr_sexpr(os, static_cast<Expr_stmt const*>(s));

 case Stmt::loc_def_stmt:
    return print_decl_sexpr(os, static_cast<Loc_def_stmt const*>(s));
  

  }
}

//debug prints

static void
print_str_debug(std::ostream& os, char const* str)
{
  os << "( " << str << " )";
}

static void
print_brk_debug(std::ostream& os, Break_stmt const* s)
{
  os << "(Break " << s << " )";
}

static void
print_cont_debug(std::ostream& os, Cont_stmt const* s)
{
  os << "(Continue " << s << " )";
}

static void
print_block_debug(std::ostream& os, Block_stmt const* s)
{
  if(s->get_param_stmts().size() == 0 )
  {
    os << "(Block " << s << ")";
  }
  else
  {
    os <<"(Block " << s << " :( ";

    auto params = s->get_param_stmts();

    for(int i = 0; i < params.size(); i++)
    {
      os << *params[i] << params[i];

      if (i == params.size()- 1)
        os << " )";
      else 
        os << ", ";
    }

  }
}

static void
print_while_debug(std::ostream& os, While_stmt const* s)
{
  os << "(While " << s << " :( while";
  debug_e(os, *s->get_expr()) << " do ";
  debug_s(os, *s->get_stmt()) << " ))";
}

static void
print_if_debug(std::ostream& os, Ternary_stmt const* s)
{
  os << "(Ternary " << s << ":( if ";
  debug_e(os, *s->get_expr1()) << " then ";
  debug_s(os, *s->get_stmt1()) << " else ";
  debug_s(os, *s->get_stmt2()) <<" ))";
}

static void
print_return_debug(std::ostream& os, Return_stmt const* s)
{
  os << "(Return " << s << ":( return "; 
  debug_e(os,*s->get_expr()) << " ))";
}

static void
print_expr_debug(std::ostream& os, Expr_stmt const* s)
{
  os << "(Expr Stmt " << s << ": (";
  debug_e(os, *s->get_expr()) << "))";
}

static void
print_decl_debug(std::ostream& os, Loc_def_stmt const* s)
{
  os << "(Local Def Stmt " << s << ": (";
  debug_d(os,*s->get_decl()) << "))";
}





void
debug(std::ostream& os, Stmt const* s)
{
  switch (s->get_kind()) {
  case Stmt::break_stmt:
    return print_brk_debug(os, static_cast<Break_stmt const*>(s));

  case Stmt::cont_stmt:
    return print_cont_debug(os, static_cast<Cont_stmt const*>(s));

  case Stmt::block_stmt:
    return print_block_debug(os, static_cast<Block_stmt const*>(s));

  case Stmt::while_stmt:
    return print_while_debug(os, static_cast<While_stmt const*>(s));

  case Stmt::ternary_stmt:
    return print_if_debug(os, static_cast<Ternary_stmt const*>(s));

 case Stmt::return_stmt:
    return print_return_debug(os, static_cast<Return_stmt const*>(s));

 case Stmt::expr_stmt:
    return print_expr_debug(os, static_cast<Expr_stmt const*>(s));

 case Stmt::loc_def_stmt:
    return print_decl_debug(os, static_cast<Loc_def_stmt const*>(s));
  

  }
}



















