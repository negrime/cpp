// lab1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//void AreaInput(bool& a[][n]); // Метод заполения поля
const int m = 3; //Строки
const int n = 3; //Столбцы

void AreaRead(bool a[m][n]);
bool UpCheck(bool a[m][n]);
int main()
{
	bool area[m][n];
	AreaRead(area);
	cout << area[1][0];

	system("pause");
	return 0;
}
void AreaRead(bool a[m][n])
{
	cout << "Input 1 if 'X' else input 0 \n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "Input " << i + 1 << ";" << j + 1 << " ";
			cin >> a[i][j];
		}
	}

	for (int b = 0; b < m; b++)
	{
		for (int c = 0; c < n; c++)
		{
			cout << a[b][c] << " ";
			if (c == n - 1)
				cout << endl;
		}
	}
}
bool UpCheck(bool a[m][n])
{
	return true;
}




