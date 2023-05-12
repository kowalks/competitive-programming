#include<stdio.h>
#include<stdlib.h>


class Matriz {
	private: 
		int **mat;
		int x;
		int y;

	public:
		Matriz(int x, int y) {
			mat = (int **) malloc(x * sizeof(int*));
			for (int i = 0; i < x; i++) {
				mat[i] = (int*) malloc(y * sizeof(int));
			}
			for (int i = 0; i < x; i++)
				for(int j = 0; j < y; j++)
					mat[i][j] = i + j;
			this->x = x;
			this->y = y;
		}
		int get(int x, int y) {
			return mat[x][y];
		}
		int getX(){
			return x;
		}
		int getY() {
			return y;
		}

		Matriz operator + (Matriz m2) {
			Matriz soma(x, y);
			for (int i = 0; i < x; i++)
				for (int j = 0; j < y; j++)
					soma.mat[i][j] = this->mat[i][j] + m2.mat[i][j];
			return soma;

		}

		Matriz operator * (int a) {
			Matriz mult(x, y);
			for (int i = 0; i < x; i++)
				for (int j = 0; j < y; j++)
					mult.mat[i][j] = a*mat[i][j];
			return mult;
		}

		void imprime() {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++)
					printf("%2d ", mat[i][j]);
				printf("\n");
			}
		}
		void set(int i, int j, int k) {
			mat[i][j] = k;
		}

};

Matriz operator * (int k, Matriz m) {
	Matriz mult(m.getX(), m.getY());
		for (int i = 0; i < m.getX(); i++)
			for (int j = 0; j < m.getY(); j++)
				mult.set(i, j, k*m.get(i, j));
	return mult;
}


int main () {
	Matriz m(10, 10);
	m.imprime();
	Matriz n(10, 10);
	printf("\n\n\n");
	n = (-1)*n*(-1);
	n.imprime();
}