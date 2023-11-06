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

	//The method of settling an elf on a large branch
	void setNameElf() {
		name_elf = generation_names();
	}
	//The method of settling elves on the middle branch
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

	//Methods of transmitting the names of settled elves
	std::string getNameBigElf() {
		return name_elf;
	}
	std::string getNameMediumElf(int n) {
		return mediumBranchs[n].getNameElf();
	}
};