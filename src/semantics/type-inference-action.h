#ifndef TYPE_INFERENCE_ACTION_H
#define TYPE_INFERENCE_ACTION_H
#include "swift_conf.h"
#include "ast/node-visitor.h"
SWIFT_NS_BEGIN


class Type;
class Expression;
class TypeInferenceAction : public NodeVisitor
{
public:
    TypeInferenceAction(SymbolRegistry* symbolRegistry);
public:
    virtual void visitVariables(Variables* node);
    virtual void visitConstants(Constant* node);
private:
    TypePtr evaluateType(Expression* expr);
private:
    SymbolRegistry* symbolRegistry;
};


SWIFT_NS_END


#endif//TYPE_INFERENCE_ACTION_H