#include <boost/noncopyable.hpp>
#include <boost/move/move.hpp>
#include <assert.h>
#include <iostream>
#include <string>
#include <string.h>

class descriptor_owner : private boost::noncopyable{
	void* descriptor_;
	
public:
	explicit descriptor_owner(const char* params) {};
	~descriptor_owner() {};
};

class descriptor_owner1 {
	void* descriptor_;
	 BOOST_MOVABLE_BUT_NOT_COPYABLE(descriptor_owner1)
	
public:
	descriptor_owner1() 
		: descriptor_(NULL) 
	{}
		
	explicit descriptor_owner1(const char* params) 
		: descriptor_(strdup(params))
	{}
	
	descriptor_owner1(BOOST_RV_REF(descriptor_owner1) param) 
		: descriptor_(param.descriptor_) {
		param.descriptor_ = NULL;
	} 
	
	descriptor_owner1& operator=(BOOST_RV_REF(descriptor_owner1) param) {
		clear();
		std::swap(descriptor_, param.descriptor_);
		return *this;
	}
	
	void clear() {
		free(descriptor_);
		descriptor_ = NULL;
	}
	
	bool empty() const {
		return !descriptor_;
	}
	
	~descriptor_owner1() {
		clear();
	}
};

descriptor_owner1 construct_descriptor2() {
	return descriptor_owner1("Construct using this string");
}

void foo_rv() {
	std::cout << "C++11\n";
	descriptor_owner1 desc;
	desc = construct_descriptor2();
	assert(!desc.empty());
}