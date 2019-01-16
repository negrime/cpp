#include "pch.h"
#include <string>
#include <iostream>

using namespace std;

template <typename T>
class List
{
	struct Node
	{
		T x;
		Node* next;
	};

private:
	Node* HEAD;
	Node* TAIL;
	int k = 0;//Количество элементов в последовательности

	bool IsEmpty()
	{
		if (HEAD == NULL) return true;
		return false;
	}

public:
	List() { HEAD = NULL; TAIL = NULL; }//Конструктор

	~List()//Деструктор
	{
		while (HEAD != NULL)
		{
			Node* temp = HEAD->next;
			delete HEAD;
			HEAD = temp;
		}
		TAIL = HEAD;
	}

	int GetK()
	{
		return k;
	}

	void Add(T xn)//Добавление записи в конец
	{
		Node* temp = new Node;
		temp->x.num = xn.num;
		if (IsEmpty())//если список пустой
		{
			temp->next = NULL;
			HEAD = temp;
			TAIL = temp;
			k++;// +1 к количеству
		}
		else//если список не пустой
		{
			temp->next = NULL;
			TAIL->next = temp;
			TAIL = temp;
			k++;// +1 к количеству
		}
	}

	void AddOne()//Добавление одного элемента
	{
		T xn;
		cout << "Введите новый элемент последовательности\n";
		cin >> xn.num;
		Add(xn);
	}

	void AddPos()//Добавление последовательности
	{
		T xn;
		int kol;
		cout << "Введите количество элементов в последовательности\n";
		cin >> kol;
		cout << "Введите последовательность\n";
		while (kol > 0)
		{
			cin >> xn.num;
			Add(xn);
			kol--;
		}
	}

	auto SeekNum(int i) //Нахождение элемента по номеру
	{
		if (i > k)
			cout << "В последовательности меньше чисел\n";
		else
		{
			Node* temp = HEAD;
			int j = 1;
			while (j != i)
			{
				j++;
				temp = temp->next;
			}
			return temp->x.num;
		}
	}

	void SeekPos()//Поиск подпоследовательности
	{

		//НЕ РАБОТАЕТ!
	}

	void Show()//Печать последовательности
	{
		Node* temp = HEAD;

		while (temp != NULL)
		{
			cout << temp->x.num << " ";
			temp = temp->next;
		}
		cout << "Количество элементов = " << k << endl;
	}

	void Seek(T xs)//Есть ли в последователности заданный элемент
	{
		Node* p = HEAD;
		bool OK = false;
		int kol = 1;
		while (p != NULL)
		{
			if (p->x.num == xs.num)
			{
				cout << "Заданный элемент найден:\n" << "X = " << p->x.num << "; Номер = " << kol;
				OK = true;
			}
			p = p->next;
			kol++;
		}
		if (!OK)
			cout << "Заданный элемент не найден\n";
	}

	void SeekE()
	{
		T xn;
		cout << "\nВведите элемент, который нужно найти\n";
		cin >> xn.num;
		Seek(xn);
	}

	void DelLast()//Удаление последнего элемента
	{
		if (!IsEmpty())
		{
			if (HEAD == TAIL)//Если в списке только одна запись
			{
				HEAD = NULL;
				TAIL = NULL;
			}
			else
			{
				Node* temp = HEAD;
				while (temp->next != TAIL)
					temp = temp->next;
				TAIL = temp;
				temp = temp->next;
				TAIL->next = NULL;
				delete temp;
			}
		}
	}

	void Del(int i)//Удаление элемента по номеру
	{
		if ((i > k) || (i <= 0))
			cout << "В последовательности нет элемента по введенному индексу \n";
		else
		{
			Node* temp = HEAD;
			int j = 1;
			if (i == 1)
			{
				k--;
				HEAD = temp->next;
				delete temp;
			}
			else
			{
				while (j != i - 1)
				{
					j++;
					temp = temp->next;
				}
				if (temp->next == TAIL)
				{
					k--;
					DelLast();
				}
				else
				{
					k--;
					Node* t = temp->next;
					temp->next = temp->next->next;
					delete t;
				}
			}
		}
	}


};

int InputSize(const char *txt, int min, int max)
{
	int ArrSize;
	cout << txt << endl; //вывод вопроса на экран
	cin >> ArrSize;
	while ((ArrSize < min) || (ArrSize > max)) //пока число num не попадает в диапозон [min..max] 
	{
		cout << "Недопустимое значение, введите еще раз:" << endl;
		cin >> ArrSize;
	}
	return ArrSize;
}

int SelectMenuItem(void)
{
	cout << "\n____________________________" << endl;
	cout << "Выберите один из пунктов меню:" << endl;
	cout << "1 - Добавить элемент" << endl;
	cout << "2 - Добавить последовательность" << endl;
	cout << "3 - Поиск подпоследовательности в последовательности" << endl;
	cout << "4 - Доступ к элементу через номер" << endl;
	cout << "5 - Удаление элемента через номер" << endl;
	cout << "6 - Показать последовательность" << endl;
	return InputSize("0 - выйти из программы", 0, 7);
}


int main()
{
	struct test {
		int num;
	};
	setlocale(LC_ALL, "Russian");
	int MenuItem = -1;
	List<test> l;
	while (MenuItem != 0)
	{
		MenuItem = SelectMenuItem();
		switch (MenuItem)
		{
		case 1: l.AddOne();
			break;
		case 2: l.AddPos();
			break;
		case 3: l.SeekPos();
			break;
		case 4: int num1;
			cout << "Введите номер элемента для доступа\n";
			cin >> num1;
			if ((num1 > l.GetK()) || (num1 <= 0)) cout << "В последовательности нет элемента по введенному индексу \n";
			else
				cout << "Элемент под этим номером = " << l.SeekNum(num1);
			break;
		case 5: int num2;
			cout << "Введите номер элемента для удаления\n";
			cin >> num2;
			l.Del(num2);
			break;
		case 6:cout << "\n";
			l.Show();
			break;
		}
	}
	return 0;
}