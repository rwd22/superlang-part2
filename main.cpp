#include "type.hpp"
#include "name.hpp"
#include "stmt.hpp"
#include "decl.hpp"
#include "expr.hpp"


#include <iostream>
#include <vector>
#include <string>

int
main() {
  Bool_type b;
  Int_type i;
  Int_type x;
  Float_type l;
  std::vector<Type*> v;
  v.push_back(&i);
  v.push_back(&b);
  Name* n;
  Ref_type rb(&b);
  Ref_type ri(&i);
  Ref_type rri(&ri);
  Fun_type f(v, &i);

  Bool_lit bl(false);
  Int_lit il(9);



  std::cout << b << '\n';
  std::cout << i << '\n';
  std::cout << rb << '\n';
  std::cout << ri << '\n';
  std::cout << rri << '\n';
  std::cout << '\n';

  std::cout << b << " == " << b << " -> " << equal(&b, &b) << '\n';
  std::cout << b << " == " << i << " -> " << equal(&b, &i) << '\n';
  std::cout << b << " == " << rb << " -> " << equal(&b, &rb) << '\n';
  std::cout << b << " == " << ri << " -> " << equal(&b, &ri) << '\n';
  std::cout << '\n';

  std::cout << i << " == " << b << " -> " << equal(&i, &b) << '\n';
  std::cout << i << " == " << i << " -> " << equal(&i, &i) << '\n';
  std::cout << i << " == " << rb << " -> " << equal(&i, &rb) << '\n';
  std::cout << i << " == " << ri << " -> " << equal(&i, &ri) << '\n';
  std::cout << '\n';

  std::cout << rb << " == " << b << " -> " << equal(&rb, &b) << '\n';
  std::cout << rb << " == " << i << " -> " << equal(&rb, &i) << '\n';
  std::cout << rb << " == " << rb << " -> " << equal(&rb, &rb) << '\n';
  std::cout << rb << " == " << ri << " -> " << equal(&rb, &ri) << '\n';
  std::cout << '\n';

  std::cout << ri << " == " << b << " -> " << equal(&ri, &b) << '\n';
  std::cout << ri << " == " << i << " -> " << equal(&ri, &i) << '\n';
  std::cout << ri << " == " << rb << " -> " << equal(&ri, &rb) << '\n';
  std::cout << ri << " == " << ri << " -> " << equal(&ri, &ri) << '\n';
  std::cout << '\n';

  std::cout << f << '\n';
  std::cout << l << " == " << l << " -> " << equal(&l, &l) << '\n';


  std::cout << bl << '\n';
  std::cout << il << '\n';



}