#include <boost/function_output_iterator.hpp>
#include <iostream>

typedef struct output_generator {
    void operator()(int x) const {
        std::cout << "Value: " << x << std::endl;
    }
};


int main(int argc, char *argv[]) {
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    std::copy(vector, vector + sizeof(vector)/sizeof(int), boost::make_function_output_iterator(output_generator()));
    return EXIT_SUCCESS;
}