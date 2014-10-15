#ifndef SWIFT_ERRORS_H
#define SWIFT_ERRORS_H
#include "swift_conf.h"

SWIFT_NS_BEGIN

struct Errors
{
    enum
    {
        E_UNEXPECTED_EOF = 0x1000,
        //grammar errors
        E_EXPECT_1,// %0 is expected
        E_UNEXPECTED_1,// Unexpected %0
        E_EXPECT_IDENTIFIER_1,// Identifier expected, but %0 found.
        E_EXPECT_KEYWORD_1,// Keyword %0 expected
        E_EXPECT_EXPRESSION_1, // Expression expected but %0 found.
        E_EXPECT_OPERATOR_1, // Operator expected but %0 found.
        E_EXPECT_INTEGER_PRECEDENCE,// Operator's precedence must be an integer
        E_INVALID_OPERATOR_PRECEDENCE, // Operator's precedence must be between [0, 255]
        E_EXPECT_INIT_SELF_DYNAMICTYPE_IDENTIFIER_1, // init/self/dynamicType or member field is expected, but %0 found.
        E_UNDEFINED_INFIX_OPERATOR_1, // Undefined infix operator %0
        E_EXPECT_CAPTURE_SPECIFIER, // The capture specifier is not specified.
        E_EXPECT_CASE, // case/default is expected in switch/case statement
        E_GETTER_SETTER_CAN_ONLY_BE_DEFINED_FOR_A_SINGLE_VARIABLE, // Getter/setter can only be defined for a single variable
        
        //semantic errors
        E_INVALID_REDECLARATION_1, // Invalid redeclaration of type %0
        E_USE_OF_UNDECLARED_TYPE_1, // Use of undeclared type %0
        E_CANNOT_ASSIGN, // cannot assign to the result of this expression
        E_USE_OF_UNRESOLVED_IDENTIFIER_1, //use of unresolved identifier '%0'
        E_USE_OF_UNINITIALIZED_VARIABLE_1, //use of local variable '%0' before its declaration
        E_USE_OF_INITIALIZING_VARIABLE, //variable used within its own initial value
        E_DEFINITION_CONFLICT, //definition conflicts with previous value
        E_USE_OF_FUNCTION_LOCAL_INSIDE_TYPE, //use of function local variable inside type declaration

        E_TUPLE_PATTERN_MUST_MATCH_TUPLE_TYPE_1,//tuple pattern cannot match values of the non-tuple type '%0'
        E_TUPLE_TYPES_HAVE_A_DIFFERENT_NUMBER_OF_ELEMENT_4, //tuple types '%0' and '%1' have a different number of elements (%2 vs. %3)
        E_OPERATOR_REDECLARED,//operator redeclared
        E_OPERATOR_PRECEDENCE_OUT_OF_RANGE,//'precedence' must be in the range of 0 to 255
        E_UNKNOWN_BINARY_OPERATOR_1, //operator '%0' is not a known binary operator
        E_IS_NOT_BINARY_OPERATOR_1, //'%0' is not a binary operator
        E_NO_OVERLOAD_ACCEPTS_ARGUMENTS_1,//could not find an overload for '%0' that accepts the supplied arguments
        E_INVALID_CALL_OF_NON_FUNCTION_TYPE_2,//invalid use of '%0' to call a value of non-function type '%1'
        E_UNMATCHED_PARAMETERS, // Unmatched number of supplied parameters
        E_UNMATCHED_PARAMETER_1, // Unmatched type of parameter %0
        E_NO_MATCHED_OVERLOAD, // No matched overload found
        E_MISSING_ARGUMENT_LABEL_IN_CALL_1,// Missing argument label '%0:' in call
        E_EXTRANEOUS_ARGUMENT_LABEL_IN_CALL_1, //Extraneous argument label '%0:' in call
        E_EXTRANEOUS_ARGUMENT, //Extraneous argument in call
        E_AMBIGUOUS_USE_1,    // Ambiguous use of '%0'
        E_INOUT_ARGUMENTS_CANNOT_BE_VARIADIC, // Inout arguments cannot be variadic
        E_DOES_NOT_HAVE_A_MEMBER_2, // '%0' does not have a member named '%1'

