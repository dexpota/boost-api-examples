/*
 * main.cpp
 *
 *  Created on: 21/mag/2012
 *      Author: Fabrizio
 */

#include <boost/iterator/filter_iterator.hpp>
#include <iostream>

int main(int argc, char *argv[]) {
	int numbers[] = {1, 2, 4, 5, 7, 87, 0, 9, 10};
    const int N = sizeof(numbers)/sizeof(int);

	typedef boost::filter_iterator<bool (*)(int), int*> filter_iterator;

	auto is_even = [](int value) -> bool{ return (value % 2) == 0; };
	filter_iterator begin(is_even, numbers);
	filter_iterator end(is_even, numbers + N);

	std::for_each(begin, end, [](int value){ std::cout << "Number " << value << " is even." << std::endl;});

	return 1;
}


