#include <iostream>
#include <string>
#include "Class.h"

int main() {
	Wood wood[5];
	std::string name;
	setlocale(LC_ALL, "rus");
	std::cout << "Let's start settling the elves!" << std::endl;

	for (int tree = 0; tree < 1; tree++) {
		std::cout << "������� " << tree + 1 << " ������!\n";
		for (int b_branch = 0; b_branch < 1 /* wood[tree].getSizeListsBigBranch()*/; b_branch++) {
			std::cout << "�� ������ � ��� " << wood[tree].getSizeListsBigBranch() << " ������� �����(�)." << std::endl;
			std::cout << "������� " << b_branch + 1 << " �����." << std::endl;
			for (int m_branch = 0; m_branch < 1 /*wood[tree].getBigBranch()->getSizeListsMediumBranch() */ ; m_branch++) {
				std::cout << "�� ���� ������� ����� � ��� " << wood[tree].getBigBranch()->getSizeListsMediumBranch() << " ������� �����." << std::endl;
				std::cout << "��c���� " << m_branch + 1 << " �����(�)." << std::endl;
				for (int house = 0; house < 5; house++) {
					std::cout << "��������� ������ �� �������, ������ ����� ������� ������ none." << std::endl;
					std::cout << house + 1 << " ����� �� 5." << std::endl;
					wood[tree].getBigBranch()->getMediumBranch()->setSettlementElves();
				}
				wood[tree].getBigBranch()->setAddHouseListsMediumBranch();
			}
			for (int b_house = 0; b_house < 5; b_house++) {
				std::cout << "������� ���� ������� �����!" << std::endl;
				std::cout << b_house + 1 << " ����� �� 5." << std::endl;
				wood[tree].getBigBranch()->setSettlementElves();
			}
			wood[tree].setAddHouseListsBigBranch();
		}
	}
	
	std::cout << "������� ��� ����� ������� �������� ����� �����: " << std::endl;
	std::cin >> name;
	for (int find = 0; find < 1; find++) {
		wood[find].getElfFinderOnBigBranch(name);
	}
	
	return 0;
}