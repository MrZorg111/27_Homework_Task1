#pragma once
#include <string>
#include <vector>
#include "Branch.h"

class MediumBranch : public Branch {
	const int SIZE_HOUSE = 5;
public:
	//������� ��� ������� � ���������� ����� �� �����
	int getSizeHouse() {
		return SIZE_HOUSE;
	}
};