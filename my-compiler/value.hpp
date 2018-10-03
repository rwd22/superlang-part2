#pragma once

/// Represents a value computed by an expression.
///
/// \todo This is actually a variant.
class Value
{
public:
  explicit Value(int n);
  /// Constructs an integer value.

  int get_integer() const;
  /// Returns the integer value.

private:
  int m_value;
};

inline
Value::Value(int n)
  : m_value(n)
{ }

inline int
Value::get_integer() const
{
  return m_value;
}
