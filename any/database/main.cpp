#include <boost/any.hpp>
#include <boost/iterator/function_input_iterator.hpp>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <iostream>

typedef boost::any cell_t;
typedef std::vector<cell_t> db_row_t;

db_row_t get_row() {
	db_row_t row;
	row.push_back(std::string("Name"));
	row.push_back(std::string("Surname"));
	row.push_back(22);
	row.push_back(std::string("Address"));
	row.push_back(33.12);
	row.push_back(true);
	return row;
}

struct db_sum : public std::unary_function<boost::any, void>{
private:
	double& sum_;
public:
	explicit db_sum(double &sum) : sum_(sum) {}
	
	void operator() (const cell_t& value) {
		const std::type_info& ti = value.type();
		if(ti == typeid(int)) {
			sum_ += boost::any_cast<int>(value);
		}else if(ti == typeid(float)) {
			sum_ += boost::any_cast<float>(value);
		}
	}
};

int main(int argc, char** argv) {
	std::vector<db_row_t> rows;

	std::back_insert_iterator<std::vector<db_row_t> > it(rows);
	auto begin = boost::make_function_input_iterator(get_row, 0);
	auto end = boost::make_function_input_iterator(get_row, 10);
	std::copy(begin, end, it);

	// select name from table
	std::for_each(rows.begin(), rows.end(), [](db_row_t row){
		std::cout << "Name: " << boost::any_cast<std::string>(row[0]) << std::endl;
	});

	// select sum(cell) from table
	float summation = 0;
	std::for_each(rows.begin(), rows.end(), [&summation](db_row_t row){
		summation += boost::any_cast<double>(row[4]);
	});
	return 0;
}

