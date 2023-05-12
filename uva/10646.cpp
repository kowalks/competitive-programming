#include<stdio.h>

int main () {
	int n, caso = 0, x, y, index;
	char card[52], suit[52];
	scanf("%d ", &n);
	while(n--) {
		index = 25;
		caso++;
		for (int i = 51; i >= 0; i--)
			scanf(" %c%c ", &card[i], &suit[i]);
		y = 0;
		for (int i = 0; i < 3; i++){
			x = (card[index] >= '2' && card[index] <= '9') ? card[index] - '0' : 10;
			
			//printf("x: %d\n", x);
			y += x;
			for (int j = 0; j <= 10-x; j++) {
				card[index] = 0;
				index++;
			}
		}
		int count  = 0;
		index = 52;
		do {
			index--;
			if (card[index] != 0)
				count++;
		} while (count < y);

		printf("Case %d: %c%c\n", caso, card[index], suit[index]);
	}

	return 0;
}