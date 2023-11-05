#pragma once
#include <string>
#include <vector>
#include "Branch.h"
#include "BigBranch.h"
#include "Functions.h"

class Wood : public Branch{
	BigBranch bigBranch;
	std::vector<BigBranch> bigBranchs;
	
	
public:
	
	void setListsElfs() {
		for (int bb = 0; bb < getSizeBB(); bb++) {
			bigBranch.setNameElf();
			bigBranch.setSettlElfOnMBranch();
			bigBranchs.push_back(bigBranch);
			bigBranch.setClear();
		}
	}

	//_____________________________________________________________//

	std::string getNameBigElf(int n) {
		return bigBranchs[n].getNameBigElf();
	}
	std::string getNameMediumElf(int n, int b) {
		return bigBranchs[n].getNameMediumElf(b);
	}
	
};

