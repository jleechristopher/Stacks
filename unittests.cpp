#include "unittests.h"
#include "stacks.h"
#include <iostream>

Test_Registrar<StackTests> StackTests::registrar;

bool StackTests::singleElementTest(IStack<int>& s)
{
	VERIFY_TRUE(s.empty());
	VERIFY_TRUE(s.push(1));
	VERIFY_FALSE(s.empty());
	VERIFY_EQ(s.size(), 1);
	VERIFY_EQ(s.top(), 1);
	VERIFY_TRUE(s.pop());
	VERIFY_FALSE(s.pop());
	VERIFY_TRUE(s.empty());
	VERIFY_EQ(s.size(), 0);
	VERIFY_TRUE(s.push(2));
	VERIFY_EQ(s.top(), 2);
	VERIFY_TRUE(s.pop());

	return true;
}

bool StackTests::orderingTest(IStack<int>& s)
{
	VERIFY_TRUE(s.push(1));
	VERIFY_TRUE(s.push(2));
	VERIFY_TRUE(s.push(3));
	VERIFY_EQ(s.size(), 3);
	VERIFY_EQ(s.top(), 3);
	VERIFY_TRUE(s.pop());
	VERIFY_EQ(s.top(), 2);
	VERIFY_TRUE(s.pop());
	VERIFY_EQ(s.top(), 1);

	return true;
}

bool StackTests::Array::singleElementTest()
{
	ArrayStack<int> s(1);
	VERIFY_TRUE(s.empty());
	VERIFY_TRUE(s.push(1));
	VERIFY_FALSE(s.push(1));
	VERIFY_FALSE(s.empty());
	VERIFY_EQ(s.size(), 1);
	VERIFY_EQ(s.top(), 1);
	VERIFY_TRUE(s.pop());
	VERIFY_FALSE(s.pop());
	VERIFY_TRUE(s.empty());
	VERIFY_EQ(s.size(), 0);
	VERIFY_TRUE(s.push(2));
	VERIFY_EQ(s.top(), 2);

	return true;
}

bool StackTests::Array::orderingTest()
{
	ArrayStack<int> s(3);
	VERIFY_TRUE(s.push(1));
	VERIFY_TRUE(s.push(2));
	VERIFY_TRUE(s.push(3));
	VERIFY_EQ(s.size(), 3);
	VERIFY_EQ(s.top(), 3);
	VERIFY_TRUE(s.pop());
	VERIFY_EQ(s.top(), 2);
	VERIFY_TRUE(s.pop());
	VERIFY_EQ(s.top(), 1);

	return true;
}