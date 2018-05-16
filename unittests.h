#ifndef __MY_QUEUE_TESTS__
#define __MY_QUEUE_TESTS__

#include <test_helpers.h>
#include "stacks.h"

class StackTests final : public UnitTests
{
protected:
    void RunTests() final
    {
        LinkedListStack<int> ll;
        VectorStack<int> vec;

        ADD_TEST(StackTests::singleElementTest, ll);
        ADD_TEST(StackTests::orderingTest, ll);
        ADD_TEST(StackTests::singleElementTest, vec);
        ADD_TEST(StackTests::orderingTest, vec);
        ADD_TEST(StackTests::Array::singleElementTest);
        ADD_TEST(StackTests::Array::orderingTest);
    }
private:

    static bool singleElementTest(IStack<int>& s);
    static bool orderingTest(IStack<int>& s);

    struct Array
    {
        static bool singleElementTest();
        static bool orderingTest();        
    };

    static Test_Registrar<StackTests> registrar;
};

#endif