        E_CANNOT_CONVERT_EXPRESSION_TYPE_2, //Cannot convert expression's type '%0' to type '%1'
        E_LET_REQUIRES_INITIALIZER, //'let' declarations require an initializer expression
        E_CANNOT_DEFINE_EMPTY_ARRAY_WITHOUT_TYPE, // cannot define an empty array without type declaration.
        E_ARRAY_CONTAINS_DIFFERENT_TYPES, // Array contains different types
        E_TYPE_DOES_NOT_CONFORM_TO_PROTOCOL_2_, // Type '%0' does not conform to '%1' protocol
        E_SUPERCLASS_MUST_APPEAR_FIRST_IN_INHERITANCE_CLAUSE_1, // Superclass '%0' must appear first in the inheritance clause
        E_INHERITANCE_FROM_NONE_PROTOCOL_NON_CLASS_TYPE_1, //Inheritance from none-protocol, non-class type '%0'
        E_INHERITANCE_FROM_NONE_PROTOCOL_TYPE_1, //Inheritance from none-protocol type '%0'
        E_DEFAULT_ARGUMENT_NOT_PERMITTED_IN_A_PROTOCOL_METHOD, //Default argument not permitted in a protocol method
        E_TYPE_DOES_NOT_CONFORM_TO_PROTOCOL_UNIMPLEMENTED_FUNCTION_3,// Type %0 does not conform to protocol %1, unimplemented function %2
        E_TYPE_DOES_NOT_CONFORM_TO_PROTOCOL_UNIMPLEMENTED_TYPE_3, //Type %0 does not conform to protocol %1, unimplemented type %2
        E_PROTOCOL_CANNOT_DEFINE_LET_CONSTANT_1, // Protocol %0 cannot define let constant
        E_PROTOCOL_VAR_MUST_BE_COMPUTED_PROPERTY_1, // Protocol %0's variable must be a computed property
        E_TYPE_DOES_NOT_CONFORM_TO_PROTOCOL_UNIMPLEMENTED_PROPERTY_3, //Type '%0' does not conform to protocol '%1', unimplemented property '%2'
        E_TYPE_DOES_NOT_CONFORM_TO_PROTOCOL_UNWRITABLE_PROPERTY_3, //Type '%0' does not conform to protocol '%1', unwritable property '%2'
        E_TYPE_ANNOTATION_MISSING_IN_PATTERN, // Type annotation missing in pattern
        E_NESTED_TYPE_IS_NOT_ALLOWED_HERE, // Nested type is not allowed here
        E_GENERIC_TYPE_ARGUMENT_REQUIRED, // Generic type argument required
        E_GENERIC_TYPE_SPECIALIZED_WITH_TOO_MANY_TYPE_PARAMETERS_3, //Generic type '%0' specialized with too many type parameters(got %1, but expected %2)
        E_GENERIC_TYPE_SPECIALIZED_WITH_INSUFFICIENT_TYPE_PARAMETERS_3, //Generic type '%0' specialized with insufficient type parameters(got %1, but expected %2);
        E_CANNOT_SPECIALIZE_NON_GENERIC_TYPE_1, //Cannot specialize non-generic type '%0'
        E_MULTIPLE_INHERITANCE_FROM_CLASS_2_, //Multiple inheritance from class '%0' and '%1'
        E_IS_NOT_A_MEMBER_OF_2, // %0 is not a member of %1
        E_SAME_TYPE_REQUIREMENTS_MAKES_GENERIC_PARAMETER_NON_GENERIC_1,//Same-type requirement makes generic parameter '%' non-generic
        E_PROTOCOL_CAN_ONLY_BE_USED_AS_GENERIC_CONSTRAINT_1,//Protocol '%0' can only be used as a generic constraint because it has Self or associated type requirements
        E_UNDEFINED_SUBSCRIPT_ACCESS_FOR_1,// Undefined subscript access for '%0'


        W_PARAM_CAN_BE_EXPRESSED_MORE_SUCCINCTLY_1, // '%0 %0' can be expressed more succinctly as '#%0'
        W_EXTRANEOUS_SHARTP_IN_PARAMETER_1, //Extraneous '#' in parameter: '%0' is already the keyword argument name
        //linking errors
    };
    
};


SWIFT_NS_END

#endif//SWIFT_ERRORS_H