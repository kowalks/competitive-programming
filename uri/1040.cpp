#include<stdio.h>

int main ()
{
	float n1, n2, n3, n4, aver, exame;
	
	scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
	aver = 0.2*n1 + 0.3*n2 + 0.4*n3 + 0.1*n4;
	printf("Media: %.1f\n", aver);
	if (aver >= 7.0)
	{
		printf("Aluno aprovado.\n");
	}
	else if (aver < 5.0)
	{
		printf("Aluno reprovado.\n");
	}
	else if (aver >= 5.0 && aver <= 6.9)
	{
		printf("Aluno em exame.\n");
		printf("Nota do exame: ");
		scanf("%f", &exame);
		aver = (aver + exame)/2.0;
		if (aver >= 5.0)
		{
			printf("Aluno aprovado.\n");
		}
		else
		{
			printf("Aluno reprovado.\n");
		}
		printf("Media final: %.1f\n", aver);
	}
	
	
	return 0;
}
