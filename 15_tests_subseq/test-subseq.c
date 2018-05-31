#include <stdio.h>
#include <stdlib.h>
#define ARR_NUMBER 30

size_t maxSeq(int * array, size_t n);
size_t printSeq(int * array, size_t n, char * name);

int seq1[1] = {};
int seq2[] = {0,0,0,0,0};
int seq3[] = {1,1,1,1,1,1};
int seq4[] = {1,2,3,4,5,6,7,8,9};
int seq5[] = {-1,-2,-3,-4,5,4,2,1,20,19,15};
int seq6[] = {1};
int seq7[] = {0};
int seq8[] = {100,50,300,20,400,-1};
int seq9[] = {10,20,30,40,50};
int seq10[] = {1000,2000,3000,10000,900000,1000000};
int seq11[] = {30,5,6,7,8,9,4,2,10,11,12,3};
int seq12[] = {10,15,17,19,11,6,3,4,5,90};
int seq13[] = {-199,-188,-150,-120,-80};
int seq14[] = {-20,-19,-18,-17,9,8,7,6,-40,-31,50};
int seq15[] = {3,4};
int seq16[] = {4,3};
int seq17[] = {100,30,3,4,5,6,7,2,500,40,30,32,35,37,39};
int seq18[] = {100,30,3,4,5,6,7,2,500,40,30,32,28,37,39};
int seq19[] = {2,3,4,2,3,4,2,3,4,2,3,4};
int seq20[] = {5,6,7,4,6,7,2,1,8,9,10,20,30,1};
int seq21[] = {-2147483648,2147483647};
int seq22[21] = {0,1};
int seq23[] = {-2,-3,-4,-6,-7,-8};
int seq24[] = {2147483647,-2147483648};
int seq25[] = {5};
int seq26[] = {-5};
int seq27[] = {-5, 0};
int seq28[] = {5,0};
int seq29[] = {0,5};
int seq30[] = {1,-1,1,-1,1,2,-1,1,2,3,-1,1,2,3,4,-1,1,2,3,4,5,-1,1,2,3,4,5,6,-1,1,2,3,4,5,6,7,-1};

int seq666[]={1};

struct _seqs {
	char *name;
	int len;
	int maxseq;
	int *seq;
};

typedef struct _seqs seqs;

seqs test_data[] = {
	{"seq1", 1, 1, seq1},
	{"seq2", 5, 1, seq2},
	{"seq3", 6, 1, seq3},
	{"seq4", 9, 9, seq4},
	{"seq5", 11, 2, seq5},
	{"seq6", 1, 1, seq6},
	{"seq7", 1, 1, seq7},
	{"seq8", 6, 2, seq8},
	{"seq9", 5, 5, seq9},
	{"seq10", 6, 6, seq10},
	{"seq11", 12, 5, seq11},
	{"seq12", 10, 4, seq12},
	{"seq13", 5, 5, seq13},
	{"seq14", 11, 5, seq14},
	{"seq15", 2,2, seq15},
	{"seq16", 2,1, seq16},
	{"seq17", 15, 5, seq17},
	{"seq18", 15, 5, seq18},
	{"seq19", 12,3, seq19},
	{"seq20", 14, 6, seq20},
	{"seq21", 2, 2, seq21},
	{"seq22", 21, 2, seq22},
	{"seq23", 6, 1, seq23},
	{"seq24", 2, 1, seq24},
	{"seq25", 1, 1, seq25},
	{"seq26", 1, 1, seq26},
	{"seq27", 2, 2, seq27},
	{"seq28", 2, 1, seq28},
	{"seq29", 2, 2, seq29},
	{"seq30", 36, 8, seq30}
};

size_t printSeq(int * arr, size_t n, char * name) {
	printf("Seq %s: {", name);
	for (int i=0; i < n; i++) {
		printf("%d, ", arr[i]);
	}
	printf("}\n");
	return EXIT_SUCCESS;
}

int main (void) {
	int i, arrc = ARR_NUMBER, n, mseq;
	size_t arrl;
	size_t rc;
	char *name;

	rc = maxSeq(seq666, 0);
	printf("666 seq: rc: %lu\n", rc);
	if (rc != 0) {
		printf("maxSeq failed: 666: %lu\n", rc);
		return EXIT_FAILURE;
	}

	for (i=0; i < arrc; i++) {
		n = test_data[i].seq[0];
		name = test_data[i].name;
		arrl = test_data[i].len;
		mseq = test_data[i].maxseq;
		printf("Seq %s: len: %lu; mseq: %d ", name, arrl, mseq);
		printSeq(test_data[i].seq, arrl, name);
		rc = maxSeq(test_data[i].seq, arrl);
		//printf("maxSeq returned: %lu\n", rc);
		if (rc != mseq) {
			printf("maxSeq failed: %lu\n", rc);
			return EXIT_FAILURE;
		}
	}
	printf("maxSeq OK\n");
	return EXIT_SUCCESS;
}

