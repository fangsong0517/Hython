#include <master.h>
#include <iostream>
#include <single.h>
#include <value.h>
namespace haizei {

SIValue ExprMaster::run(ASTNode &tree, std::shared_ptr<Parameter> &p) {
    #define BOP(op) (*MasterChainSingle::run(tree[0], p)) op (*MasterChainSingle::run(tree[1], p))
    #define MR(a, b) MasterChainSingle::run(a, b)
    switch (tree.type()) {
        case DEF: { 
            SIValue init_val = HZNULL;
            for (int i = 0; i < tree.size(); i++) {
                std::string var(tree[i].text());
                init_val = 0;
                if (tree[i].size() == 1) {
                    init_val = MR(tree[i][0], p);
                }
                p->def_param(var, init_val);
            }
            return init_val;
        } break;
        case INT: {
            std::string s = tree.text();
            if(s[0] == '-') {
                return std::make_shared<IntValue>(-atoi(s.c_str() + 1));
            }
            else {
                return std::make_shared<IntValue>(atoi(s.c_str()));
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
        case OR: {
            if (MR(tree[0], p)->isTrue()) return HZTrue;
            if (MR(tree[1], p)->isTrue()) return HZTrue;
            return HZFalse;
        } break;
        case AND: {
            if (MR(tree[0], p)->isFalse()) return HZFalse;
            if (MR(tree[1], p)->isFalse()) return HZFalse;
            return HZTrue;
        } break;
        case GT: return BOP(>) ? HZTrue : HZFalse;
        case LITTLE: return BOP(<) ? HZTrue : HZFalse;
        case EQ: return BOP(==) ? HZTrue : HZFalse;
        case GE: return BOP(>=) ? HZTrue : HZFalse;
        case LE: return BOP(<=) ? HZTrue : HZFalse;
        case NE: return BOP(!=) ? HZTrue : HZFalse;
        case ASSIGN: {
            std::string var(tree[0].text());
            p->get_param(var);
            SIValue val = MR(tree[1], p);
            p->set_param(var, val);
            return val;
        }
    }
    #undef MR
    #undef BOP
    throw std::runtime_error(
        std::string(typeid(*this).name()) 
        + std::string("Unhandled token: #")
        + std::to_string(tree.type())
    );
    return 0;
}

SIValue ControlBlockMaster::run(ASTNode &tree, std::shared_ptr<Parameter> &p) {
    #define MR(a, b) MasterChainSingle::run(a, b)
    std::shared_ptr<Parameter> newp = std::make_shared<Parameter>(p);
    switch (tree.type()) {
        case BLOCK: {
            for (int i = 0; i < tree.size(); i++) {
                SIValue val = MR(tree[i], newp);
            }
            return 0;
        } break;
        case FOR: {
            for (MR(tree[0], newp); MR(tree[1], newp); MR(tree[2], newp)) {
                MR(tree[3], newp);
            }
            return 0;
        } break;
    }
    #undef MR
    throw std::runtime_error(
        std::string(typeid(*this).name()) 
        + std::string("Unhandled token: #") 
        + std::to_string(tree.type())
    );
    return 0;
}

SIValue ControlNoBlockMaster::run(ASTNode &tree, std::shared_ptr<Parameter> &p) {
    #define MR(a, b) MasterChainSingle::run(a, b)
    switch (tree.type()) {
        case IF: {
            if (MR(tree[0], p)) {
                MR(tree[1], p);
            } else if (tree.size() == 3) {
                MR(tree[2], p);
            }
            return 0;
        } break;
        case WHILE: {
            while (MR(tree[0], p)) {
                MR(tree[1], p);
            }
            return 0;
        }
        case DOWHILE: {
            do {
                MR(tree[1], p);
            } while (MR(tree[0], p));
            return 0;
        } break;
    }
    #undef MR
    throw std::runtime_error(
        std::string(typeid(*this).name()) 
        + std::string("Unhandled token: #") 
        + std::to_string(tree.type())
    );
    return 0;
}

SIValue PrintMaster::run(ASTNode &tree, std::shared_ptr<Parameter> &p) {
    #define MR(a, b) MasterChainSingle::run(a, b)
    switch (tree.type()) { 
        case PRINT: {
            for (int i = 0; i < tree.size(); i++) {
                i && std::cout << " ";
                std::cout << MR(tree[i], p);
            }
            std::cout << std::endl;
            return 0;
        } break;
    }
    #undef MR
    throw std::runtime_error(
        std::string(typeid(*this).name()) 
        + std::string("Unhandled token: #") 
        + std::to_string(tree.type())
    );
    return 0;
}

}

