#ifndef NATLEN_NODE_H
#define NATLEN_NODE_H

#include <iostream>

template <typename T>
class Node
{
public:

	/* -- FUNCTION MEMBERS -- */
	Node() : m_pData(nullptr), m_pNext(nullptr) {};
	Node(const T& data) : m_pData(new T(data)), m_pNext(nullptr) {};
	Node(const Node<T>& node)
	{
		if (node.m_pData == nullptr)
		{
			m_pData = nullptr;
		}
		else
		{
			m_pData = new T(*node.m_pData);
		}

		if (node.m_pNext == nullptr)
		{
			m_pNext = nullptr;
		}
		else
		{
			m_pNext = new Node<T>(*node.m_pNext);
		}
	};
	Node(Node<T>&& node) noexcept
	{
		m_pData = node.m_pData;
		m_pNext = node.m_pNext;

		node.m_pData = nullptr;
		node.m_pNext = nullptr;
	};
	~Node()
	{
		delete m_pData;
		delete m_pNext;
	}
	bool operator == (const Node<T>& node)
	{
		if (m_pData == nullptr && node.m_pData == nullptr)
			return true;
		else if (m_pData == nullptr && node.m_pData != nullptr)
			return false;
		else if (m_pData != nullptr && node.m_pData == nullptr)
			return false;
		return *m_pData == *node.m_pData;
	}

private:
	/* -- DATA MEMBERS -- */
	T* m_pData;
	Node<T>* m_pNext;

	/* -- FRIENDS -- */
	template <typename T>
	friend class Stack;
	template <typename T>
	friend std::ostream& operator << (std::ostream& os, const Node<T>* node);
	template <typename T>
	friend std::ostream& operator << (std::ostream& os, const Node<T>& node);
};

template <typename T>
std::ostream& operator << (std::ostream& os, const Node<T>& node)
{
	if (node.m_pData == nullptr)
		os << "empty-node";
	else
		os << *node.m_pData;
	return os;
}

#endif