#pragma once
#include <string>
#include <vector>
#include "MediumBranch.h"
#include "Functions.h"

class BigBranch {
	std::string name_elf;
	MediumBranch mediumBranch;
	std::vector<MediumBranch> mediumBranchs;
	//Метод определения кол-ва средних веток на одной большой
	const int VOL_MB = random_size(2, 2);

public:

	//Метод заселения эльфа ма большую ветку
	void setNameElf() {
		name_elf = generation_names();
	}
	//Метод заселения эльфов на среднюю ветку
	void setSettlElfOnMBranch() {
		for (int put_elf = 0; put_elf < VOL_MB; put_elf++) {
			mediumBranch.setNameElf();
			mediumBranchs.push_back(mediumBranch);
		}
	}
	void setClear() {
		mediumBranchs.clear();
	}
	//___________________________________________________//

	std::string getNameBigElf() {
		return name_elf;
	}
	void getNameMediumElfs() {
		for (int e_n = 0; e_n < VOL_MB; e_n++) {
			std::cout << "\t\t--На средней ветке номер " << e_n + 1;
			if (mediumBranchs[e_n].getNameElf() == "None") {
				std::cout << " никто не проживает!" << std::endl;
			}
			else {
				std::cout << " проживает " << mediumBranchs[e_n].getNameElf() << std::endl;
			}
			
		}
	}
	bool getFindElf(std::string wanted_elf) {
		for (int want_e = 0; want_e < VOL_MB; want_e++) {
			if (mediumBranchs[want_e].getNameElf() == wanted_elf) {
				return true;
			}
		}
		return false;
	}
};