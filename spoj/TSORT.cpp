#include<stdio.h>
#define MAXN 1000010

int array[MAXN];
int t;

void quickSort(int l, int r) {
	// make division
	// A[l] ... A[i] will be less than A[r-1]
	int aux;
	int x = array[r-1];
	int i = l;
	for (int j = l; j < r; j++)
		if (array[j] <= x)  {
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			i++;
		}	
	// sort lists
	if (i-l > 1)
		quickSort(l, i);
	if (r - i > 1)
		quickSort(i, r);
}

int main () {
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		scanf("%d", &array[i]);
	quickSort(0, t);
	for (int i = 0; i < t; i++)
		printf("%d\n", array[i]);

}
