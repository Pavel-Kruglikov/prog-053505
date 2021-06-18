// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
void instructions() {
	printf("Choose what to do : \n1 - Enter two numbers\n2 - show \n3 - add \n4 - subtract \n5 - multiply \n6 - divide\n7 - harmonic value \n8 - program info \n9 - close\n ");
}
int numeric1() {
	int n1;
	printf("Enter numerator of your first number\n");
	scanf_s("%d", &n1);
	return n1;
}
int denominator1() {
	int d1;
	printf("Enter denominator of your first number\n");
	scanf_s("%d", &d1);
	return d1;
}
int numeric2() {
	int n2;
	printf("Enter numerator of your second number\n");
	scanf_s("%d", &n2);
	return n2;
}
int denominator2() {
	int d2;
	printf("Enter denominator of your second number\n");
	scanf_s("%d", &d2);
	return d2;
}
void show_secret(int n1, int d1, int n2, int d2) {
	printf("your two numbers are: \n");
	printf("%d       %d\n__      __\n%d       %d\n\n", n1, n2, d1, d2);
}
void add(int n1, int d1, int n2, int d2) {
	int res_numeric = 0;
	int res_denominator = 0;
	if (d1 == d2) {
		res_denominator = d1;
		res_numeric = n1 + n2;
	}
	else {
		res_denominator = d1 * d2;
		res_numeric = n1 * d2 + n2 * d1;
	}
	if (res_denominator % 2 == 0 && res_numeric % 2 == 0) {
		res_denominator = res_denominator / 2;
		res_numeric = res_numeric / 2;
	}
	else if (res_denominator % 3 == 0 && res_numeric % 3 == 0) {
		res_denominator = res_denominator / 3;
		res_numeric = res_numeric / 3;
	}
	else if (res_denominator % 4 == 0 && res_numeric % 4 == 0) {
		res_denominator = res_denominator / 4;
		res_numeric = res_numeric / 4;
	}
	else if (res_denominator % 5 == 0 && res_numeric % 5 == 0) {
		res_denominator = res_denominator / 5;
		res_numeric = res_numeric / 5;
	}
	if (res_numeric != res_denominator) {
		printf("adding result is: \n%d\n__\n%d\n", res_numeric, res_denominator);
	}
	else if (res_numeric == res_denominator) {
		printf("adding result is: \n%d\n", res_numeric);
	}
}
void subtract(int n1, int d1, int n2, int d2) {
	int res_numeric = 0;
	int res_denominator = 0;
	if (d1 == d2) {
		res_denominator = d1;
		res_numeric = n1 - n2;
	}
	else {
		res_denominator = d1 * d2;
		res_numeric = n1 * d2 - n2 * d1;
	}
	if (res_denominator % 2 == 0 && res_numeric % 2 == 0) {
		res_denominator = res_denominator / 2;
		res_numeric = res_numeric / 2;
	}
	else if (res_denominator % 3 == 0 && res_numeric % 3 == 0) {
		res_denominator = res_denominator / 3;
		res_numeric = res_numeric / 3;
	}
	else if (res_denominator % 4 == 0 && res_numeric % 4 == 0) {
		res_denominator = res_denominator / 4;
		res_numeric = res_numeric / 4;
	}
	else if (res_denominator % 5 == 0 && res_numeric % 5 == 0) {
		res_denominator = res_denominator / 5;
		res_numeric = res_numeric / 5;
	}
	if (res_numeric != res_denominator) {
		printf("subtracting result is: \n%d\n__\n%d\n", res_numeric, res_denominator);
	}
	else if (res_numeric == res_denominator) {
		printf("subtracting result is: \n%d\n", res_numeric);
	}
}
void multiply(int n1, int d1, int n2, int d2) {
	int res_numeric = 0;
	int res_denominator = 0;
	res_numeric = n1 * n2;
	res_denominator = d1 * d2;
	if (res_denominator % 2 == 0 && res_numeric % 2 == 0) {
		res_denominator = res_denominator / 2;
		res_numeric = res_numeric / 2;
	}
	else if (res_denominator % 3 == 0 && res_numeric % 3 == 0) {
		res_denominator = res_denominator / 3;
		res_numeric = res_numeric / 3;
	}
	else if (res_denominator % 4 == 0 && res_numeric % 4 == 0) {
		res_denominator = res_denominator / 4;
		res_numeric = res_numeric / 4;
	}
	else if (res_denominator % 5 == 0 && res_numeric % 5 == 0) {
		res_denominator = res_denominator / 5;
		res_numeric = res_numeric / 5;
	}
	if (res_numeric != res_denominator) {
		printf("multiplying result is: \n%d\n__\n%d\n", res_numeric, res_denominator);
	}
	else if (res_numeric == res_denominator) {
		printf("multiplying result is: \n%d\n", res_numeric);
	}
}
void divide(int n1, int d1, int n2, int d2) {
	int res_numeric = 0;
	int res_denominator = 0;
	res_numeric = n1 * d2;
	res_denominator = d1 * n2;
	if (res_denominator % 2 == 0 && res_numeric % 2 == 0) {
		res_denominator = res_denominator / 2;
		res_numeric = res_numeric / 2;
	}
	else if (res_denominator % 3 == 0 && res_numeric % 3 == 0) {
		res_denominator = res_denominator / 3;
		res_numeric = res_numeric / 3;
	}
	else if (res_denominator % 4 == 0 && res_numeric % 4 == 0) {
		res_denominator = res_denominator / 4;
		res_numeric = res_numeric / 4;
	}
	else if (res_denominator % 5 == 0 && res_numeric % 5 == 0) {
		res_denominator = res_denominator / 5;
		res_numeric = res_numeric / 5;
	}
	if (res_numeric != res_denominator) {
		printf("dividing result is: \n%d\n__\n%d\n", res_numeric, res_denominator);
	}
	else if (res_numeric == res_denominator) {
		printf("dividing result is: \n%d\n", res_numeric);
	}
}
void harmonic_value(int n1, int d1, int n2, int d2) {

	int res_numeric = 0;
	int res_denominator = 0;
	int bn1 = 0;
	int bd1 = 0;
	int bn2 = 0;
	int bd2 = 0;
	bn1 = d1;
	bd1 = n1;
	bn2 = d2;
	bd2 = n2;
	if (bd1 == bd2) {
		res_denominator = 2 * bd1;
		res_numeric = bn1 + bn2;
	}
	else {
		res_denominator = 2 * bd1 * bd2;
		res_numeric = bn1 * bd2 + bn2 * bd1;
	}
	printf("harmonic value is: \n%d\n__\n%d\n", res_denominator, res_numeric);
}
void program_info() {
	printf("Lab2\nVersion: 1.0\nAuthor: Pavel Kruglikov, group 053505\n\n");
}
int main()
{
	int index;
	int working = 1;
	int n = 0, m = 0, v = 0, w = 0;
	while (working == 1) {
		instructions();
		scanf_s("%d", &index);
		system("cls");
		switch (index) {
		case 1:
			n = numeric1();
			m = denominator1();
			v = numeric2();
			w = denominator2();
			system("cls");
			break;
		case 2:
			show_secret(n, m, v, w);
			break;
		case 3:
			add(n, m, v, w);
			break;
		case 4:
			subtract(n, m, v, w);
			break;
		case 5:
			multiply(n, m, v, w);
			break;
		case 6:
			divide(n, m, v, w);
			break;
		case 7:
			harmonic_value(n, m, v, w);
			break;
		case 8:
			program_info();
			break;
		case 9:
			working = 0;
			break;
		default:
			break;
		}
	}
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
