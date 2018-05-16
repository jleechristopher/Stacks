#ifndef __MY_QUEUE_TESTS__
#define __MY_QUEUE_TESTS__

#include <test_helpers.h>

class StackTests final : public UnitTests
{
protected:
    void RunTests() final
    {
        ADD_TEST(StackTests::LinkedList::singleElementTest);
        ADD_TEST(StackTests::LinkedList::orderingTest);
        ADD_TEST(StackTests::Array::singleElementTest);
        ADD_TEST(StackTests::Array::orderingTest);
        ADD_TEST(StackTests::Vector::singleElementTest);
        ADD_TEST(StackTests::Vector::orderingTest);
    }
// later: overload ADD_TEST to accept an ISTACK object. Make StackTests instantiate a member stack object for
    // each stack implementation then run the set of tests, passing them a ref to the member object
private:
    struct LinkedList
    {
        static bool singleElementTest();
        static bool orderingTest();        
    };
    struct Array
    {
        static bool singleElementTest();
        static bool orderingTest();        
    };
    struct Vector
    {
        static bool singleElementTest();
        static bool orderingTest();        
    };

    static Test_Registrar<StackTests> registrar;
};

#endif