#pragma once
#include <ctime>
#include <string>
#include <vector>

class Branch {
    //����������� ���� 
    std::vector<std::string> elfs_home;
public:
    //����� ���������� ������������ ����
    void setSettlementElves() {
        std::string name;
        std::cout << "Enter elf name: " << std::endl;
        std::cin >> name;
        elfs_home.push_back(name);
    }
    // ����� ������� � ����������� ������
    void getResidentElf() {
        for (int i = 0; i < elfs_home.size(); i++) {
            std::cout << elfs_home[i] << std::endl;
        }
    }
    //������� ��������� ������������� �������
    int random_size(int max, int step) {
        std::srand(std::time(nullptr));
        return rand() % max + step;
    }
};

class MediumBranch: public Branch {
    //������ ����� ��������� ���� elfs_home
public:
    //������ ���� ��������� ����� ������ ������ � ����� elfs_home
};

class BigBranch: public Branch {
    //������ ����� ��������� ���� elfs_home � ��� ������ ������ � ���
    //������������� ������ MediumBranch
    MediumBranch* mediumBranch = new MediumBranch();
    const int SIZE = random_size(3, 3);
    //�������� ������� ������� MediumBranch
    std::vector<MediumBranch*> mediumBranchs;
public:
   //����� ��������� ������ ����� �� �����
    void setAddHouseListsMediumBranch() {
        mediumBranchs.push_back(mediumBranch);
    }
    //����� ������� � ������� ������ ����� �� �����
    int getSizeListsMediumBranch() {
        return SIZE;
    }
    //����� ������� � ������ ����� �� �����
    void getListHouseMediumBranch(int num_house) {
        mediumBranchs[num_house]->getResidentElf();
    }
    //����� ������� � ������ MediumBranch
    MediumBranch* getMediumBranch() {
        return mediumBranch;
    }
    void setDeleteClassMediumBranch() {
        delete mediumBranch;
        mediumBranch = nullptr;
    }
};

class Wood: public Branch {
    //������������� ������ MediumBranch
    BigBranch* bigBranch = new BigBranch();
    const int SIZE = random_size(1, 2);
    //�������� ������� ������� BigBranch
    std::vector<BigBranch*> bigBranchs;
public:
    //����� ��������� ������ ����� �� �����
    void setAddHouseListsBigBranch() {
        bigBranchs.push_back(bigBranch);
    }
    //����� ������� � ������ ����� �� �����
    void getListHouseBigBranch(int num_house) {
        bigBranchs[num_house]->getResidentElf();
    }
    //����� ������� � ������� ������ ����� �� �����
    int getSizeListsBigBranch() {
        return SIZE;
    }
    //����� ������� � ������ BigBranch
    BigBranch* getBigBranch() {
        return bigBranch;
    }
    void setDeleteClassBigBranch() {
        delete bigBranch;
        bigBranch = nullptr;
    }
};




