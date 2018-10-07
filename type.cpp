#include "type.hpp"
#include "name.hpp"

#include <iostream>
#include <iterator>

static void
print_str(std::ostream& os, char const* str)
{
  os << str;
}

static void
print_ref(std::ostream& os, Ref_type const* t)
{
  os << "ref " << *t->get_referent_type();
}

static void
print_fun(std::ostream& os, Fun_type const* t)
{
  if(t->get_param_types().size() == 0 )
  {
    os << "( )" << "-> " << *t->get_ret_type();
  }
  else
  {
    os <<"(";

    auto params = t->get_param_types();

    for(int i = 0; i < params.size(); i++)
    {
      os << *params[i];

      if (i == params.size()- 1)
        os << ") ->"<< *t->get_ret_type();
      else 
        os << ",";
    }

  }
}


void
print(std::ostream& os, Type const* t)
{
  switch (t->get_kind()) {
  case Type::bool_type:
    return print_str(os, "bool");
  
  case Type::int_type:
    return print_str(os, "int");

  case Type::float_type:
    return print_str(os, "float");
  
  case Type::ref_type:
    return print_ref(os, static_cast<Ref_type const*>(t));

  case Type::fun_type:
    return print_fun(os, static_cast<Fun_type const*>(t));
  }
}

std::ostream&
operator<<(std::ostream& os, Type const& t)
{
  print(os, &t);
  return os;
}




























static void
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
    os  << "-> " << "(( )"  << *t->get_ret_type() << " )";
  }
  else
  {
    os <<"(->(";

    auto params = t->get_param_types();

    for(int i = 0; i < params.size(); i++)
    {
      os << *params[i];

      if (i == params.size()- 1)
        os << ") "<< *t->get_ret_type() << " )";
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
}
