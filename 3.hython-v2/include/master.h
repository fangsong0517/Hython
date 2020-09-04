/*************************************************************************
	> File Name: master.h
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月02日 星期三 10时47分44秒
 ************************************************************************/

#ifndef _MASTER_H
#define _MASTER_H

#include <memory>
#include <AST.h>
#include <parameter.h>

namespace haizei {

class IMaster {
public :
    virtual int run(ASTNode &, std::shared_ptr<Parameter> &) = 0;
};

class ExprMaster : public IMaster {
public :
    virtual int run(ASTNode &, std::shared_ptr<Parameter> &);
};

class ControlBlockMaster : public IMaster {
public :
    virtual int run(ASTNode &, std::shared_ptr<Parameter> &);
};

class ControlNoBlockMaster : public IMaster {
public :
    virtual int run(ASTNode &, std::shared_ptr<Parameter> &);
};

class PrintMaster : public IMaster {
public :
    virtual int run(ASTNode &, std::shared_ptr<Parameter> &);
};

} // end of namespace haizei
#endif
