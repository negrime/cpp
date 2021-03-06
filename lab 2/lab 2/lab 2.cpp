// lab 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "pch.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <locale.h>
#include <string>
using namespace std;

class payment
{
	// КОНСТАНТЫ
		const float nalog = 0.13; // Процент налога	
		const float pension = 0.1; // налог для пенсии
	// ПОЛЯ
private:
	string fio; // Фио
	float oklad; // Оклад
	int year; // Год поступления на работу
	float bonusProcent; // Процент надбавки
	int   workDayMonth; // Кол-во отработанных дней
	int dayMonth; // Кол-во рабочих дней
	float seniority; // Стаж (полное кол-во лет)
	// МЕТОДЫ
public :
	float calculationPayDay(); // Вычисление оплаты за день
	float vichisl_nach_summ(); // Вычисление начальной ЗП
	float vichisl_yder_summ(); // Вычисление удержанной суммы
	float calculationPay(); // Вычисление ЗП
	float calculationSeniority(); // Вычисление стажа
	float calculationBonus(); // Вычисление 
public:
	void  Init(); // Инициализация
	void  Read(); // Считывание
	void  Display(); // Вывод
	
	// GET SET
public :
	// ФИО
	std::string GetFio()
	{
		return fio;
	}
	void SetFio(std::string value)
	{
		fio = value;
	}
	// Оклад
	float GetOklad()
		{
			return oklad;
		}
	void SetOklad(float value)
		{
			if (value > 0)
			{
				oklad = value;
			}
		}
	// Год поступления
	int GetYear()
	{
		return year;
	}
	void SetYear(int value)
	{
		if (value > 0)
		{
			year = value;
		}
	}
	// Процент надбавки
	float GetBonus()
	{
		return bonusProcent;
	}
	void SetBonus(float value)
	{
		if (value >= 0)
		{
			bonusProcent = value;
		}
	}
	// Кол-во отработанных дней
	int GetWorkDayMoth()
	{
		return workDayMonth;
	}
	void SetGetWorkMonth(int value)
	{
		if (value >= 0)
		{
			workDayMonth = value;
		}
	}
	// Кол-во рабочих дней
	int GetDayMonth()
	{
		return dayMonth;
	}
	void SetDayMonth(int value)
	{
		if (value >= 0)
		{
			dayMonth = value;
		}
	}
};

float payment::calculationPayDay()
{
	return (oklad / dayMonth);
}

float payment::vichisl_nach_summ()
{
	return ((calculationPayDay() * workDayMonth) + calculationBonus());
}

float payment::calculationBonus()
{
	return ((oklad / 100) * bonusProcent);
}

float payment::vichisl_yder_summ()
{
	return (vichisl_nach_summ()*nalog + vichisl_nach_summ() * nalog);
}

float payment::calculationPay()
{
	return (vichisl_nach_summ() - vichisl_yder_summ());
}

float payment::calculationSeniority()
{
	return (2018 - year);
}

void payment::Init() 
{
	
	 fio = "";
	 oklad = 0;
	 year = 0;
	 bonusProcent = 0;
	 workDayMonth = 0;
	 dayMonth = 0;
	 seniority = 0;
	 system("cls");
}

void payment::Read()
{
	cout << "Расчет зарплаты сотрудника: \n\n";
	cout << "Имя: ";
	string name, lastName, patronymic;
	cin >> lastName >> name >> patronymic;
	fio = lastName + " " + name + " " + patronymic;
	cout << "Оклад: ";
	cin >> oklad;
	cout << "Год поступления на работу: ";
	cin >> year;
	cout << "% надбавки: ";
	cin >> bonusProcent;
	cout << "Кол-во рабочих дней в месяце: ";
	cin >> dayMonth;
	cout << "Кол-во отработанных дней: ";
	cin >> workDayMonth;
	system("cls");
}
void DrawLine()
{
	cout << "____________________________________\n\n";
}
void payment::Display()
{
	cout << "\n\nРезультат:\n";
	cout << "Стаж составляет: " << calculationSeniority() << "\n";
	cout << "Начисленная сумма составляет: " << vichisl_nach_summ() << "\n";
	cout << "Удержанная сумма составляет: " << vichisl_yder_summ() << "\n";
	cout << "Сумма, выдаваемая на руки составляет: " << calculationPay() << "\n";	
	DrawLine();
}


