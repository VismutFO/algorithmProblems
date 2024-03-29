#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 03-8: Итерированная медиана
Дан массив целых чисел нечетной длины N. По нему строится массив длины N-2 по следующему правилу:
первый элемент нового массива равен медиане первого, второго и третьего элементов старого,
второй элемент нового — медиане второго, третьего и четвертого элементов старого, и так далее.
i-ый элемент нового массива равен медиане i-го, i+1-го и i+2-го.
Далее по новому массиву строится следующий массив длины N-4 по такому же правилу.
Затем строится массив длины N-6, и так далее. Процесс продолжается до тех пор, пока не получится массив длины 1.
Ваша задача определить, чему будет равен единственный элемент этого массива.
На стандартном потоке ввода задаётся нечетное натуральное число N (0 < N ≤ 1000),
после которого следуют N целых чисел ai — элементы исходного массива (0 ≤ ai ≤ 106).
На стандартный поток вывода напечатайте единственное число — значение единственного элемента конечного массива.
Указание: в решении необходимо реализовать функцию, которая находит медиану трех чисел.
*/

int getMed(int a, int b, int c)
{
    int t;
    if (a > b)
    {
        t = a;
        a = b;
        b = t;
    }
    if (b > c)
    {
        t = b;
        b = c;
        c = t;
    }
    if (a > b)
    {
        t = a;
        a = b;
        b = t;
    }
    return b;
}

int main(int argc, char** argv)
{
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (n > 1)
    {
        n -= 2;
        int* newArr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
        {
            newArr[i] = getMed(arr[i], arr[i + 1], arr[i + 2]);
        }
        free(arr);
        arr = newArr;
    }
    printf("%d", arr[0]);
    return 0;
}
