#pragma once
#include <string>
#include <vector>
#include "Branch.h"

class MediumBranch : public Branch {
	const int VOL_HOUSE_MBRANCH = 3;
public:
	//Мектод для достума к количеству домов на ветке
	int getVolumeHouseMBranch() {
		return VOL_HOUSE_MBRANCH;
	}
	//Метод проверки на средней ветке
	bool getCheckMB(std::string name) {
		return getFindElf(name);
	}
};