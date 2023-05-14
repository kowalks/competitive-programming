#include<stdio.h>

int main ()
{
	int diai, horai, minutoi, segundoi;
	int diaf, horaf, minutof, segundof;
	int d, h, m, s;
	
	scanf("Dia %d\n", &diai);
	scanf("%d : %d : %d\n", &horai, &minutoi, &segundoi);
	scanf("Dia %d\n", &diaf);
	scanf("%d : %d : %d", &horaf, &minutof, &segundof);
	
	d = diaf - diai;
	h = horaf - horai;
	m = minutof - minutoi;
	s = segundof - segundoi;
	
	if (s < 0)
	{
		s += 60;
		m --;
	}
	if (m < 0)
	{
		m += 60;
		h--;
	}
	if (h < 0)
	{
		h += 24;
		d--;
	}
	
	printf("%d dia(s)\n", d);
	printf("%d hora(s)\n", h);
	printf("%d minuto(s)\n", m);
	printf("%d segundo(s)\n", s);
	
	
	return 0;
}
