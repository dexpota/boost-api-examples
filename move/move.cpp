#include <boost/swap.hpp>
#include <boost/move/move.hpp>
#include <string>
#include <assert.h>

namespace other {
	class characteristics{};
}

struct person_info {
	bool is_male_;
	std::string name_;
	std::string second_name_;
	other::characteristics characteristics_;
	
	void swap(person_info& rhs) {
		std::swap(is_male_, rhs.is_male_);
		name_.swap(rhs.name_);
		second_name_.swap(rhs.second_name_);
		boost::swap(characteristics_, rhs.characteristics_);
	}
	
private:
	BOOST_COPYABLE_AND_MOVABLE(person_info)
	
public:
	person_info(){}
	// Copy ctor
	person_info(const person_info& p) 
		: is_male_(p.is_male_)
		, name_(p.name_)
		, second_name_(p.second_name_)
		, characteristics_(p.characteristics_)
	{}
	// Move ctor
	person_info(BOOST_RV_REF(person_info) person){
		swap(person);
	}
	
	// Copy assigment
	person_info& operator=(BOOST_COPY_ASSIGN_REF(person_info) person) {
		if(this != &person) {
			person_info tmp(person);
			swap(tmp);
		}
		return *this;
	}
	
	// Move assignment
	person_info& operator=(BOOST_RV_REF(person_info) person) {
		if(this != &person) {
			swap(person);
			person_info tmp;
			tmp.swap(person);
		}
		return *this;
	}
};

int main(int argc, char** argv) {
	person_info vasya;
	vasya.name_ = "Vasya";
	vasya.second_name_ = "Snow";
	vasya.is_male_ = true;
	
	person_info new_vasya(boost::move(vasya));
	assert(new_vasya.name_ == "Vasya");
	assert(new_vasya.second_name_ == "Snow");
	assert(vasya.name_.empty());
	assert(vasya.second_name_.empty());
	
	vasya = boost::move(new_vasya);
	assert(vasya.name_ == "Vasya");
	assert(vasya.second_name_ == "Snow");
	assert(new_vasya.name_.empty());
	assert(new_vasya.second_name_.empty());
}
