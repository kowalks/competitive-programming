#include<stdio.h>

int main ()
{
	int hi, mi, hf, mf, h, m;
	scanf("%d %d %d %d", &hi, &mi, &hf, &mf);
	
	h = hf - hi;
	m = mf - mi;
	
	if (m < 0)
	{
		m += 60;
		h --;
	}
	if (h < 0 || h == 0 && m == 0)
		h += 24;	
		
	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", h, m);
	
	return 0;
}
