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

//declaration structures

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

//operators and functions

std::ostream& operator<<(std::ostream& os, Decl const& d);

std::ostream& sexpr_d(std::ostream& os, Decl const& d);

std::ostream& debug_d(std::ostream& os, Decl const& d);

void print(std::ostream& os, Decl const* d);

void debug(std::ostream& os, Decl const* d);

void sexpr(std::ostream& os, Decl const* d);
