// C++_1LabV2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

//ввод размерности из файла
void InputMatrSizeFile(ifstream &in, int* n, int* m)
{
	if (in.is_open())
	{
		in >> *n;
		in >> *m;
	}
}

//ввод числа с заданными границами
int InputNum(const char *txt, int min, int max)
{
	int num;
	cout << txt << endl; //вывод вопроса на экран
	cin >> num;
	while ((num < min) || (num > max)) //пока число num не попадает в диапозон [min..max] 
	{
		cout << "Недопустимое значение, введите еще раз:" << endl;
		cin >> num;
	}
	return num;
}

char** CreateMatr(int n, int m)
{
	char **A; //создаём матрицу введённой размерности
	A = new char *[n]; //через массив указателей
	for (int i = 0; i < n; i++) {
		A[i] = new char[m];
	}
	return A;
}

//ввод матрицы из файла
void InputMatrFile(char** mas, ifstream &FileIn, int n, int m)
{
	if (FileIn.is_open())
	{
		cout << "Введенная матрица:\n";
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				FileIn >> mas[i][j];
				cout << mas[i][j] << " ";
			}
			cout << endl;
		}
	}
	FileIn.close();
}

//ввод матрицы с клавиатуры
void InputMatrKey(char** mas, int* n, int* m, int toWin)
{
	*n = InputNum("Введите количество строк", toWin, 50);
	*m = InputNum("Введите количество столбцов", toWin, 50);
	for (int i = 0; i < *n; ++i)
		mas[i] = new char[*m];
	cout << "Заполните массив: ""\n";
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *m; j++)
		{
			cin >> mas[i][j];
		}
	}
	cout << "Введенная матрица:\n";
	for (int i = 0; i < *n; ++i)
	{
		for (int j = 0; j < *m; ++j)
		{
			cout << mas[i][j] << " ";			//"\t";
		}
		cout << endl;
	}
}
//вывод результата в файл
void OutputResFile(const char *txt)
{
	ofstream FileOut("output.txt");
	if (FileOut.is_open())
	{
		FileOut << txt << endl;
	}

	FileOut.close();
}



//выбор пункта меню ввода
int SelectInputMenuItem(void)
{
	cout << "1 - Ввод массива из консоли" << endl;
	cout << "2 - Ввод массива из файла" << endl;
	return InputNum("0 - выход", 0, 2);
}
//выбор пункта меню вывода результата
int SelectResultMenuItem(void)
{
	cout << "1 - Вывести результат в консоль" << endl;
	cout << "2 - Вывести результат в файл" << endl;
	return InputNum("0 - выход", 0, 2);
}

//проверка границ
bool CheckBorder(int far_x, int far_y, int n, int m)
{
	if ((far_x <= n) && (far_y <= m))
		return true;
	else
		return false;
}

// проверка линии
static bool checkLine(char **mas, int n, int m, int x, int y, int vx, int vy, int len, char c) {
	int far_x = x + (len - 1) * vx;           // посчитаем конец проверяемой линии
	int far_y = y + (len - 1) * vy;
	if (!CheckBorder(far_x, far_y, n, m)) return false;   // проверим не выйдет-ли проверяемая линия за пределы поля
	for (int i = 0; i < len; i++) {                 // ползём по проверяемой линии
		if (mas[y + i * vy][x + i * vx] != c) return false;   // проверим одинаковые-ли символы в ячейках
	}
	return true;
}


// проверка на победу
static bool checkWin(char **mas, int n, int m, int toWin, char c)
{
	for (int i = 0; i < n; i++) {          // ползём по всему полю   //m
		for (int j = 0; j < m; j++) {									//n
			if (checkLine(mas, n, m, i, j, 1, 0, toWin, c)) return true;   // проверим линию по х					
			if (checkLine(mas, n, m, i, j, 1, 1, toWin, c)) return true;   // проверим по диагонали х у
			if (checkLine(mas, n, m, i, j, 0, 1, toWin, c)) return true;   // проверим линию по у
			if (checkLine(mas, n, m, i, j, 1, -1, toWin, c)) return true;  // проверим по диагонали х -у
		}
	}
	return false;
}




//главная программа
int main()
{
	setlocale(LC_ALL, "Russian");//русский язык	
	ifstream FileIn("input.txt");

	const int toWin = 5;		//длина последовательности символов, необходимая для выигрыша
	int n, m;
	char c = 'X';
	char** arr = new char*[0];
	int MenuItem;
	int SubMenuItem;

	MenuItem = SelectInputMenuItem();

	switch (MenuItem)
	{
	case 1:
		InputMatrKey(arr, &n, &m, toWin);
		break;
	case 2:
		InputMatrSizeFile(FileIn, &n, &m);
		arr = CreateMatr(n, m);
		InputMatrFile(arr, FileIn, n, m);
		break;
	default:
		return 0;
	}

	
	SubMenuItem = SelectResultMenuItem();

	switch (SubMenuItem)
	{
	case 1:
		if (checkWin(arr, n, m, toWin, c))
			cout << "Win" << endl;
		else
			cout << "Lose" << endl;
		system("pause");
		break;
	case 2:
		if (checkWin(arr, n, m, toWin, c))
			OutputResFile("Win");
		else
			OutputResFile("Lose");

		system("pause");
		break;
	default:
		return 0;
	}
	
	return 0;
}
