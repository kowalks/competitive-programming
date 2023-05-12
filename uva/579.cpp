#include<stdio.h>

void getTime(int &h, int &m) {
	char c;
	scanf("%c ", &c);
	h = c - '0';
	scanf("%c ", &c);
	if (c != ':') {
		h = 10*h + c - '0';
		scanf("%c ", &c);
	}
	scanf("%c ", &c);
	m = c - '0';
	scanf("%c ", &c);
	m = 10*m + c - '0';
}

int main () {
	int h, m;
	float ans;
	getTime(h, m);
	while (h != 0 || m != 0) {
		float angleMin = 6*m;
		float angleHour = (h%12)*360.0/12 + 30.0*m/60;
		//printf("min>%.3f   h>%.3f\n\n", angleMin, angleHour);
		ans = angleMin - angleHour;
		ans = (ans < 0) ? ans+360 : ans;
		ans = (ans > 180) ? 360 - ans : ans;
		printf("%.3f\n", ans);
		getTime(h, m);
	}
}