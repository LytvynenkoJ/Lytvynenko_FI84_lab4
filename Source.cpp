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
	int* degree = new int[k];
	int tr =0;
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
	cout << endl;

	sum = Add(first, second);
	cout << "Сумма:   ";
	outArr(sum);
	cout << endl;
	cout << dec << "Время работы суммы в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;

	square = Squa(first);
	cout << "Квадрат первого:   ";
	outArr(square);
	cout << endl;
	cout << dec << "Время работы квадрата в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(en - st).count()
		<< " ns" << endl << endl;
	square = Squa(second);
	cout << "Квадрат второго:   ";
	outArr(square);
	cout << endl;
	cout << dec << "Время работы квадрата в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(en - st).count()
		<< " ns" << endl << endl;

	tr = trace(first);
	cout << "След первого:   " << tr << endl;
	cout << dec << "Время работы функции следа в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;
	tr = trace(second);
	cout << "След второго:   " << tr << endl;
	cout << dec << "Время работы функции следа в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;

	int** matrixL = new int* [k];
	for (int i = 0; i < k; i++)
	{
		matrixL[i] = new int[k];
		obnul(matrixL[i], k);
	}
	matrixL = MatrixLam();

	mul = Multiple(first, second, matrixL);
	cout << "Умножение:   ";
	outArr(mul,0);
	cout << endl;
	cout << dec << "Время работы умножения в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(en - st).count()
		<< " ns" << endl << endl;

	cout << "В какую степень вы хотите вознести первый полином? (в двоичном виде, не более чем 2^{n}-1)" << endl;
	cin >> deg;
	cout << endl;
	degree = strToArr(deg);
	degree = Degr(first, degree, matrixL);
	cout << "Степень:   ";
	outArr(degree);
	cout << endl;
	cout << dec << "Время работы степени в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;

	inv = inverse(first, matrixL);
	cout << "Обратный:   ";
	outArr(inv);
	cout << endl;
	cout << dec << "Время работы нахождения обратного в наносекундах : "
		<< chrono::duration_cast<chrono::nanoseconds>(endtime - start).count()
		<< " ns" << endl << endl;
	
	AB(first, second, degree, matrixL);
	cout << endl;

	firM(first, matrixL);
	cout << endl;

	delete[] first;
	delete[] second;
	delete[] sum;
	delete[] mul;
	delete[] square;
	delete[] inv;
	return 0;
}
