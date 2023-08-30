#pragma once
#include <string>
#include <vector>
#include "MediumBranch.h"
#include "Functions.h"

class BigBranch : public Branch {
	MediumBranch mediumBranch;
	std::vector<MediumBranch> mediumBranchs;
	//����� ����������� ���-�� ������� ����� �� ����� �������
	const int VOL_MB = random_size(1, 2);
	const int VOL_HOUSE_BBRANCH = 5;
public:
	//����� ��������� ������ �� ������� �����
	void setSettlElfOnMBranch(std::string name_elf) {
		mediumBranch.setSettlElf(name_elf);
	}
	//����� ���������� ������ ���������� ������� �����
	void setListSettleMBranch() {
		mediumBranchs.push_back(mediumBranch);
		mediumBranch.setClear();
	}


	//����� ������� � ���������� ����� �� ������
	int getVolumeAllHouse(char s) {
		if (s == 'B') {
			return VOL_HOUSE_BBRANCH;
		}
		else if (s == 'M') {
			return mediumBranch.getVolumeHouseMBranch();
		}
		else {
			std::cout << "�������� ����!" << std::endl;
		}
	}
	//����� ������� � ������� ������ �������
	int getAllElfsHome(char s) {
		if (s == 'B') {
			return getVolElfs();
		}
		else if (s == 'M') {
			return mediumBranch.getVolElfs();
		}
		else {
			std::cout << "�������� ���� ������!";
		}
	}
	//����� ������� � ���-�� ������� ����� �� ���� �������
	int getVolMB() {
		return VOL_MB;
	}
	//����� ������� � ���������� ����� � ������ ���������
	int getVolMBRealTime() {
		return mediumBranchs.size();
	}
	//����� �������� �� ������� �����
	bool getCheckBB(std::string name) {
		return getFindElf(name);
	}
	//����� �������� �� ������� �����
	bool getCheckMB(std::string name) {
		if (mediumBranchs.size() == 0) {
			return mediumBranch.getCheckMB(name);
		}
		for (int check_m = 0; check_m < mediumBranchs.size(); check_m++) {
			if (mediumBranchs[check_m].getCheckMB(name)) {
				return true;
			}
		}
		return false;
	}
	//����� ������� � ������� ������� ������ ����� �� ������� �����
	void getClearListMB() {
		mediumBranchs.clear();
	}
	//����� ������� � ������ �� ������� ������
	bool getFindElfOnMBranch(std::string name_elf, int num_m = 0) {
		if (!mediumBranchs[num_m].getFindElf(name_elf)) {
			if ((num_m + 1) >= VOL_MB) {
				return false;
			}
			else {
				return getFindElfOnMBranch(name_elf, num_m += 1);
			}
		}
		else {
			mediumBranchs[num_m].getFindNeighbourInHome(name_elf);
			return true;
		}
	}
};