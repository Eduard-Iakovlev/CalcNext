#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Functional.h"

using std::cout;
using std::cin;

int main()
{
	SetConsoleOutputCP(1251);
	// запрашиваемые переменные
	float a;                      
	float b;
	// переменные для перехода между меню
	char wish_global = 32;
	bool clearing;
	// переменные для работы с выбором операции
	bool check = true;
	bool operNum = true;
	char oper;
	char oper1;
	// переменная для записи результата
	long double result;


	instruction();

	while (wish_global == 32) // Запуск работы калькулятора
	{
		clearing = true;
		operNum = true;
		a = 0;
		b = 0;

		while (clearing)
		{
			checkDigit(&a, &oper, &oper1, &operNum, &wish_global, &clearing);
			if (clearing == false) break;
			if (wish_global != 32) break;
			if (oper == '!')
			{
				if (fact(a, &operNum, &oper, &oper1) == 0)
				{
					begining(&operNum, &oper1);
					break;
				}
				cout << oper << " = " << fact(a, &operNum, &oper, &oper1) << "\n ";
				begining(&operNum, &oper1);
				break;
			}
			else
			{
				cout << " " << oper << " ";
				checkDigit(&b, &oper, &oper1, &operNum, &wish_global, &clearing);
				cout << " " << oper1 << " ";

				while (check)
				{
					switch (oper) // обработка оператора
					{
					case '+':
						result = plus(a, b);
						check = false;
						break;

					case '-':
						result = sub(a, b);
						check = false;
						break;

					case '*':
						result = mult(a, b);
						check = false;
						break;

					case '/':
						result = div(a, b);
						check = false;
						break;

					case '^': // как за ранее определить переполнение, при возведении в степень, пока не разобрался
						result = power(a, b);
						check = false;
						break;
					case '%':
						result = procent(a, b);
						check = false;
						break;

					default:
						check = false;
						break;
					}
				}
				if (oper == '/' && b == 0)
				{
					check = true;
					continue;
				}
				if (oper == '%') cout << result << oper << "\n ";
				else if (result == (-0)) cout << 0 << "\n ";
				else cout << result << "\n ";

				check = true;

			}
		}
	}
	system("cls");
	cout << "\n\n\n\n                        Всего хорошего.\n\n\n\n\n\n\n\n";
	system("pause");
}

