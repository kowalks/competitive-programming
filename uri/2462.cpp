#include<stdio.h>

int main () {
	int pa, ca, pb, cb;
	scanf("%d :00 %d :00 %d :00 %d :00", &pa, &cb, &pb, &ca);
	
	int cb1, cb2;
	cb1 = cb - pa;
	cb1 %= 24;
	cb2 = pb - ca;
	cb2 %= 24;
	
	int fuso = (cb1 + cb2)/2;
	
	if (cb1*cb2 < 0) {
		if (cb1 > 0)
			fuso += 12;
		else
			fuso -= 12;
	}
	
	int duracao = cb - (fuso + pa);
	if (duracao < 0) duracao += 24;
	
	printf("%d %d", duracao*60, fuso);
	
}
