#include <boost/array.hpp>
#include <iostream>
#include <array>

struct add_1 : public std::unary_function<char, void> {
	void operator() (char& c) const {
		++c;
	}
};


int main(int argc, char **argv) {
	// std::array is now part of the C++11 standard
	boost::array<int, 5> values = {0, 1, 2, 3, 5};

    std::copy(values.begin(), values.end(), std::ostream_iterator<int>(std::cout, " "));
	return EXIT_SUCCESS;
}