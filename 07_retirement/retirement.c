#include <stdio.h>
#include <stdlib.h>

#define WORK_MONTHS 489
#define RETIRE_MONTHS 384
#define WORK_CONTR 1000
#define RETIRED_CONTR -4000

struct _retire_info {
	int months;
	double contribution;
	double rate_of_return;
};

typedef struct _retire_info retire_info;

void retire_report(int *age, double *balance, retire_info info) {
	int i, years, months;
	for (i=0; i < info.months; i++) {
                years = *age / 12;
                months = *age % 12;
                printf("Age %3d month %2d you have $%.2lf\n", years, months, *balance);
                (*age)++;
                *balance += (*balance * (info.rate_of_return / 100 / 12)) + info.contribution;
        }
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
	int *agep = &startAge;
	double *balancep = &initial;
	retire_report(agep, balancep, working);
	retire_report(agep, balancep, retired);
}

int main() {
	int age = 327;
	double capital = 21345.0;
	retire_info working;
	retire_info retired;

	working.months = WORK_MONTHS;
	working.contribution = WORK_CONTR;
	working.rate_of_return = 4.5;

	retired.months = RETIRE_MONTHS;
	retired.contribution = RETIRED_CONTR;
	retired.rate_of_return = 1.0;

	retirement(age, capital, working, retired);	

	return EXIT_SUCCESS;
}
