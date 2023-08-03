#pragma once
#include <string>
#include <vector>
#include "BigBranch.h"

class Wood {
	BigBranch bigBranch;
	std::vector<BigBranch> bigBranchs;
	const int VOL_BB = random_size(3, 2);
public:
	//����� ������� � ��������� ������� �����
	void setSettlMB() {
		bigBranch.setSettlElfOnMBranch();
	}
	//����� ��������� ������� �����
	void setSettlBB() {
		bigBranch.setSettlElf();
	}
	//����� ������� � �������� ������ ����� �� ������� ������
	void setMakeLIstMB() {
		bigBranch.setListSettleMBranch();
	}
	//����� �������� ������ ����� �� ������� ������
	void setMakeListBB() {
		bigBranchs.push_back(bigBranch);
		bigBranch.setClear();
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
	//����� ������� � ���������� ������
	void getInfoLists() {
		for (int bb_list = 0; bb_list < bigBranchs[bb_list].getVolumeHouseBBranch(); bb_list++) {
			bigBranchs[bb_list].getListResident();
			bigBranchs[bb_list].getResidentElf();
		}
	}
};