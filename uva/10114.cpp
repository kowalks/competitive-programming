#include<stdio.h>

int main () {
	double carValue, dtpayment, loan, rate;
	double rateByMonth[105];
	int duration, dep, month;

	scanf("%d %lf %lf %d", &duration, &dtpayment, &loan, &dep);
	while(duration > 0) {
		for (int i = 0; i < 105; i++)
			rateByMonth[i] = 0;
		while(dep--) {
			scanf("%d %lf", &month, &rate);
			rateByMonth[month] = rate;
		}
		for (int i = 1; i < 105; i++)
			if (rateByMonth[i] == 0)
				rateByMonth[i] = rateByMonth[i-1];
		carValue = dtpayment + loan;
		int payment = loan/duration;
		carValue -= carValue*rateByMonth[0];
		int i = 0;
		while (loan >= carValue) {
			i++;
			loan -= payment;
			carValue -= carValue*rateByMonth[i];
		}

		if (i == 1)
			printf("1 month\n");
		else
			printf("%d months\n", i);


		scanf("%d %lf %lf %d", &duration, &dtpayment, &loan, &dep);
	}
	return 0;
}