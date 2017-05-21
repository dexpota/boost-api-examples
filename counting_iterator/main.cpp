/*
 * main.cpp
 *
 *  Created on: 22/mag/2012
 *      Author: Fabrizio
 */

#include <boost/iterator/counting_iterator.hpp>

#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]) {
	std::cout << "Counting from 1 to 100." << std::endl;
	boost::counting_iterator<int> begin(1), end(100);
	std::copy(begin, end, std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	return 1;
}
