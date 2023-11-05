#pragma once
#include <string>
#include <vector>
#include "MediumBranch.h"
#include "Branch.h"
#include "Functions.h"

class BigBranch : public Branch {
	std::string name_elf;
	MediumBranch mediumBranch;
	std::vector<MediumBranch> mediumBranchs;
	//Метод определения кол-ва средних веток на одной большой

public:

	//Метод заселения эльфа ма большую ветку
	void setNameElf() {
		name_elf = generation_names();
	}
	//Метод заселения эльфов на среднюю ветку
	void setSettlElfOnMBranch() {
		for (int put_elf = 0; put_elf < getSizeMB(); put_elf++) {
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
	std::string getNameMediumElf(int n) {
		return mediumBranchs[n].getNameElf();
	}
};