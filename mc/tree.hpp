#pragma once

#include <cassert>
#include <array>
#include <vector>

/// A node with a fixed number of operands. The base class B parameter 
/// specifies the hierarchy.
template<typename B, int N>
class Fixed_arity_node : public B
{
public:
  Fixed_arity_node();
  /// Constructs a nullary expression.
  
  Fixed_arity_node(B* e);
  /// Constructs a unary expression.
  
  Fixed_arity_node(B* e1, B* e2);
  /// Constructs a binary expression.

  Fixed_arity_node(B* e1, B* e2, B* e3);
  /// Constructs a ternary expression.

  // Accessors

  static constexpr int get_arity() { return N; }
  /// Returns the artiy of the expression.

  B* get_operand(int n) const;
  /// Returns the nth operand.

  B* get_operand() const;
  /// Returns the sole operand. This is valid only when N == 1.

  // Iteration

  B** begin() { return m_ops.data(); }
  /// Returns an iterator pointing to the first operand.
  
  B** end() { return m_ops.data() + m_ops.size(); }
  /// Returns an iterator pointing past the last operand.

  B* const* begin() const { return m_ops.data(); }
  /// Returns an iterator pointing to the first operand.
  
  B* const* end() const { return m_ops.data() + m_ops.size(); }
  /// Returns an iterator pointing past the last operand.

private:
  std::array<B*, N> m_ops;
};

template<typename B, int N>
inline
Fixed_arity_node<B, N>::Fixed_arity_node()
  : m_ops()
{
  assert(N == 0);
}

template<typename B, int N>
inline
Fixed_arity_node<B, N>::Fixed_arity_node(B* e)
  : m_ops {e}
{
  assert(N == 1);
}

template<typename B, int N>
inline Fixed_arity_node<B, N>::Fixed_arity_node(B* e1, B* e2)
  : m_ops{e1, e2}
{
  assert(N == 2);
}

template<typename B, int N>
inline Fixed_arity_node<B, N>::Fixed_arity_node(B* e1, B* e2, B* e3)
  : m_ops{e1, e2, e3}
{
  assert(N == 3);
}

template<typename B, int N>
inline B*
Fixed_arity_node<B, N>::get_operand(int n) const
{
  assert(0 <= n && n < N);
  return m_ops[n];
}

template<typename B, int N>
inline B*
Fixed_arity_node<B, N>::get_operand() const
{
  static_assert(N == 1);
  return m_ops[0];
}


/// An expression with a variable number of operands.
template<typename B>
class Variable_arity_node : public B
{
public:
  Variable_arity_node(std::initializer_list<B*> list);
  /// Constructs the node with a list of operators.

  // Accessors

  int get_arity() const { return m_ops.size(); }
  /// Returns the arity of the expression.

  B* get_operand(int n) const;
  /// Returns the nth operand of the node.

  // Iteration

  B** begin() { return m_ops.data(); }
  /// Returns an iterator pointing to the first operand.
  
  B** end() { return m_ops.data() + m_ops.size(); }
  /// Returns an iterator pointing past the last operand.

  B* const* begin() const { return m_ops.data(); }
  /// Returns an iterator pointing to the first operand.
  
  B* const* end() const { return m_ops.data() + m_ops.size(); }
  /// Returns an iterator pointing past the last operand.

private:
  std::vector<B*> m_ops;
};

template<typename B>
inline
Variable_arity_node<B>::Variable_arity_node(std::initializer_list<B*> list)
  : m_ops(list)
{ }

template<typename B>
inline B*
Variable_arity_node<B>::get_operand(int n) const
{
  return m_ops[n];
}
