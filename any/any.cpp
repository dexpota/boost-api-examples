#include <boost/any.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>


int main(int argc, char** argv) {

	{
		boost::any any_value = 10;
		std::cout << boost::any_cast<int>(any_value) << std::endl;
		int *pointer = boost::any_cast<int>(&any_value);
		std::cout << *pointer << std::endl;

		any_value = 2.34;
		std::cout << boost::any_cast<double>(any_value) << std::endl;

		any_value = false;
		std::cout << std::boolalpha << boost::any_cast<bool>(any_value) << std::endl;
	}

	{
		boost::any any_value = 10;
		assert(any_value.type() == typeid(int));

		boost::any empty_value;
		assert(empty_value.empty());
	}

	return 0;
}