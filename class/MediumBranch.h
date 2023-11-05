#pragma once
#include <string>
#include "Branch.h"
#include "Functions.h"

class MediumBranch {
	std::string name_elf;
public:

	void setNameElf() {
		name_elf = generation_names();
	}

	//_________________________________________________________//

	std::string getNameElf() {
		return name_elf;
	}
};