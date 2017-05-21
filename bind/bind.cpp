#include <boost/bind.hpp>
#include <functional>
#include <vector>
#include <iostream>

class Number{ 
public:
	int i;
public:
	explicit Number(int n) {i=n;};
};
inline Number operator+(const Number& n1, const Number& n2) { return Number(n1.i + n2.i); };


struct print_number : public std::unary_function<Number, void> {
	void operator() (Number n1) const {
		std::cout << n1.i << " ";
	}
};

struct mul_2 : public std::unary_function<Number, void> {
	void operator() (Number& n1) const {
		n1.i = n1.i + n1.i;
	}
};

void mul_2_values(std::vector<Number>& values) {
	std::for_each(values.begin(), values.end(), boost::bind(mul_2(), _1));
}

int main(int argc, char** argv) {
	std::vector<Number> vec;
	vec.push_back(Number(1));
	vec.push_back(Number(2));
	vec.push_back(Number(3));
	vec.push_back(Number(4));
	
	mul_2_values(vec);
	std::for_each(vec.begin(), vec.end(), print_number());
}