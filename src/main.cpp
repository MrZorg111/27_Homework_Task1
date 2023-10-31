#include <iostream>
#include <string>
#include "Wood.h"
#include "Functions.h"


int main() {
	Wood woods[5];
	const int SIZE_WOOD = 5;
	std::string name;
	setlocale(LC_ALL, "rus");
	
	//�������� ������
	std::cout << "���� ���������";
	for (int w = 0; w < SIZE_WOOD; w++) {
		std::cout << ". ";
		woods[w].setListsElfs();
	}
	std::cout << std::endl;

	//��������� �� ����� ������

	for (int w = 0; w < SIZE_WOOD; w++) {
		std::cout << "\n�� ������ " << w + 1 << " ���������: " << std::endl;
		woods[w].getNameElfsLists();
	}

	//����� ������� ����� � ��� �������
	std::cout << "������� ��� �������� �����: ";
	std::string wanted_elf;
	std::cin >> wanted_elf;

	for (int f_e = 0; f_e < SIZE_WOOD; f_e++) {
		int adress;
		if (woods[5].getFindElf(wanted_elf, adress)) {
			std::cout << "���� ������!" << std::endl;
		}
	}
	std::cout << "���� ��� �� ���������!" << std::endl;
	return 0;
}
