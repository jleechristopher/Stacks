// STACKS
// This program contains several implementations of stacks
// 
// NEW PATTERNS/TECHNIQUES IMPLEMENTED
// 
// Author: Chris Lee
// Date: May 8th, 2018
// Last Edited: May 8th, 2018

#ifndef __MY_STACK__
#define __MY_STACK__

#include <stdexcept> // for std::invalid_argument
#include <vector> 

template<typename T>
class IStack
{
public:
	virtual bool empty() = 0;
	virtual int size() = 0;
	virtual T& top() = 0;
	virtual bool push(const T& value) = 0;
	virtual bool pop() = 0;
};

template<typename T>
class LinkedListStack: public IStack<T>
{
private:
	class Node
	{
	public:
		Node(const T& value, Node* next): m_data{value}, m_next{next}
		{
		}
	private:
		T m_data;
		Node* m_next;
		friend LinkedListStack;
	};

public: 
	LinkedListStack(): m_top(nullptr)
	{
	}
	~LinkedListStack()
	{
		Node* current = m_top;
		while (m_top)
		{
			current = m_top;
			m_top = m_top->m_next;
			delete current;
		}
	}

	bool empty()
	{
		if (!m_top)
		{
			return true;
		}
		return false;
	}

	int size()
	{
		int count = 0; 
		Node* current = m_top;
		while(current)
		{
			++count;
			current = current->m_next;
		}
		return count;
	}

	T& top()
	{
		if (!m_top)
		{
			throw std::invalid_argument( "Empty stack" );
		}
		return m_top->m_data;
	}

	bool push(const T& value)
	{
		Node* x = new Node(value, m_top);
		m_top = x;
		return true;
	}

	bool pop()
	{
		if (empty())
		{
			return false; 
		}
		Node* toDelete = m_top;
		m_top = m_top->m_next;
		delete toDelete;
		return true;
	} 

private:
	Node* m_top; 
};

template<typename T>
class VectorStack: public IStack<T>
{
public:
	VectorStack(): m_top{-1}
	{
	}
	bool empty()
	{
		if (m_top < 0)
		{
			return true;
		}
		return false;
	}

	int size()
	{
		if (m_top < 0)
		{
			return 0;
		}
		return m_top + 1;
	}

	T& top()
	{
		if (m_top < 0)
		{
			throw std::invalid_argument( "Empty stack" );
		}
		return m_data[m_top];
	}

	bool push(const T& value)
	{
		if (m_top + 1 == m_data.size())
		{
			m_data.push_back(value);
			++m_top; 
			return true;
		}
		++m_top; 
		m_data[m_top] = value;
		return true;
	}

	bool pop()
	{
		if (m_top < 0)
		{
			return false;
		}
		--m_top;
		return true;
	}
private:
	std::vector<T> m_data;
	int m_top;
};
template<typename T>
class ArrayStack: public IStack<T>
{
public:
	ArrayStack(int size): m_data(new T[size]), m_top{-1}, m_size{size}
	{
	}
	~ArrayStack()
	{
		delete[] m_data;
	}
	bool empty()
	{
		if (m_top < 0)
		{
			return true;
		}
		return false;
	}

	int size()
	{
		if (m_top < 0)
		{
			return 0;
		}
		return m_top + 1;
	}

	T& top()
	{
		if (m_top < 0)
		{
			throw std::invalid_argument( "Empty stack" );
		}
		return m_data[m_top];
	}

	bool push(const T& value)
	{
		if (m_top + 1 == m_size)
		{
			return false;			
		}
		++m_top;
		m_data[m_top] = value;
		return true;
	}

	bool pop()
	{
		if (m_top < 0)
		{
			return false;
		}
		--m_top;
		return true;
	}
private:
	T* m_data;
	int m_top;
	int m_size;
};

#endif