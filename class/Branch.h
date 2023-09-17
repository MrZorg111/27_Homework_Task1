#pragma once
#include <string>
#include <vector>
#include "Functions.h"

class Branch {
	std::vector<std::string> elfs_home;
public:
	//����� ��������� ������ � ������
	void setSettlElf() {
		elfs_home.push_back(generation_names());
	}
	//����� ������� ������ � ���������
	void setClear() {
		elfs_home.clear();
	}	
	//����� ������� � ����������� ������ 
	void getElfs() {
		for (int elf = 0; elf < elfs_home.size(); elf++) {
			std::cout << elfs_home[elf] << " ";
		}
	}
	//����� ������ �� �����
	bool getFindElf(std::string wanted, int& neighbour) {
		for (int want = 0; want < elfs_home.size(); want++) {
			if (wanted == elfs_home[want]) {
				for (int neig = 0; neig < elfs_home.size(); neig++) {
					if (elfs_home[neig] != "None" && elfs_home[neig] != wanted) {
						neighbour += 1;
					}
				}
				return true;
			}
		}
		return false;
	}
};