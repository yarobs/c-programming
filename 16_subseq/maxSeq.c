#include <stdio.h>

size_t maxSeq(int * arr, size_t n) {
	int i = 0;
	int last = 0;
	int seq = 0, maxseq = 1;

	if (n == 0) {
		return 0;
	}
	
	for (i=0; i < n; i++) {
		//printf("%d\n", arr[i]);

		if (arr[i] > last) {
			seq++;
			//printf("i: %d > last: %d seq: %d\n", arr[i], last, seq);
		} else {
			seq = 1;
		}
		last = arr[i];
		if (seq > maxseq) {
			//printf("Found new max seq: old: %d, new: %d\n", maxseq, seq);
			maxseq = seq;
		}
	}
	return maxseq;
}
