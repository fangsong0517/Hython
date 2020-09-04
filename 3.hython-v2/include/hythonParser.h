/** \file
 *  This C header file was generated by $ANTLR version 3.4
 *
 *     -  From the grammar source file : ./thirdpart/hython.g
 *     -                            On : 2020-09-04 18:19:57
 *     -                for the parser : hythonParserParser
 *
 * Editing it, at least manually, is not wise.
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser 
hythonParser

has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 *
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef phythonParser, which is returned from a call to hythonParserNew().
 *
 * The methods in phythonParser are  as follows:
 *
 *  - 
 hythonParser_defid_expr_return
      phythonParser->defid_expr(phythonParser)
 *  - 
 hythonParser_defid_return
      phythonParser->defid(phythonParser)
 *  - 
 hythonParser_condition_expr_return
      phythonParser->condition_expr(phythonParser)
 *  - 
 hythonParser_andExpr_return
      phythonParser->andExpr(phythonParser)
 *  - 
 hythonParser_cmp_atom_return
      phythonParser->cmp_atom(phythonParser)
 *  - 
 hythonParser_cond_atom_return
      phythonParser->cond_atom(phythonParser)
 *  - 
 hythonParser_expr_return
      phythonParser->expr(phythonParser)
 *  - 
 hythonParser_multExpr_return
      phythonParser->multExpr(phythonParser)
 *  - 
 hythonParser_atom_return
      phythonParser->atom(phythonParser)
 *  - 
 hythonParser_if_expr_return
      phythonParser->if_expr(phythonParser)
 *  - 
 hythonParser_for_expr_return
      phythonParser->for_expr(phythonParser)
 *  - 
 hythonParser_while_expr_return
      phythonParser->while_expr(phythonParser)
 *  - 
 hythonParser_init_expr_return
      phythonParser->init_expr(phythonParser)
 *  - 
 hythonParser_for_do_expr_return
      phythonParser->for_do_expr(phythonParser)
 *  - 
 hythonParser_block_return
      phythonParser->block(phythonParser)
 *  - 
 hythonParser_block_tree_return
      phythonParser->block_tree(phythonParser)
 *  - 
 hythonParser_stmt_return
      phythonParser->stmt(phythonParser)
 *  - 
 hythonParser_prog_return
      phythonParser->prog(phythonParser)
 * 
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD license"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_hythonParser_H
#define _hythonParser_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct hythonParser_Ctx_struct hythonParser, * phythonParser;



    #include <assert.h>


#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif

/* ========================
 * BACKTRACKING IS ENABLED
 * ========================
 */

typedef struct hythonParser_defid_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_defid_expr_return;



typedef struct hythonParser_defid_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_defid_return;



typedef struct hythonParser_condition_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_condition_expr_return;



typedef struct hythonParser_andExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_andExpr_return;



typedef struct hythonParser_cmp_atom_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_cmp_atom_return;



typedef struct hythonParser_cond_atom_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_cond_atom_return;



typedef struct hythonParser_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_expr_return;



typedef struct hythonParser_multExpr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_multExpr_return;



typedef struct hythonParser_atom_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_atom_return;



typedef struct hythonParser_if_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_if_expr_return;



typedef struct hythonParser_for_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_for_expr_return;



typedef struct hythonParser_while_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_while_expr_return;



typedef struct hythonParser_init_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_init_expr_return;



typedef struct hythonParser_for_do_expr_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_for_do_expr_return;



typedef struct hythonParser_block_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_block_return;



typedef struct hythonParser_block_tree_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_block_tree_return;



typedef struct hythonParser_stmt_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_stmt_return;



typedef struct hythonParser_prog_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;
    pANTLR3_BASE_TREE	tree;

}
    hythonParser_prog_return;




/** Context tracking structure for 
hythonParser

 */
struct hythonParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;

     hythonParser_defid_expr_return
     (*defid_expr)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_defid_return
     (*defid)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_condition_expr_return
     (*condition_expr)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_andExpr_return
     (*andExpr)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_cmp_atom_return
     (*cmp_atom)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_cond_atom_return
     (*cond_atom)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_expr_return
     (*expr)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_multExpr_return
     (*multExpr)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_atom_return
     (*atom)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_if_expr_return
     (*if_expr)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_for_expr_return
     (*for_expr)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_while_expr_return
     (*while_expr)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_init_expr_return
     (*init_expr)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_for_do_expr_return
     (*for_do_expr)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_block_return
     (*block)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_block_tree_return
     (*block_tree)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_stmt_return
     (*stmt)	(struct hythonParser_Ctx_struct * ctx);

     hythonParser_prog_return
     (*prog)	(struct hythonParser_Ctx_struct * ctx);

     ANTLR3_BOOLEAN
     (*synpred1_hython)	(struct hythonParser_Ctx_struct * ctx);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct hythonParser_Ctx_struct * ctx);
    void	    (*free)   (struct hythonParser_Ctx_struct * ctx);
/* @headerFile.members() */
pANTLR3_BASE_TREE_ADAPTOR	adaptor;
pANTLR3_VECTOR_FACTORY		vectors;
/* End @headerFile.members() */
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API phythonParser hythonParserNew         (
pANTLR3_COMMON_TOKEN_STREAM
 instream);
ANTLR3_API phythonParser hythonParserNewSSD      (
pANTLR3_COMMON_TOKEN_STREAM
 instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the 
parser
 will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif
#define EOF      -1
#define T__39      39
#define T__40      40
#define T__41      41
#define T__42      42
#define T__43      43
#define AND      4
#define ASSIGN      5
#define BLOCK      6
#define COMMENT      7
#define DEF      8
#define DIV      9
#define DO      10
#define DOT      11
#define DOWHILE      12
#define ELSE      13
#define EQ      14
#define ESC_SEQ      15
#define EXPONENT      16
#define FLOAT      17
#define FOR      18
#define GE      19
#define GT      20
#define HEX_DIGIT      21
#define ID      22
#define IF      23
#define INT      24
#define LE      25
#define LITTLE      26
#define MINUS      27
#define MOD      28
#define NE      29
#define OCTAL_ESC      30
#define OR      31
#define PLUS      32
#define PRINT      33
#define STRING      34
#define TIMES      35
#define UNICODE_ESC      36
#define WHILE      37
#define WS      38
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for hythonParser
 * =============================================================================
 */
/** } */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
