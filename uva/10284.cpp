#include<stdio.h>
#include<string.h>

bool isValid(int i, int j) {
	if (i>=0 && i<8 && j >=0 && j<8)
		return true;
	return false;
}

void printBoard(int board[][8]) {
	for (int i = 0; i < 8; i++){
			for (int j = 0; j < 8; j++)
				if (board[i][j] != '\0')
					printf("%c", board[i][j]);
				else 
					printf("-");
			printf("\n");
		}
}

int main () {
	char board[8][8];
	int attack[8][8];
	char str[1000];
	int dx[] = {-2, -2, -1, -1, +1, +1, +2, +2};
	int dy[] = {-1, +1, +2, -2, +2, -2, -1, +1};
	int dxx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int dyy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

	while (scanf(" %[^\n]s", str) > 0) {
		int len = strlen(str);
		for (int k = 0, i=0, j=0; k < len; k++)
			if (str[k] >= '1' && str[k] <= '8')
				for (int l = 0; l < str[k]-'0'; l++)
					board[i][j++] = '\0';
			else if (str[k] != '/')
				board[i][j++] = str[k];
			else {
				j = 0;
				i++;
			}

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (board[i][j] != '\0')
					attack[i][j] = 1;
				else
					attack[i][j] = 0;

		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (board[i][j] == 'r' || board[i][j] == 'R') {
					for (int k = 0; k < 8; k++)
						attack[i][k] = attack[k][j] = 1;
				}
				else if (board[i][j] == 'n' || board[i][j] == 'N') {
					for (int k = 0; k < 8; k++) {
						if (isValid(i+dx[k], j+dy[k]))
							attack[i+dx[k]][j+dy[k]] = 1;
					}
				}
				else if (board[i][j] == 'b' || board[i][j] == 'B') {
					for (int k = 0; k<8; k++){
						if (isValid(i+k, j+k))
							attack[i+k][j+k] = 1;
						if (isValid(i+k, j-k))
							attack[i+k][j-k] = 1;
						if (isValid(i-k, j+k))
							attack[i-k][j+k] = 1;
						if (isValid(i-k, j-k))
							attack[i-k][j-k] = 1;
					}
				}
				else if (board[i][j] == 'q' || board[i][j] == 'Q') {
					for (int k = 0; k < 8; k++)
						attack[i][k] = attack[k][j] = 1;
					for (int k = 0; k<8; k++){
						if (isValid(i+k, j+k))
							attack[i+k][j+k] = 1;
						if (isValid(i+k, j-k))
							attack[i+k][j-k] = 1;
						if (isValid(i-k, j+k))
							attack[i-k][j+k] = 1;
						if (isValid(i-k, j-k))
							attack[i-k][j-k] = 1;
					}
				}
				else if (board[i][j] == 'k' || board[i][j] == 'K') {
					for (int k = 0; k < 8; k++)
						if (isValid(i+dxx[k], j+dyy[k]))
							attack[i+dxx[k]][j+dyy[k]] = 1;
				}
				else if (board[i][j] == 'p') {
					if (isValid(i+1,j-1))
						attack[i+1][j-1] = 1;
					if (isValid(i+1, j+1))
						attack[i+1][j+1] = 1; 
				}
				else if (board[i][j] == 'P') {
					if (isValid(i-1,j-1))
						attack[i-1][j-1] = 1;
					if (isValid(i-1, j+1))
						attack[i-1][j+1] = 1; 
				}

		int resp = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (attack[i][j] == 0)
					resp ++;
		printf("%d\n", resp);
	}
	return 0;
}