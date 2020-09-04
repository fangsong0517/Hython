#include <parameter.h>

namespace haizei {

Parameter::Parameter(std::shared_ptr<Parameter> next) : next(next) {}

void Parameter::def_param(std::string name, int val) {
    if (memory.find(name) != memory.end()) {
        #ifdef DEBUG
        for (auto x : memory) {
            std::cout << "debug log(memory) : " << x.first << " " << x.second << std::endl;
        }
        #endif
        throw std::runtime_error("param redefined : " + name);
    }
    memory[name] = val;
    return ;
}

void Parameter::set_param(std::string name, int val) {
    if (memory.find(name) == memory.end()) {
        if (this->next) {
            this->next->set_param(name, val);
            return ;
        }
        throw std::runtime_error("unknown param : " + name);
    }
    memory[name] = val;
    return ;
}

int Parameter::get_param(std::string name) {
    if (memory.find(name) == memory.end()) {
        if (this->next) return this->next->get_param(name);
        throw std::runtime_error("unknown param : " + name);
    }
    return memory[name];
}

} // end of haizei
