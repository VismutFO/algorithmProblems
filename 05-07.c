#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 05-7: Сортировка строк
Даны N строк различной длины, состоящих из символов латинского алфавита. Требуется отсортировать их в лексикографическом порядке. Лексикографический порядок зададим 
следующим образом. Символ C1 меньше символа C2, если C1 - строчная буква, а C2 - заглавная, либо если оба символа C1 и C2 одновременно являются строчными или заглавными
буквами и C1 находится раньше по алфавиту, чем C2. Если символы совпадают, они считаются равными. Во всех остальных случаях, считается, что символ C1 больше символа C2.

Строка символов S1 меньше в лексикографическом порядке строки символов S2, если у них, возможно, есть одинаковый префикс, после которого либо очередной символ строки S1
меньше очередного символа строки S2, либо строка S1 закончилась, а S2 продолжается. Иначе, если строки совпадают по длине и посимвольно, они считаются равными.
Во всех остальных случаях, строка S1 больше в лексикографическом порядке строки S2.

На стандартном потоке ввода в первой строке задано натуральное число N (1 ≤ N ≤ 500000) и в следующих N строках задано N последовательностей символов (строк),
состоящих из строчных и заглавных латинских букв. Каждая строка входных данных ограничена символом перевода строки '\n'. Суммарная длина входных строк L удовлетворяет
неравенству 1 ≤ L ≤ 9000000.

На стандартный поток вывода напечатайте данные строки в лексикографическом порядке по возрастанию.

Указание: для хранения строк используйте динамическую память. Считайте, что объема памяти достаточно для хранения входных данных.
*/

typedef long long ll;

int cmpChar(char a, char b)
{
    if (a == b) { return 0; }
    if ('a' <= a && a <= 'z' && 'A' <= b && b <= 'Z') { return -1; }
    if ('a' <= b && b <= 'z' && 'A' <= a && a <= 'Z') { return 1; }
    return (a < b ? -1 : 1);
}

int cmpString(const void* a, const void* b)
{
    char* A = *((char**)a), *B = (*(char**)b);
    int n = strlen(A), m = strlen(B);
    for (int i = 0; i < n && i < m; i++)
    {
        int temp = cmpChar(A[i], B[i]);
        if (temp == 0) { continue; }
        return temp;
    }
    if (n == m) { return 0; }
    return (n < m ? -1 : 1);
}

int main(int argc, char** argv)
{
    int n;
    scanf("%d\n", &n);
    char** arr = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++)
    {
        int curSize = 0, realSize = 1;
        char* temp = (char*)malloc(realSize * sizeof(char));
        char x;
        scanf("%c", &x);
        while (x != '\n')
        {
            temp[curSize++] = x;
            scanf("%c", &x);
            if (curSize == realSize)
            {
                realSize *= 2;
                char* temp2 = temp;
                temp = (char*)malloc(realSize * sizeof(char));
                for (int j = 0; j < curSize; j++)
                {
                    temp[j] = temp2[j];
                }
                free(temp2);
            }
        }
        temp[curSize] = '\0';
        arr[i] = temp;
    }
    qsort(arr, n, sizeof(char*), cmpString);
    for (int i = 0; i < n; i++)
    {
        int len = strlen(arr[i]);
        for (int j = 0; j < len; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    free(arr);
    free(temp);
    return 0;
}
