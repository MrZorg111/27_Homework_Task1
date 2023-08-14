#include <iostream>
#include <string>
#include "Wood.h"

int main() {
	Wood woods[2];
	const int SIZE_WOOD = 2;
	std::string name;
	setlocale(LC_ALL, "rus");
	std::cout << "������� ������� ����� ������ �� �������:" << std::endl;

	for (int wood = 0; wood < 2; wood++) {
		std::cout << "������� ���� " << wood + 1 << "� ������: " << std::endl;
		std::cout << "�� ��� " << woods[wood].getVolBB() << " ������� �����(�)." << std::endl;
			
		for (int b_branch = 0; b_branch < woods[wood].getVolBB(); b_branch++) {
			std::cout << "�� " << b_branch + 1 << " �����, " << woods[wood].getVolMB() << " ������� �����." << std::endl;
					
			for (int m_branch = 0; m_branch < woods[wood].getVolMB(); m_branch++) {
				std::cout << "������� " << m_branch + 1 << " ������� �����.";
				woods[wood].setSettlMB();
				woods[wood].setMakeLIstMB();
			}
			std::cout << "������� ���� ������� �����: " << std::endl;
			woods[wood].setSettlBB();
			woods[wood].setMakeListBB();
		}
		std::cout << "\n\n\n";
	}


	std::string name_find_elf;
	std::cout << "������� ��� ����, ������� �������� ����� �����:\n";
	std::cin >> name_find_elf;

	for (int it = 0; it < SIZE_WOOD; it++) {
		if (woods[it].getFindElfOnBigBranch(name_find_elf)) {
			break;
		}
		else if ((it + 1) == SIZE_WOOD) {
			std::cout << "������ ���� ����� �� ���������!" << std::endl;
		}
	}
}
