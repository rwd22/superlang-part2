#include <iostream>

#include "name.hpp"
#include "type.hpp"
#include "expr.hpp"
#include "stmt.hpp"
#include "decl.hpp"
#include "value.hpp"

Decl* make_min()
{
  Type* b = new Bool_type();
  Type* z = new Int_type();
  Decl* p1 = new Obj_decl(new Name("a"), z, nullptr);
  Decl* p2 = new Obj_decl(new Name("b"), z, nullptr);
  Decl* r = new Obj_decl(nullptr, z, nullptr);

  // p1 < p2 ? p1 : p2
  Expr* expr = new Cond_expr(
    z,
    new Lt_expr(b, new Id_expr(z, p1), new Id_expr(z, p2)),
    new Id_expr(z, p1),
    new Id_expr(z, p2)
  );
  Stmt* body = new Block_stmt({
    new Ret_stmt(expr)
  });

  // Build the function type.
  Type* f = new Fn_type({z, z, z});

  return new Fn_decl(new Name("min"), f, {p1, p2, r}, body);
}

int
main()
{
  Decl* min = make_min();
  std::cout << *min << '\n';
}
