#pragma once

class Calculator {
public:
	Calculator() = default;

private:
	// ������������� ����������
	float _a{ 0 };
	float _b{ 0 };
	// ���������� ��� �������� ����� ����
	char wish_global = 32;
	bool clearing;
	// ���������� ��� ������ � ������� ��������
	bool check = true;
	bool operNum = true;
	char oper;
	char oper1;
	// ���������� ��� ������ ����������
	long double result{ 0 };

};