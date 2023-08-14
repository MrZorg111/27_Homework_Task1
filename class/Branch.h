#pragma once
#include <string>
#include <vector>

class Branch {
	std::vector<std::string> elfs_home;
public:
	//������� ��������� ������ � ������
	void setSettlElf(int max_house) {
		std::string name_elf;
		std::cout << "����� ������� " << max_house << std::endl;
		std::cout << "������� ��� �����: " << std::endl;
		for (int h = 0; h < max_house; h++) {
			std::cout << h + 1 << ")";
			std::cin >> name_elf;
			elfs_home.push_back(name_elf);
		}
	}
	//������� ������� ������ � ���������
	void setClear() {
		elfs_home.clear();
	}
	//������� ������ ������� ��������� �����
	bool getFindElf(std::string find_elf) {
		for (int find = 0; find < elfs_home.size(); find++) {
			if (find_elf == elfs_home[find]) {
				return true;
			}
		}
		return false;
	}
	//������� ��� ������ ������� �������� �����
	void getFindNeighbourInHome(std::string find_elf) {
		std::cout << "������ �������� �����: ";
		for (int find_neigh = 0; find_neigh < elfs_home.size(); find_neigh++) {
			if (elfs_home[find_neigh] != find_elf && elfs_home[find_neigh] != "none") {
				std::cout << elfs_home[find_neigh] << ", ";
			}
		}
	}
};