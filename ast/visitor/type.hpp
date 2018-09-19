#pragma once

#include <iosfwd>


class Type;
class Bool_type;
class Int_type;
class Ref_type;

/// The Visitor class is the base class of all specific visitors. It
/// defines the dispatch table for a function. Derived classes represent
/// functions.
class Visitor
{
public:
  virtual void visit(Type* t) { }
  virtual void visit(Bool_type* t) { return visit((Type*)t); }
  virtual void visit(Int_type* t) { return visit((Type*)t); }
  virtual void visit(Ref_type* t) { return visit((Type*)t); }
};


/// ... and this is the price you pay for const correctness.
class Const_visitor
{
public:
  virtual void visit(Type const* t) { }
  virtual void visit(Bool_type const* t) { return visit((Type const*)t); }
  virtual void visit(Int_type const* t) { return visit((Type const*)t); }
  virtual void visit(Ref_type const* t) { return visit((Type const*)t); }
};


/// Represents all strings that spell a type.
class Type
{
public:
  virtual void accept(Visitor& v) = 0;
  virtual void accept(Const_visitor& v) const = 0;
};


/// Represents the string `bool`.
class Bool_type : public Type
{
public:
  void accept(Visitor& v) override { 
    return v.visit(this); 
  }
  void accept(Const_visitor& v) const override { 
    return v.visit(this); 
  }
};


/// Represents the string `int`.
class Int_type : public Type
{
public:
  void accept(Visitor& v) override { 
    return v.visit(this); 
  }
  void accept(Const_visitor& v) const override { 
    return v.visit(this); 
  }
};


/// Represents strings of the form `ref t` where `t` is a type.
class Ref_type : public Type
{
public:
  Ref_type(Type* t)
    : m_type(t)
  { }

  Type* get_referent_type() const { return m_type; }

  void accept(Visitor& v) override { 
    return v.visit(this); 
  }
  void accept(Const_visitor& v) const override { 
    return v.visit(this); 
  }


private:
  Type* m_type;
};

void print(std::ostream& os, Type const* t);
/// Prints the type t.

std::ostream& operator<<(std::ostream& os, Type const& t);
/// Write t to the output stream.

bool equal(Type const* a, Type const* b);
/// Returns true if a and b are the same type.
