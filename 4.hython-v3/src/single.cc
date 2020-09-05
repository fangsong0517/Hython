#include <single.h>

namespace haizei {

const IHandle *MasterChainSingle::object = nullptr;
std::mutex Singleton::m_mutex;

SIValue MasterChainSingle::run(ASTNode node, std::shared_ptr<Parameter> &p) {
    const IHandle *h = get();
    SIValue ret = HZNULL;
    while (h != nullptr) {
        if (!(h->Test(node))) {
            h = h->next();
            continue; 
        }
        auto m = h->getMaster();
        ret = m->run(node, p);
        break;
    }
    if (h == nullptr) throw std::runtime_error(
        "not handle type : "
        + std::to_string(node.type())
    );
    return ret;
}

const IHandle *MasterChainSingle::get() {
    if (object == nullptr) {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (object == nullptr) {
            object = SingleInit();
        }
    }
    return object;
}

const IHandle *MasterChainSingle::SingleInit() {
    PrintHandle *node4 = new PrintHandle(nullptr);
    ControlNoBlockHandle  *node3 = new ControlNoBlockHandle(node4);
    ControlBlockHandle *node2 = new ControlBlockHandle(node3);
    ExprHandle *node1 = new ExprHandle(node2);
    return node1;
}

} // end of namespace haizei


