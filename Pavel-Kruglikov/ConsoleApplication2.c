// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDSIZE 80
#define MAXSIZE 1000

int main(void)
{
    char dataLab4[WORDSIZE], word_need[WORDSIZE], word_file[MAXSIZE];
    FILE* in = NULL;

    printf("Input: ");
    scanf("%s", dataLab4);

    if ((in = fopen(dataLab4, "r")) == NULL)
    {
        perror("Couldn't open file");
        exit(1);
    }

    printf("Put word: ");
    scanf("%s", word_need);

    while (fscanf(in, "%s", word_file) && !feof(in))
        if (!strcmp(word_file, word_need))
        {
            printf("Word '%s' fined.\n", word_file);
            fclose(in);
            return 0;
        }

    printf("No found.\n");
    fclose(in);

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
