#include<stdio.h>
#define MAXN 1010
#include<queue>

using namespace std;

int fila[MAXN];
priority_queue<int> heap;

int main () {
	int n, k;
	fila[0] = 0;
	int resp;
	bool first = true;
	
	while (scanf("%d %d", &n, &k) == 2) {
		for (int i = 1; i < n; i++)
			scanf("%d", &fila[i]);
		for (int i = 0; i < n-1; i++) {
			heap.push(fila[i+1] - fila[i]);
		}
		
		resp = fila[n-1];
		for (int i = 0; i < k-1; i++) {
			int aux = heap.top();
			resp -= aux;
			heap.pop();
		}
		
		printf("%d\n", resp);
		
		first = false;
		heap = priority_queue <int>();
	}
	
	return 0;
}
