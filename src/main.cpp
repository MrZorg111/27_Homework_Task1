#include <iostream>
#include <string>
#include "Wood.h"
#include "Functions.h"


int main() {
	Wood woods[5];
	const int SIZE_TREE = 5;
	std::string name;
	
	//Settle the elves
	std::cout << "Check-in is underway";
	for (int w = 0; w < SIZE_TREE; w++) {
		std::cout << ". ";
		woods[w].setListsElfs();
	}
	std::cout << std::endl;

	//Let's look at our elves

	for (int view_tree = 0; view_tree < SIZE_TREE; view_tree++) {
		std::cout << "On the tree number " << view_tree + 1 << ", large branches " << woods->getSizeBB() << " on each of them on " << woods->getSizeMB() << " medium branches" << std::endl;
		for (int view_bbranch = 0; view_bbranch < woods->getSizeBB(); view_bbranch++) {
			std::cout << "\tOn the big branch number " << view_bbranch + 1;
			if (woods[view_tree].getNameBigElf(view_bbranch) == "None") {
				std::cout << " no one lives! " << std::endl;
				}
			else {
				std::cout << " lives " << woods[view_tree].getNameBigElf(view_bbranch) << std::endl;
			}
			for (int view_mbranch = 0; view_mbranch < woods->getSizeMB(); view_mbranch++) {
				std::cout << "\t\t--On the middle branch number " << view_mbranch + 1;
				if (woods[view_tree].getNameMediumElf(view_bbranch, view_mbranch) == "None") {
					std::cout << " no one lives!" << std::endl;
				}
				else {
					std::cout << " lives " << woods[view_tree].getNameMediumElf(view_bbranch, view_mbranch) << std::endl;
				}
			}
		}
		std::cout << "\n\n";
	}

	//Search for the right elf and his neighbors
	std::cout << "Enter the name of the elf you are looking for: ";
	std::string wanted_elf;
	std::cin >> wanted_elf;
	
	for (int w_elf = 0; w_elf < SIZE_TREE; w_elf++) {
		for (int w_bigelf = 0; w_bigelf < woods->getSizeBB(); w_bigelf++) {
			if (woods[w_elf].getNameBigElf(w_bigelf) == wanted_elf) {
				std::cout << "The sought elf lives at: " << std::endl;
				std::cout << "Tree number " << w_elf + 1 << ", big branch number " << w_bigelf + 1 << std::endl;
				std::cout << "And he also has neighbors: " << std::endl;
				for (int nieg= 0; nieg < woods->getSizeMB(); nieg++) {
					if (woods[w_elf].getNameMediumElf(w_bigelf, nieg) != "None") {
						std::cout << "\t--" << woods[w_elf].getNameMediumElf(w_bigelf, nieg) << std::endl;
					}
				}
				return 0;
			}
			else {
				for (int w_medelf = 0; w_medelf < woods->getSizeMB(); w_medelf++) {
					if (woods[w_elf].getNameMediumElf(w_bigelf, w_medelf) == wanted_elf) {
						std::cout << "The sought elf lives at: " << std::endl;
						std::cout << "Tree number " << w_elf + 1 << ", big branch number " << w_bigelf + 1 << ", middle branch number " << w_medelf + 1 << std::endl;
						std::cout << "And he also has neighbors: " << std::endl;
						if (woods[w_elf].getNameBigElf(w_bigelf) != "None") {
							std::cout << "\t--" << woods[w_elf].getNameBigElf(w_bigelf) << std::endl;
						}
						for (int neig = 0; neig < woods->getSizeMB(); neig++) {
							if (woods[w_elf].getNameMediumElf(w_bigelf, neig) != "None" && woods[w_elf].getNameMediumElf(w_bigelf, neig) != wanted_elf) {
								std::cout << "\t--" << woods[w_elf].getNameMediumElf(w_bigelf, neig) << std::endl;
							}
						}
						return 0;
					}
				}
			}
		}
		if (w_elf == SIZE_TREE - 1) {
			std::cout << "The desired elf does not live here!" << std::endl;
		}
	}

	return 0;
}
