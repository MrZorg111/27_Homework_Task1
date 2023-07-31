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
	void setSettlElfOnMBranch() {
		mediumBranch.setSettlElf();
	}
	//����� ���������� ������ ���������� ������� �����
	void setListSettleMBranch() {
		mediumBranchs.push_back(mediumBranch);
		mediumBranch.setClear();
	}
	//����� ������� � ������ �� ������� �����
	void getResidendElfOnMBranch() {
		mediumBranch.getResidentElf();
	}
	//����� ������� � ���-�� ����� �� ������� �����
	int getVolumeHouseBBranch() {
		return VOL_HOUSE_BBRANCH;
	}
	//����� ������� � ������ ���������� ������� �����
	void getListResident() {
		for (int res_branch = 0; res_branch < mediumBranchs.size(); res_branch++) {
			mediumBranchs[res_branch].getResidentElf();
		}
	}
	// ����� ������� � ����� ������
	MediumBranch getHouseMB() {
		return mediumBranch;
	}
	//����� ������� � ���-�� ������� ����� �� ���� �������
	int getVolMB() {
		return VOL_MB;
	}
};