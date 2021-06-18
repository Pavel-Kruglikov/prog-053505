// ConsoleApplication8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check(void)
{
	int sum, flag; char a;
	flag = 0;
	while (flag == 0) {
		sum = 0; a = '0';
		while ((a <= '9') && (a >= '0')) {
			scanf_s("%c", &a);
			if (a == '\n') {
				break;
			}
			sum = sum * 10 + (a - '0');
		}
		if (a != '\n') {
			printf("THE ENTERED VALUE IF INVALID, PLEASE TRY AGAIN\n");
			while (a != '\n') {
				scanf_s("%c", &a);
			}
		}
		else {
			flag = 1;
			break;
		}
	}
	return sum;
}

int main(void)
{
	int n, m, i, j, player, x, y; int** a;
	puts("Enter N:");
	n = check();
	puts("Enter M:");
	m = check();
	a = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++)
		a[i] = (int*)malloc(m * sizeof(int));
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			a[i][j] = 1;
	a[n - 1][0] = -1;
	player = 1;
	while (1)
	{
		printf("Player number %d chooses a piece.\n", player);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++)
				printf("%3d", a[i][j]);
			printf("\n");
		}
		printf("Choose a piece. ");
		printf("Enter the coordinate of the line: ");
		x = check();
		x--;
		printf("Enter the coordinate of the column: ");
		y = check();
		y--;
		if ((x >= n) || (y >= m) || (x < 0) || (y < 0)) {
			printf("Getting out of bounds\n");
		}
		else {
			if (a[x][y] == 0) {
				printf("The piece's already gone.\n");
			}
			if (a[x][y] == 1) {
				for (i = 0; i <= x; i++)
					for (j = y; j < m; j++)
						a[i][j] = 0;
				if (player == 2) {
					player = 1;
				}
				else {
					player = 2;
				}
			}
			if (a[x][y] == -1) {
				break;
			}
		}
	}
	printf("Player %d lost \n", player);//defeat
	free(a);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
