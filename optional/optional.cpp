#include <boost/optional.hpp>
#include <iostream>
#include <stdlib.h>

class locked_device {
	explicit locked_device(const char *param) {
		std::cout << "Device is locked.\n";
	}
public:
	~locked_device() {}
	
	void use() {
		std::cout << "Success!\n";
	}
	
	static boost::optional<locked_device> try_lock_device() {
		if(rand()%2) {
			return boost::none;
		}
		return locked_device("device name");
	}
};

int main(int argc, char **argv){
	srandom(5);
	for(unsigned i=0; i<10; ++i) {
		boost::optional<locked_device> t = locked_device::try_lock_device();
		
		if(t) {
			t->use();
			return 0;
		}else {
			std::cout << "...trying again.\n";
		}
	}
	std::cout << "Failure!\n";
	return -1;
}