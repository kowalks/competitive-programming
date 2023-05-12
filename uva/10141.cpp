#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main ()
{
	int n, p, metReq, metReqBest;
	int caseCount = 0;
	char lixo[100];
	char name[100], nameBest[100];
	float price, priceBest;
	scanf(" %d %d ", &n, &p);
	while (n != 0 || p != 0)
	{
		caseCount++;
		metReqBest = -1;
		priceBest = -1;
		for (int i = 0; i < n; i++)
			fgets(lixo, 100, stdin);
		for (int i = 0; i < p; i++) {
			// proposal
			fgets(name, 100, stdin);
			scanf(" %f %d ", &price, &metReq);
			for (int j = 0; j < metReq; j++)
				fgets(lixo, 100, stdin);
			if (metReq > metReqBest || metReq == metReqBest && price < priceBest) {
				strcpy(nameBest, name);
				metReqBest = metReq;
				priceBest = price;
			}
		}

		if (caseCount != 1)
			printf("\n");
		printf("RFP #%d\n", caseCount);
		printf("%s", nameBest);
		scanf(" %d %d ", &n, &p);
	}	


	return 0;
}