#include <iostream>
#include "locale.h"
using namespace std;
int k = 4;
//int t = 2 * k - 1;
int* q = new int[k];


int* obnul(int arr[], int c)
{
	for (int i = 0; i < c; i++)
	{
		arr[i] = 0;
	}
	return arr;
}
int* NulEl()
{
	int* arr = new int[k];
	obnul(arr, k);
	return arr;
}
int* OneEl()
{
	int* arr = new int[k];
	obnul(arr, k);
	for (int i = 0; i < k; i++)
	{
		arr[i] = 1;
	}
	return arr;
}
int stringTo2(char letter)
{
	switch (letter)
	{
	case '0': return 0;
	case '1':return 1;
	}
	return -1;
}
int* strToArr(string num)
{
	int* arr = new int[k];
	arr = obnul(arr, k);
	if (num.size() > k)
	{
		cout << "Error 404: Вы ввели некорректное значение (слишком длинное)" << endl;
		exit(0);
	}
	for (int i = 1; i < num.size() + 1; i++)
	{
		if (stringTo2(num[num.size() - i]) != -1)
			arr[k - i] = stringTo2(num[num.size() - i]);
		else
		{
			cout << "Error 404: Вы ввели некорректное значение (таких коэффициентов нет в поле характеристики 2)" << endl;
			exit(0);
		}
	}
	return arr;
}
void outArr(int arr[])
{
	for (int i = 0; i < k; i++)
	{
		cout << arr[i];
	}
}
int* Add(int first[], int second[])
{
	int* sum = new int[k];
	obnul(sum,k);
	for (int i = 0; i < k; i++)
	{
		sum[i] = (first[i] + second[i]) % 2;
	}
	return sum;
}
int* Squa(int num[])
{
	int* square = new int[k];
	square = obnul(square, k);
	square[0] = num[k - 1];
	for (int i = 0; i < k - 1; i++)
	{
		square[i+1] = num[i];
	}
	return square;
}
int trace(int num[])
{
	int tr=0;
	for (int i = 0; i < k; i++)
	{
		tr = (tr + num[i]) % 2;
	}
	return tr;
}
int* Multiple(int first[], int second[])
{
	int* mult = new int[k];
	obnul(mult, k);

	int** matrixL = new int* [k];
	for (int i = 0; i < k; i++)
	{
		matrixL[i] = new int[k];
		obnul(matrixL[i],k);
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << matrixL[i][j] << " ";
		}
		cout << endl;
	}
	return mult;
}