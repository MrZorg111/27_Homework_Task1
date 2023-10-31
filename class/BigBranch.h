#pragma once
#include <string>
#include <vector>
#include "MediumBranch.h"
#include "Functions.h"

class BigBranch {
	std::string name_elf;
	MediumBranch mediumBranch;
	std::vector<MediumBranch> mediumBranchs;
	//����� ����������� ���-�� ������� ����� �� ����� �������
	const int VOL_MB = random_size(2, 2);

public:

	//����� ��������� ����� �� ������� �����
	void setNameElf() {
		name_elf = generation_names();
	}
	//����� ��������� ������ �� ������� �����
	void setSettlElfOnMBranch() {
		for (int put_elf = 0; put_elf < VOL_MB; put_elf++) {
			mediumBranch.setNameElf();
			mediumBranchs.push_back(mediumBranch);
		}
	}
	void setClear() {
		mediumBranchs.clear();
	}
	//___________________________________________________//

	std::string getNameBigElf() {
		return name_elf;
	}
	void getNameMediumElfs() {
		for (int e_n = 0; e_n < VOL_MB; e_n++) {
			std::cout << "\t\t--�� ������� ����� ����� " << e_n + 1;
			if (mediumBranchs[e_n].getNameElf() == "None") {
				std::cout << " ����� �� ���������!" << std::endl;
			}
			else {
				std::cout << " ��������� " << mediumBranchs[e_n].getNameElf() << std::endl;
			}
			
		}
	}
	bool getFindElf(std::string wanted_elf) {
		for (int want_e = 0; want_e < VOL_MB; want_e++) {
			if (mediumBranchs[want_e].getNameElf() == wanted_elf) {
				return true;
			}
		}
		return false;
	}
};