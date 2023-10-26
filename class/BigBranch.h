#pragma once
#include <string>
#include <vector>
#include "MediumBranch.h"
#include "Functions.h"

class BigBranch {
	MediumBranch mediumBranch;
	std::vector<MediumBranch> mediumBranchs;
	//����� ����������� ���-�� ������� ����� �� ����� �������
	const int VOL_MB = random_size(2, 2);

public:

	//����� ��������� ������ �� ������� �����
	void setSettlElfOnMBranch() {
		for (int put_elf = 0; put_elf < VOL_MB; put_elf++) {
			mediumBranch.setNameElf();
			mediumBranchs.push_back(mediumBranch);
		}
	}
	//����� ������� ������ ������� �����
	void SetClearMBranchs() {
		mediumBranchs.clear();
	}


	//����� ������� � ���-�� ������� �� ������� �����
	int getVolHouseBBranch() {
		return VOL_HOUSE_BBRANCH;
	}
	//����� ������� � ������ ������� �� ������� ������
	void getListMBranch() {
		for (int list_mb = 0; list_mb < mediumBranchs.size(); list_mb++) {
			std::cout << "Middle branch " << list_mb + 1 << " ";
			mediumBranchs[list_mb].getElfs();
			std::cout << std::endl;
		}
	}
	//����� ������ ������ �� ���� ������
	bool getFindAllBranch(std::string wanted, int& adress_mb, int& neighbour) {
		for (int want_ab = 0; want_ab < mediumBranchs.size(); want_ab++) {
			if (mediumBranchs[want_ab].getFindElf(wanted, neighbour)) {
				adress_mb = want_ab + 1;
				return true;
			}
		}
		if (getFindElf(wanted, neighbour)) {
			return true;
		}
		return false;
	}
};