void MethodsChoice(payment &h)
{
	int k = 0;
	do
	{
		cout << "1 - Вычисление начисленной суммы\n";
		cout << "2 - Вычисление удержанной суммы\n";
		cout << "3 - Вычисление стажа\n";
		cout << "4 - Выполнить все\n";
		cout << "0 - назад\n";
		DrawLine();
		cin >> k;
		switch (k)
		{
		case 1:
			cout <<"Начисленная сумма = " << h.vichisl_nach_summ() << "\n";
			break;
		case 2:
			cout <<"Удерженная сумма = " << h.vichisl_yder_summ() << "\n";
			break;
		case 3:
			cout <<"Стаж = "<< h.calculationSeniority() << "\n";
			break;
		case 4:
			h.Display();
			break;
		default:
			break;
		}
		
	} while ((k != 0));
	system("cls");
	//SecondMenu(h);

}
void FieldEdit(payment &h, int fieldIndex)
{
	cout << "Введите новое значение\n";
	switch (fieldIndex)
	{
	case 1 :
	{
		float value;
		cin >> value;
		h.SetOklad(value);
		break;
	}
	case 2 :
	{
		int value;
		cin >> value;
		h.SetYear(value);
		break;
	}
	case 3 :
	{
		float value;
		cin >> value;
		h.SetBonus(value);
		break;
	}
	case 4 :
	{
		int value;
		cin >> value;
		h.SetDayMonth(value);
		break;
	}
		
	case 5 :
	{
		int value;
		cin >> value;
		h.SetGetWorkMonth(value);
		break;
	}
	case 6 :
	{
		string value;
		string name, lastName, patronymic;
		cin >> lastName >> name >> patronymic;
		value = lastName + " " + name + " " + patronymic;
		h.SetFio(value);
		break;
	} 
	default:
		break;
	}
}
void Fields(payment &h)
{
	int k = 0;
	do
	{
	cout << "Оклад = " << h.GetOklad() << " 1 - чтобы изменить\n";
	cout << "Год поступления на работу = " << h.GetYear() << " 2 - чтобы изменить\n";
	cout << "% надбавки = " << h.GetBonus() << " 3 - чтобы изменить\n";
	cout << "Количество рабочих дней в месяце = " << h.GetDayMonth() << " 4 - чтобы изменить\n";
	cout << "Количество отработанных дней за месяц = " << h.GetWorkDayMoth() << " 5 - чтобы изменить\n";
	cout << "ФИО: " << h.GetFio() << " 6 - чтобы изменить\n";
	cout << "0 - Назад\n";
	cin >> k;
	FieldEdit(h, k);
	system("cls");
	} while (k != 0);
}
void SecondMenu(payment &h)
{
	int k = 0;
	do
	{
		cout << "1 - Изменить поле\n";
		cout << "2 - Показать список методов\n";
		cout << "0 - Назад\n";
		cin >> k;
		system("cls");
		switch (k)
		{
		case 1 :
			Fields(h);
			break;
		case 2 :
			MethodsChoice(h);
			break;
		default:
			break;
		}
	} while ((k != 0));
	system("cls");
}


void MainMenu(payment &h)
{
	
	int k = 0;
	do
	{
		k = 0;
		cout << "1 - Инициализировать самому\n";
		cout << "2 - Инициализировать с помощью Init()\n";
		cout << "0 - Выход\n";
		cin >> k;
		DrawLine();
		switch (k)
		{
		case 1:
			h.Read();
			SecondMenu(h);
			break;
		case 2:
			h.Init();
			SecondMenu(h);
			break;
		default:
			break;
		}
		system("cls");
	} while ((k != 0));
	
}
void main()
{	
	setlocale(LC_CTYPE, ".1251");
	payment human;
	MainMenu(human);
}

