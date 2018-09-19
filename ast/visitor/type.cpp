#include "type.hpp"

#include <iostream>


// Printing

void
print(std::ostream& os, Type const* t)
{
  /// Implements the print function.
  struct V : Const_visitor
  {
    V(std::ostream& os) : os(os) { }

    void visit(Bool_type const* t) override {
      os << "bool";
    }
    void visit(Int_type const* t) override {
      os << "int";
    }
    void visit(Ref_type const* t) override {
      os << "ref " << *t->get_referent_type();
    }
  
    std::ostream& os;
  };

  V vis{os};
  t->accept(vis);
}

std::ostream&
operator<<(std::ostream& os, Type const& t)
{
  print(os, &t);
  return os;
}


// Equality

bool equal(Type const* a, Type const* b);

bool
equal(Bool_type const* a, Type const* b)
{
  struct V : Const_visitor
  {
    V(Bool_type const* t)
      : a(t)
    { }

    void visit(Type const* t) override {
      result = false;
    }
    void visit(Bool_type const* b) override {
      result = true;
    }

    Bool_type const* a; // Stores the 1st argument.
    bool result; // Stores the result.
  };

  V vis{a};
  b->accept(vis);
  return vis.result;
}

bool
equal(Int_type const* a, Type const* b)
{
  struct V : Const_visitor
  {
    V(Int_type const* t)
      : a(t)
    { }

    void visit(Type const* t) override {
      result = false;
    }
    void visit(Int_type const* b) override {
      result = true;
    }

    Int_type const* a; // Stores the 1st argument.
    bool result; // Stores the result.
  };

  V vis{a};
  b->accept(vis);
  return vis.result;
}

bool
equal(Ref_type const* a, Type const* b)
{
  struct V : Const_visitor
  {
    V(Ref_type const* t)
      : a(t)
    { }

    void visit(Type const* t) override {
      result = false;
    }
    void visit(Ref_type const* b) override {
      result = equal(a->get_referent_type(), b->get_referent_type());
    }

    Ref_type const* a; // Stores the 1st argument.
    bool result; // Stores the result.
  };

  V vis{a};
  b->accept(vis);
  return vis.result;
}


bool
equal(Type const* a, Type const* b)
{
  /// Implements the print function.
  struct V : Const_visitor
  {
    V(Type const* t)
      : b(t)
    { }

    void visit(Bool_type const* a) override {
      result = equal(a, b); 
    }
    void visit(Int_type const* a) override {
      result = equal(a, b);
    }
    void visit(Ref_type const* a) override {
      result = equal(a, b);
    }

    Type const* b; // Stores the 2nd argument.
    bool result; // Stores the result.
  };

  V vis{b};
  a->accept(vis);
  return vis.result;
}
