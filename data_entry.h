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
	std::string _instr = " ������� ��������� � ������� a+b=(��� Enter) ��� a! \n ��������� ��������: '+' '-' '*' '/' '!' '^' '%' \n ��� ������ ������� \"Esc\". ��� ������� ������� ������� \"������\"\n ";
};