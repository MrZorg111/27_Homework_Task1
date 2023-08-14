#include <iostream>
#include <string>
#include "Wood.h"

int main() {
	Wood woods[2];
	const int SIZE_WOOD = 2;
	std::string name;
	setlocale(LC_ALL, "rus");
	std::cout << "Давайте рассеим наших эльфов по домикам:" << std::endl;

	for (int wood = 0; wood < 2; wood++) {
		std::cout << "Заселим наше " << wood + 1 << "е дерево: " << std::endl;
		std::cout << "На нем " << woods[wood].getVolBB() << " больших веток(и)." << std::endl;
			
		for (int b_branch = 0; b_branch < woods[wood].getVolBB(); b_branch++) {
			std::cout << "На " << b_branch + 1 << " ветке, " << woods[wood].getVolMB() << " средних веток." << std::endl;
					
			for (int m_branch = 0; m_branch < woods[wood].getVolMB(); m_branch++) {
				std::cout << "Заселим " << m_branch + 1 << " среднюю ветку.";
				woods[wood].setSettlMB();
				woods[wood].setMakeLIstMB();
			}
			std::cout << "Заселим саму большую ветку: " << std::endl;
			woods[wood].setSettlBB();
			woods[wood].setMakeListBB();
		}
		std::cout << "\n\n\n";
	}


	std::string name_find_elf;
	std::cout << "Введите имя эьфа, соседей которого нужно найти:\n";
	std::cin >> name_find_elf;

	for (int it = 0; it < SIZE_WOOD; it++) {
		if (woods[it].getFindElfOnBigBranch(name_find_elf)) {
			break;
		}
		else if ((it + 1) == SIZE_WOOD) {
			std::cout << "Данный эльф здесь не проживает!" << std::endl;
		}
	}
}
