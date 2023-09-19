#include <iostream>
#include <string>
#include "Wood.h"
#include "Functions.h"


int main() {
	Wood woods[5];
	const int SIZE_WOOD = 5;
	std::string name;
	setlocale(LC_ALL, "rus");
	std::cout << "Check-in is underway ";
	for (int w = 0; w < SIZE_WOOD; w++) {
		std::cout << ". ";
		woods[w].setSettlBB();
	}

	std::cout << "\nLet's look at our elves!" << std::endl;

	for (int tree = 0; tree < SIZE_WOOD; tree++) {
		std::cout << "Tree " << tree + 1 << std::endl;
		woods[tree].getAllElfs();
		std::cout << std::endl;
	}

	std::cout << "\nLet's look for our elf:" << std::endl;
	int adress_mb = 0, adress_bb = 0, neighbour = 0;
	std::string wanted;
	std::cin >> wanted;

	for (int tree = 0; tree < SIZE_WOOD; tree++) {
		if (woods[tree].getAllFind(wanted, adress_mb, adress_bb, neighbour)) {
			std::cout << "Our Elf lives here!" << std::endl;
			std::cout << "At address: " << std::endl;
			if (adress_mb > 0) {
				std::cout << "Medium branch ¹" << adress_mb << " on big branch ¹ " << adress_bb << " on tree ¹ " << tree + 1 << std::endl;
				std::cout << "And has " << neighbour << " neighbors(her)!";
				break;
			}
			else {
				std::cout << "Big branch ¹ " << adress_bb << " on tree ¹ " << tree + 1 << std::endl;
				std::cout << "And has " << neighbour << " neighbors(her)!";
				break;
			}
		}
		if (tree == SIZE_WOOD - 1) {
			std::cout << "Our elf doesn't live here!" << std::endl;
		}
	}
	return 0;
}
