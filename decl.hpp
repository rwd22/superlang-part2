#pragma once

#include <iostream>

class Type;
struct Expr;
struct Stmt;

struct Decl
{
public:
  enum Kind
  {
    var_decl,
    ref_decl,
    func_decl
  };

protected:
  Decl(Kind k) : m_kind(k) { }
  

public:
  Kind get_kind() const { return m_kind; }


private:
  Kind m_kind;
};


struct Var_decl : public Decl
{
public:
  Var_decl(Name* n, Type* t, Expr* e)
    : Decl(var_decl), m_name(n), m_type(t), m_exp(e)
  { }

  Name* get_name() const { return m_name; }
  Type* get_type() const { return m_type; }
  Expr* get_e() const { return m_exp; }

private:
  Type* m_type;
  Expr* m_exp;
  Name* m_name;
};

struct Ref_decl : public Decl
{
public:
  Ref_decl(Name* n, Type* t, Expr* e)
    : Decl(ref_decl), m_name(n), m_type(t), m_exp(e)
  { }

  Name* get_name() const { return m_name; }
  Type* get_type() const { return m_type; }
  Expr* get_e() const { return m_exp; }

private:
  Type* m_type;
  Expr* m_exp;
  Name* m_name;
};

struct Func_decl : public Decl
{
public:
  Func_decl(Name* n, Type* t, Expr* e, std::vector<Decl*> decls, Stmt* s)
    : Decl(func_decl), m_name(n), m_type(t), m_exp(e), m_decls(decls), m_stmt(s)
  { }

  Name* get_name() const { return m_name; }
  Type* get_type() const { return m_type; }
  Expr* get_e() const { return m_exp; }
  std::vector<Decl*> get_decls() const { return m_decls; }
  Stmt* get_stmt() const { return m_stmt; }

private:
  Type* m_type;
  Expr* m_exp;
  Name* m_name;
  std::vector<Decl*> m_decls;
  Stmt* m_stmt;
};






std::ostream& operator<<(std::ostream& os, Decl const& d);



void print(std::ostream& os, Decl const* d);

void sexpr(std::ostream& os, Decl const* d);













/*struct Name;
struct Type;
struct Expr;
struct Stmt;

struct Decl
{

};

using Decl_seq = std::vector<Decl*>;

struct Var_decl : Decl
{
    Name* name;
    Type* type;
    Expr* init;
};

struct Ref_decl : Decl
{
    Name* name;
    Type* type;
    Expr* init;
};

struct Func_decl : Decl
{
    Name* name;
    Decl_seq* parms;
    Type* ret;
    Stmt* body;
};*/
