/*
 * main.cpp
 *
 *  Created on: 22/mag/2012
 *      Author: Fabrizio
 */

#include <boost/iterator/counting_iterator.hpp>

#include <iostream>
#include <algorithm>
#include <vector>

int main(int argc, char *argv[]) {

	// This is a naive example of counting from 1 to 100.
	{
		std::cout << "Counting from 1 to 100." << std::endl;
		boost::counting_iterator<int> begin(1), end(100);
		std::copy(begin, end, std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}

	// It may be useful if you want to initialize a vector.
	{
		boost::counting_iterator<int> begin(0), end(10);
		std::vector<int> v;
		std::copy(begin, end, std::back_inserter(v));
	}

	return EXIT_SUCCESS;
}
