#include <master.h>
#include <iostream>
#include <single.h>

namespace haizei {

int ExprMaster::run(ASTNode &tree, std::shared_ptr<Parameter> &p) {
    #define BOP(op) MasterChainSingle::run(tree[0], p) op MasterChainSingle::run(tree[1], p)
    #define MR(a, b) MasterChainSingle::run(a, b)
    switch (tree.type()) {
        case DEF: { 
            int init_val = 0;
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
            int val = MR(tree[1], p);
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

int ControlBlockMaster::run(ASTNode &tree, std::shared_ptr<Parameter> &p) {
    #define MR(a, b) MasterChainSingle::run(a, b)
    std::shared_ptr<Parameter> newp = std::make_shared<Parameter>(p);
    switch (tree.type()) {
        case BLOCK: {
            for (int i = 0; i < tree.size(); i++) {
                int val = MR(tree[i], newp);
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

int ControlNoBlockMaster::run(ASTNode &tree, std::shared_ptr<Parameter> &p) {
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

int PrintMaster::run(ASTNode &tree, std::shared_ptr<Parameter> &p) {
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
