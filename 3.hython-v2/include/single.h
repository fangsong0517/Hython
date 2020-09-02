/*************************************************************************
	> File Name: single.h
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月02日 星期三 10时47分12秒
 ************************************************************************/

#ifndef _SINGLE_H
#define _SINGLE_H
#include <handle.h>
#include <mutex>

namespace haizei {

class Singleton {
public :
protected:
    Singleton() = default;
    static std::mutex m_mutex;
};

class MasterChainSingle : public Singleton {
public :
    static int run(ASTNode &, std::shared_ptr<Parameter> &);
private:
    static const Handle *get();
    MasterChainSingle() = delete;
    static const Handle *SingleInit();
    static const Handle *object;
};

}

#endif
