
#pragma

class Visitor
{
  virtual void visit(Bool_type* b) { }
  virtual void visit(Int_type* b) { }
  virtual void visit(Ref_type* b) { }
};

class Type
{
  // One of two choices:
  // 
  // A bunch of virtual functions.
  // visitor pattern.

  // Makes this "pure OO".
  virtual void print() const = 0;

  virtual void accept(Visitor& v);
};

class Bool_type : public Type
{
  void accept(Visitor& v) override { v.visit(this); }
};

class Int_type : public Type
{
  void accept(Visitor& v) override { v.visit(this); }
};

class Ref_type : public Type
{
  void accept(Visitor& v) override { v.visit(this); }
};

class Size_visitor : public Visitor
{
  void visit(Bool_type* b) { size = 1;}
  void visit(Bool_type* b) { size = 4; }
  void visit(Ref_type* r) { size = 8; }

  int size;
};

