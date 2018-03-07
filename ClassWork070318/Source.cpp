#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "Header.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");

	int task = TaskNumb();
	switch (task)
	{
		case 1:
		{
			int k = 0;
			scanf("%d", &k);

			//ќдномерный массив типа double
			double * arr;
			arr = (double*)malloc(k * sizeof(double));
			/*

			отработал массив


			*/

			free(arr); // очистили пам€ть после пользовани€ массива. работает только с malloc
		} break;
		
		case 2:
		{
			double *arr;
			int max;
			int numb;
			int i = 0;
			puts("Enter quantity of max type double - ");
			scanf("%d", &max);
			arr = (double*)malloc(max * sizeof(double));

			if (arr == NULL)
			{
				puts("It couldn't allocate memory. Programm terminated.");
				exit(EXIT_FAILURE);
			}

			puts("Enter value\n");
			while (i < max && scanf("%lf", &arr[i]) == 1)
			/*если scanf успешно отработал, то вернул 1, не успешно - 0 т.е
			мы использу€ %lf просим его ввести long float - число. 
			ѕрин€в число он вернул 1. ¬вели не число - вернул 0 - конец работы и выход из цикла*/
			{
				i++;
			}
			printf("Entered %d elements: \n", numb = i);

			for (i = 0; i < numb; i++)
			{
				printf("%7.2f", arr[i]);
			}

			puts("\nProgramm compleated\n");
			free(arr);
			//malloc резервирует определенное кол-во €чеек пам€ти, допустим 30. Ќо заполнив их не 30ю, а меньше, допустим 20, то в оставшихс€ 10 €чейках будет мусор
		} break;

		case 3:
		{
			//a.—формировать одномерный массив, каждый элемент которого равен сумме четных положительных элементов соответствующего столбца двумерного массива
			int * arr = NULL, *newArr = NULL;
			int column, row, sum = 0;
			printf("¬ведите кол-во солбцов - ");
			scanf("%d", &column);
			printf("¬ведите кол-во строк - ");
			scanf("%d", &row);
			arr = (int*)calloc((column * row), sizeof(int));
			newArr = (int*)calloc(column, sizeof(int));
			if (arr == NULL)
			{
				puts("It couldn't allocate memory. Programm terminated.");
				exit(EXIT_FAILURE);
			}
			CreateMatrix(arr, &column, &row);
			PrintMatrix(arr, &column, &row);
			for (int i = 0; i < column; i++)
			{
				sum = 0;
				for (int j = 0; j < row; j++)
				{
					if (*(arr + i * column + j) % 2 == 0 && *(arr + i * column + j) > 0)
						sum += *(arr + i * column + j);
					else
						*newArr = 0;
				}
				*arr = sum;
				printf("%d\n", *arr);
				arr++;
			}
		} break;

		case 4:
		{
			//b.—формировать одномерный массив, каждый элемент которого равен количеству нечетных отрицательных элементов соответствующей строки двумерного массива
			int * arr = NULL, *newArr = NULL;
			int column, row, sum = 0;
			printf("¬ведите кол-во солбцов - ");
			scanf("%d", &column);
			printf("¬ведите кол-во строк - ");
			scanf("%d", &row);
			arr = (int*)calloc((column * row), sizeof(int));
			newArr = (int*)calloc(column, sizeof(int));
			if (arr == NULL)
			{
				puts("It couldn't allocate memory. Programm terminated.");
				exit(EXIT_FAILURE);
			}
			CreateMatrix(arr, &column, &row);
			PrintMatrix(arr, &column, &row);
			for (int i = 0; i < column; i++)
			{
				sum = 0;
				for (int j = 0; j < row; j++)
				{
					if (*(arr + i * column + j) % 2 != 0 && *(arr + i * column + j) < 0)
						sum += *(arr + i * column + j);
					else
						*newArr = 0;
				}
				*arr = sum;
				printf("%d\n", *arr);
				arr++;
			}
		} break;
	}
	
}