#pragma once

#include <cassert>
#include <array>
#include <vector>

/// A node with a statically fixed number of operands N. The type T 
/// specifies the the type of node in the hierarchy.
template<typename T, int N>
class Static_arity_node
{
public:
  Static_arity_node();
  /// Constructs a nullary expression.
  
  Static_arity_node(T* e);
  /// Constructs a unary expression.
  
  Static_arity_node(T* e1, T* e2);
  /// Constructs a binary expression.

  Static_arity_node(T* e1, T* e2, T* e3);
  /// Constructs a ternary expression.

  // Accessors

  static constexpr int get_arity() { return N; }
  /// Returns the arity of the expression.

  T* get_child(int n) const;
  /// Returns the nth operand.

  T* get_child() const;
  /// Returns the sole operand. This is valid only when N == 1.

  // Iteration

  T** begin() { return m_ops.data(); }
  /// Returns an iterator pointing to the first operand.
  
  T** end() { return m_ops.data() + m_ops.size(); }
  /// Returns an iterator pointing past the last operand.

  T* const* begin() const { return m_ops.data(); }
  /// Returns an iterator pointing to the first operand.
  
  T* const* end() const { return m_ops.data() + m_ops.size(); }
  /// Returns an iterator pointing past the last operand.

private:
  std::array<T*, N> m_ops;
};

template<typename T, int N>
inline
Static_arity_node<T, N>::Static_arity_node()
  : m_ops()
{
  assert(N == 0);
}

template<typename T, int N>
inline
Static_arity_node<T, N>::Static_arity_node(T* e)
  : m_ops {e}
{
  assert(N == 1);
}

template<typename T, int N>
inline Static_arity_node<T, N>::Static_arity_node(T* e1, T* e2)
  : m_ops {e1, e2}
{
  assert(N == 2);
}

template<typename T, int N>
inline Static_arity_node<T, N>::Static_arity_node(T* e1, T* e2, T* e3)
  : m_ops {e1, e2, e3}
{
  assert(N == 3);
}

template<typename T, int N>
inline T*
Static_arity_node<T, N>::get_child(int n) const
{
  assert(0 <= n && n < N);
  return m_ops[n];
}

template<typename T, int N>
inline T*
Static_arity_node<T, N>::get_child() const
{
  static_assert(N == 1);
  return m_ops[0];
}


/// An expression with a variable number of operands.
///
/// \todo Supply an allocator so that we can ensure that all memory for
/// a single tree is allocated from the same pool.
template<typename T>
class Dynamic_arity_node
{
public:
  Dynamic_arity_node(std::initializer_list<T*> list);
  /// Constructs the node with the children in `list`.

  Dynamic_arity_node(std::vector<T*> const& vec);
  /// Constructs the node with the children in `vec`.

  Dynamic_arity_node(std::vector<T*>&& vec);
  /// Constructs the node with the children in `vec`.

  // Accessors

  int get_arity() const { return m_ops.size(); }
  /// Returns the arity of the expression.

  T* get_child(int n) const;
  /// Returns the nth operand of the node.

  // Iteration

  T** begin() { return m_ops.data(); }
  /// Returns an iterator pointing to the first operand.
  
  T** end() { return m_ops.data() + m_ops.size(); }
  /// Returns an iterator pointing past the last operand.

  T* const* begin() const { return m_ops.data(); }
  /// Returns an iterator pointing to the first operand.
  
  T* const* end() const { return m_ops.data() + m_ops.size(); }
  /// Returns an iterator pointing past the last operand.

private:
  std::vector<T*> m_ops;
};

template<typename T>
inline
Dynamic_arity_node<T>::Dynamic_arity_node(std::initializer_list<T*> list)
  : m_ops(list)
{ }

template<typename T>
inline
Dynamic_arity_node<T>::Dynamic_arity_node(std::vector<T*> const& vec)
  : m_ops(vec)
{ }

template<typename T>
inline
Dynamic_arity_node<T>::Dynamic_arity_node(std::vector<T*>&& vec)
  : m_ops(std::move(vec))
{ }

template<typename T>
inline T*
Dynamic_arity_node<T>::get_child(int n) const
{
  return m_ops[n];
}
