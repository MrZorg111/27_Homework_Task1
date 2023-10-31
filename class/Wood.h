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
	
	void setListsElfs() {
		for (int bb = 0; bb < VOL_BB; bb++) {
			bigBranch.setNameElf();
			bigBranch.setSettlElfOnMBranch();
			bigBranchs.push_back(bigBranch);
			bigBranch.setClear();
		}
	}

	//_____________________________________________________________//

	void getNameElfsLists() {
		for (int total_name = 0; total_name < VOL_BB; total_name++) {
			std::cout << "На большой ветке номер " << total_name + 1;
			if (bigBranchs[total_name].getNameBigElf() == "None") {
				std::cout << " никто не проживает!" << std::endl;
			}
			else {
				std::cout << " проживает " << bigBranchs[total_name].getNameBigElf() << std::endl;
			}
			bigBranchs[total_name].getNameMediumElfs();
		}
	}
	bool getFindElf(std::string wanted_elf, int& adress) {
		for (int find_bbranch = 0; find_bbranch < VOL_BB; find_bbranch++) {
			if (bigBranchs[find_bbranch].getNameBigElf() == wanted_elf) {
				adress = find_bbranch;
				return true;
			}
			else if (bigBranchs[find_bbranch].getFindElf(wanted_elf)) {
				adress = find_bbranch;
				return true;
			}
		}
		return false;
	}
};

