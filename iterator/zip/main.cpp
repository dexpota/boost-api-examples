#include <boost/iterator/zip_iterator.hpp>
#include <iostream>
#include <vector>
#include <list>


int squared(int n) {
    return n*n;
}

int main(int argc, char *argv[]) {
    std::vector<int> vector = {45, 34, 33, 12};
    std::vector<std::string> names = {"John", "Joe", "Joel", "Jerry"};

    auto begin = boost::make_zip_iterator(boost::make_tuple(vector.cbegin(), names.cbegin()));
    auto end = boost::make_zip_iterator(boost::make_tuple(vector.cend(), names.cend()));

    std::for_each(begin, end, [](boost::tuple<int, std::string> t){ std::cout << t.get<0>() << std::endl; });

    return EXIT_SUCCESS;
}