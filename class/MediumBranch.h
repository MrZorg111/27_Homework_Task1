#pragma once
#include <string>
#include <vector>
#include "Branch.h"

class MediumBranch : public Branch {
	const int VOL_HOUSE_MBRANCH = 3;
public:
	//������ ��� ������� � ���������� ����� �� �����
	int getVolumeHouseMBranch() {
		return VOL_HOUSE_MBRANCH;
	}
	//����� �������� �� ������� �����
	bool getCheckMB(std::string name) {
		return getFindElf(name);
	}
};