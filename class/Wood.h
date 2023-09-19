#pragma once
#include <string>
#include <vector>
#include "BigBranch.h"
#include "Functions.h"

class Wood {
	BigBranch bigBranch;
	std::vector<BigBranch> bigBranchs;
	const int VOL_BB = random_size(3, 3);
	
public:
	//Метод доступа к заселению средней ветки
		void setSettlMB() {
			bigBranch.setSettlElfOnMBranch();
		}
	//Метод заселения большой ветки
	void setSettlBB() {
		for (int bb = 0; bb < VOL_BB; bb++) {
			setSettlMB();
			for (int b = 0; b < bigBranch.getVolHouseBBranch(); b++) {
				bigBranch.setSettlElf();
			}
		
			bigBranchs.push_back(bigBranch);
			bigBranch.setClear();
			bigBranch.SetClearMBranchs();
		}
	}
	//Метод доступа к проживающим эльфам на всех ветках
	void getAllElfs() {
		for (int list_bb = 0; list_bb < bigBranchs.size(); list_bb++) {
			std::cout << "Big branch " << list_bb + 1 << " ";
			bigBranchs[list_bb].getElfs();
			std::cout << std::endl;
			bigBranchs[list_bb].getListMBranch();
			std::cout << std::endl;
		}
	}
	//Метод поиска 
	bool getAllFind(std::string wanted, int& adress_mb, int& adress_bb, int& neighbour) {
		for (int wood = 0; wood < bigBranchs.size(); wood++) {
			if (bigBranchs[wood].getFindAllBranch(wanted, adress_mb, neighbour)) {
				adress_bb = wood + 1;
				return true;
			}
		}
		return false;
	}
};

