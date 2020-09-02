/*************************************************************************
	> File Name: handle.h
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月02日 星期三 09时27分29秒
 ************************************************************************/

#ifndef _HANDLE_H
#define _HANDLE_H
#include <AST.h>
namespace haizei {

class IHandle {
public :
    Handle(IHandle *);
    virtual bool Test(const ASTNode &) const = 0;
    IHandle *next() const;

private:
    IHandle *__next;
};

class ExprHandle : public IHandle {
public :
    ExprHandle(IHandle *);
    bool Test(const ASTNode &) const ;
};

class ControlBlockHandle : public IHandle {
public :
    ControlBlockHandle(IHandle *);
    bool Test(const ASTNode &) const;
};

class ControlNoBlockHandle : public IHandle {
public :
    ControlNoBlockHandle(IHandle *);
    bool Test(const ASTNode &) const;
};

class PrintHandle : public IHandle {
public :
    PrintHandle(IHandle *);
    bool Test(const ASTNode &) const;
};

}

#endif
