#include "Calculator.h"
#include "Windows.h"
#include <cmath>


void Calculator::start_calc(){
	Data data;
	data.print_instruction();

	while (_wish_global == 32) {
		_clearing = true;
		_operNum = true;
		_a = 0;
		_b = 0;
		_result = 0;

		while (_clearing){
			data.data_enter(&_a, &_oper, &_oper1, &_operNum, &_wish_global, &_clearing);
			if (_clearing == false) break;
			if (_wish_global != 32) break;
			if (_oper == '!') {
				if (fact(_a) == 0) {
					begining();
					break;
				}
				std::cout << "! = " << fact(_a) << "\n ";
				break;
			}
			else{
				std::cout << " " << _oper << " ";
				data.data_enter(&_b, &_oper, &_oper1, &_operNum, &_wish_global, &_clearing);
				std::cout << " " << _oper1 << " ";

				while (_check){

					switch (_oper){

					case '+':
						_result = plus();
						_check = false;
						break;

					case '-':
						_result = sub();
						_check = false;
						break;

					case '*':
						_result = mult();
						_check = false;
						break;

					case '/':
						_result = div();
						_check = false;
						break;

					case '^': // как за ранее определить переполнение, при возведении в степень, пока не разобрался
						_result = power();
						_check = false;
						break;
					case '%':
						_result = procent(_a, _b);
						_check = false;
						break;

					default:
						_check = false;
						break;
					}
				}
				if (_oper == '/' && _b == 0){

					_check = true;
					continue;
				}
				if (_oper == '%') std::cout << _result << _oper << "\n ";
				else if (_result == (-0)) std::cout << 0 << "\n ";
				else std::cout << _result << "\n ";

				_check = true;

			}
		}
	}
}

void Calculator::begining(){
	_operNum = true;
	_oper1 = 61;
}

float Calculator::plus(){
	return _a + _b;
}

float Calculator::sub(){
	return _a - _b;
}

float Calculator::mult(){
	return _a * _b;
}

float Calculator::div()
{
	if (_b != 0) return _a / _b;
	else
	{
		Beep(1000, 250);
		std::cout << " на 0 делить нельзя!!! \n ";
		return 0;
	}
}

long double Calculator::fact(long double n){

	if (n - (int)n != 0)
	{
		begining();
		std::cout << " для вычисления факториала, значение должно быть целым. \n ";
		return 0;
	}
	else if (n < 0)
	{
		begining();
		std::cout << " факториал для отрицательных чисел не существует! \n ";
		return 0;
	}
	else if (n > 170)
	{
		begining();
		std::cout << " переполнение. максимальное число для вычисления факториала 170.\n ";
		return 0;
	}
	else
	{
		if (n == 0) return 1;
		else return n * fact(n - 1);
	}
}

long double Calculator::power()
{
	return pow(_a, _b);
}

float Calculator::procent(double x, double y)
{
	return _a / _b * 100;
}

