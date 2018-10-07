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


  Add_expr superex(&addex, &subex); //an expression made of two add expressions




  std::cout << "Types" << '\n';
  std::cout << '\n';

  std::cout << b << '\n';
  std::cout << '\n';
  std::cout << i << '\n';
  std::cout << '\n';
  std::cout << rb << '\n';
  std::cout << '\n';
  std::cout << ri << '\n';
  std::cout << '\n';
  std::cout << l << '\n';
  std::cout << '\n';
  std::cout << f << '\n';
  std::cout << '\n';

  sexpr(std::cout,&b);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&i);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&rb);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&ri);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&l);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&f);
  std::cout << '\n';
  std::cout << '\n';

  debug(std::cout,&b);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&i);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&rb);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&ri);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&l);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&f);
  std::cout << '\n';
  std::cout << '\n';

  std::cout << '\n';
  std::cout << "Expressions" << '\n';
  std::cout << '\n';

  std::cout << bl << '\n';
  std::cout << '\n';
  std::cout << il << '\n';
  std::cout << '\n';
  std::cout << addex << '\n';
  std::cout << '\n';
  std::cout << subex << '\n';
  std::cout << '\n';
  std::cout << mulex << '\n';
  std::cout << '\n';
  std::cout << divex << '\n';
  std::cout << '\n';
  std::cout << remex << '\n';
  std::cout << '\n';
  std::cout << gtex << '\n';
  std::cout << '\n';
  std::cout << ltex << '\n';
  std::cout << '\n';
  std::cout << gteex << '\n';
  std::cout << '\n';
  std::cout << lteex << '\n';
  std::cout << '\n';
  std::cout << eqex << '\n';
  std::cout << '\n';
  std::cout << neex << '\n';
  std::cout << '\n';
  std::cout << andex << '\n';
  std::cout << '\n';
  std::cout << orex << '\n';
  std::cout << '\n';
  std::cout << negex << '\n';
  std::cout << '\n';
  std::cout << recex << '\n';
  std::cout << '\n';
  std::cout << notex << '\n';
  std::cout << '\n';
  std::cout << superex << '\n';
  std::cout << '\n';
  std::cout << idex << '\n';
  std::cout << '\n';
  std::cout << conex << '\n';
  std::cout << '\n';

  sexpr(std::cout,&bl);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&il);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&addex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&subex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&mulex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&divex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&remex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&gtex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&ltex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&gteex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&lteex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&eqex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&neex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&andex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&orex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&negex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&recex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&notex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&superex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&idex);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&conex);
  std::cout << '\n';
  std::cout << '\n';

  debug(std::cout,&bl);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&il);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&addex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&subex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&mulex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&divex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&remex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&gtex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&ltex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&gteex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&lteex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&eqex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&neex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&andex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&orex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&negex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&recex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&notex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&superex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&idex);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&conex);
  std::cout << '\n';
  std::cout << '\n';

 
  std::cout << '\n';
  std::cout << "Declarations" << '\n';
  std::cout << '\n';

  std::cout << vd << '\n';
  std::cout << '\n';
  std::cout << rd << '\n';
  std::cout << '\n';
  std::cout << fd << '\n';
  std::cout << '\n';

  sexpr(std::cout,&vd);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&rd);
  std::cout << '\n';
  std::cout << '\n';
  sexpr(std::cout,&fd);
  std::cout << '\n';
  std::cout << '\n';

  debug(std::cout,&vd);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&rd);
  std::cout << '\n';
  std::cout << '\n';
  debug(std::cout,&fd);
  std::cout << '\n';
  std::cout << '\n';


  std::cout << '\n';
  std::cout << "Statements" << '\n';
  std::cout << '\n';
  

  std::cout << brs << '\n';
  std::cout << '\n';

  std::cout << cont << '\n';
  std::cout << '\n';

  std::cout << wstmt << '\n';
  std::cout << '\n';

  std::cout << rtstmt << '\n';
  std::cout << '\n';

  std::cout << exstmt << '\n';
  std::cout << '\n';

  std::cout << blstmt << '\n';
  std::cout << '\n';

  std::cout << terstmt << '\n';
  std::cout << '\n';

  std::cout << ldstmt << '\n';
  std::cout << '\n';



  sexpr(std::cout,&brs);
  std::cout << '\n';
  std::cout << '\n';

  sexpr(std::cout,&cont);
  std::cout << '\n';
  std::cout << '\n';

  sexpr(std::cout,&blstmt);
  std::cout << '\n';
  std::cout << '\n';

  sexpr(std::cout,&wstmt);
  std::cout << '\n';
  std::cout << '\n';

  sexpr(std::cout,&terstmt);
  std::cout << '\n';
  std::cout << '\n';

  sexpr(std::cout,&rtstmt);
  std::cout << '\n';
  std::cout << '\n';

  sexpr(std::cout,&exstmt);
  std::cout << '\n';
  std::cout << '\n';

  sexpr(std::cout,&ldstmt);
  std::cout << '\n';
  std::cout << '\n';


  debug(std::cout,&brs);
  std::cout << '\n';
  std::cout << '\n';

  debug(std::cout,&cont);
  std::cout << '\n';
  std::cout << '\n';

  debug(std::cout,&blstmt);
  std::cout << '\n';
  std::cout << '\n';

  debug(std::cout,&wstmt);
  std::cout << '\n';
  std::cout << '\n';

  debug(std::cout,&terstmt);
  std::cout << '\n';
  std::cout << '\n';

  debug(std::cout,&rtstmt);
  std::cout << '\n';
  std::cout << '\n';

  debug(std::cout,&exstmt);
  std::cout << '\n';
  std::cout << '\n';

  debug(std::cout,&ldstmt);
  std::cout << '\n';
  std::cout << '\n';

}
