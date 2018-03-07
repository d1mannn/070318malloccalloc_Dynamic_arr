#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include "Header.h"
using namespace std;

int TaskNumb()
{
	setlocale(LC_ALL, "Rus");
	int task;
	cout << "¬ведите номер задани€ - ";
	cin >> task;
	return task;
}

int CreateMatrix(int *arr, int *column, int *row)
{	
	srand(time(NULL));
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *column; j++)
		{
			*(arr + i * *column + j) = -30 + rand() % 100; // обращение к элементу двухмерного массива
		}
	}
	return *arr;
}

void PrintMatrix(int * arr, int * column, int *row)
{
	for (int i = 0; i < *row; i++)
	{
		for (int j = 0; j < *column; j++)
		{
			printf("%d\t", *(arr + i * *column + j));
		}
		printf("\n");
	}
}