#ifndef NATLEN_STACK_H
#define NATLEN_STACK_H

#include "Node.h"

template <typename T>
class Stack
{
public:

	/* -- FUNCTION MEMBERS -- */
	Stack() : m_pTop(nullptr), m_pBottom(nullptr) {};
	Stack(const T& data) : m_pTop{ new Node<T>(data) }, m_pBottom{ m_pTop } {};
	Stack(const Stack<T>& stack) : m_pTop(nullptr), m_pBottom(nullptr)
	{
		if (stack.m_pTop == nullptr) 
		{ 
			m_pTop = nullptr;
		}
		else
		{
			m_pTop = new Node<T>(*stack.m_pTop);
		}
		m_pBottom = retrieveBottom();
	};
	Stack(Stack<T>&& stack) noexcept : m_pTop(nullptr), m_pBottom(nullptr)
	{
		m_pTop = stack.m_pTop;
		m_pBottom = stack.m_pBottom;

		stack.m_pTop = nullptr;
		stack.m_pBottom = nullptr;
	};
	Stack(const std::initializer_list<T>& dataList) : m_pTop(nullptr), m_pBottom(nullptr)
	{
		Node<T>* newStack = nullptr;
		for (auto data = std::rbegin(dataList); data != std::rend(dataList); data++)
		{
			if (data == std::rbegin(dataList)) // if first data on reverse order
			{
				m_pTop = new Node<T>(*data);
				newStack = m_pTop;
			}
			else
			{
				newStack->m_pNext = new Node<T>(*data);
				newStack = newStack->m_pNext;
			}
		}
		m_pBottom = newStack;
	};
	~Stack()
	{
		delete m_pTop; // recursively deletes all ->next nodes at ~Node(), including m_pBottom.
	};
	Stack<T>& operator = (const Stack<T>& stack)
	{
		if (m_pTop != nullptr)
		{
			delete m_pTop;
		}
		if (stack.m_pTop == nullptr)
		{
			m_pTop = nullptr;
		}
		else
		{
			m_pTop = new Node<T>(*stack.m_pTop);
		}
		m_pBottom = retrieveBottom();
		return *this;
	};
	Stack<T>& operator = (Stack<T>&& stack) noexcept
	{
		m_pTop = stack.m_pTop;
		m_pBottom = stack.m_pBottom;

		stack.m_pTop = nullptr;
		stack.m_pBottom = nullptr;

		return *this;
	};
	bool operator == (const Stack<T>& stack)
	{
		return areTheSameStacks(m_pTop, stack.m_pTop);
	};
	

private:
	/* -- DATA MEMBERS -- */
	Node<T>* m_pTop;
	Node<T>* m_pBottom;
	int64_t m_depth;

	/* -- FUNCTION MEMBERS -- */
	Node<T>* retrieveBottom()
	{
		Node<T>* nodeIt = m_pTop;
		if (nodeIt != nullptr)
		{
			while (nodeIt->m_pNext != nullptr)
			{
				nodeIt = nodeIt->m_pNext;
			}
			m_pBottom = nodeIt;
		}
		return nodeIt;
	};
	bool areTheSameStacks(Node<T>* node1, Node<T>* node2)
	{
		if (node1 == nullptr && node2 == nullptr)
			return true;
		else if (node1 == nullptr && node2 != nullptr)
			return false;
		else if (node1 != nullptr && node2 == nullptr)
			return false;
		return (*node1 == *node2) && areTheSameStacks(node1->m_pNext, node2->m_pNext);
	};

	/* -- FRIENDS -- */
	template <typename T>
	friend std::ostream& operator << (std::ostream& os, const Stack<T>& stack);
};

template <typename T>
std::ostream& operator << (std::ostream& os, const Stack<T>& stack)
{
	
	if (stack.m_pTop == nullptr)
		os << "{ empty-stack }" << std::endl;
	else
		os << "{ " << stack.m_pTop << " }" << std::endl;
	return os;
};

template <typename T>
std::ostream& operator << (std::ostream& os, const Node<T>* node)
{
	if (node == nullptr)
	{
		os << "nullptr";
		return os;
	}
	if (node->m_pData == nullptr)
		os << "nullptr" << ", ";
	else
		os << *node->m_pData;
	if (node->m_pNext != nullptr)
		os << ", " << node->m_pNext;
	return os;
}

#endif