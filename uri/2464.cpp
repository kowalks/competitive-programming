#include<stdio.h>

int main ()
{
	char chave[26];
	char crip[10010];
	
	for (int i = 0; i < 26; i++) {
		scanf("%c ", &chave[i]);
		chave[i] -= 'a';
	}
	
	gets(crip);
	for (int i = 0; crip[i] != '\0'; i++) {
		printf("%c", 'a' + chave[crip[i] - 'a']);
	}
	printf("\n");
	
	return 0;
}
