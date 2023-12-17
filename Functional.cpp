#include "Functional.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>


using std::cout;
using std::cin;


void checkDigit(float* digit, char* oper, char* oper1, bool* operNum, char* wish_global, bool* clearing)
{
    char str[256];
    bool worck = true;
    int counter = 0;
    char sign = '\0';
    while (worck)
    {
        str[counter] = _getch();
        if (str[0] == '-' && counter == 0)
        {
            cout << str[0];
            sign = '-';
            continue;
        }
        if (str[counter] == 27)
        {
            *wish_global = 27;
            break;
        }
        if (*oper1 == 61 && str[counter] == 32)
        {
            system("cls");
            instruction();
            *clearing = false;
            break;
        }
        if (*operNum == true)
        {
            if (str[counter] == 43 || str[counter] == 45 || str[counter] == 42 || str[counter] == 47 || str[counter] == 33 || str[counter] == 94 || str[counter] == 37)
            {
                *oper = str[counter];
                str[counter] = '\0';
                worck = false;
                break;
            }
        }
        else
        {
            if (str[counter] == 61 || str[counter] == 13)
            {
                *oper1 = 61;
                str[counter] = '\0';
                worck = false;
                break;
            }
        }

        if ((str[counter] >= 48 && str[counter] <= 57) || str[counter] == 46)
        {
            cout << str[counter];
            counter++;
        }
        else if (str[counter] == 8)
        {
            if (counter == 0)
            {
                if (sign == '-')
                {
                    cout << "\b" << " " << "\b";
                    sign = '\0';
                }
                else Beep(100, 250);
            }
            else
            {
                cout << "\b" << " " << "\b";
                counter--;
            }
        }

        else
        {
            Beep(1500, 200);
            cout << " " << "\b";
        }

    }
    setlocale(LC_NUMERIC, "C");

    *digit = atof(str);
    if (sign == '-') *digit *= (-1);
    sign = '\0';
    *operNum = !*operNum;
}

float plus(float x, float y)
{
    return x + y;
}

float sub(float x, float y)
{
    return x - y;
}

float mult(float x, float y)
{
    return x * y;
}

float div(float x, float y)
{
    int n{ 0 };
    if (y != 0) return x / y;
    else
    {
        Beep(1000, 250);
        cout << " на 0 делить нельзя!!! \n ";
        return n;
    }
}

long double fact(long double n, bool* operNum, char* oper1, char* oper)
{
    if (n - (int)n != 0)
    {
        begining(operNum, oper1);
        cout << " для вычисления факториала, значение должно быть целым. \n ";
        return 0;
    }
    else if (n < 0)
    {
        begining(operNum, oper1);
        cout << " факториал для отрицательных чисел не существует! \n ";
        return 0;
    }
    else if (n > 170)
    {
        begining(operNum, oper1);
        cout << " переполнение. максимальное число для вычисления факториала 170.\n ";
        return 0;
    }
    else
    {
        if (n == 0) return 1;
        else return n * fact(n - 1, operNum, oper1, oper);
    }
}

long double power(float x, float y)
{
    //int n{ 0 };
    //const int c = 1;
    //if (y == 0) return 1;
    //else if (y - (int)y != 0)
    //{
    //    cout << " вычисление дробной степени в разработке \n ";
    //    return n;
    //}
    //else if (y < 0)
    //{
    //    int p = y * (-1);
    //    float n = x * power(x, (p - 1));
    //    return c / n;
    //}
    //else return x * power(x, (y - 1));
    return pow(x, y);
}


float procent(double x, double y)
{
    return x / y * 100;
}

void begining(bool* operNum, char* oper1)
{
    *operNum = true;
    *oper1 = 61;
}

void instruction()
{
    cout << " введите выражение в формате a+b=(или Enter) или a! =(или Enter)\n доступные операции: '+' '-' '*' '/' '!' '^' '%' \n для выхода нажмите \"Esc\". для очистки дисплея нажмите \"пробел\"\n ";
}
