#include<stdio.h>
#include<conio.h>
#include<math.h>
#include <intrin.h>
#include <locale>
#define n 4 //размерность матрицы
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	setlocale(LC_CTYPE, "UTF-8");
	int i, k = 0;
	double L[n], D[n], U[n], f[n];


	/*
	//задаем циклом
	for (i = 0; i < n; i++){
		L[i] = 3, //lower
		D[i] = 7, //diag
		U[i] = 3, //upper
		f[i] = 12; //правая часть
	}
	*/
	
	L[0] = 0; //lower (null)
	L[1] = 3; //lower 1
	L[2] = 4; //lower 2
	L[3] = 3; //lower 3


	D[0] = 7; //diag 1
	D[1] = 6; //diag 2
	D[2] = 7; //diag 3
	D[3] = 8; //diag 4

	U[0] = 3, //upper 1
	U[1] = 2, //upper 2
	U[2] = 3, //upper 3
	U[3] = 0, //upper (null)

	f[0] = 12; //rhs
	f[1] = 0;
	f[2] = 3;
	f[3] = 6;
	
	double A[n], B[n], e, x[n]; //альфа, бетта, точность, решение
	
	//вывод матрицы
	for (i = 0; i <= n - 1; i++)
		printf("L[%d]=%2.2f  \n", i + 1, L[i]);
	for (i = 0; i <= n - 1; i++)
		printf("D[%d]=%2.2f  \n", i + 1, D[i]);
	for (i = 0; i <= n - 1; i++)
		printf("U[%d]=%2.2f  \n", i + 1, U[i]);
	for (i = 0; i <= n - 1; i++)
		printf("f[%d]=%2.1f  \n", i + 1, f[i]);

	printf("\n\Проверка диагональных элементов: ");
	for(i = 0; i <= n - 1; i++){
		if (fabs(D[i])<(fabs(L[i]) + fabs(U[i])))
			k++;
	}
	if(k == 0)
		printf("|di|<=|ui|+|li| Верно!\n\n");
	else
		printf("|di|<=|ui|+|li| НЕ верно!\n\n");

	//начало прогонки
	//первые 2 коэффициента
	A[0] = -U[0] / D[0];
	B[0] = f[0] / D[0];

	printf("Коэффициенты: \n\nA[1]=%1.3f", A[0]);
	printf("\nB[1]=%1.3f\n", B[0]);

	//остальные коэффициенты
	for (i = 1; i<n; i++) {
		e = L[i] * A[i - 1] + D[i];
		A[i] = -U[i] / e;
		B[i] = (f[i] - L[i] * B[i - 1]) / e;

		printf("A[%d]=%1.3f\n", i + 1, A[i]);
		printf("B[%d]=%1.3f\n", i + 1, B[i]);
	}
	//обратный ход
	x[n - 1] = (f[n - 1] - L[n - 1] * B[n - 2]) / (D[n - 1] + L[n - 1] * A[n - 2]);
	for (i = n - 2; i >= 0; i--) {
		x[i] = x[i + 1] * A[i] + B[i];
	}
	printf("\n\nРешение системы: \n\n");
	for (i = 0; i <= n - 1; i++)
		printf("x[%d]=%2.2f  \n", i + 1, x[i]);
	//конец
	scanf_s("%d", i);
	return 0;

}