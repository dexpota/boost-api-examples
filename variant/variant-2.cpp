#include <boost/variant.hpp>
#include <vector>
#include <string>
#include <iostream>

typedef boost::variant<int, float, std::string> cell_t;
typedef std::vector<cell_t> db_row_t;

db_row_t get_row(const char* query) {
	db_row_t row;
	row.push_back(10);
	row.push_back(10.1f);
	row.push_back("hello again");
	return row;
}

struct db_sum_visitor : public boost::static_visitor<double> {
	double operator() (int value) const {
		return value;
	}
	
	double operator() (float value) const {
		return value;
	}
	
	double operator() (const std::string&) const {
		return 0.0;
	}
};

int main(int argc, char **argv) {
	db_row_t row = get_row("Give me that!");
	double res = 0.0;
	db_row_t::const_iterator it = row.begin(), end = row.end();
	for(; it!=end; ++it) {
		res += boost::apply_visitor(db_sum_visitor(), *it);
	}
	
	std::cout << "Sum of arithmetic types in database row is: " << res << std::endl;
	return 0;
}

