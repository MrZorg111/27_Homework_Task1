#include <iostream>
#include <string>
#include "Class.h"

int main() {
	Wood wood[5];
	std::string name;
	setlocale(LC_ALL, "rus");
	std::cout << "Let's start settling the elves!" << std::endl;

	for (int tree = 0; tree < 1; tree++) {
		std::cout << "Заселим " << tree + 1 << " дерево!\n";
		for (int b_branch = 0; b_branch < 1 /* wood[tree].getSizeListsBigBranch()*/; b_branch++) {
			std::cout << "На дереве у нас " << wood[tree].getSizeListsBigBranch() << " больших веток(и)." << std::endl;
			std::cout << "Заселим " << b_branch + 1 << " ветку." << std::endl;
			for (int m_branch = 0; m_branch < 1 /*wood[tree].getBigBranch()->getSizeListsMediumBranch() */ ; m_branch++) {
				std::cout << "На этой большой ветке у нас " << wood[tree].getBigBranch()->getSizeListsMediumBranch() << " средних веток." << std::endl;
				std::cout << "Заcелим " << m_branch + 1 << " ветку(и)." << std::endl;
				for (int house = 0; house < 5; house++) {
					std::cout << "Разместим эльфов по домикам, пустой домик отметим словом none." << std::endl;
					std::cout << house + 1 << " домик из 5." << std::endl;
					wood[tree].getBigBranch()->getMediumBranch()->setSettlementElves();
				}
				wood[tree].getBigBranch()->setAddHouseListsMediumBranch();
			}
			for (int b_house = 0; b_house < 5; b_house++) {
				std::cout << "Заселим нашу большую ветку!" << std::endl;
				std::cout << b_house + 1 << " домик из 5." << std::endl;
				wood[tree].getBigBranch()->setSettlementElves();
			}
			wood[tree].setAddHouseListsBigBranch();
		}
	}
	
	std::cout << "Введите имя эльфа соседей которого нужно найти: " << std::endl;
	std::cin >> name;
	for (int find = 0; find < 1; find++) {
		wood[find].getElfFinderOnBigBranch(name);
	}
	
	return 0;
}