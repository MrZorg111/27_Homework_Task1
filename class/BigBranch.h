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
	void setSettlElfOnMBranch(std::string name_elf) {
		mediumBranch.setSettlElf(name_elf);
	}
	//Метод заполнения списка заселенных средних веток
	void setListSettleMBranch() {
		mediumBranchs.push_back(mediumBranch);
		mediumBranch.setClear();
	}


	//Метод доступа к количеству домов на ветках
	int getVolumeAllHouse(char s) {
		if (s == 'B') {
			return VOL_HOUSE_BBRANCH;
		}
		else if (s == 'M') {
			return mediumBranch.getVolumeHouseMBranch();
		}
		else {
			std::cout << "Incorrect input!" << std::endl;
		}
		return 0;
	}
	//Метод доступа к размеру списка жильцов
	int getAllElfsHome(char s) {
		if (s == 'B') {
			return getVolElfs();
		}
		else if (s == 'M') {
			return mediumBranch.getVolElfs();
		}
		else {
			std::cout << "Incorrect input!";
		}
	}
	//Метод доступа к кол-ву средних веток на этой большой
	int getVolMB() {
		return VOL_MB;
	}
	//Метод доступа к количеству веток в момент заселения
	int getVolMBRealTime() {
		return mediumBranchs.size();
	}
	//Метод проверки на большой ветке
	bool getCheckBB(std::string name) {
		return getFindElf(name);
	}
	//Метод проверки на средней ветке
	bool getCheckMB(std::string name) {
		if (mediumBranchs.size() == 0) {
			return mediumBranch.getCheckMB(name);
		}
		if (mediumBranchs.size() > 0 && mediumBranchs.size() <= VOL_MB) {
			for (int check_mb = 0; check_mb < mediumBranchs.size(); check_mb++) {
				if (mediumBranchs[check_mb].getCheckMB(name)) {
					return true;
				}
			}
			if (mediumBranchs.size() != VOL_MB) {
				return mediumBranch.getCheckMB(name);
			}
		}
		return false;
	}
	//Метод доступа к очистке вектора списка домов на средней ветке
	void getClearListMB() {
		mediumBranchs.clear();
	}
	//Метод доступа к поиску на средних ветках
	bool getFindElfOnMBranch(std::string name_elf, int num_m = 0) {
		if (!mediumBranchs[num_m].getFindElf(name_elf)) {
			if ((num_m + 1) >= VOL_MB) {
				return false;
			}
			else {
				return getFindElfOnMBranch(name_elf, num_m += 1);
			}
		}
		else {
			mediumBranchs[num_m].getFindNeighbourInHome(name_elf);
			return true;
		}
	}
};