#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <iostream>
#include <queue>

using namespace std;
int** a;
int i, j, n;
int* vis;
queue <int> q;

void BFS(int s)
{
	q.push(s);
	vis[s] = 0;
	while (!q.empty())
	{
		s = q.front();
		printf(" %d", s);
		q.pop();
		for (i = 0; i < n; i++)
		{
			if (a[s][i] == 1 && vis[i] == -1)
			{
				q.push(i);
				vis[i] = vis[s] + 1;
				
			}
		}
	}
}

int main()
{
	int start;
	system("chcp 1251");
	system("cls");
	printf("Введите количество вершин: ");
	scanf("%d", &n);
	a = (int**)malloc(n * sizeof(int*));
	vis = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		vis[i] = -1;
	}
	for (i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(n * sizeof(int));
	}
	srand(time(NULL));

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			if (i != j) {
				a[i][j] = rand() % 2;
				a[j][i] = a[i][j];
			}
			else a[i][j] = 0;
		}
	printf("M1:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)

			printf("%3d", a[i][j]);
		printf("\n");
	};

	printf("\n");
	printf("\n");
	printf("Введите стартовую вершину: ");
	scanf("%d", &start);
	printf("Порядок обхода: ");
	BFS(start);
	printf("\n");
	printf("Расстояния от выбранной вершины: ");
	for (i = 0; i < n; i++)
	{
		printf("%3d", vis[i]);
	}
	printf("\n");
	delete[]vis;
	free(a);
	system("pause");
}
