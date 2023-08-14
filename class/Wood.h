#pragma once
#include <string>
#include <vector>
#include "BigBranch.h"
#include "Functions.h"

class Wood {
	BigBranch bigBranch;
	std::vector<BigBranch> bigBranchs;
	const int VOL_BB = 1 /*random_size(3, 2)*/;
public:
	//����� ������� � ��������� ������� �����
	void setSettlMB() {
		bigBranch.setSettlElfOnMBranch();
	}
	//����� ��������� ������� �����
	void setSettlBB() {
		bigBranch.setSettlElf(bigBranch.getVolumeHouseBBranch());
	}
	//����� ������� � �������� ������ ����� �� ������� ������
	void setMakeLIstMB() {
		bigBranch.setListSettleMBranch();
	}
	//����� �������� ������ ����� �� ������� ������
	void setMakeListBB() {
		bigBranchs.push_back(bigBranch);
		bigBranch.setClear();
		bigBranch.getClearListMB();
	}
	/*------------------------------------------------------*/
	//����� ������� � ���-�� ������� �����
	int getVolMB() {
		return bigBranch.getVolMB();
	}
	//����� ������� � ���-�� ������� �����
	int getVolBB() {
		return VOL_BB;
	}
	//����� ������ ������� ��������� �����
	bool getFindElfOnBigBranch(std::string find_elf, int num_b = 0) {
		if (!bigBranchs[num_b].getFindElfOnMBranch(find_elf)) {
			if (!bigBranchs[num_b].getFindElf(find_elf)) {
				if ((num_b + 1) >= VOL_BB) {
					return false;
				}
				else {
					getFindElfOnBigBranch(find_elf, num_b += 1);
				}
			}
			else {
				bigBranchs[num_b].getFindNeighbourInHome(find_elf);
				return true;
			}
		}
		else {
			return true;
		}
	}
};