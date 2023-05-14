#include<stdio.h>

int main () {
	int t;
	char str[100];
	scanf("%d", &t);
	gets(str);
	while(t--) {
		gets(str);
		
		int resp = 1;
		for (int i = 0; str[i] != '\0'; i++)
			if (str[i] == 'A' ||str[i] == 'E' ||str[i] == 'I' || str[i] == 'O' || str[i] == 'S' ||
				str[i] == 'a' ||str[i] == 'e' ||str[i] == 'i' || str[i] == 'o' || str[i] == 's')
				resp *= 3;
			else
				resp *= 2;
		
		printf("%d\n", resp);
	}
	
	
	
	return 0;
}
