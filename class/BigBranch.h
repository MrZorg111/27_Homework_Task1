#pragma once
#include <string>
#include <vector>
#include "MediumBranch.h"
#include "Functions.h"

class BigBranch : public Branch {
	MediumBranch mediumBranch;
	std::vector<MediumBranch> mediumBranchs;
	//Метод определения кол-ва средних веток на одной большой
	const int VOL_MB = 1 /*random_size(1, 2)*/ ;
	const int VOL_HOUSE_BBRANCH = 5;
public:
	//Метод заселения эльфов на среднюю ветку
	void setSettlElfOnMBranch() {
		mediumBranch.setSettlElf(mediumBranch.getVolumeHouseMBranch());
	}
	//Метод заполнения списка заселенных средних веток
	void setListSettleMBranch() {
		mediumBranchs.push_back(mediumBranch);
		mediumBranch.setClear();
	}
	//Метод доступа к поиску на средних ветках
	bool getFindElfOnMBranch(std::string name_elf, int num_m) {
		if (num_m < mediumBranchs.size()) {
			if (!mediumBranchs[num_m].getFindElf(name_elf)) {
				getFindElfOnMBranch(name_elf, num_m += 1);
			}
			else {
				mediumBranchs[num_m].getFindNeighbourInHome(name_elf);
				return true;
			}
		}
		else {
			return false;
		}
	}
	//Метод доступа к кол-ву домов на большой ветке
	int getVolumeHouseBBranch() {
		return VOL_HOUSE_BBRANCH;
	}
	//Метод доступа к кол-ву средних веток на этой большой
	int getVolMB() {
		return VOL_MB;
	}
	//Метод доступа к оситке вектора списка домов на средней ветке
	void getClearListMB() {
		mediumBranchs.clear();
	}
};