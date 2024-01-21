#pragma once
#include<iostream>
#include <string>
#include <conio.h>

class Data {
public:
	Data() = default;

	void print_instruction();
	void data_enter(float* digit, char* oper, char* oper1, bool* operNum, char* wish_global, bool* clearing);


private:
	char _str[256]{};
	bool _entry = true;
	int _counter = 0;
	char _sign = '\0';
	std::string _instr = " введите выражение в формате a+b=(или Enter) или a! \n доступные операции: '+' '-' '*' '/' '!' '^' '%' \n для выхода нажмите \"Esc\". для очистки дисплея нажмите \"пробел\"\n ";
};