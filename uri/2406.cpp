#include<stdio.h>
#define MAXC 100010

int main (){
	char cadeia[MAXC];
	char pilha[MAXC];
	int ptr;
	int t;
	bool quebrou;
	
	scanf("%d ", &t);
	
	while (t--) {
		gets(cadeia);
		
		ptr = -1;
		quebrou = false;
		for (int i = 0; cadeia[i] != '\0'; i++) {
			if (cadeia[i] == '(' || cadeia[i] == '[' || cadeia[i] == '{')
				pilha[++ptr] = cadeia[i];
			else if (ptr >= 0 && ((cadeia[i] == ']' && pilha[ptr] == '[') || (cadeia[i] == '}' && pilha[ptr] == '{') || (cadeia[i] == ')' && pilha[ptr] == '(') ))
				ptr--;
			else {
				quebrou = true;
				break;
			}
		}	
		
		if (quebrou || ptr != -1)
			printf("N\n");
		else
			printf("S\n");
		
	}
	
	return 0;
}
