#include <iostream>

#include "expr.hpp"
#include "value.hpp"

int
main()
{
  Expression* three = new Integer_literal(3);
  Expression* five = new Integer_literal(5);
  Expression* seven = new Integer_literal(7);
  Expression* e1 = new Sub_expression(five, three);
  Expression* e2 = new Add_expression(e1, seven);

  e2->to_sexpr();
  std::cout << '\n';

  e2->dump();

  // std::cout << "value: " << e2->evaluate().get_integer() << '\n';
}
