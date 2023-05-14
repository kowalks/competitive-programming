#include<stdio.h>
#define int long long


main () {
	int n, p;
	
	scanf("%lld", &n);
	
	while (n > 0) {
		printf("%lld = ", n);
		p = 3;
		while (n%p != 0)
			p+=2;
		printf("%lld x ", p);
		n /= p;
		while (n%p != 0)
			p+=2;
		printf("%lld x ", p);
		n /= p;
		printf("%lld\n", n);
		
		
		scanf("%lld", &n);
	}
}
