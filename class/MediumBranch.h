#pragma once
#include <string>
#include "Functions.h"

class MediumBranch {
	std::string name_elf;
public:

	void setNameElf() {
		name_elf = generation_names();
	}

	std::string getNameElf() {
		return name_elf;
	}
};