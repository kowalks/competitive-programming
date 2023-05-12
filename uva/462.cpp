#include<stdio.h>

int main () {
	char c, s, lixo;
	char card[13];
	int suit[13];
	int num[4];
	int points;
	int stopped[4];
	int sairDesesperado;
	do {
		points = 0;
		num[0] = num[1] = num[2] = num[3] = 0;
		stopped[0] = stopped[1] = stopped[2] = stopped[3] = 0;
		for (int i = 0; i < 13; i++){
			sairDesesperado = scanf(" %c%c", &c, &s);
			if (sairDesesperado != 2)
				goto FIM;
			card[i] = c;
			switch(s) {
				case 'S':	suit[i] = 0; break;
				case 'H':	suit[i] = 1; break;
				case 'D':	suit[i] = 2; break;
				case 'C':	suit[i] = 3; break;
			}
			num[suit[i]]++;
			if (c == 'A')
				points += 4;
			else if (c == 'K')
				points += 3;
			else if (c == 'Q')
				points += 2;
			else if (c == 'J')
				points += 1;
		}

		for (int i = 0; i < 13; i++)
			if (card[i] == 'K' && num[suit[i]] <= 1)
				points -= 1;
			else if (card[i] == 'Q' && num[suit[i]] <= 2)
				points -= 1;
			else if (card[i] == 'J' && num[suit[i]] <= 3)
				points -= 1;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 13; j++)
				if (card[j] == 'A' && suit[j] == i)
					stopped[i] = 1;
				else if (card[j] == 'K' && num[i] >= 2 && suit[j] == i)
					stopped[i] = 1;
				else if (card[j] == 'Q' && num[i] >= 3 && suit[j] == i)
					stopped[i] = 1;

		if (points >= 16 && stopped[0] == 1 && stopped[1] == 1 && stopped[2] == 1 && stopped[3] == 1)
			printf("BID NO-TRUMP\n");
		else {
			for (int i = 0; i < 4; i++)
				if (num[i] == 2)
					points++;
				else if (num[i] <= 1)
					points += 2;

			if (points < 14)
				printf("PASS\n");
			else {
				int ss = -1;
				int numcards = -1;
				for (int i = 0; i < 4; i++)
					if (num[i] > numcards) {
						numcards = num[i];
						ss = i;
					}
				printf("BID ");
				switch(ss) {
					case 0: printf("S\n"); break;
					case 1: printf("H\n"); break;
					case 2: printf("D\n"); break;
					case 3: printf("C\n"); break;
				}
			}
		}
		lixo = 0;
		scanf("%c", &lixo);
//		printf("lixo: %d\n", lixo);
	} while (lixo == '\n');

	FIM:

	return 0;
}