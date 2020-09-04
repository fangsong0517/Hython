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

namespace haizei {

class ExprTreeEvaluator {
public:
    ExprTreeEvaluator();
    int run(haizei::ASTNode);
};

}

#endif
