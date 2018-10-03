#pragma once

#include "tree.hpp"

class Printer;
class Value;

/// Represents an expression in the language.
class Expression
{
public:
  // Evaluation

  virtual Value evaluate() const = 0;
  /// Compute a value from the expression.

  // Printing

  virtual void to_sexpr() const { }
  // Print a representation of the expression
  // to cout.

  // Debugging

  void dump() const;
  /// Emit debug info about the node.

  virtual void dump(Printer& p) const = 0;
  /// Emit debug info about the node.

protected:
  void dump_node(Printer& p, char const* name) const;
  /// Emits the node header for this node.

private:
};

// General purpose expression classes

/// Represents nullary expressions.
class Nullary_expression : public Fixed_arity_node<Expression, 0>
{
public:
  Nullary_expression();
};

inline
Nullary_expression::Nullary_expression()
  : Fixed_arity_node<Expression, 0>()
{ }


/// Represents unary expressions.
class Unary_expression : public Fixed_arity_node<Expression, 1>
{
public:
  Unary_expression(Expression* e);
};

inline
Unary_expression::Unary_expression(Expression* e)
  : Fixed_arity_node<Expression, 1>(e)
{ }


/// Represents binary expressions.
class Binary_expression : public Fixed_arity_node<Expression, 2>
{
public:
  Binary_expression(Expression* e1, Expression* e2);
};

inline
Binary_expression::Binary_expression(Expression* e1, Expression* e2)
  : Fixed_arity_node<Expression, 2>(e1, e2)
{ }


/// Represents ternary expressions.
class Ternary_expression : public Fixed_arity_node<Expression, 3>
{
public:
  Ternary_expression(Expression* e1, Expression* e2, Expression* e3);
};

inline
Ternary_expression::Ternary_expression(Expression* e1, Expression* e2, Expression* e3)
  : Fixed_arity_node<Expression, 3>(e1, e2)
{ }


// Literals

// A literal is a nullary node with a value.
template<typename T>
class Literal : public Nullary_expression
{
public:
  Literal(T const& value);
  /// Constructs a literal from the given value.

  T const& get_value() const { return m_value; }
  /// Returns the value.

private:
  T m_value;  
  /// The interpreted value of the literal.
};

template<typename T>
inline
Literal<T>::Literal(T const& value)
  : m_value(value)
{ }


/// A boolean literal, true or false.
class Boolean_literal : public Literal<bool>
{
public:
  using Literal<bool>::Literal;

  // Evaluation

  Value evaluate() const override;
  /// Compute a value from the expression.

  // Printing
  
  void to_sexpr() const override;
  // Print the literal as an s-expression.


  // Debugging

  void dump(Printer& p) const override;
  /// Emit debug info about the node.
};


/// An integer literal.
class Integer_literal : public Literal<int>
{
public:
  using Literal<int>::Literal;

  // Evaluation

  Value evaluate() const override;
  /// Compute a value from the expression.

  // Printing
  
  void to_sexpr() const override;
  // Print the literal as an s-expression.

  // Debugging

  void dump(Printer& p) const override;
  /// Emit debug info about the node.
};


// Arithmetic expressions

/// Represents expressions of the form `e1 + e2`.
class Add_expression : public Binary_expression
{
public:
  using Binary_expression::Binary_expression;

  // Evaluation

  Value evaluate() const override;
  /// Compute a value from the expression.

  // Printing
  
  void to_sexpr() const override;
  // Print the expression as an s-expression.

  // Debugging

  void dump(Printer& p) const override;
  /// Emit debug info about the node.
};


/// Represents expressions of the form `e1 - e2`.
class Sub_expression : public Binary_expression
{
public:
  using Binary_expression::Binary_expression;

  // Evaluation

  Value evaluate() const override;
  /// Compute a value from the expression.

  // Printing
  
  void to_sexpr() const override;
  // Print the expression as an s-expression.

  // Debugging

  void dump(Printer& p) const override;
  /// Emit debug info about the node.
};


/// Represents expressions of the form `e1 * e2`.
class Mul_expression : public Binary_expression
{
public:
  using Binary_expression::Binary_expression;

  // Evaluation

  Value evaluate() const override;
  /// Compute a value from the expression.

  // Printing
  
  void to_sexpr() const override;
  // Print the expression as an s-expression.

  // Debugging

  void dump(Printer& p) const override;
  /// Emit debug info about the node.
};


/// Represents expressions of the form `e1 / e2`.
class Quo_expression : public Binary_expression
{
public:
  using Binary_expression::Binary_expression;

  // Evaluation

  Value evaluate() const override;
  /// Compute a value from the expression.

  // Printing
  
  void to_sexpr() const override;
  // Print the expression as an s-expression.

  // Debugging

  void dump(Printer& p) const override;
  /// Emit debug info about the node.
};


/// Represents expressions of the form `e1 % e2`.
class Rem_expression : public Binary_expression
{
public:
  using Binary_expression::Binary_expression;

  // Evaluation

  Value evaluate() const override;
  /// Compute a value from the expression.

  // Printing
  
  void to_sexpr() const override;
  // Print the expression as an s-expression.

  // Debugging

  void dump(Printer& p) const override;
  /// Emit debug info about the node.
};


/// Represents expressions of the form `-e`.
class Neg_expression : public Unary_expression
{
public:
  using Unary_expression::Unary_expression;

  // Evaluation

  Value evaluate() const override;
  /// Compute a value from the expression.

  // Debugging

  void dump(Printer& p) const override;
  /// Emit debug info about the node.
};


/// Represents expressions of the form `/e`.
class Rec_expression : public Unary_expression
{
public:
  using Unary_expression::Unary_expression;

  // Evaluation

  Value evaluate() const override;
  /// Compute a value from the expression.

  // Debugging

  void dump(Printer& p) const override;
  /// Emit debug info about the node.
};


/// Represents call expressions of the form `e(e1, e2, ..., en)`.
class Call_expression : public Variable_arity_node<Expression>
{
public:
  using Variable_arity_node<Expression>::Variable_arity_node;

  // Evaluation

  Value evaluate() const override;
  /// Compute a value from the expression.

  // Debugging

  void dump(Printer& p) const override;
  /// Emit debug info about the node.
};
