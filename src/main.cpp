#include <iostream>
#include <string>
#include "Class.h"

int main() {
	Wood wood[5];
	std::string name;

	std::cout << "Let's start settling the elves!" << std::endl;

	for (int tree = 0; tree < 1; tree++) {
		for (int b_branch = 0; b_branch < 1 /*wood[tree].getSizeListsBigBranch()*/; b_branch++) {
			for (int m_branch = 0; m_branch < 1 /*wood[tree].getBigBranch()->getSizeListsMediumBranch()*/; m_branch++) {
				for (int house = 0; house < 5; house++) {
					wood[tree].getBigBranch()->getMediumBranch()->setSettlementElves();
				}
				wood[tree].getBigBranch()->setAddHouseListsMediumBranch();
			}
			for (int b_house = 0; b_house < 5; b_house++) {
				wood[tree].getBigBranch()->setSettlementElves();
			}
			wood[tree].setAddHouseListsBigBranch();
		}
	}
	wood[0].getBigBranch()->getListHouseMediumBranch(0);
	wood[0].getListHouseBigBranch(0);

	
	return 0;
}