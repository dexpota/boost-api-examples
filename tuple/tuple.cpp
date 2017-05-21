#include <boost/tuple/tuple.hpp>
#include <string>
#include <set>

int main(int argc, char** argv) {
	boost::tuple<int, std::string> a_pair(10, "Hello");
	boost::tuple<int, float, double, int> quad(10, 1.0f, 10.0, 1);
	
	int i = boost::get<0>(a_pair);
	const std::string& str = boost::get<1>(a_pair);
	double d = boost::get<2>(quad);
	
	boost::tuple<int, double, int> s;
	s = boost::make_tuple(1,1.0f,2);
	
	float f;
	int i2;
	boost::tie(i,f,d,i2) = quad;
	return 0;
}