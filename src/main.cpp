#include <iostream>
#include <string>
#include "Wood.h"
#include "Functions.h"


int main() {
	Wood woods[5];
	const int SIZE_WOOD = 5;
	std::string name;
	setlocale(LC_ALL, "rus");
	
	//Расселим эльфов
	std::cout << "Идет заселение";
	for (int w = 0; w < SIZE_WOOD; w++) {
		std::cout << ". ";
		woods[w].setListsElfs();
	}
	std::cout << std::endl;

	//Посмотрим на наших эльфов

	for (int w = 0; w < SIZE_WOOD; w++) {
		std::cout << "\nНа дереве " << w + 1 << " проживают: " << std::endl;
		woods[w].getNameElfsLists();
	}

	//Поиск нужного эльфа и его соседей
	std::cout << "Введите имя искомого эльфа: ";
	std::string wanted_elf;
	std::cin >> wanted_elf;

	for (int f_e = 0; f_e < SIZE_WOOD; f_e++) {
		int adress;
		if (woods[5].getFindElf(wanted_elf, adress)) {
			std::cout << "Эльф найден!" << std::endl;
		}
	}
	std::cout << "Эльф тут не проживает!" << std::endl;
	return 0;
}
