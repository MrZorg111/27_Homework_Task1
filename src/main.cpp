#include <iostream>
#include <string>
#include "Wood.h"

int main() {
	Wood woods[2];
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
	}

	std::cout << "��������� �� ���������� ����������!" << std::endl;
	for (int info = 0; info < 2; info++) {
		woods[info].getInfoLists();
	}

	return 0;
}
