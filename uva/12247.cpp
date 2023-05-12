#include<stdio.h>

bool willWin (int a, int b, int c, int d, int e, int f) {
	if (a < d && b < e)
		return true;
	if (a < d && c < f)
		return true;
	if (b < e && c < f)
		return true;
	return false;
}


bool willAlwaysWin (int a, int b, int c, int d, int e, int f) {
	if (!willWin(a, b, c, d, e, f))
		return false;
	if (!willWin(a, b, c, d, f, e))
		return false;
	if (!willWin(a, b, c, e, d, f))
		return false;
	if (!willWin(a, b, c, e, f, d))
		return false;
	if (!willWin(a, b, c, f, e, d))
		return false;
	if (!willWin(a, b, c, f, d, e))
		return false;
	return true;
}

int main () {
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d ", &a, &b, &c, &d, &e);
	while (a > 0 || b > 0 || c >0 || d >0 || e > 0) {
		int resp = -1;
		for (int i = 1; i <= 52; i++)
			if (i != a && i != b && i != c && i != d && i != e)
				if (willAlwaysWin(a, b, c, d, e, i)) {
					resp = i;
					break;
				} 
		printf("%d\n", resp);

		scanf("%d %d %d %d %d ", &a, &b, &c, &d, &e);
	}
	return 0;
}