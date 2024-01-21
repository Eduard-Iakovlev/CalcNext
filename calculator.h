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
	// ������������� ����������
	float _a;
	float _b;
	// ���������� ��� �������� ����� ����
	char _wish_global = 32;
	bool _clearing;
	// ���������� ��� ������ � ������� ��������
	bool _check = true;
	bool _operNum = true;
	char _oper;
	char _oper1;
	// ���������� ��� ������ ����������
	long double _result;
};