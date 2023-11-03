#pragma once
#include "Functional.h"
#include <conio.h>

class Data {
public:
	Data() = default;


private:
	char _str[256]{};
	bool entry = true;
	int counter = 0;
	char sign = '\0';
};