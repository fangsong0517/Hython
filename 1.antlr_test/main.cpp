/*************************************************************************
	> File Name: main.cpp
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年08月24日 星期一 09时56分46秒
 ************************************************************************/
#include "ExprCppTreeLexer.h"
#include "ExprCppTreeParser.h"
#include <cassert>
#include <map>
#include <string>
#include <iostream>
using std::map;
using std::string;
using std::cout;
using std::endl;
 
class ExprTreeEvaluator {
    map<string,int> memory;//字符串到整形的map映射,保存每一个变量的值例如a = b + 1;
public:
    int run(pANTLR3_BASE_TREE);//传入抽象语法树,返回一个值,获得值,
    void set_param(string, int);
    int get_param(string);
};
 
pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE, unsigned);
const char* getText(pANTLR3_BASE_TREE tree);
 
int main(int argc, char* argv[])
{
  pANTLR3_INPUT_STREAM input;
  pExprCppTreeLexer lex;
  pANTLR3_COMMON_TOKEN_STREAM tokens;
  pExprCppTreeParser parser;
 
  assert(argc > 1);
  input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1],ANTLR3_ENC_8BIT);//拿出第一项参数,加载input
  lex = ExprCppTreeLexerNew(input);
  tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT,
                                            TOKENSOURCE(lex));
  parser = ExprCppTreeParserNew(tokens);
 
  ExprCppTreeParser_prog_return r = parser->prog(parser);//所要的是r;
  cout << "done" << endl;
  pANTLR3_BASE_TREE tree = r.tree;//r字段是tree,就是抽象语法树
 
  ExprTreeEvaluator eval;//执行表示树的执行者对象

  int rr = eval.run(tree);
  cout << "Evaluator result: " << rr << '\n';
 
  parser->free(parser);
  tokens->free(tokens);
  lex->free(lex);
  input->close(input);
 
  return 0;
}

void ExprTreeEvaluator::set_param(string name, int val) {
    if (memory.find(name) != memory.end()) {
        throw std::runtime_error("param redefined : " + name);
    }
    memory[name] = val;
    return ;
}

int ExprTreeEvaluator::get_param(string name) {
    if (memory.find(name) == memory.end()) {//当前作用域中找
        throw std::runtime_error("unknown param : " + name);
    }
    return memory[name];
}

int ExprTreeEvaluator::run(pANTLR3_BASE_TREE tree)
{
    pANTLR3_COMMON_TOKEN tok = tree->getToken(tree);//取出根节点的信息
    if(tok) {
        switch(tok->type) {
        case INT: {//如果当前根节点是INT
            const char* s = getText(tree);
            if(s[0] == '~') {//如果是~就是-值
                return -atoi(s+1);
            }
            else {
                return atoi(s);
            }
        }
        case ID: {//如果当前是ID
            string var(getText(tree));//提取ID字符串
            return get_param(var);
        }
        case PLUS:
            return run(getChild(tree,0)) + run(getChild(tree,1));//左孩子右孩子找
        case MINUS:
            return run(getChild(tree,0)) - run(getChild(tree,1));
        case TIMES:
            return run(getChild(tree,0)) * run(getChild(tree,1));
        case DIV:
            return run(getChild(tree,0)) / run(getChild(tree,1));
        case MOD:
            return run(getChild(tree,0)) % run(getChild(tree,1));
        case DEF: { 
            int k = tree->getChildCount(tree);
            int init_val = 0;
            for (int i = 0; i < k; i++) {
                pANTLR3_BASE_TREE child = getChild(tree, i);
                string var(getText(child));
                init_val = 0;
                if (child->getChildCount(child) == 1) {
                    init_val = run(getChild(child, 0));
                }
                cout << "set param val : " << var << " = " << init_val << endl;
                this->set_param(var, init_val);
            }
            return init_val;
        } break;
        case BLOCK: {

        }
        case ASSIGN: {//赋值表达式的时候
            string var(getText(getChild(tree,0)));//获取第一个位置信息
            get_param(var);
            int val = run(getChild(tree,1));
            memory[var] = val;//映射
            return val;
        }
        default:
            cout << "Unhandled token: #" << tok->type << '\n';
            return -1;
        }
    }
    else {
        int k = tree->getChildCount(tree);
        int r = 0;
        for(int i = 0; i < k; i++) {
            r = run(getChild(tree, i));
            cout << "Evaluator result: " << r << endl;
        }
        return r;
    }
    return 0;
}
 
pANTLR3_BASE_TREE getChild(pANTLR3_BASE_TREE tree, unsigned i)
{
    assert(i < tree->getChildCount(tree));
    return (pANTLR3_BASE_TREE) tree->getChild(tree, i);
}

const char* getText(pANTLR3_BASE_TREE tree)
{
    return (const char*) tree->getText(tree)->chars;
}
