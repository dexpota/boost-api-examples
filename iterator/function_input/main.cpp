#include <boost/iterator/function_input_iterator.hpp>
#include <iostream>
#include <random>

typedef struct{
    typedef int result_type;
    result_type operator() (){
        return std::rand();
    };
} generator;

int main(int argc, char *argv[]){
    auto g = generator();
    boost::function_input_iterator<generator, int> begin(g, 0);
    boost::function_input_iterator<generator, int> end(g, 10);

    // Output 10 random integer numbers.
    std::copy(begin, end, std::ostream_iterator<int>(std::cout, " "));

    return EXIT_SUCCESS;
}