#pragma once
#include "Branch.h"

class MediumBranch : public Branch {
	const int VOL_HOUSE_MBRANCH = 3;
public:
	//Мектод для достума к количеству домов на ветке
	int getVolumeHouseMBranch() {
		return VOL_HOUSE_MBRANCH;
	}
};