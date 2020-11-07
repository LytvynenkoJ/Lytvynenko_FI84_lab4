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
	cout << "Введите первый элемент:   ";
	cin >> firstNum;
	first = strToArr(firstNum);
	cout << "Введите второй элемент:   ";
	cin >> secondNum;
	second = strToArr(secondNum);

	sum = Add(first, second);
	cout << "Сумма:   ";
	outArr(sum);
	cout << endl;

	square = Squa(first);
	cout << "Квадрат первого:   ";
	outArr(square);
	cout << endl;
	square = Squa(second);
	cout << "Квадрат второго:   ";
	outArr(square);
	cout << endl;

	tr = trace(first);
	cout << "След первого:   " << tr << endl;
	tr = trace(second);
	cout << "След второго:   " << tr << endl;

	mul = Multiple(first, second);
	cout << "Умножение:   ";
	outArr(mul);
	cout << endl << endl;
	
	cout << "В какую степень вы хотите вознести первый полином? (в двоичном виде, не более чем 2^{n}-1)" << endl;
	cin >> deg;
	degree = strToArr(deg);
	degree = Degr(first, degree);
	cout << "Степень:   ";
	outArr(degree);
	cout << endl;

	inv = inverse(first);
	cout << "Обратный:   ";
	outArr(inv, k);
	cout << endl;

	delete[] first;
	delete[] second;
	delete[] sum;
	delete[] mul;
	delete[] square;
	delete[] inv;
	return 0;
}
