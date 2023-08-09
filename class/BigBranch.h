#pragma once
#include <string>
#include <vector>
#include "MediumBranch.h"
#include "Functions.h"

class BigBranch : public Branch {
	MediumBranch mediumBranch;
	std::vector<MediumBranch> mediumBranchs;
	//����� ����������� ���-�� ������� ����� �� ����� �������
	const int VOL_MB = 1 /*random_size(1, 2)*/ ;
	const int VOL_HOUSE_BBRANCH = 5;
public:
	//����� ��������� ������ �� ������� �����
	void setSettlElfOnMBranch() {
		mediumBranch.setSettlElf(mediumBranch.getVolumeHouseMBranch());
	}
	//����� ���������� ������ ���������� ������� �����
	void setListSettleMBranch() {
		mediumBranchs.push_back(mediumBranch);
		mediumBranch.setClear();
	}
	//����� ������� � ������ �� ������� ������
	bool getFindElfOnMBranch(std::string name_elf, int num_m) {
		if (num_m < mediumBranchs.size()) {
			if (!mediumBranchs[num_m].getFindElf(name_elf)) {
				getFindElfOnMBranch(name_elf, num_m += 1);
			}
			else {
				mediumBranchs[num_m].getFindNeighbourInHome(name_elf);
				return true;
			}
		}
		else {
			return false;
		}
	}
	//����� ������� � ���-�� ����� �� ������� �����
	int getVolumeHouseBBranch() {
		return VOL_HOUSE_BBRANCH;
	}
	//����� ������� � ���-�� ������� ����� �� ���� �������
	int getVolMB() {
		return VOL_MB;
	}
	//����� ������� � ������ ������� ������ ����� �� ������� �����
	void getClearListMB() {
		mediumBranchs.clear();
	}
};