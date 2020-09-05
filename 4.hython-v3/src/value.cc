#include <value.h>

namespace haizei {

IntValue::IntValue(int val) : BaseValue(val) {}
FloatValue::FloatValue(double val) : BaseValue(val) {}
StringValue::StringValue(std::string val) : BaseValue(val) {}

bool IValue::little_compare(IntValue &a) {
    throw std::runtime_error("type can't compare");
}
bool IValue::little_compare(FloatValue &a) {
    throw std::runtime_error("type can't compare");
}
bool IValue::little_compare(StringValue &a) {
    throw std::runtime_error("type can't compare");
}
bool IntValue::little_compare(IntValue &a) {
    return val() < a.val();
}
bool IntValue::little_compare(FloatValue &a) {
    return val() < a.val();
}
bool FloatValue::little_compare(IntValue &a) {
    return val() < a.val();
}
bool FloatValue::little_compare(FloatValue &a) {
    return val() < a.val();
}
bool StringValue::little_compare(StringValue &a) {
    return val() < a.val();
}

bool IntValue::re_little_compare(IValue &a) {
    return a.little_compare(*this);
}
bool FloatValue::re_little_compare(IValue &a) {
    return a.little_compare(*this);
}
bool StringValue::re_little_compare(IValue &a) {
    return a.little_compare(*this);
}

bool IValue::isFalse() const { return !(this->isTrue()); }
bool StringValue::isTrue() const {
    if (val() == "") return false;
    return true;
}

bool IValue::operator<(IValue &a) {
    return a.re_little_compare(*this);
}

bool IValue::operator>(IValue &a) {
    return a < (*this);
}
bool IValue::operator==(IValue &a) {
    if ((*this) < a) return false;
    if (a< (*this)) return false;
    return true;
}
bool IValue::operator!=(IValue &a) {
    if ((*this) == a) return false;
    return true;
}
bool IValue::operator<=(IValue &a) {
    if (a < (*this)) return false;
    return true;
}
bool IValue::operator>=(IValue &a) {
    if ((*this) < a) return false;
    return true;
}

SIValue HZNULL = std::make_shared<IntValue>(0);
SIValue HZTrue = std::make_shared<IntValue>(1);
SIValue HZFalse = std::make_shared<IntValue>(0);

} // end of haizei

