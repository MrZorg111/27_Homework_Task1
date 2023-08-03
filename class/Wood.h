#pragma once
#include <string>
#include <vector>
#include "BigBranch.h"

class Wood {
	BigBranch bigBranch;
	std::vector<BigBranch> bigBranchs;
	const int VOL_BB = random_size(3, 2);
public:
	//Метод доступа к заселению средней ветки
	void setSettlMB() {
		bigBranch.setSettlElfOnMBranch();
	}
	//Метод заселения большой ветки
	void setSettlBB() {
		bigBranch.setSettlElf();
	}
	//Метод доступа к созданию списка домов на средних ветках
	void setMakeLIstMB() {
		bigBranch.setListSettleMBranch();
	}
	//Метод создания списка домов на больших ветках
	void setMakeListBB() {
		bigBranchs.push_back(bigBranch);
		bigBranch.setClear();
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
	//Метод доступа к заселенным веткам
	void getInfoLists() {
		for (int bb_list = 0; bb_list < bigBranchs[bb_list].getVolumeHouseBBranch(); bb_list++) {
			bigBranchs[bb_list].getListResident();
			bigBranchs[bb_list].getResidentElf();
		}
	}
};