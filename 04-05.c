#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 04-5: Вращение слова
Требуется написать программу, которая должна напечатать слово, полученное из исходного циклическим сдвигом его на N символов влево.
Будем называть словом любую последовательность букв латинского алфавита A-Z, a-z.
На входе программы задаётся слово длины L ≤ 80 и натуральное число N < 2 000 000 000.
При циклическом сдвиге на каждом шагу буква слова, стоящая на первом месте, перемещается в конец.
Формат входных данных: в первой строке на стандартный ввод подается число N, во второй — исходное слово.
Формат выходных данных: одна строка, содержащая полученное слово.
*/

int main(int argc, char** argv)
{
    int n;
    scanf("%d", &n);
    char buf[200];
    fgets(buf, 200, stdin);
    fgets(buf, 200, stdin);
    int len = 0;
    while (buf[len] != '\n' && buf[len] != '\0') { len++; }
    for (int i = 0; i < len; i++)
    {
        printf("%c", buf[(i + n) % len]);
    }
    printf("\n");
    return 0;
}