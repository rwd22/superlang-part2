#pragma once

#include <iosfwd>

#include "type.hpp"

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
  Bool_lit( bool val, Type* t)
    : Expr(bool_lit), m_val(val), m_type(t)
  { }

	bool get_val() const { return m_val; }
	Type* get_type() const { return m_type; }

private:

	bool m_val;
	Type* m_type;
};

struct Int_lit : Expr
{

public:
  Int_lit( int val, Type* t)
    : Expr(bool_lit), m_val(val), m_type(t)
  { }

	int get_val() const { return m_val; }
	Type* get_type() const { return m_type; }

private:

	int m_val;
	Type * m_type;
};

struct Add_expr : Expr
{

public:
	Add_expr(Expr* e1, Expr* e2)
		: Expr(add_expr), m_e1(e1), m_e2(e2)
	{ }

	Expr* get_expr1() const {return m_e1;}
	Expr* get_expr2() const {return m_e2;}


private:

	Expr* m_e1;
	Expr* m_e2;
	
};












std::ostream& operator<<(std::ostream& os, Expr const& e);


void print(std::ostream& os, Expr const* e);

void sexpr(std::ostream& os, Expr const *e);
