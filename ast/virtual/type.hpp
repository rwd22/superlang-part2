#pragma once

#include <iosfwd>

class Type;
class Bool_type;
class Int_type;
class Ref_type;

/// Represents all strings that spell a type.
class Type
{
public:
  // Prints a type.
  virtual void print(std::ostream& os) const = 0;

  // Check to see if this type is equal to that type.
  virtual bool equal(Type const* that) const = 0;
  virtual bool equal(Bool_type const* that) const { return false; }
  virtual bool equal(Int_type const* that) const { return false; }
  virtual bool equal(Ref_type const* that) const { return false; }
};


/// Represents the string `bool`.
class Bool_type : public Type
{
public:
  void print(std::ostream& os) const override;

  bool equal(Type const* that) const override {
    return that->equal(this);
  }
  bool equal(Bool_type const* that) const override {
    return true;
  }
};


/// Represents the string `int`.
class Int_type : public Type
{
public:
  void print(std::ostream& os) const override;

  bool equal(Type const* that) const override {
    return that->equal(this);
  }
  bool equal(Int_type const* that) const override {
    return true;
  }
};


/// Represents strings of the form `ref t` where `t` is a type.
class Ref_type : public Type
{
public:
  Ref_type(Type* t)
    : m_ref(t)
  { }

  Type* get_referent_type() const { return m_ref; }

  void print(std::ostream& os) const override;
  
  bool equal(Type const* that) const override {
    return that->equal(this);
  }
  bool equal(Ref_type const* that) const override {
    return m_ref->equal(that->m_ref);
  }

private:
  Type* m_ref;
};

inline void
print(std::ostream& os, Type const* t)
{
  t->print(os);
}

std::ostream& operator<<(std::ostream& os, Type const& t);

inline bool
equal(Type const* a, Type const* b)
{
  return a->equal(b);
}



