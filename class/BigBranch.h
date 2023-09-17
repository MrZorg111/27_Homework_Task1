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
		for (int mb = 0; mb < VOL_MB; mb++) {
			for (int m = 0; m < mediumBranch.getVolumeHouseMBranch(); m++) {
				mediumBranch.setSettlElf();
			}
			mediumBranchs.push_back(mediumBranch);
			mediumBranch.setClear();
		}
	}
	//Метод очистки списка средних веток
	void SetClearMBranchs() {
		mediumBranchs.clear();
	}


	//Метод доступа к кол-ву домиков на большой ветке
	int getVolHouseBBranch() {
		return VOL_HOUSE_BBRANCH;
	}
	//Метод доступа к списку домиков на средних ветках
	void getListMBranch() {
		for (int list_mb = 0; list_mb < mediumBranchs.size(); list_mb++) {
			std::cout << "Middle branch " << list_mb + 1 << " ";
			mediumBranchs[list_mb].getElfs();
			std::cout << std::endl;
		}
	}
	//Метод поиска эльфов на всех ветвях
	bool getFindAllBranch(std::string wanted, int& adress_mb, int& neighbour) {
		for (int want_ab = 0; want_ab < mediumBranchs.size(); want_ab++) {
			if (mediumBranchs[want_ab].getFindElf(wanted, neighbour)) {
				adress_mb = want_ab + 1;
				return true;
			}
		}
		if (getFindElf(wanted, neighbour)) {
			return true;
		}
		return false;
	}
};