#include "Header.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	string firstNum;
	string secondNum;
	string deg;
	int* first = new int[k];
	int* second = new int[k];
	int* sum = new int[k];
	int* mul = new int[k];
	int* inv = new int[k];
	int* square = new int[k];
	int tr =0;
	int* degree = new int[k];
	degree = obnul(degree, k);
	first = obnul(first, k);
	second = obnul(second, k);
	sum = obnul(sum, k);
	mul = obnul(mul, k);
	inv = obnul(inv, k);
	square = obnul(square, k);
	cout << "������� ������ �������:   ";
	cin >> firstNum;
	first = strToArr(firstNum);
	cout << "������� ������ �������:   ";
	cin >> secondNum;
	second = strToArr(secondNum);

	sum = Add(first, second);
	cout << "�����:   ";
	outArr(sum);
	cout << endl;

	square = Squa(first);
	cout << "�������:   ";
	outArr(square);
	cout << endl;

	tr = trace(first);
	cout << "����:   " << tr << endl;

	mul = Multiple(first, second);

	delete[] first;
	delete[] second;
	delete[] sum;
	delete[] mul;
	delete[] square;
	delete[] inv;
	return 0;
}