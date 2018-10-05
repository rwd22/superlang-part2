#pragma once

#include <iosfwd>


struct Expr
{
	enum Kind
	{
   		bool_lit,
   	 	int_lit,
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


};



struct Bool_lit : Expr
{

public:
  Bool_lit( bool val )
    : Expr(bool_lit), m_val(val) 
  { }

	bool get_val() const { return m_val; }

private:

	bool m_val;
};

struct Int_lit : Expr
{

public:
  Int_lit( int val )
    : Expr(bool_lit), m_val(val) 
  { }

	int get_val() const { return m_val; }

private:

	int m_val;
};


std::ostream& operator<<(std::ostream& os, Expr const& e);


void print(std::ostream& os, Expr const* e);


bool equal(Expr const* e1, Expr const* e2);
