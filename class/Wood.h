#pragma once
#include <string>
#include <vector>
#include "BigBranch.h"
#include "Functions.h"

class Wood {
	BigBranch bigBranch;
	std::vector<BigBranch> bigBranchs;
	const int VOL_BB = 1 /*random_size(3, 2)*/;
public:
	//Метод доступа к заселению средней ветки
	void setSettlMB() {
		bigBranch.setSettlElfOnMBranch();
	}
	//Метод заселения большой ветки
	void setSettlBB() {
		bigBranch.setSettlElf(bigBranch.getVolumeHouseBBranch());
	}
	//Метод доступа к созданию списка домов на средних ветках
	void setMakeLIstMB() {
		bigBranch.setListSettleMBranch();
	}
	//Метод создания списка домов на больших ветках
	void setMakeListBB() {
		bigBranchs.push_back(bigBranch);
		bigBranch.setClear();
		bigBranch.getClearListMB();
	}
	/*------------------------------------------------------*/
	//Метод доступа к кол-ву средних веток
	int getVolMB() {
		return bigBranch.getVolMB();
	}
	//Метод доступа к кол-ву больших веток
	int getVolBB() {
		return VOL_BB;
	}
	//Метод поиска соседей заданного эльфа
	bool getFindElfOnBigBranch(std::string find_elf, int num_b = 0) {
		if (!bigBranchs[num_b].getFindElfOnMBranch(find_elf)) {
			if (!bigBranchs[num_b].getFindElf(find_elf)) {
				if ((num_b + 1) >= VOL_BB) {
					return false;
				}
				else {
					getFindElfOnBigBranch(find_elf, num_b += 1);
				}
			}
			else {
				bigBranchs[num_b].getFindNeighbourInHome(find_elf);
				return true;
			}
		}
		else {
			return true;
		}
	}
};