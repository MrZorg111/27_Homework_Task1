#pragma once
#include <string>
#include <vector>
#include "BigBranch.h"
#include "Functions.h"

class Wood {
	BigBranch bigBranch;
	std::vector<BigBranch> bigBranchs;
	const int VOL_BB = random_size(3, 2);
public:
	//Метод доступа к заселению средней ветки
	void setSettlMB(std::string name_elf) {
		bigBranch.setSettlElfOnMBranch(name_elf);
	}
	//Метод заселения большой ветки
	void setSettlBB(std::string name_elf) {
		bigBranch.setSettlElf(name_elf);
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
	//Метод доступа к кол-ву домов на ветках
	int getAllHause(char s) {
		return bigBranch.getVolumeAllHouse(s);
	}
	//Метод доступа к макс. кол-ву веток
	int getAllBranch(char s) {
		if (s == 'M') {
			return bigBranch.getVolMB();
		}
		else if (s == 'B') {
			return VOL_BB;
		}
		else {
			std::cout << "Не верный ввод данных! " << std::endl;
			return false;
		}
	}
	//Метод доступа к количеству веток в момент заселения
	int getAllVolBranchsRealTime(char s) {
		if (s == 'B') {
			return bigBranchs.size();
		}
		else if (s == 'M') {
			return bigBranch.getVolMBRealTime();
		}
	}
	//Метод доступа к размеру списка жильцов
	int getAllVolElfs(char s) {
		return bigBranch.getAllElfsHome(s);
	}
	//Метод проверочного поиска на ветках 
	bool getCheckAllBranch(std::string name) {
		if (bigBranchs.size() == 0) {
			if (!bigBranch.getCheckMB(name)) {
				return bigBranch.getCheckBB(name);
			}
			else {
				return true;
			}
		}
		else {
			for (int check_b = 0; check_b < bigBranchs.size(); check_b++) {
				if (!bigBranchs[check_b].getCheckMB(name)) {
					if (!bigBranchs[check_b].getCheckBB(name)) {
						return false;
					}
					else {
						return true;
					}
				}
				else {
					return true;
				}
			}
		}
	}
	//Метод поиска соседей заданного эльфа
	bool getFindElfOnBigBranch(std::string find_elf, int num_b = 0) {
		if (!bigBranchs[num_b].getFindElfOnMBranch(find_elf)) {
			if (!bigBranchs[num_b].getFindElf(find_elf)) {
				if ((num_b + 1) >= VOL_BB) {
					return false;
				}
				else {
					return getFindElfOnBigBranch(find_elf, num_b += 1);
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