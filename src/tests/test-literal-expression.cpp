#include "utils.h"
#include "parser/parser.h"
#include "parser/symbol-registry.h"
#include "ast/ast.h"
#include "ast/node-factory.h"

using namespace Swift;

class TestLiteralExpression : public SwiftTestCase
{
    CPPUNIT_TEST_SUITE(TestLiteralExpression);
    CPPUNIT_TEST(testLiteral);
    CPPUNIT_TEST(testLiteral2);
    CPPUNIT_TEST(testLiteral3);
    CPPUNIT_TEST(testCompileConstants);
    CPPUNIT_TEST(testCompileConstants2);
    CPPUNIT_TEST(testCompileConstants3);
    CPPUNIT_TEST(testCompileConstants4);
    CPPUNIT_TEST(testArrayLiteral);
    CPPUNIT_TEST(testArrayLiteral2);
    CPPUNIT_TEST(testArrayLiteral3);
    CPPUNIT_TEST(testArrayLiteral4);
    CPPUNIT_TEST(testArrayLiteral5);
    CPPUNIT_TEST(testDictionaryLiteral);
    CPPUNIT_TEST(testDictionaryLiteral2);
    CPPUNIT_TEST_SUITE_END();
public:
    void testLiteral()
    {
        
        Node* root = parse(L"3");
        CPPUNIT_ASSERT(root != NULL);
        IntegerLiteral* n = dynamic_cast<IntegerLiteral*>(root);
        CPPUNIT_ASSERT(n != NULL);
        ASSERT_EQUALS(L"3", n->toString().c_str());
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
    void testLiteral2()
    {
        Node* root = parse(L"3.45e4");
        CPPUNIT_ASSERT(root != NULL);
        FloatLiteral* f = dynamic_cast<FloatLiteral*>(root);
        CPPUNIT_ASSERT(f != NULL);
        ASSERT_EQUALS(L"3.45e4", f->toString().c_str());
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
    
    void testLiteral3()
    {
        Node* root = parse(L"\"str\\thello\"");
        CPPUNIT_ASSERT(root != NULL);
        StringLiteral* str = dynamic_cast<StringLiteral*>(root);
        CPPUNIT_ASSERT(str != NULL);
        ASSERT_EQUALS(L"str\thello", str->toString().c_str());
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
        
    }
    void testArrayLiteral()
    {
        Node* root = parse(L"[]");
        CPPUNIT_ASSERT(root != NULL);
        ArrayLiteral* a = dynamic_cast<ArrayLiteral*>(root);
        CPPUNIT_ASSERT(a != NULL);
        CPPUNIT_ASSERT_EQUAL(0, a->numChildren());
        
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
    
    void testArrayLiteral2()
    {
        Node* root = parse(L"[5]");
        CPPUNIT_ASSERT(root != NULL);
        ArrayLiteral* a = dynamic_cast<ArrayLiteral*>(root);
        CPPUNIT_ASSERT(a != NULL);
        CPPUNIT_ASSERT_EQUAL(1, a->numChildren());
        IntegerLiteral* i = dynamic_cast<IntegerLiteral*>(a->get(0));
        CPPUNIT_ASSERT(i != NULL);
        ASSERT_EQUALS(L"5", i->toString().c_str());
        
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
    void testArrayLiteral3()
    {
        Node* root = parse(L"[\"a\",]");
        CPPUNIT_ASSERT(root != NULL);
        ArrayLiteral* a = dynamic_cast<ArrayLiteral*>(root);
        CPPUNIT_ASSERT(a != NULL);
        CPPUNIT_ASSERT_EQUAL(1, a->numChildren());
        StringLiteral* s = dynamic_cast<StringLiteral*>(a->get(0));
        CPPUNIT_ASSERT(s != NULL);
        ASSERT_EQUALS(L"a", s->toString().c_str());
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
    void testArrayLiteral4()
    {
        Node* root = parse(L"[5,6]");
        CPPUNIT_ASSERT(root != NULL);
        ArrayLiteral* a = dynamic_cast<ArrayLiteral*>(root);
        CPPUNIT_ASSERT(a);
        CPPUNIT_ASSERT_EQUAL(2, a->numChildren());
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
    void testArrayLiteral5()
    {
        Node* root = parse(L"[5,6, [5]]");
        CPPUNIT_ASSERT(root != NULL);
        ArrayLiteral*a = dynamic_cast<ArrayLiteral*>(root);
        CPPUNIT_ASSERT(a);
        CPPUNIT_ASSERT_EQUAL(3, a->numChildren());
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
        
    }
    void testDictionaryLiteral()
    {
        Node* root = parse(L"[:]");
        CPPUNIT_ASSERT(root != NULL);
        DictionaryLiteral* d = dynamic_cast<DictionaryLiteral*>(root);
        CPPUNIT_ASSERT(d != NULL);
        CPPUNIT_ASSERT_EQUAL(0, d->numChildren());
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
    void testDictionaryLiteral2()
    {
        Node* root = parse(L"[5 : 1]");
        CPPUNIT_ASSERT(root != NULL);
        DictionaryLiteral* d = dynamic_cast<DictionaryLiteral*>(root);
        CPPUNIT_ASSERT(d != NULL);
        CPPUNIT_ASSERT_EQUAL(2, d->numChildren());
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
    void testCompileConstants()
    {
        Node* root = parse(L"__FILE__");
        CPPUNIT_ASSERT(root != NULL);
        CompileConstant* c = dynamic_cast<CompileConstant*>(root);
        CPPUNIT_ASSERT(c != NULL);
        ASSERT_EQUALS(L"<file>", c->getValue().c_str());
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
    void testCompileConstants2()
    {
        Node* root = parse(L"__LINE__");
        CPPUNIT_ASSERT(root != NULL);
        CompileConstant* c = dynamic_cast<CompileConstant*>(root);
        CPPUNIT_ASSERT(c != NULL);
        ASSERT_EQUALS(L"1", c->getValue().c_str());
        
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
    void testCompileConstants3()
    {
        Node* root = parse(L"__COLUMN__");
        CPPUNIT_ASSERT(root != NULL);
        CompileConstant* c = dynamic_cast<CompileConstant*>(root);
        CPPUNIT_ASSERT(c != NULL);
        ASSERT_EQUALS(L"1", c->getValue().c_str());
        
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
    void testCompileConstants4()
    {
        Node* root = parse(L"__FUNCTION__");
        CPPUNIT_ASSERT(root != NULL);
        CompileConstant* c = dynamic_cast<CompileConstant*>(root);
        CPPUNIT_ASSERT(c != NULL);
        ASSERT_EQUALS(L"<top>", c->getValue().c_str());
        
        delete root;
        CPPUNIT_ASSERT_EQUAL(0, Node::NodeCount);
    }
};
;

CPPUNIT_TEST_SUITE_NAMED_REGISTRATION(TestLiteralExpression, "alltest");