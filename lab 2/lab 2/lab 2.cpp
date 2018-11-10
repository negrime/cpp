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
public: static const int fioSize = 30;
	
private:
	char fio [fioSize]; //Фио
	float oklad; //оклад
	int year; //год поступления на работу
	float bonusProcent; //процент надбавки
	int   workDayMonth; //кол-во отработанных дней
	float dayMonth; //кол-во рабочих дней
	float seniority; //стаж (полное кол-во лет)
	float nalog; //подоходный налог
	float calculationPayDay(); // Зарплата за 1н день
	float vichisl_nach_summ();
	float vichisl_yder_summ();
	float calculationPay();
	float calculationSeniority(); //вычисление стажа
	float calculationBonus();
public:
	void  Init();
	void  Read();
	void  Display();

};

float payment::calculationPayDay()
{
	return (oklad / dayMonth);
}

float payment::vichisl_nach_summ()
{
	return (calculationPayDay()*workDayMonth);
}

float payment::calculationBonus()
{
	return ((vichisl_nach_summ()/100) * bonusProcent);
}

float payment::vichisl_yder_summ()
{
	return (vichisl_nach_summ()*0.01 + vichisl_nach_summ()*nalog);
}

float payment::calculationPay()
{
	return (workDayMonth*calculationPayDay() - (workDayMonth*calculationPayDay()*0.13) + calculationBonus());
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
	float oklad = 0;
	int year = 0;
	float bonusProcent = 0;
	int   workDayMonth = 0;
	float dayMonth = 0;
	float seniority = 0;
	float nalog = 0;

}

void payment::Read()
{
	cout << "Расчет зарплаты сотрудника: \n\n";
	cout << "ФИО: ";
	cin.getline(fio, 30);
	cout << fio;
	cout << "Оклад: ";
	cin >> oklad;
	cout << "Год поступления на работу: ";
	cin >> year;
	cout << "% надбавки: ";
	cin >> bonusProcent;
	cout << "Подоходный налог: ";
	cin >> nalog;
	cout << "Кол-во рабочих дней в месяце: ";
	cin >> dayMonth;
	cout << "Кол-во отработанных дней: ";
	cin >> workDayMonth;
}

void payment::Display()
{
	cout << "\n\nРезультат:\n";
	cout << "Начисленная сумма составляет: " << vichisl_nach_summ() << "\n";
	cout << "Удержанная сумма составляет: " << vichisl_yder_summ() << "\n";
	cout << "Сумма, выдаваемая на руки составляет: " << calculationPay() << "\n";
	cout << "Стаж составляет: " << calculationSeniority() << "\n";
	
}



void main()
{
	
	setlocale(LC_CTYPE, ".1251");
	payment human;
	human.Init();
	human.Read();
	human.Display();
	cout << human.fioSize;
	
//	getch();
}

