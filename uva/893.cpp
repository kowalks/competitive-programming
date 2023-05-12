#include<stdio.h>

int daysInYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 366;
	else
		return 365; 
}

int daysInMonth(int month, int year) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month != 2)
		return 30;
	else if (daysInYear(year) == 366)
		return 29;
	else
		return 28;
}

int main () {
	int days;
	int d, m, y;

	scanf("%d %d %d %d", &days, &d, &m, &y);
	while(days!= 0 || d!=0 || m!=0 || y!=0) {
		int aux = 0;
		int im=1;
		while (im != m){
			aux += daysInMonth(im, y);
			im++;
		}
		aux += (d - 1);
		d = 1;
		m = 1;
		days += aux;
		while (daysInYear(y) <= days){
			days -= daysInYear(y);
			y++;
		}
		while(daysInMonth(m, y) <= days) {
			days -= daysInMonth(m,y);
			m++;
		}
		d += days;
		days -= days;

		printf("%d %d %d\n", d, m, y);

		scanf("%d %d %d %d", &days, &d, &m, &y);
	}

	return 0;
}