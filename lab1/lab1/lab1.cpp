/* 2к. 91 гр. Атапина Александра
№6
Реализовать шаблон класса множество. Класс должен одержать методы:
-добавление эл-та
-удаление эл-та
-проверка существования эл-та
-объединение двух мн-в(+)
-пересечение двух мн-в(*)
-разность двух мн-в(-)
-печать мн-ва
*/

#include "stdafx.h"
#include <iostream>
#include "string"

using namespace std;

template <class T>
class set
{
private:
	T *a;
	const int max_size = 10;
	int size;
public:
	//по умолчанию
	set() {
		a = new T[max_size];
		for (int i = 0; i < max_size; i++)
			a[i] = T();
		size = 0;
	};

	//Деструктор:
	~set() {
		delete[]a;
	};

	//проверка вхождения эл-та в множество
	bool check_in(T x)const
	{
		for (int i = 0; i < size; i++)
			if (a[i] == x)
				return true;
		return false;
	};

	//добавление эл-та в множество
	void add(T x)
	{
		if (size < max_size)
		{
			if (!check_in(x))
			{
				a[size] = x;
				size += 1;
			}
			else
				cout << ("Добавление невозможно, элемент уже существует!");
		}
		else
			cout << ("Добавление невозможно!");
	};

	//удаление эл-та из множества
	void del(T x)
	{
		if ((size != 0) && this->check_in(x))
		{
			for (int i = 0; i < size; i++)
			{
				if (a[i] == x)
				{
					for (int j = i; j < size - 1; j++)
					{
						a[j] = a[j + 1];
					}
					size -= 1;
				}
			}
		}
		else
			cout << ("Удаление невозможно!");
	};

	//Вывод множества на экран
	void output() {
		if (size == 0)
		{
			cout << "{ }";
			return;
		}
		cout << "{" << a[0];
		for (int i = 1; i < size; i++)
			cout << ", " << a[i];
		cout << "}";

	};
	//присваивание одного множества другому
	set<T> operator= (const set <T> &s)
	{
		for (int i = 0; i < s.size; i++)
		{
			a[i] = s.a[i];
		}
		size = s.size;
		return *this;
	};

	// пересечение
	set<T> operator* (const set <T> &s2)
	{
		set <T> s3;
		s3.size = 0;
		for (int i = 0; i < size; i++)
			if (s2.check_in(a[i]))
				s3.add(a[i]);
		return s3;
	};

	//объединение
	set<T> operator+ (const set <T> &s2)
	{
		set <T> s3;
		s3 = *this;
		for (int i = 0; i < s2.size; i++)
			if (!s3.check_in(s2.a[i]))
				s3.add(s2.a[i]);
		return s3;
	};

	//разность
	set<T> operator- (const set <T> &s2)
	{
		set <T> s3;
		s3 = *this;
		for (int i = 0; i < size; i++)
			if (s2.check_in(a[i]))
				s3.del(a[i]);
		return s3;
	};

	//ввод множества с клавиатуры с проверкой существования
	void Input_set(int n)
	{
		T x;
		size = n;
		cout << "Заполните множество:" << endl;
		for (int i = 0; i < size; i++)
		{
			do
			{
				cin >> x;
				if (this->check_in(x))
					cout << "Данный элемент уже существует!Повторите ввод!" << endl;
			} while (this->check_in(x));
			a[i] = x;
		}
	};

};

//ввод размера множества
int InputSize()
{
	cout << "Введите размер (положительное целое число) множества: ";
	int n; cin >> n;
	return n;
};
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
};

//выбор пункта меню обработки для одного множества
int SelectDoMenuItem(void)
{
	cout << "1 - Проверка принадлежность элемента множеству" << endl;
	cout << "2 - Добавление элемента" << endl;
	cout << "3 - Удаление элемента" << endl;
	cout << "4 - Печать множества" << endl;
	cout << "5 - Операции с двумя множествами" << endl;
	return InputNum("0 - Выход", 0, 5);
};
//для двух мн-в
int SelectOperationMenuItem(void)
{
	cout << "1 - Объединение" << endl;
	cout << "2 - Пересечение" << endl;
	cout << "3 - Разность" << endl;
	return InputNum("0 - Вернуться", 0, 3);
};

int main()
{
	setlocale(0, "RUS");
	int k = 1;
	int x;
	set<int>  a, b, c;
	int n, p;
	n = InputSize();
	a.Input_set(n);
	b = a;
	//b.output();
	return 0;
}
