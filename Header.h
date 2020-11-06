#include <iostream>
#include "locale.h"
using namespace std;
int k = 3;
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
void outArr(int arr[], int c=k)
{
	for (int i = 0; i < c; i++)
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
int* sumNum(int fN[], int sN[])
{
	int* summa = new int[k];
	obnul(summa,k);
	int carry = 0;
	int temp = 0;
	for (int i = 1; i < k+2; i++)
	{
		temp = fN[k - i] + sN[k - i] + carry;
		summa[k - i] = temp % 2;
		carry = temp / 2;
	}
	return summa;
}
int* pTo2()
{
	int* p = new int[k];
	obnul(p, k);
	int y = 2 * k + 1;
	int i = k-1;
	while (y!=0)
	{
		p[i] = y % 2;
		y = y / 2;
		i--;
	}
	return p;
}
int compare(int first[], int second[], int c=k)
{
	for (int i = 0; i < c; i++)
	{
		if (first[i] > second[i]) return 1;
		if (first[i] < second[i]) return 2;
	}
	return 0;
}
int* DivNum(int first[], int second[])
{
	int* div = new int[k];
	obnul(div, k);
	int borrow = 0;
	int temp = 0;
	for (int i = 0; i < k; i++)
	{
		temp = first[i]-second[i]-borrow;
		if (temp>=0)
		{
			div[i] = temp;
			borrow = 0;
		}
		else
		{
			div[i] = temp + 2;
			borrow = 1;
		}
	}
	return div;
}
int high(int num[])
{
	int h = -1;
	for (int i = 0; i < k; i++)
	{
		if (num[i] != 0)
		{
			h = k - i;
			i = k;
		}
	}
	return h;
}
int* modul(int num[], int m[])
{
	int* modNum = new int[k];
	obnul(modNum, k);
	int* m2= new int[k];
	obnul(m2, k);
	for (int i = 0; i < k+1; i++)
	{
		modNum[i] = num[i];
	}
	int t1 = high(m);
	while (compare(modNum,m,k+1)<2)
	{
		int t2 = high(modNum);
		t2 = t2 - t1;
		for (int i = 0; i < k - t2 + 1; i++)
		{
			m2[i] = m[i + t2];
		}
		if (compare(modNum,m2)==2)
		{
			for (int i = k - 2; i > 0; i--)
			{
				m2[i + 1] = m2[i];
			}
			m2[0] = 0;
		}
		modNum = DivNum(modNum,m2);
	}
	/*for (int i = 0; i < k; i++)
	{
		modNum[i] = modNum[i + 1];
	}
	modNum[k] = 0;*/
	outArr(modNum);
	return modNum;
}
int* Multiple(int first[], int second[])
{
	int* mult = new int[k];
	obnul(mult, k);
	mult[k - 1] = 1;
	int* b = new int[k];
	obnul(b, k);
	int* i2 = new int[k];
	obnul(i2, k+1);
	int* j2 = new int[k];
	obnul(j2, k+1);
	int** matrixL = new int* [k];
	for (int i = 0; i < k; i++)
	{
		matrixL[i] = new int[k];
		obnul(matrixL[i],k);
	}
	for (int i = 1; i < k+1; i++)
	{
		for (int j = 1; j < k+1; j++)
		{
			i2[k - i] = 1;
			cout << "i2   ";
			outArr(i2,k);
			cout << endl;
			j2[k - j] = 1;
			cout << " j2   ";
			outArr(j2,k);
			cout << endl;
			i2 = sumNum(i2,j2);
			cout << "  sumNum(i2,j2)   ";
			outArr(i2,k);
			cout << endl;
			j2 = pTo2();
			cout << "   p   ";
			outArr(j2,k);
			cout << endl;
			b = modul(i2,j2);
			cout << "    modul(i2,j2)   ";
			outArr(b);
			cout << endl;
			if (compare(b,mult)==0)
			{
				matrixL[i][j] = 1;
				cout << "Уиииииииииииииииииииииииииииииииииииии";
			}
			obnul(i2, k + 1);
			obnul(j2, k + 1);
		}
		outArr(matrixL[i]);
		cout << endl;
	}
	obnul(mult,k);
	delete[] b;
	delete[] i2;
	delete[] j2;
	return mult;
}
