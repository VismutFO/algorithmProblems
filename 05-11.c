#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

/*
Задача 05-11: Сочи-2014
В рамках строительства олимпийских объектов местным чиновникам было поручено предложить план дороги на участке недалеко от Сочи.
Участок можно схематично представить как матрицу из NxM подучастков, для каждого из которых выделяется некая сумма на его освоение.
Дорогой называется такой набор из M подучастков, что в каждом столбце содержится ровно по одному подучастку и для подучастков с координатами (i1, j) и (i2, j+1) верно,
что |i1-i2| ≤ 1. Соответственно, сумма денег, выделяемых на освоение дороги, равна сумме денег выделяемых на каждый из её подучастков. Так как большая сумма несомненно
приведёт к лучшему качеству исполнения дороги в целом, чиновники заинтересованы в максимизации осваиваемых средств. Ваша задача в том, чтобы помочь России не упасть в грязь
лицом на предстоящих играх.

Входные данные:
Сначала идут числа N и M, оба не превосходят 2*103.
Далее идут N*M чисел, задающих участок, каждое из которых неотрицательное 32-х битное число.

Выходные данные: выведите максимально возможную сумму осваиваемых средств. Гарантируется, что ответ не переполняет 32-х битное беззнаковое число.
*/

typedef long long ll;

int main(int argc, char** argv)
{
    int n, m;
    scanf("%d %d\n", &n, &m);
    ll** arr = (ll**)malloc(n * sizeof(ll*)), **dp = (ll**)malloc(n * sizeof(ll*));
    for (int i = 0; i < n; i++)
    {
        arr[i] = (ll*)malloc(m * sizeof(ll));
        dp[i] = (ll*)malloc(m * sizeof(ll));
        for (int j = 0; j < m; j++)
        {
            scanf("%lld", &arr[i][j]);
            dp[i][j] = arr[i][j];
        }
    }
    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int best = dp[i][j - 1];
            if (i > 0 && dp[i - 1][j - 1] > best)
            {
                best = dp[i - 1][j - 1];
            }
            if (i < n - 1 && dp[i + 1][j - 1] > best)
            {
                best = dp[i + 1][j - 1];
            }
            dp[i][j] += best;
        }
    }
    ll max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < dp[i][m - 1])
        {
            max = dp[i][m - 1];
        }
    }
    printf("%lld\n", max);
    return 0;
}