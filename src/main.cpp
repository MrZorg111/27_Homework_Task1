#include <iostream>
#include <string>
#include "Wood.h"
#include "Functions.h"


int main() {
	Wood woods[5];
	const int SIZE_TREE = 5;
	std::string name;
	setlocale(LC_ALL, "rus");
	
	//Расселим эльфов
	std::cout << "Идет заселение";
	for (int w = 0; w < SIZE_TREE; w++) {
		std::cout << ". ";
		woods[w].setListsElfs();
	}
	std::cout << std::endl;

	//Посмотрим на наших эльфов

	for (int view_tree = 0; view_tree < SIZE_TREE; view_tree++) {
		std::cout << "На дереве номер " << view_tree + 1 << ", больших веток " << woods->getSizeBB() << " на кождой из них по " << woods->getSizeMB() << " средних веток" << std::endl;
		for (int view_bbranch = 0; view_bbranch < woods->getSizeBB(); view_bbranch++) {
			std::cout << "\tНа большой ветке номер " << view_bbranch + 1;
			if (woods[view_tree].getNameBigElf(view_bbranch) == "None") {
				std::cout << " никто не проживает! " << std::endl;
				}
			else {
				std::cout << " проживает " << woods[view_tree].getNameBigElf(view_bbranch) << std::endl;
			}
			for (int view_mbranch = 0; view_mbranch < woods->getSizeMB(); view_mbranch++) {
				std::cout << "\t\t--На средней ветке номер " << view_mbranch + 1;
				if (woods[view_tree].getNameMediumElf(view_bbranch, view_mbranch) == "None") {
					std::cout << " никто не проживает!" << std::endl;
				}
				else {
					std::cout << " проживает " << woods[view_tree].getNameMediumElf(view_bbranch, view_mbranch) << std::endl;
				}
			}
		}
		std::cout << "\n\n";
	}

	//Поиск нужного эльфа и его соседей
	std::cout << "Введите имя искомого эльфа: ";
	std::string wanted_elf;
	std::cin >> wanted_elf;
	
	for (int w_elf = 0; w_elf < SIZE_TREE; w_elf++) {
		for (int w_bigelf = 0; w_bigelf < woods->getSizeBB(); w_bigelf++) {
			if (woods[w_elf].getNameBigElf(w_bigelf) == wanted_elf) {
				std::cout << "Искомый эльф проживает по адресу: " << std::endl;
				std::cout << "Дерево номер " << w_elf + 1 << ", большая ветка номер " << w_bigelf + 1 << std::endl;
				std::cout << "А так же у него есть соседи: " << std::endl;
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
						std::cout << "Искомый эльф проживает по адресу: " << std::endl;
						std::cout << "Дерево номер " << w_elf + 1 << ", большая ветка номер " << w_bigelf + 1 << ", средняя ветка номер " << w_medelf + 1 << std::endl;
						std::cout << "А так же у него есть соседи: " << std::endl;
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
			std::cout << "Искомый эльф здесь не проживает!" << std::endl;
		}
	}

	return 0;
}
