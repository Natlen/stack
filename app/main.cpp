#include <iostream>

#include "Stack.h"

class dummy
{
public:
	dummy() : x {0 }, y{ 0.0 }, z{ 0.0F } {};
	dummy(int x, double y, float z) : x{ x }, y{ y }, z{ z } {};

	bool operator == (const dummy& d)
	{
		return x == d.x && y == d.y && z == d.z;
	}
	friend std::ostream& operator << (std::ostream& os, const dummy& D);
private:
	int x;
	double y;
	float z;
};
std::ostream& operator << (std::ostream& os, const dummy& d)
{
	return os << "[" << d.x << ", " << d.y << ", " << d.z << "]";
}
int main()
{
	
	Node<int> n1(1);
	Node<int> n2 = std::move(n1);
	Stack<int> s1{ 1,1,1,1,8};
	Stack<int> s2 = s1;
	Stack<int> s3 { 1,2,3,4,5 };
	Stack<int> s4{ std::move(s3) };
	Stack<int> s5;
	s5 = s1;
	Stack<int> s6;
	s5 = s4;
	s6 = std::move(s4);
	std::cout << s6;
	Stack<int> s7;
	std::cout << s7;
	dummy d1{ 1, 1.1, 1.11F };
	dummy d2{ 2, 2.2, 2.22F };
	dummy d3{ 3, 3.3, 3.33F };
	dummy d4{ 4, 4.4, 4.44F };
	Node<dummy> nd{ d1 };
	std::cout << nd << std::endl;
	Stack<dummy> sd1{ d1,d2,d3 };
	Stack<dummy> sd2{ d1,d2,d3 };
	Stack<dummy> sd3{ d1,d2 };
	Stack<dummy> sd4{ d1,d2,d3, d4 };
	Stack<dummy> sd5;
	Stack<dummy> sd6;
	sd1 == sd2 ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;
	sd1 == sd3 ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;
	sd1 == sd4 ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;
	sd5 == sd6 ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;
	sd5 == sd1 ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;
	sd1 == sd6 ? std::cout << "true" : std::cout << "false";
	std::cout << std::endl;
	std::cout << sd1;
	return 0;
}