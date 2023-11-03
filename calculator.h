#pragma once

class Calculator {
public:
	Calculator() = default;

private:
	// запрашиваемые переменные
	float _a{ 0 };
	float _b{ 0 };
	// переменные для перехода между меню
	char wish_global = 32;
	bool clearing;
	// переменные для работы с выбором операции
	bool check = true;
	bool operNum = true;
	char oper;
	char oper1;
	// переменная для записи результата
	long double result{ 0 };

};