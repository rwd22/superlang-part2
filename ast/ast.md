# Formal languages

A formal language is defined by a set of strings (of symbols, over an
alphabet), typically having a set of rules needed to specify which 
combinations of symbols form valid strings and the meaning of those
strings.

The rules that specify which strings are valid are typically referred 
as *syntactic rules*, which govern the basic formation of strings from
sequences of symbols. The rules that assign meaning to strings are
the *semantics* of the language. 

Without those rules, however, we are simply left working with uninterpreted
strings. For example, a language for a simple arithmetic
calculator might include the following strings:

```
0
1
3 + 4
x * 2 + (6 - y)
n / 0
```

We could try to define the language by enumerating all possible strings,
but that set is infinite; this doesn't work. Instead, we can enumerate
patterns or schemas that generate structurally similar strings. If we
are defining `e` be the set of all strings representing arithmetic
expressions, then our set might be:

```
e ::= n        -- the numbers 0, 1, 2, ...
      e1 + e2  -- addition
      e1 - e2  -- subtraction
      e1 * e2  -- multiplication
      e1 / e2  -- division
```

Note that we could have written e.g., `e1 + e2` as simply `e + e`. However,
we use subscripts so that we can refer to each substring as distinct
entities. Strings that are not self-referential are called *literals* or
sometimes *terminals*, depending on the usage. 

We will often use parentheses to show appropriate grouping of expressions
(e.g., `(3 + 2) + 2)` groups `(3 + 2)` as the left hand side of an addition
and `2` as the right hand side.

This definition lets us generate all strings in the language using a simple 
algorithm.

1. e_0 the set of all numbers denoted by n
2. The set e_i is the union of e_i-1 and the set formed by taking non-literal 
   and substituting all combinations of e_i-1 for references to e. For
   example, e_1 will include {0, 1, 2, ..., 0 + 0, 0 + 1, 1 + 0, ...}.

There are some nice theoretical properties of this set, but that's outside
of the scope of this discussion. The remainder of these notes discuss
implementation strategies and tradeoffs.

The set `e` defines the *abstract syntax* of our language. It defines only
which strings are in the language, but not specific rules about how those
strings might be formed. For example, the string lexical string 
`4 + 5 * 2` can be associated with two elements of `e`:

- `(4 + 5) * 2`
- `4 + (5 * 2)`

The rules for determining which meaning the lexical string has is not
a property of the *concrete* syntax of the language. The rules for transforming
concrete syntax into abstract syntax will be discussed later.

# Abstract syntax trees

Compilers operate on the strings of a language; they apply a lot of different
analyses those strings in order verify, optimize, and transform them. It
is not effective to represent programs as sequences of symbols. The analyses
we want to use require knowledge of the structure of those strings. More
specifically, we find it easiest to analyze or interpret strings based on
the syntactic structure, which is conveniently presented the definition
of our language, `e`. In other words, our aim is to build a data structure
that captures or encodes that structure, not just the sequence of symbols.

This data structure is called an abstract syntax tree or AST.
An AST represents strings of a language. For example, the `3 + x` is a
string in a language; `3` and `x` are also strings. An implementation of 
an AST for this language would necessarily include data structures that
represent the strings `3`, `x` and the combination of those using `+`.

In imperative or object-oriented languages, we typically implement ASTs
using class hierarchies. The base class represents all strings of the
language, and its derived classes represent specific subsets of strings.
In the language above, we might represent this as:

```c++
/// Represents all expressions in the language (expressions are strings).
struct Expr 
{
};

// Represents all strings of the form `n` where `n` is a nonnegative
// integer literal.
struct Int_expr : Expr 
{
  int value; // Stores the value of `n`.
};

// Represents all strings of the form `x` where `x` is an identifier
// that denotes an object, reference, or function.
struct Id_expr : Expr 
{
  string id; // Stores the spelling of `x`.
};

// Represents all strings of the form `e1 + e2` where `e1` and `e2`
// are expressions.
struct Add_expr : Expr 
{
  Expr* lhs; // Points to e1.
  Expr* rhs; // Points to e2.
};
```

# Functions on ASTs

An function (query, transformation, etc.) on an AST is typically defined
in terms of specific behaviors for each subset of strings. For example, if
we want to evaluate (compute a value for) the language above, then we would
need to define what it means to evaluate integers, identifiers, and
additions. In other words, functions are ASTs are piecewise definitions.

Abstractly, such a function might look like this:

```c++
/// Evaluates an expression. This returns the value denoted by
/// the operators and operands in the expression.
int evaluate(Expr const* e);
```

However, the implementation should consist of more specific behaviors:

```c++
/// Returns the value corresponding to an integer literal.
int evaluate_int(Int_expr const* e);

/// Returns the value corresponding to an identifier.
int evaluate_id(Id_expr const* e);

/// Returns the value corresponding to the addition of two operands.
int evaluate_add(Add_expr const* e);
```

The only job of the original function is to determine what kind of expression
is being evaluated and then dispatch to one of the more specific behaviors.

It sometimes helps to to think of behavior as a lookup table where each
element is a behavior defined for a subset of strings. For example:

```
+----------+--------------+
| Int_expr | evaluate_int |
| Id_expr  | evaluate_id  |
| Add_expr | evaluate_add |
+----------+--------------+
```

The `evaluate` function simply lookups the corresponding behavior in the
table and executes it. 

# Functions with multiple AST arguments

Some operations require multiple ASTs as inputs. These operations need to
select a behavior for corresponding to the types of *all* arguments. For
example, suppose we want to define an operation to see if two expressions
are syntactically equivalent (i.e., have similar spellings). Our function 
for computing that might be this:

```c++
bool equivalent(Expr const* a, Expr const* b);
```

Both `a` or `b` could represent any string in the language. This means that
we could have 9 possible behaviors:
- Int_expr with Int_expr
- Int_expr with Id_expr
- Int_expr with Add_expr
- etc.

In other words, our implementation might have the following behaviors:

```c++
bool eq_int_int(Expr const* a, Expr const* b);
bool eq_int_id(Expr const* a, Expr const* b);
bool eq_int_add(Expr const* a, Expr const* b);
// etc.
```

Again the job of the "main" function is to select a specific behavior to
execute. In this case, however, the table is 2-dimensional.

```
|          | Int_expr   | Id_expr   | Add_expr   |
+----------+------------+-----------+------------+
| Int_expr | eq_int_int   eq_int_id   eq_int_add |
| Id_expr  | eq_id_int    eq_id_id    eq_id_add  |
| Add_expr | eq_add_int   eq_add_id   eq_add_add |
+----------+-------------------------------------+
```

For this particular function, the behavior is actually a bit simpler. A
string (i.e., AST node) is only equivalent to strings of the same form
or "shape". For example, `3 + 4` is never equivalent to just `3`. In other
words, our table is really this:

```
|          | Int_expr   | Id_expr   | Add_expr   |
+----------+------------+-----------+------------+
| Int_expr | eq_int_int   false       false      |
| Id_expr  | false        eq_id_id    false      |
| Add_expr | false        false       eq_add_add |
+----------+-------------------------------------+
```

Specific behaviors reside along the diagonal and false everywhere else.


# Implementing operations on ASTs

There are three ways to implement this behavior on C++ class hierarchies used
to represent ASTs.
1. Virtual functions (virtual)
2. Polymorphic Visitors (visitor)
3. Discriminated ASTs (switch)
4. Generic Visitors (generic)

Only the first three are worth talking about in detail because they're the
most obvious. The last requires significant programming know-how.

Each approach as pros and cons, which are documented in the various
subdirectories.

