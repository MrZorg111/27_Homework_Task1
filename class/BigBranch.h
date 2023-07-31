#pragma once
#include <string>
#include <vector>
#include "MediumBranch.h"
#include "Functions.h"

class BigBranch : public Branch {
	MediumBranch mediumBranch;
	std::vector<MediumBranch> mediumBranchs;
	//Метод определения кол-ва средних веток на одной большой
	const int VOL_MB = random_size(1, 2); 
	const int VOL_HOUSE_BBRANCH = 5;
public:
	//Метод заселения эльфов на среднюю ветку
	void setSettlElfOnMBranch() {
		mediumBranch.setSettlElf();
	}
	//Метод заполнения списка заселенных средних веток
	void setListSettleMBranch() {
		mediumBranchs.push_back(mediumBranch);
		mediumBranch.setClear();
	}
	//Метод доступа к эльфам на средней ветке
	void getResidendElfOnMBranch() {
		mediumBranch.getResidentElf();
	}
	//Метод доступа к кол-ву домов на большой ветке
	int getVolumeHouseBBranch() {
		return VOL_HOUSE_BBRANCH;
	}
	//Метод доступа к списку заселенных средних веток
	void getListResident() {
		for (int res_branch = 0; res_branch < mediumBranchs.size(); res_branch++) {
			mediumBranchs[res_branch].getResidentElf();
		}
	}
	// Метод доступа к домам эльфов
	MediumBranch getHouseMB() {
		return mediumBranch;
	}
	//Метод доступа к кол-ву средних веток на этой большой
	int getVolMB() {
		return VOL_MB;
	}
};