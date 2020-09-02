#include <handle.h>
namespace haizei {

Handle::Handle(Handle *next) : __next(next) {}
ExprHandle::ExprHandle(Handle *next) : Handle(next) {}
ControlBlockHandle::ControlBlockHandle(Handle *next) : Handle(next) {}
ControlNoBlockHandle::ControlNoBlockHandle(Handle *next) : Handle(next) {}
PrintHandle::PrintHandle(Handle *next) : Handle(next) {}

Handle *Handle::next() { return this->__next; }

bool ExprHandle::Test(const ASTNode &n) {
    switch (n.type()) {
        case INT: 
        case ID: 
        case PLUS:
        case MINUS:
        case TIMES:
        case DIV:
        case MOD:
        case OR: 
        case AND:
        case GT:
        case LITTLE:
        case EQ: 
        case GE: 
        case LE: 
        case NE: return true;
    }
    return false;
}

bool ControlBlockHandle::Test(const ASTNode &n) {
    switch (n.type()) {
        case BLOCK:
        case FOR: return true;
    }
    return false;
}

bool ControlNoBlockHandle::Test(const ASTNode &n) {
    switch (n.type()) {
        case IF:
        case WHILE: 
        case DOWHILE: return true;
    }
    return false;
}

bool PrintHandle::Test(const ASTNode &n) {
    switch (n.type()) {
        case PRINT: return true;
    }
    return false;
}

}

