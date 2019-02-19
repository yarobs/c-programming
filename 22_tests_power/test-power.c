#include <stdio.h>
#include <stdlib.h>

unsigned power(unsigned, unsigned);

int run_test(unsigned x, unsigned y, unsigned a) {
	unsigned rc;
	rc = power(x, y);
	//printf("%u\n", rc);
	if (rc == a) {
		return EXIT_SUCCESS;
	} else {
		exit(EXIT_FAILURE);
		//return EXIT_FAILURE;
	}
}

void main() {
	run_test(-2, 3, 4294967288);
	run_test(1, -1, 1);
	run_test(-1, -3, 4294967295);
	run_test(5, 3,125);
	run_test(100000, 3, 2764472320);
	run_test(1000, 30000, 0);
	run_test(0, -0, 1);
	run_test(0, -1, 0);
	run_test(2, 10, 1024);
	run_test(1, 1000000000, 1);
	run_test(8, 9, 134217728);
	run_test(0, 999999999, 0);
	run_test(2, 5, 32);
	run_test(-8, 100, 0);
	run_test(10000000, 2, 276447232);
	run_test(1111111111, -4, 3046746529);
}

