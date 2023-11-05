#include <iostream>
#include <string>
#include "Wood.h"
#include "Functions.h"


int main() {
	Wood woods[5];
	const int SIZE_TREE = 5;
	std::string name;
	setlocale(LC_ALL, "rus");
	
	//�������� ������
	std::cout << "���� ���������";
	for (int w = 0; w < SIZE_TREE; w++) {
		std::cout << ". ";
		woods[w].setListsElfs();
	}
	std::cout << std::endl;

	//��������� �� ����� ������

	for (int view_tree = 0; view_tree < SIZE_TREE; view_tree++) {
		std::cout << "�� ������ ����� " << view_tree + 1 << ", ������� ����� " << woods->getSizeBB() << " �� ������ �� ��� �� " << woods->getSizeMB() << " ������� �����" << std::endl;
		for (int view_bbranch = 0; view_bbranch < woods->getSizeBB(); view_bbranch++) {
			std::cout << "\t�� ������� ����� ����� " << view_bbranch + 1;
			if (woods[view_tree].getNameBigElf(view_bbranch) == "None") {
				std::cout << " ����� �� ���������! " << std::endl;
				}
			else {
				std::cout << " ��������� " << woods[view_tree].getNameBigElf(view_bbranch) << std::endl;
			}
			for (int view_mbranch = 0; view_mbranch < woods->getSizeMB(); view_mbranch++) {
				std::cout << "\t\t--�� ������� ����� ����� " << view_mbranch + 1;
				if (woods[view_tree].getNameMediumElf(view_bbranch, view_mbranch) == "None") {
					std::cout << " ����� �� ���������!" << std::endl;
				}
				else {
					std::cout << " ��������� " << woods[view_tree].getNameMediumElf(view_bbranch, view_mbranch) << std::endl;
				}
			}
		}
		std::cout << "\n\n";
	}

	//����� ������� ����� � ��� �������
	std::cout << "������� ��� �������� �����: ";
	std::string wanted_elf;
	std::cin >> wanted_elf;
	
	for (int w_elf = 0; w_elf < SIZE_TREE; w_elf++) {
		for (int w_bigelf = 0; w_bigelf < woods->getSizeBB(); w_bigelf++) {
			if (woods[w_elf].getNameBigElf(w_bigelf) == wanted_elf) {
				std::cout << "������� ���� ��������� �� ������: " << std::endl;
				std::cout << "������ ����� " << w_elf + 1 << ", ������� ����� ����� " << w_bigelf + 1 << std::endl;
				std::cout << "� ��� �� � ���� ���� ������: " << std::endl;
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
						std::cout << "������� ���� ��������� �� ������: " << std::endl;
						std::cout << "������ ����� " << w_elf + 1 << ", ������� ����� ����� " << w_bigelf + 1 << ", ������� ����� ����� " << w_medelf + 1 << std::endl;
						std::cout << "� ��� �� � ���� ���� ������: " << std::endl;
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
			std::cout << "������� ���� ����� �� ���������!" << std::endl;
		}
	}

	return 0;
}
