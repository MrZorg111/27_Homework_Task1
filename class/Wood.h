#pragma once
#include <string>
#include <vector>
#include "BigBranch.h"
#include "Functions.h"

class Wood {
	BigBranch bigBranch;
	std::vector<BigBranch> bigBranchs;
	const int VOL_BB = random_size(3, 2);
public:
	//����� ������� � ��������� ������� �����
	void setSettlMB(std::string name_elf) {
		bigBranch.setSettlElfOnMBranch(name_elf);
	}
	//����� ��������� ������� �����
	void setSettlBB(std::string name_elf) {
		bigBranch.setSettlElf(name_elf);
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
	//����� ������� � ���-�� ����� �� ������
	int getAllHause(char s) {
		return bigBranch.getVolumeAllHouse(s);
	}
	//����� ������� � ����. ���-�� �����
	int getAllBranch(char s) {
		if (s == 'M') {
			return bigBranch.getVolMB();
		}
		else if (s == 'B') {
			return VOL_BB;
		}
		else {
			std::cout << "�� ������ ���� ������! " << std::endl;
			return false;
		}
	}
	//����� ������� � ���������� ����� � ������ ���������
	int getAllVolBranchsRealTime(char s) {
		if (s == 'B') {
			return bigBranchs.size();
		}
		else if (s == 'M') {
			return bigBranch.getVolMBRealTime();
		}
	}
	//����� ������� � ������� ������ �������
	int getAllVolElfs(char s) {
		return bigBranch.getAllElfsHome(s);
	}
	//����� ������������ ������ �� ������ 
	bool getCheckAllBranch(std::string name) {
		if (bigBranchs.size() == 0) {
			if (!bigBranch.getCheckMB(name)) {
				return bigBranch.getCheckBB(name);
			}
			else {
				return true;
			}
		}
		else {
			for (int check_b = 0; check_b < bigBranchs.size(); check_b++) {
				if (!bigBranchs[check_b].getCheckMB(name)) {
					if (!bigBranchs[check_b].getCheckBB(name)) {
						return false;
					}
					else {
						return true;
					}
				}
				else {
					return true;
				}
			}
		}
	}
	//����� ������ ������� ��������� �����
	bool getFindElfOnBigBranch(std::string find_elf, int num_b = 0) {
		if (!bigBranchs[num_b].getFindElfOnMBranch(find_elf)) {
			if (!bigBranchs[num_b].getFindElf(find_elf)) {
				if ((num_b + 1) >= VOL_BB) {
					return false;
				}
				else {
					return getFindElfOnBigBranch(find_elf, num_b += 1);
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