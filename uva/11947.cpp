#include<stdio.h>


int daysInMonth(int month, int year) {
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	else if (month != 2)
		return 30;
	else if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 29;
	else 
		return 28;
}

int main () {
	int n;
	int caso = 0;
	int d, m, y;
	char c;
	scanf("%d ", &n);
	while (n--) {
		caso++;
		scanf(" %c ", &c);
		m = c - '0';
		scanf(" %c ", &c);
		m = 10*m + c - '0';
		scanf(" %c ", &c);
		d = c - '0';
		scanf(" %c ", &c);
		d = 10*d + c - '0';
		scanf(" %c ", &c);
		y = c - '0';
		scanf(" %c ", &c);
		y = 10*y + c - '0';
		scanf(" %c ", &c);
		y = 10*y + c - '0';
		scanf(" %c ", &c);
		y = 10*y + c - '0';
		int days = 280;
		days += d - 1;
		d = 1;

		while (daysInMonth(m, y) < days) {
			days -= daysInMonth(m, y);
			m = (m+1);
			if (m == 13) {
				m = 1;
				y++;
			}
		}
		d += days;
		days -= days;

		printf("%d %02d/%02d/%4d ", caso, m, d, y);
	
		if (m == 1 && d >= 21 || m == 2 && d <= 19)
			printf("aquarius\n");
		else if (m == 2 || m == 3 && d <= 20)
			printf("pisces\n");
		else if (m == 3 || m == 4 && d <= 20)
			printf("aries\n");
		else if (m == 4 || m == 5 && d <= 21)
			printf("taurus\n");
		else if (m == 5 || m == 6 && d <= 21)
			printf("gemini\n");
		else if (m == 6 || m == 7 && d <= 22)
			printf("cancer\n");
		else if (m == 7 || m == 8 && d <= 21)
			printf("leo\n");
		else if (m == 8 || m == 9 && d <= 23)
			printf("virgo\n");
		else if (m == 9 || m == 10 && d <= 23)
			printf("libra\n");
		else if (m == 10 || m == 11 && d <= 22)
			printf("scorpio\n");
		else if (m == 11 || m == 12 && d <= 22)
			printf("sagittarius\n");
		else
			printf("capricorn\n");
	}

	return 0;
}