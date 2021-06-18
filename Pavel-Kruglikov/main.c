// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 80

int JustifyText(const char* const src, char* const resultStr)
{
    int errorCode = 0;  /* error code + return value */

    size_t sequenceCount = 0;           /* non-space sequence counter */
    size_t totalSequenceLength = 0;     /* total length of non-space sequences */
    size_t spacesBetweenSequences = 0;  /* number of spaces required to insert */
    size_t remainder = 0;               /* remainder of spaces to insert */
    size_t i = 0;
    size_t j = 0;

    char* tempSrcStr = NULL;  /* temporary source string */
    char* tempResStr = NULL;  /* temporary return string */
    char* pch = NULL;         /* temporary pointer */

    do
    {
        if ((src == NULL) || (resultStr == NULL))
        {
            errorCode = 1;
            break;
        }

        if (strlen(src) >= N)
        {
            errorCode = 1;
            break;
        }

        /* allocating buffers */
        tempSrcStr = malloc((strlen(src) + 1) * sizeof(*src));
        if (tempSrcStr == NULL)
        {
            errorCode = 1;
            break;
        }

        tempResStr = malloc((N + 1) * sizeof(*tempResStr));
        if (tempResStr == NULL)
        {
            errorCode = 1;
            break;
        }

        strcpy(tempSrcStr, src);
        memset(tempResStr, 0, (N + 1) * sizeof(*tempResStr));

        
        sequenceCount = 0;
        totalSequenceLength = 0;

        pch = strtok(tempSrcStr, " ");
        while (pch != NULL)
        {
            sequenceCount++;
            totalSequenceLength = totalSequenceLength + strlen(pch);

            pch = strtok(NULL, " ");
        }

        /* calculating how many spaces between sequences we need */
        spacesBetweenSequences = (N - totalSequenceLength) / (sequenceCount - 1);

        strcpy(tempSrcStr, src);

        /*
          calculating remainder

          in case if we are unable to insert equal amounts of spaces between all
          sequences we will need to add remaining (to N) amount somewhere in the
          middle of string
        */
        remainder = N - (spacesBetweenSequences * (sequenceCount - 1) + totalSequenceLength);

        /* composing string */
        j = 0;
        pch = strtok(tempSrcStr, " ");
        while (pch != NULL)
        {
            strcat(tempResStr, pch); /* copying sequence */

            /*
              inserting remainder

              NOTE:
                there is no increment of "j" because these spaces are counted as
              a part of current sequence
            */
            if (j == (sequenceCount - 1) / 2)
            {
                for (i = 0; i < remainder; i++)
                {
                    tempResStr[strlen(tempResStr)] = ' ';
                }
            }

            /* padding sequence with spaces */
            if (j < (sequenceCount - 1))
            {
                for (i = 0; i < spacesBetweenSequences; i++)
                {
                    tempResStr[strlen(tempResStr)] = ' ';
                }
                j++;
            }

            pch = strtok(NULL, " ");
        }

        /* exporting result */
        strcpy(resultStr, tempResStr);
    }   while (0);

    free(tempSrcStr);
    free(tempResStr);

    return errorCode;
}

int main(void)
{
    char* s = malloc((N + 1) * sizeof(*s));

    JustifyText("This, whatever it is, must be a test string!", s);

    printf("%s\n", s);

    free(s);

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
