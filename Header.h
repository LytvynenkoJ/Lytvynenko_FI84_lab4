#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include "time.h"
#include <string>
#include "locale.h"
using namespace std;
int k = 239+1;
//int t = 2 * k - 1;
int* q = new int[k];
auto start = chrono::steady_clock::now();
auto endtime = chrono::steady_clock::now();
auto st = chrono::steady_clock::now();
auto en = chrono::steady_clock::now();


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
void outArr(int arr[], int c=1)
{
	for (int i = c; i < k; i++)
	{
		cout << arr[i];
	}
}
int* Add(int first[], int second[])
{
	int* sum = new int[k];
	obnul(sum,k);
	start = chrono::steady_clock::now();
	for (int i = 0; i < k; i++)
	{
		sum[i] = (first[i] + second[i]) % 2;
	}
	endtime = chrono::steady_clock::now();
	return sum;
}
int* Squa(int num[])
{
	int* square = new int[k];
	square = obnul(square, k);
	st = chrono::steady_clock::now();
	square[1] = num[k - 1];
	for (int i = 1; i < k - 1; i++)
	{
		square[i+1] = num[i];
	}
	en = chrono::steady_clock::now();
	return square;
}
int trace(int num[])
{
	int tr=0;
	start = chrono::steady_clock::now();
	for (int i = 0; i < k; i++)
	{
		tr = (tr + num[i]) % 2;
	}
	endtime = chrono::steady_clock::now();
	return tr;
}
int* sumNum(int fN[], int sN[])
{
	int* summa = new int[k];
	obnul(summa,k);
	int carry = 0;
	int temp = 0;
	for (int i = 0; i < k; i++)
	{
		temp = fN[k - i - 1] + sN[k - i - 1] + carry;
		summa[k - i - 1] = temp % 2;
		carry = temp / 2;
	}
	return summa;
}
int* pTo2()
{
	int* p = new int[k];
	obnul(p, k);
	int y = 2 * (k-1) + 1;
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
	for (int i = 1; i < k+1; i++)
	{
		temp = first[k-i]-second[k-i]-borrow;
		if (temp>=0)
		{
			div[k-i] = temp;
			borrow = 0;
		}
		else
		{
			div[k-i] = temp + 2;
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
	for (int i = 0; i < k; i++)
	{
		modNum[i] = num[i];
	}
	int t1 = high(m);
	while (compare(modNum,m)<2)
	{
		int t2 = high(modNum);
		t2 = t2 - t1;
		for (int i = 0; i < k - t2; i++)
		{
			m2[i] = m[i + t2];
		}
		if (compare(modNum,m2)==2)
		{
			t2 -= 1;
			if (t2 < 0) return modNum;
			for (int i = k - 2; i >= 0; i--)
			{
				m2[i + 1] = m2[i];
			}
			m2[0] = 0;
		}
		modNum = DivNum(modNum,m2);
		obnul(m2, k);
	}
	delete[] m2;
	return modNum;
}
int** MatrixLam()
{
	int* mult = new int[k];
	obnul(mult, k);
	mult[k - 1] = 1;
	int* b = new int[k];
	obnul(b, k);
	int* i2 = new int[k];
	obnul(i2, k);
	int* p = new int[k];
	obnul(p, k);
	int** matrixL = new int* [k];
	for (int i = 0; i < k; i++)
	{
		matrixL[i] = new int[k];
		obnul(matrixL[i], k);
	}
	p = pTo2();
	int** mL = new int* [k-1];
	for (int i = 0; i < k; i++)
	{
		mL[i] = new int[k];
		obnul(mL[i], k);
		i2[k - i - 1] = 1;
		b = modul(i2, p);
		for (int j = 0; j < k; j++)
		{
			mL[i][j] = b[j];
		}
		obnul(i2, k);
	}
	matrixL[k - 1][k - 1] = 1;
	for (int i = 1; i < k; i++)
	{
		for (int j = 1; j < k; j++)
		{
			//2^i + 2^j
			for (int h = 0; h < k; h++)
			{
				i2[h] = mL[i-1][h];
				b[h] = mL[j-1][h];
			}
			q = sumNum(i2,b);
			if (compare(q,p)!=2)
			{
				q = DivNum(q,p);
			}
			if (compare(q,mult)==0)
			{
				matrixL[i][j] = 1;
			}
			else
			{
				if (compare(DivNum(p,q), mult) == 0)
				{
					matrixL[i][j] = 1;
				}
			}

			//-2^i + 2^j
			for (int h = 0; h < k; h++)
			{
				i2[h] = mL[i - 1][h];
				b[h] = mL[j - 1][h];
			}
			q = obnul(q,k);
			if (compare(i2,b)==1)
			{
				q = DivNum(i2,b);
				q = DivNum(p,q);
			}
			if (compare(i2,b)==2)
			{
				q = DivNum(b, i2);
			}
			if (compare(q, mult) == 0)
			{
				matrixL[i][j] = 1;
			}
			else
			{
				if (compare(DivNum(p, q), mult) == 0)
				{
					matrixL[i][j] = 1;
				}
			}
		}
	}
	delete[] i2;
	delete[] p;
	delete[] b;
	delete[] mult;
	return matrixL;
}
int* Multiple(int first[], int second[], int** matrixL)
{
	int* mult = new int[k];
	obnul(mult, k);
	int* b = new int[k];
	b = obnul(b,k);
	mult = obnul(mult,k);
	st = chrono::steady_clock::now();
	for (int h = 1; h < k; h++)
	{
		b = obnul(b, k);
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (matrixL[j][i]==1)
				{
					b[i] = b[i] + first[j];
					b[i] = b[i] % 2;
				}
			}
			if (second[i] == 1)
			{
				mult[h] += b[i];
				mult[h] %= 2;
			}
		}
		int f = first[1];
		int s = second[1];
		for (int i = 1; i < k-1; i++)
		{
			first[i] = first[i + 1];
			second[i] = second[i + 1];
		}
		first[k-1] = f;
		second[k-1] = s;
	}
	en = chrono::steady_clock::now();
	delete[] b;
	return mult;
}
int* Degr(int num[], int deg[], int** matrixL)
{
	int* degree = new int[k];
	degree = obnul(degree, k);
	start = chrono::steady_clock::now();
	degree=OneEl();
	for (int i = k - high(deg); i < k; i++)
	{
		if (deg[i] == 1) degree = Multiple(degree, num, matrixL);
		if (i != k - 1) degree = Squa(degree);
	}
	endtime = chrono::steady_clock::now();
	return degree;
}
int* inverse(int num[], int** matrixL)
{
	int* inv = new int[k];
	inv = obnul(inv, k);
	start = chrono::steady_clock::now();
	inv = OneEl();
	for (int i = 1; i < k-1; i++)
	{
		inv = Multiple(inv, num, matrixL);
		inv = Squa(inv);
	}
	endtime = chrono::steady_clock::now();
	return inv;
}
int* Ito(int num[], int** matrixL)
{
	int* m = new int[k];
	int* inver = new int[k];
	int* b = new int[k];
	obnul(b,k);
	obnul(m, k);
	obnul(inver, k);
	int y = k - 2;
	int i = k - 1;
	int cou = -1;
	while (y != 0)
	{
		m[i] = y % 2;
		y = y / 2;
		i--; cou++;
	}
	for (int i = 0; i < k; i++)
	{
		inver[i] = num[i];
	}
	int c = 1;
	start = chrono::steady_clock::now();
	for (int i = 0; i < cou; i++)
	{
		b = Squa(inver);
		for (int i = 0; i < c-1; i++)
		{
			b = Squa(b);
		}
		inver = Multiple(inver, b, matrixL);
		c = 2 * c;
		if (m[k-cou+i]==1)
		{
			inver = Squa(inver);
			inver = Multiple(inver, num, matrixL);
			c += 1;
		}
	}
	inver = Squa(inver);
	endtime = chrono::steady_clock::now();
	return inver;
}
int* AB(int first[], int second[], int third[], int** matrixL)
{
	int* d = new int[k];
	d = obnul(d, k);
	d = Add(Multiple(first, third, matrixL), Multiple(second, third, matrixL));
	cout << "A*C+B*C    ";
	outArr(d);
	cout << endl;
	d = obnul(d, k);
	d = Multiple(Add(first, second), third, matrixL);
	cout << "(A+B)*C    ";
	outArr(d);
	cout << endl;
	return d;
}
int* firM(int num[], int** matrixL)
{
	int* d = new int[k];
	d = obnul(d, k);
	int* n = new int[k];
	n = obnul(n, k);
	for (int i = 0; i < k; i++)
	{
		n[i] = num[i];
	}
	d = Ito(num, matrixL);
	cout << "num^{-1}   ";
	outArr(d);
	cout << endl;
	d = Multiple(d, n, matrixL);
	cout << "num^{-1}*num   ";
	outArr(d);
	cout << endl;
	return d;
}
