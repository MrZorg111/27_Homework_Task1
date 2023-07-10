#pragma once
#include <ctime>
#include <string>
#include <vector>

class Branch {
    //����������� ���� 
    std::string elfs_home;
public:
    //����� ���������� ������������ ����
    void setSettlementElves() {
        std::string name;
        std::cout << "Enter elf name: " << std::endl;
        std::cin >> name;
       this -> elfs_home = name;
    }
    // ����� ������� � ����������� ������
    std::string getResidentElf() {
        return elfs_home;
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
    //����� ������� � ������ ����� �� �����
    std::vector<MediumBranch*> getListHouseMediumBranch() {
        return mediumBranchs;
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
    std::vector<BigBranch*> getListHouseBigBranch() {
        return bigBranchs;
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




