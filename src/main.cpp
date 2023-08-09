#include <iostream>
#include <string>
#include "Wood.h"

int main() {
	Wood woods[1];
	std::string name;
	setlocale(LC_ALL, "rus");
	std::cout << "Давайте рассеим наших эльфов по домикам:" << std::endl;

	for (int wood = 0; wood < 1; wood++) {
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
	}
	int n = 0;
	std::cout << "Enter name\n";
	std::cin >> name;
	if (woods[0].getFindElfOnBigBranch(name, n)) {
		std::cout << "YAHHO!\n";
	}
	else {
		std::cout << "Very Bad\n";
	}
	
	return 0;
}
