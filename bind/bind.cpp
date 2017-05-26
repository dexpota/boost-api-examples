#include <boost/bind.hpp>
#include <functional>
#include <vector>
#include <iostream>
#include <cmath>

void print_number(std::string prefix, int number) {
	std::cout << prefix << number << std::endl;
}

int summation(int a, int b){
	return a + b;
}

int power(int a, int n) {
	return std::pow(a, n);
}

struct Foo {
	void say_hello_to(std::string s){
		std::cout << "Hi " << s << "!" << std::endl;
	}
};


int main(int argc, char* argv[]) {
	std::vector<int> vector = {1, 2, 3, 4, 5};

	{
		// simple use of binding function
		// arbitrary function objects, functions, function pointers, and member function pointers
		std::for_each(vector.begin(), vector.end(), boost::bind(print_number, "Value: ", _1));
	}

	{
		// function composition
		auto composition = boost::bind(power, boost::bind(summation, _1, 2), _2);
		std::cout << composition(1, 2) << std::endl;
	}

	{
		// member function, make a copy of Foo(), if don't want a copy use ref(Foo()) instead
		auto member_function = boost::bind(&Foo::say_hello_to, Foo(), _1);
		member_function("John");
	}

	{
		// logical operators
		std::copy_if(vector.begin(), vector.end(),
					 std::ostream_iterator<int>(std::cout, " "),
					 !boost::bind<bool>([](int n)->bool{ return n % 2 == 0; }, _1));

	}




	return EXIT_SUCCESS;
}