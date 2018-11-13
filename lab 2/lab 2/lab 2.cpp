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
private: static const int fioSize = 30; // Кол-во символов для ФИО
		const float nalog = 0.13; // Процент налога	
	// ПОЛЯ
private:
	char fio [fioSize]; //Фио
	float oklad; // Оклад
	int year; // Год поступления на работу
	float bonusProcent; // Процент надбавки
	int   workDayMonth; // Кол-во отработанных дней
	float dayMonth; // Кол-во рабочих дней
	float seniority; // Стаж (полное кол-во лет)
	// МЕТОДЫ
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
	return (vichisl_nach_summ()*0.01 + vichisl_nach_summ() * nalog);
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
	for (size_t i = 0; i < fioSize; i++)
	{
		fio[i] = NULL;
	}
	 oklad = 0;
	 year = 0;
	 bonusProcent = 0;
	 workDayMonth = 0;
	 dayMonth = 0;
	 seniority = 0;
}

void payment::Read()
{
	cout << "Расчет зарплаты сотрудника: \n\n";
	cout << "ФИО: ";
	cin.getline(fio, 30);
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
}

void payment::Display()
{
	cout << "\n\nРезультат:\n";
	cout << "Стаж составляет: " << calculationSeniority() << "\n";
	cout << "Начисленная сумма составляет: " << vichisl_nach_summ() << "\n";
	cout << "Удержанная сумма составляет: " << vichisl_yder_summ() << "\n";
	cout << "Сумма, выдаваемая на руки составляет: " << calculationPay() << "\n";	
}



void main()
{	
	setlocale(LC_CTYPE, ".1251");
	payment human;
	human.Init();
	human.Read();
	human.Display();
}

