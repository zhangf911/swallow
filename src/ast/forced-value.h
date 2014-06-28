#ifndef FORCED_VALUE_H
#define FORCED_VALUE_H
#include "expression.h"

SWIFT_NS_BEGIN

class ForcedValue : public Expression
{
public:
    ForcedValue(Expression* expr);
public:
    void setExpression(Expression* expr);
    Expression* getExpression();
public:
    virtual void serialize(std::wostream& out);
};

SWIFT_NS_END

#endif//FORCED_VALUE_H