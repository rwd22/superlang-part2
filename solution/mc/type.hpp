#pragma once

#include "tree.hpp"
#include "value.hpp"

class Printer;


/// Represents the types in the language.
class Type
{
public:
  enum Kind
  {
    bool_type,
    int_type,
    float_type,
    ref_type,
    fn_type,
  };

protected:
  Type(Kind k);

public:
  // Queries

  Kind get_kind() const { return m_kind; }
  /// Returns the kind of type.

  bool is_bool() const { return m_kind == bool_type; }
  /// Returns true if this is `bool`.
  
  bool is_int() const { return m_kind == int_type; }
  /// Returns true if this is `int`.
  
  bool is_float() const { return m_kind == float_type; }
  /// Returns true if this is `float`.
  
  bool is_reference() const { return m_kind == ref_type; }
  /// Returns true if this is a reference type `ref t`.
  
  bool is_function() const { return m_kind == fn_type; }
  /// Returns true if this is a function type `(t1, t2, ..., n-1)->tn`.

  bool is_same_as(Type const* that) const;
  /// Returns true if this is the same type as that.

private:
  Kind m_kind;
  /// The kind of expression.
};

inline
Type::Type(Kind k)
  : m_kind(k)
{ }


// General purpose expression classes

/// Represents nullary types (i.e., base types or leaf nodes).
class Nullary_type : public Type, public Static_arity_node<Type, 0>
{
protected:
  Nullary_type(Kind k);
};

inline
Nullary_type::Nullary_type(Kind k)
  : Type(k), Static_arity_node<Type, 0>()
{ }


/// Represents unary type constructors (i.e., types with one operand).
class Unary_type : public Type, public Static_arity_node<Type, 1>
{
protected:
  Unary_type(Kind k, Type* e);
  /// Constructs the expression with the given arguments.
};

inline
Unary_type::Unary_type(Kind k, Type* e)
  : Type(k), Static_arity_node<Type, 1>(e)
{ }


/// Represents k-ary type constructors (i.e., nodes with k children).
class Kary_type : public Type, public Dynamic_arity_node<Type>
{
protected:
  Kary_type(Kind k, std::initializer_list<Type*> list);
  /// Constructs the expression with the given arguments.
  
  Kary_type(Kind k, std::vector<Type*> const& vec);
  /// Constructs the expression with the given arguments.
  
  Kary_type(Kind k, std::vector<Type*>&& vec);
  /// Constructs the expression with the given arguments.
};

inline
Kary_type::Kary_type(Kind k, std::initializer_list<Type*> list)
  : Type(k), Dynamic_arity_node<Type>(list)
{ }

inline
Kary_type::Kary_type(Kind k, std::vector<Type*> const& vec)
  : Type(k), Dynamic_arity_node<Type>(vec)
{ }

inline
Kary_type::Kary_type(Kind k, std::vector<Type*>&& vec)
  : Type(k), Dynamic_arity_node<Type>(std::move(vec))
{ }


// Base types


/// The type `bool`.
class Bool_type : public Nullary_type
{
public:
  Bool_type();
  /// Constructs the type `bool`.
};

inline
Bool_type::Bool_type()
  : Nullary_type(bool_type)
{ }


/// The type `int`.
class Int_type : public Nullary_type
{
public:
  Int_type();
  /// Constructs the type `int`.
};

inline
Int_type::Int_type()
  : Nullary_type(bool_type)
{ }


/// The type `float`.
class Float_type : public Nullary_type
{
public:
  Float_type();
  /// Constructs the type `float`.
};

inline
Float_type::Float_type()
  : Nullary_type(bool_type)
{ }


// Type constructors

/// Represents types of the form `ref t`.
class Ref_type : public Unary_type
{
public:
  Ref_type(Type* t);
  /// Constructs the type `ref t`.
};

inline
Ref_type::Ref_type(Type* t)
  : Unary_type(ref_type, t)
{ }


/// Represents function types of the form `(t1, t2, ..., tn-1) -> tn`.
class Fn_type : public Kary_type
{
public:
  Fn_type(std::initializer_list<Type*> list);
  /// Construct the expression `e(e1, e2, ..., en)`.
  
  Fn_type(std::vector<Type*> const& vec);
  /// Construct the expression `e(e1, e2, ..., en)`.
  
  Fn_type(std::vector<Type*>&& vec);
  /// Construct the expression `e(e1, e2, ..., en)`.
};

inline
Fn_type::Fn_type(std::initializer_list<Type*> list)
  : Kary_type(fn_type, list)
{ }

inline
Fn_type::Fn_type(std::vector<Type*> const& vec)
  : Kary_type(fn_type, vec)
{ }

inline
Fn_type::Fn_type(std::vector<Type*>&& vec)
  : Kary_type(fn_type, std::move(vec))
{ }


// Operations

void print(Printer& p, Type const* t);
/// Print `t` using the given printer.

std::ostream& operator<<(std::ostream& os, Type const& t);
/// Write `t` to the output stream.

