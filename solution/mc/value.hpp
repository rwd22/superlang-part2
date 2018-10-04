#pragma once

/// Represents a value computed by an expression.
///
/// \todo This is actually a variant.
class Value
{
public:
  explicit Value(int n);
  /// Constructs an integer value.

  int get_int() const;
  /// Returns the integer value.

  double get_float() const;
  /// Returns the floating point value.

private:
  int m_value;
};

inline
Value::Value(int n)
  : m_value(n)
{ }

inline int
Value::get_int() const
{
  return m_value;
}

inline double
Value::get_float() const
{
  return m_value;
}
