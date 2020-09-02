/*************************************************************************
	> File Name: ExprTreeEvaluator.h
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月29日 星期六 09时12分42秒
 ************************************************************************/

#ifndef _EXPRTREEEVALUATOR_H
#define _EXPRTREEEVALUATOR_H

#include <string>
#include <map>
#include <AST.h>

class ExprTreeEvaluator {
public:
    ExprTreeEvaluator();
    ExprTreeEvaluator(ExprTreeEvaluator *);
    int run(haizei::ASTNode);
    void def_param(std::string, int);
    void set_param(std::string, int);
    int get_param(std::string);
    ExprTreeEvaluator *next;

private :
    std::map<std::string,int> memory;
};

#endif

