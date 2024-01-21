#include "Data_entry.h"
#include "Windows.h"

void Data::print_instruction(){
	system("cls");
	std::cout << _instr;
}

void Data::data_enter(float* digit, char* oper, char* oper1, bool* operNum, char* wish_global, bool* clearing){
    while (_entry)
    {
        _str[_counter] = _getch();
        if (_str[0] == '-' && _counter == 0){

            std::cout << _str[0];
            _sign = '-';
            continue;
        }
        if (_str[_counter] == 27){

            *wish_global = 27;
            break;
        }
        if (*oper1 == 61 && _str[_counter] == 32){

            print_instruction();
            *clearing = false;
            break;
        }
        if (*operNum == true){

            if (_str[_counter] == 43 || _str[_counter] == 45 || _str[_counter] == 42 || _str[_counter] == 47 || _str[_counter] == 33 || _str[_counter] == 94 || _str[_counter] == 37)
            {
                *oper = _str[_counter];
                _str[_counter] = '\0';
                _entry = false;
                break;
            }
        }
        else{

            if (_str[_counter] == 61 || _str[_counter] == 13)
            {
                *oper1 = 61;
                _str[_counter] = '\0';
                _entry = false;
                break;
            }
        }

        if ((_str[_counter] >= 48 && _str[_counter] <= 57) || _str[_counter] == 46){

            std::cout << _str[_counter];
            _counter++;
        }
        else if (_str[_counter] == 8){

            if (_counter == 0){

                if (_sign == '-')
                {
                    std::cout << "\b" << " " << "\b";
                    _sign = '\0';
                }
                else Beep(100, 250);
            }
            else{

                std::cout << "\b" << " " << "\b";
                _counter--;
            }
        }

        else{

            Beep(1500, 200);
            std::cout << " " << "\b";
        }

    }
    setlocale(LC_NUMERIC, "C");

    *digit = atof(_str);
    _str[0] = '\0';
    if (_sign == '-') *digit *= (-1);
    _sign = '\0';
    *operNum = !*operNum;
    _entry = true;
    _counter = 0;
}
