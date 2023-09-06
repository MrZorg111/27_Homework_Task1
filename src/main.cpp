#include <iostream>
#include <string>
#include "Wood.h"
#include "Functions.h"


bool check_name(Wood woods[], int size_w, std::string name) {
	for (int w = 0; w < size_w; w++) {
		if (woods[w].getCheckAllBranch(name)) {
			return true;
		}
	}
	return false;
}

int main() {
	Wood woods[2];
	const int SIZE_WOOD = 2;
	std::string name;
	setlocale(LC_ALL, "rus");
	std::cout << "Let's settle our elves in their houses:" << std::endl;

	for (int wood = 0; wood < SIZE_WOOD; wood++) {
		std::cout << "Let's populate our " << wood + 1 << "st tree: " << std::endl;
		std::cout << "On him " << woods[wood].getAllBranch('B') << " large branches." << std::endl;
			
		for (int b_branch = 0; b_branch < woods[wood].getAllBranch('B'); b_branch++) {
			std::cout << "On " << b_branch + 1 << " branch, " << woods[wood].getAllBranch('M') << " medium branchs." << std::endl;
					
			for (int m_branch = 0; m_branch < woods[wood].getAllBranch('M'); m_branch++) {
				std::cout << "Populate " << m_branch + 1 << "st medium branch." << std::endl;
				std::cout << "Total houses " << woods[wood].getAllHause('M') << std::endl;
				std::cout << "Enter the name of the elf: " << std::endl;
				for (int h = 0; h < woods[wood].getAllHause('M'); h++) {
					std::cout << h + 1 << ")";
					std::cin >> name;
					if (!check_name(woods, SIZE_WOOD, name)) {
						woods[wood].setSettlMB(name);
					}
					else {
						std::cout << "This elf is already inhabited!" << std::endl;
						if (h == 0) {
							h = -1;
						}
						else if (h > 0) {
							h -= 1;
						}
 					}
				}
				woods[wood].setMakeLIstMB();
			}
			std::cout << "Let 's populate the big branch itself: " << std::endl;
			std::cout << "Total houses " << woods[wood].getAllHause('B') << std::endl;
			std::cout << "Enter the name of the elf: " << std::endl;
			for (int h = 0; h < woods[wood].getAllHause('B'); h++) {
				std::cout << h + 1 << ")";
				std::cin >> name;
				if (!check_name(woods, SIZE_WOOD, name)) {
					woods[wood].setSettlBB(name);
				}
				else {
					std::cout << "This elf is already inhabited!" << std::endl;
					if (h == 0) {
						h = -1;
					}
					else if (h > 0) {
						h -= 1;
					}
				}
			}
			woods[wood].setMakeListBB();
		}
		std::cout << "\n\n\n";
	}


	std::string name_find_elf;
	std::cout << "Enter the name of the elf whose neighbors you want to find:\n";
	std::cin >> name_find_elf;

	for (int it = 0; it < SIZE_WOOD; it++) {
		if (woods[it].getFindElfOnBigBranch(name_find_elf)) {
			break;
		}
		else if ((it + 1) == SIZE_WOOD) {
			std::cout << "This elf does not live here!" << std::endl;
		}
	}
}
