#pragma once
#include <string>
#include <vector>

class Branch {
	std::vector<std::string> elfs_home;
public:
	//������� ��������� ������ � ������
	void setSettlElf() {
		std::string name_elf;
		std::cout << "������� ��� �����: " << std::endl;
		std::cin >> name_elf;
		elfs_home.push_back(name_elf);
	}
	//������� ������� ������ � ���������
	void setClear() {
		elfs_home.clear();
	}
	//������� ������� � ����������� ������
	void getResidentElf() {
		for (int res_elf = 0; res_elf < elfs_home.size(); res_elf++) {
			std::cout << elfs_home[res_elf] << "\t";
		}
		std::cout << std::endl;
	}
};