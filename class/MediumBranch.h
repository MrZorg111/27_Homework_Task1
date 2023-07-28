#pragma once
#include <string>
#include <vector>
#include "Branch.h"

class MediumBranch : public Branch {
	const int SIZE_HOUSE = 5;
public:
	//Геттерс для достума к количеству домов на ветке
	int getSizeHouse() {
		return SIZE_HOUSE;
	}
};