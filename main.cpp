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
  std::string g = "name";
  Bool_type b;
  Int_type i;
  Int_type x;
  Float_type l;
  std::vector<Type*> v;
  std::vector<Stmt*> st;
  std::vector<Decl*> de;
  v.push_back(&i);


  Name n;
  n.str = g;
  Ref_type rb(&b);
  Ref_type ri(&i);
    v.push_back(&ri);
  Ref_type rri(&ri);
  Fun_type f(v, &i);

  Type bt = Bool_type();
  Type it = Int_type();

  Bool_lit bl(false, &bt);
  Int_lit il(9, &it);
  Int_lit il2(1, &it);

  Add_expr addex(&il, &il2);
  Sub_expr subex(&il, &il2);
  Mul_expr mulex(&il, &il2);
  Div_expr divex(&il, &il2);
  Rem_expr remex(&il, &il2);
  Gt_expr gtex(&il, &il2);
  Lt_expr ltex(&il, &il2);
  Gte_expr gteex(&il, &il2);
  Lte_expr lteex(&il, &il2);
  Eq_expr eqex(&il, &il);
  Ne_expr neex(&il, &il2);
  And_expr andex(&il, &il2);
  Or_expr orex(&il, &il2);
  Neg_expr negex(&il);
  Rec_expr recex(&il);
  Not_expr notex(&il);
  Id_expr idex(&n);
  Con_expr conex(&eqex, &recex, &addex );

  Stmt brs = Break_stmt();
  Stmt cont = Cont_stmt();
  While_stmt wstmt(&gteex, &brs);
  Return_stmt rtstmt(&gteex);
  Expr_stmt exstmt(&gteex);
  st.push_back(&wstmt);
  st.push_back(&rtstmt);
  Block_stmt blstmt(st);
  Ternary_stmt terstmt(&gteex, &brs, &cont);




  Var_decl vd(&n, &bt, &addex);
  Ref_decl rd(&n, &it, &addex);
      de.push_back(&vd);
  de.push_back(&rd);
  Func_decl fd(&n, &it, &addex, de, &brs);

    Loc_def_stmt ldstmt(&vd);






    Add_expr superex(&addex, &subex);





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

  std::cout << addex << '\n';
  std::cout << subex << '\n';
  std::cout << mulex << '\n';
  std::cout << divex << '\n';
  std::cout << remex << '\n';
  std::cout << gtex << '\n';
  std::cout << ltex << '\n';
  std::cout << gteex << '\n';
  std::cout << lteex << '\n';
  std::cout << eqex << '\n';
  std::cout << neex << '\n';
  std::cout << andex << '\n';
  std::cout << orex << '\n';
  std::cout << negex << '\n';
  std::cout << recex << '\n';
  std::cout << notex << '\n';
  std::cout << superex << '\n';


  std::cout << idex << '\n';

    std::cout << conex << '\n';

  sexpr(std::cout,&addex);
  std::cout << '\n';
  sexpr(std::cout,&il);
  std::cout << '\n';
  sexpr(std::cout,&bl);
  std::cout << '\n';
    sexpr(std::cout,&subex);
  std::cout << '\n';
    sexpr(std::cout,&mulex);
  std::cout << '\n';
    sexpr(std::cout,&divex);
  std::cout << '\n';
    sexpr(std::cout,&remex);
  std::cout << '\n';
    sexpr(std::cout,&gtex);
  std::cout << '\n';
    sexpr(std::cout,&ltex);
  std::cout << '\n';
    sexpr(std::cout,&gteex);
  std::cout << '\n';
    sexpr(std::cout,&lteex);
  std::cout << '\n';
    sexpr(std::cout,&eqex);
  std::cout << '\n';
    sexpr(std::cout,&neex);
  std::cout << '\n';
    sexpr(std::cout,&andex);
  std::cout << '\n';
    sexpr(std::cout,&orex);
  std::cout << '\n';
    sexpr(std::cout,&negex);
  std::cout << '\n';
    sexpr(std::cout,&recex);
  std::cout << '\n';
    sexpr(std::cout,&notex);
  std::cout << '\n';
    sexpr(std::cout,&superex);
  std::cout << '\n';

      sexpr(std::cout,&idex);
  std::cout << '\n';


    sexpr(std::cout,&conex);
  std::cout << '\n';

      sexpr(std::cout,&f);
  std::cout << '\n';

        sexpr(std::cout,&b);
  std::cout << '\n';

        sexpr(std::cout,&rb);
  std::cout << '\n';


  std::cout << brs << '\n';

  std::cout << cont << '\n';

  std::cout << wstmt << '\n';

  std::cout << rtstmt << '\n';

    std::cout << exstmt << '\n';

    std::cout << blstmt << '\n';

std::cout << terstmt << '\n';

std::cout << vd << '\n';

std::cout << rd << '\n';

std::cout << fd << '\n';

std::cout << ldstmt << '\n';

      sexpr(std::cout,&vd);
  std::cout << '\n';

        sexpr(std::cout,&fd);
  std::cout << '\n';

        sexpr(std::cout,&rd);
  std::cout << '\n';

          sexpr(std::cout,&brs);
  std::cout << '\n';

            sexpr(std::cout,&cont);
  std::cout << '\n';

              sexpr(std::cout,&blstmt);
  std::cout << '\n';

                sexpr(std::cout,&wstmt);
  std::cout << '\n';

                sexpr(std::cout,&terstmt);
  std::cout << '\n';

                sexpr(std::cout,&rtstmt);
  std::cout << '\n';

                sexpr(std::cout,&exstmt);
  std::cout << '\n';

                sexpr(std::cout,&ldstmt);
  std::cout << '\n';

                debug(std::cout,&rb);
  std::cout << '\n';

                  debug(std::cout,&f);
  std::cout << '\n';

                    debug(std::cout,&b);
  std::cout << '\n';

                   debug(std::cout,&i);
  std::cout << '\n';

                   debug(std::cout,&l);
  std::cout << '\n';

                     debug(std::cout,&bl);
  std::cout << '\n';

                       debug(std::cout,&il);
  std::cout << '\n';

                         debug(std::cout,&addex);
  std::cout << '\n';













}