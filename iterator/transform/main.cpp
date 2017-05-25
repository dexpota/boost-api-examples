#include <boost/iterator/transform_iterator.hpp>
#include <iostream>
#include <vector>
#include <list>

int squared(int n) {
    return n*n;
}

int main(int argc, char *argv[]) {
    int vector[] = {45, 34, 33, 12, 4, 54, 6, 57, 68, 79};
    int n = sizeof(vector)/sizeof(int);

    auto begin = boost::make_transform_iterator(vector, squared);
    auto end = boost::make_transform_iterator(vector + n, squared);

    std::copy(begin, end, std::ostream_iterator<int>(std::cout, " "));

    return EXIT_SUCCESS;
}