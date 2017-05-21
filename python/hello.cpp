#include <memory>

char const* greet()
{
   return "hello, world";
}

char const* create() {
    char *mem = new char[3];
    mem[0] = 'a';
    mem[1] = 'a';
    mem[2] = 'a';
    return mem;
}

#include <boost/python.hpp>

BOOST_PYTHON_MODULE(hello_ext)
{
    using namespace boost::python;
    def("greet", greet);

    def("hello", create);
}
