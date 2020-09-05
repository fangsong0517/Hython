#include <cassert>
#include <ExprTreeEvaluator.h>
#include <iostream>
#include <string>
#include <memory>
#include <AST.h>
#include <parameter.h>
#include <single.h>

namespace haizei {

ExprTreeEvaluator::ExprTreeEvaluator() {}

SIValue ExprTreeEvaluator::run(haizei::ASTNode tree) {
    std::shared_ptr<Parameter> p = std::make_shared<Parameter>(nullptr);
    return MasterChainSingle::run(tree, p);
}

} // end of namespace haizei

