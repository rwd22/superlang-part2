#pragma once

#include <iostream>

struct Expr;

struct Location;

struct Decl;

struct Stmt
{

};

using Stmt_seq = std::vector<Stmt*>;

struct Break_stmt : Stmt
{
    Location* loc;
};

struct Cont_stmt : Stmt
{
    Location* loc;
};

struct Block_stmt : Stmt
{
    Stmt_seq* stmts;
};

struct While_stmt : Stmt
{
    Expr* cond;
    Stmt* body;
};

struct Ternary_stmt : Stmt
{
    Expr* cond;
    Stmt* then;
    Stmt* els;
};

struct Return_stmt : Stmt
{
    Stmt* stmt;
};

struct Expression_stmt : Stmt
{
    Expr* expr;
};

struct Local_defn_stmt : Stmt
{
    Decl* decl;
};