#pragma once
#include<iostream>
#include <string>
#include "Data_entry.h"

class Calculator {
public:
	Calculator() = default;

	void start_calc();
	void begining();

	float plus();
	float sub();
	float mult();
	float div();
	long double fact(long double n);
	long double power();
	float procent(double x, double y);


private:
	// запрашиваемые переменные
	float _a;
	float _b;
	// переменные для перехода между меню
	char _wish_global = 32;
	bool _clearing;
	// переменные для работы с выбором операции
	bool _check = true;
	bool _operNum = true;
	char _oper;
	char _oper1;
	// переменная для записи результата
	long double _result;
};