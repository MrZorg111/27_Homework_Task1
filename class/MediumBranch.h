#pragma once
#include <string>
#include <vector>
#include "Branch.h"

class MediumBranch : public Branch {
	const int VOL_HOUSE_MBRANCH = 5;
public:
	//������� ��� ������� � ���������� ����� �� �����
	int getVolumeHouseMBranch() {
		return VOL_HOUSE_MBRANCH;
	}
};