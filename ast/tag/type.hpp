
struct Type
{
  enum Kind {
    bool_t,
    int_t,
    ref_t,
  };

  Type(Kind k) // Make me protected
    : kind(k)
  { }

  Kind kind;
  /// Stores the kind of type.
};

struct Bool_type : Type
{
  Bool_type()
    : Type(bool_t)
  { }
};

struct Int_type : Type
{
  Int_type()
    : Type(int_t)
  { }

};

struct Ref_type : Type
{
  Ref_type(Type* t)
    : Type(ref_t), ptr(t)
  { }

  Type* ptr;
};

inline void
print(Type const* t)
{
  switch (t->kind) {
  case bool_t:
    static_cast<Bool_type const*>(t)
  case int_t:
  case ref_t:
  }
}


