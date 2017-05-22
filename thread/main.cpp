#include <boost/thread.hpp>
#include <boost/random/linear_congruential.hpp>

#include <stdio.h>

struct callable_with_loop {
    void operator()() {
		while(1) {
			printf("Thread che esegue le sue routine\n");
		}
		return;
	};
};

struct callable_with_loop_and_param {
    void operator()(int param) {
		boost::rand48 random(param);
		boost::rand48::result_type lim_sup = 10;

		while(1) {
			boost::rand48::result_type min = random.min();
			boost::rand48::result_type max = random.max();
			boost::rand48::result_type ret = random();

			boost::rand48::result_type value = lim_sup*((ret - min)/(float)max);

			printf("Thread che esegue le sue routine %d\n", param);
			printf("Numero casuale %d\n", ret);
			printf("Numero normalizzato %d\n", value);
			printf("min %d e max %d\n", min, max);

			boost::this_thread::sleep(boost::posix_time::seconds(value));
		}
		return;
	};
};

struct callable {
    void operator()() {
		printf("Thread esegue il codice\n");
		return;
	};
};

struct callable_with_param {
    void operator()(int param) {
		printf("Thread esegue il codice, il parametro e' %d\n", param);
		return;
	};
};

void auto_detach_test(void);
void manual_detach_test(void);

int main(int argc, char *argv[]) {


	callable_with_loop_and_param p1;
	callable_with_loop_and_param p2;

	boost::thread t1(p1, 1);
	boost::thread t2(p2, 2);

	while(1);

	return EXIT_SUCCESS;
}

void auto_detach_test(void) {
	callable_with_loop y;
	boost::thread thread_with_loop(y);
	// thread becomes detached
	// l'oggetto boost::thread viene eliminato, ma il thread rimane in vita fino a quando la funzione callable non � terminata o il programma non � terminato.
	return;
}

void manual_detach_test(void) {
	callable_with_loop y;
	boost::thread thread_with_loop(y);
	thread_with_loop.detach();
	// threads becomes not-a-thread
	// l'oggetto boost::thread viene eliminato, ma il thread rimane in vita fino a quando la funzione callable non � terminata o il programma non � terminato.
	// un thread di questo tipo viene ignorato dalla funzione join.
	return;
}