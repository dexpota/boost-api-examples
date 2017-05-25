#include <boost/iterator/permutation_iterator.hpp>
#include <iostream>
#include <vector>
#include <list>


int main(int argc, char *argv[]) {
    int index[] = {9, 1, 2, 3, 4, 5, 6, 7, 8, 0};
    int vector[] = {45, 34, 33, 12, 4, 54, 6, 57, 68, 79};
    int n = sizeof(vector)/sizeof(int);

    // This iterator provides a different view of a given range.
    boost::permutation_iterator<int*, int*> begin = boost::make_permutation_iterator(vector, index);
    boost::permutation_iterator<int*, int*> end = boost::make_permutation_iterator(vector + n, index + n);

    std::copy(begin, end, std::ostream_iterator<int>(std::cout, " "));

    return EXIT_SUCCESS;
}