/*************************************************************************
	> File Name: parameter.h
	> Author:fangsong
	> Mail: fangsong517@gmail.com
	> Created Time: 2020年09月04日 星期五 12时30分18秒
 ************************************************************************/

#ifndef _PARAMETER_H
#define _PARAMETER_H

#include <map>
#include <string>
#include <memory>
namespace haizei {

class Parameter {
public :
    Parameter(std::shared_ptr<Parameter> next);
    void def_param(std::string, int);
    void set_param(std::string, int);
    int get_param(std::string);

private:
    std::map<std::string, int> memory;
    std::shared_ptr<Parameter> next;
};

} // end of namespace haizei

#endif
