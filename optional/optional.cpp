#include <boost/optional.hpp>
#include <iostream>
#include <stdlib.h>

boost::optional<int> return_value() {
    return boost::optional<int>(10);
}

boost::optional<int> return_none() {
    return boost::none;
}

int main(int argc, char **argv){
    // none value converted to bool is false
    assert(!return_none());

    // return 10 because the optional value is none
    assert(return_none().value_or(10) == 10);

    // call the function because the optional value is none
    assert(return_none().value_or_eval([](){return 10;}) == 10);

    try {
        return_none().value();
    }catch (const boost::bad_optional_access&) {
        std::cout << "It's none." << std::endl;
    }

    // return an optional filled with a value
    assert(return_value().value() == 10);

    return EXIT_SUCCESS;
}