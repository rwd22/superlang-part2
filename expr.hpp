#pragma once



struct Expr
{
	enum Kind
	{
   		bool_lit,
   	 	int_lit,
   		float_lit,
   	 	id_expr,
   	 	add_expr,
   	 	sub_expr,
   	 	mul_expr,
   	 	div_expr,
   	 	rem_expr,
   	 	neg_expr,
   	 	rec_expr,
   	 	eq_expr,
    	ne_expr,
    	lt_expr,
    	gt_expr,
    	lte_expr,
    	gte_expr,
    	con_expr,
    	and_expr,
    	or_expr,
    	not_expr,
	};

protected:
  Expr(Kind k) : m_kind(k) { }
  

public:
  Kind get_kind() const { return m_kind; }


private:
  Kind m_kind;

  Type* m_type;

};



struct Bool_expr : Expr
{
	Value evaluate() const override 
	{
		return Value(value); 
	}

	bool value;
};

struct Int_expr : Expr
{
	Value evaluate() const override 
	{
		return Value(value); 
	}
	int value;
};

struct Float_expr : Exprr
{
	Value evaluate() const override 
	{
		return Value(value); 
	}

	float value;
};

struct Add_expr : Expr
{
	Value evaluate() const override 
	{
		Value v1 = e1->evaluate();
		Value v2 = e2->evaluate();

		if (v1.kind() != v2.kind())
			throw std::logic_error("oops");

		if (v1.kind() == Value::int_val)
			return v1.get_int() + v2.get_int();

		else if (v1.kind() == Value::float)
			return Value(v1.get_float() + v2.get_float())

		throw std::logic_error("unknown value");
 	}

	Expr* expr1;
	Expr* expr2;
};

struct Sub_expr : Expr
{
	Value evaluate() const override 
	{
		Value v1 = e1->evaluate();
		Value v2 = e2->evaluate();

		if (v1.kind() != v2.kind())
			throw std::logic_error("Wrong kinds");

		if (v1.kind() == Value::int_val)
			return v1.get_int() - v2.get_int();

		else if (v1.kind() == Value::float)
			return Value(v1.get_float() - v2.get_float())

		throw std::logic_error("unknown value");
 	}

	Expr* expr1;
	Expr* expr2;
};

struct Eq_expr : Expr
{
	Value evaluate() const override
	{
		return e1->evaluate() == e2->evaluate();
	}

	Expr* expr1;
	Expr* expr2;
};
