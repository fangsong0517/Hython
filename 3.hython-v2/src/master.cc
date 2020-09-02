#include <master.h>
#include <single.h>

namespace haizei {

int ExprMaster::run(ASTNode &node, std::share_ptr<Parameter> &p) {
    #define BOP(op) MasterChainRun::run(tree[0], p) op MasterChainRun::run(tree[1], p)
    switch (node.type()) {
        case INT: {
            std::string s = tree.text();
            if(s[0] == '-') {
                return -atoi(s.c_str() + 1);
            }
            else {
                return atoi(s.c_str());
            }
        }
        case ID: {
            return p->get_param(tree.text());
        }
        case PLUS: return BOP(+);
        case MINUS: return BOP(-);
        case TIMES: return BOP(*);
        case DIV: return BOP(/);
        case MOD: return BOP(%);
        case OR: return BOP(||);
        case AND: return BOP(&&);
        case GT: return BOP(>);
        case LITTLE: return BOP(<);
        case EQ: return BOP(==);
        case GE: return BOP(>=);
        case LE: return BOP(<=);
        case NE: return BOP(!=);
        case ASSIGN: {
            std::string var(tree[0].text());
            p->get_param(var);
            int val = run(tree[1]);
            p->set_param(var, val);
            return val;
        }
    }
    #undef BOP
    throw runtime_error(typeid(*this).name() + "Unhandled token: #" + tree.type());
    return 0;
}

int ControlBlockMaster::run(ASTNode &node, share_ptr<Parameter> &p) {
    // TODO
}

int ControlNoBlockExprMaster::run(ASTNode &node, share_ptr<Parameter> &p) {
    // TODO
}

int PrintMaster::run(ASTNode &node, share_ptr<Parameter> &p) {
    // TODO
}

}

