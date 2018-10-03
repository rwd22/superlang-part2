#pragma once

#include "tree.hpp"

class Name;
class Type;
class Expr;
class Stmt;
class Printer;


/// Represents the base class of all declarations.
class Decl
{
public:
  enum Kind
  {
    prog_decl,
    obj_decl,
    ref_decl,
    fn_decl,
  };

protected:
  Decl(Kind k);

public:
  // Queries
  
  Kind get_kind() const { return m_kind; }
  /// Returns the kind of declaration.

  bool is_object() const { return m_kind == obj_decl; }
  /// Returns true if this declares an object.
  
  bool is_reference() const { return m_kind == ref_decl; }
  /// Returns true if this declares a reference.
  
  bool is_function() const { return m_kind == fn_decl; }
  /// Returns true if this declares a function.

  virtual Name* get_name() const { return nullptr; }
  /// Returns the name of the declaration, if any.
  
  virtual Type* get_type() const { return nullptr; }  
  /// Returns the type of the declaration, if any.

private:
  Kind m_kind;
  /// The kind of declaration.
};

inline
Decl::Decl(Kind k)
  : m_kind(k)
{ }


// Helper classes

/// A nullary declaration has no children.
class Nullary_decl : public Decl, public Static_arity_node<Decl, 0>
{
protected:
  Nullary_decl(Kind k);
};

inline
Nullary_decl::Nullary_decl(Kind k)
  : Decl(k)
{ }


/// A Kary declaration has k children.
class Kary_decl : public Decl, public Dynamic_arity_node<Decl>
{
protected:
  Kary_decl(Kind k, std::initializer_list<Decl*> list);
  /// Constructs the declaration with the given arguments.
  
  Kary_decl(Kind k, std::vector<Decl*> const& vec);
  /// Constructs the declaration with the given arguments.
  
  Kary_decl(Kind k, std::vector<Decl*>&& vec);
  /// Constructs the declaration with the given arguments.
};

inline
Kary_decl::Kary_decl(Kind k, std::initializer_list<Decl*> list)
  : Decl(k), Dynamic_arity_node<Decl>(list)
{ }

inline
Kary_decl::Kary_decl(Kind k, std::vector<Decl*> const& vec)
  : Decl(k), Dynamic_arity_node<Decl>(vec)
{ }

inline
Kary_decl::Kary_decl(Kind k, std::vector<Decl*>&& vec)
  : Decl(k), Dynamic_arity_node<Decl>(std::move(vec))
{ }


/// The base class of all declarations that can have values.
class Value_decl
{
protected:
  Value_decl(Name* n, Type* t);

public:
  Name* get_name() const { return m_name; }
  /// Returns the name of the declaration.

  Type* get_type() const { return m_type; }
  /// Returns the type of the declaration.

private:
  Name* m_name;
  /// The name of the declaration.

  Type* m_type;
  /// The type of the declaration.
};

inline
Value_decl::Value_decl(Name* n, Type* t)
  : m_name(n), m_type(t)
{ }


/// Variable (object and reference) declarations.
class Var_decl : public Value_decl
{
protected:
  Var_decl(Name* n, Type* t, Expr* e);

public:
  Expr* get_initializer() const { return m_init; }
  /// Returns the initializer of the declaration.

private:
  Expr* m_init;
  /// The initializer of the declaration.
};

inline 
Var_decl::Var_decl(Name* n, Type* t, Expr* e)
  : Value_decl(n, t), m_init(e)
{ }


/// Represents declarations of the form `var x : t = e`.
class Obj_decl : public Nullary_decl, public Var_decl
{
public:
  Obj_decl(Name* n, Type* t, Expr* e);

  Name* get_name() const override { return Var_decl::get_name(); }
  /// Returns the name of the declaration, if any.
  
  Type* get_type() const override { return Var_decl::get_type(); }  
  /// Returns the type of the declaration, if any.
};

inline
Obj_decl::Obj_decl(Name* n, Type* t, Expr* e)
  : Nullary_decl(obj_decl), Var_decl(n, t, e)
{ }


/// Represents declarations of the form `ref x : t = e`.
class Ref_decl : public Nullary_decl, public Var_decl
{
public:
  Ref_decl(Name* n, Type* t, Expr* e);

  Name* get_name() const override { return Var_decl::get_name(); }
  /// Returns the name of the declaration, if any.
  
  Type* get_type() const override { return Var_decl::get_type(); }  
  /// Returns the type of the declaration, if any.
};

inline
Ref_decl::Ref_decl(Name* n, Type* t, Expr* e)
  : Nullary_decl(ref_decl), Var_decl(n, t, e)
{ }


/// Represents declarations of the form `fun x (decl-seq) -> t s`.
///
/// The children of this node include the parameters and an explicit
/// declaration of the return object.
class Fn_decl : public Kary_decl, public Value_decl
{
public:
  Fn_decl(Name* n, Type* t, std::initializer_list<Decl*> list, Stmt* s);
  /// Constructs the function with the given arguments.
  
  Fn_decl(Name* n, Type* t, std::vector<Decl*> const& vec, Stmt* s);
  /// Constructs the function with the given arguments.
  
  Fn_decl(Name* n, Type* t, std::vector<Decl*>&& vec, Stmt* s);
  /// Constructs the function with the given arguments.

  Name* get_name() const override { return Value_decl::get_name(); }
  /// Returns the name of the declaration, if any.
  
  Type* get_type() const override { return Value_decl::get_type(); }  
  /// Returns the type of the declaration, if any.

  Stmt* get_body() const { return m_body; }
  /// Returns the body of the function.

private:
  Stmt* m_body;
  /// The body of the function.
};

inline
Fn_decl::Fn_decl(Name* n, Type* t, std::initializer_list<Decl*> list, Stmt* s)
  : Kary_decl(fn_decl, list), Value_decl(n, t), m_body(s)
{ }

inline
Fn_decl::Fn_decl(Name* n, Type* t, std::vector<Decl*> const& vec, Stmt* s)
  : Kary_decl(fn_decl, vec), Value_decl(n, t), m_body(s)
{ }

inline
Fn_decl::Fn_decl(Name* n, Type* t, std::vector<Decl*>&& vec, Stmt* s)
  : Kary_decl(fn_decl, vec), Value_decl(n, t), m_body(s)
{ }


/// A program declaration is a list of declarations.
class Prog_decl : public Kary_decl
{
public:
  Prog_decl(std::initializer_list<Decl*> list);
  /// Constructs a program from the given declarations.
  
  Prog_decl(std::vector<Decl*> const& vec);
  /// Constructs a vector from the given declarations.
  
  Prog_decl(std::vector<Decl*>& vec);
  /// Constructs a program from the given declarations.
};

inline
Prog_decl::Prog_decl(std::initializer_list<Decl*> list)
  : Kary_decl(prog_decl, list)
{ }
  
inline
Prog_decl::Prog_decl(std::vector<Decl*> const& vec)
  : Kary_decl(prog_decl, vec)
{ }
  
inline
Prog_decl::Prog_decl(std::vector<Decl*>& vec)
  : Kary_decl(prog_decl, vec)
{ }


// Operations

void print(Printer& p, Decl const* d);
/// Print `d` using the given printer.


std::ostream& operator<<(std::ostream& os, Decl const& d);
/// Write `d` to the output stream.

