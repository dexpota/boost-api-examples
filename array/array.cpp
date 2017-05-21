#include <boost/array.hpp>
#include <algorithm>
#include <array>

struct add_1 : public std::unary_function<char, void> {
	void operator() (char& c) const {
		++c;
	}
};


typedef boost::array<char, 4> array4_t;
array4_t& vector_advance(array4_t& val) {
	std::for_each(val.begin(), val.end(), add_1());
	return val;
}

int main(int argc, char **argv) {
	array4_t val = {0,1,2,3};
	// std::array<int,4> p;
	array4_t val_res;
	val_res = vector_advance(val);
	return 0;
}