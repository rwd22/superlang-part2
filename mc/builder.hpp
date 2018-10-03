#pragma once

class Ast_builder
{
public:
  // Types

  Type* get_bool_type() const { return m_bool_type; }
  /// Returns the type `bool`.
  
  Type* get_int_type() const { return m_int_type; }
  /// Returns the type `int`.
  
  Type* get_ref_type() const { return m_ref_type; }
  /// Returns the type `float`.

  // Expression builder
  Expression* make_bool(bool b);
  /// Returns a new boolean literal.

  Expression* make_int(int n);
  /// Returns a new integer literal.

  Expression* make_float(double n);
  /// Returns a new floating point literal.

private:
  Bool_type m_bool_type;
  /// The type `bool`.

  Int_type m_int_type;
  /// The type `int`.

  Float_type m_float_type;
  /// The type `float`.
};
