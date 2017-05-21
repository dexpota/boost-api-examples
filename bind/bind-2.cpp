#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <iostream>
#include <string>

// This solve a bug with clang and libc++
template class std::basic_string<char>;

int main(int argc, char** argv) {
	boost::array<int, 12> values = {1,2,3,4,5,6,7,100,99,98,97,96};
	
	std::size_t count0 = std::count_if(values.begin(), values.end(), std::bind1st(std::less<int>(),5));
	std::size_t count1 = std::count_if(values.begin(), values.end(), boost::bind(std::less<int>(), 5, _1));
	std::cout << count0 << " " << count1 << std::endl;
	
	
	boost::array<std::string, 3> str_values = {"We ", "are", "the champions!"};
	count0 = std::count_if(str_values.begin(), str_values.end(), std::mem_fun_ref(&std::string::empty));
	count1 = std::count_if(str_values.begin(), str_values.end(), boost::bind(&std::string::empty, _1));
	std::cout << count0 << " " << count1 << std::endl;

	count1 = std::count_if(str_values.begin(), str_values.end(),
					boost::bind(std::less<std::size_t>(), boost::bind(&std::string::size, _1), 5) );
	
	std::string s("Expensive copy constructor of std::string will be called when binding");
	count0 = std::count_if(str_values.begin(), str_values.end(), std::bind2nd(std::less<std::string>(), s) );
	count1 = std::count_if(str_values.begin(), str_values.end(), boost::bind(std::less<std::string>(), _1, s));
	std::cout << count0 << " " << count1 << std::endl;
	
    /*std::string s("Expensive copy constructor of std::string now won't be called when binding");
	count0 = std::count_if(str_values.begin(), str_values.end(),
             std::bind2nd(std::less<std::string>(), boost::cref(s)));
	count1 = std::count_if(str_values.begin(), str_values.end(),
             boost::bind(std::less<std::string>(), _1, boost::cref(s)));*/
			 
	return 0;
}