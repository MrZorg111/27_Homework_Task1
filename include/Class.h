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
    std::string getResidentElf() {
        for (int i = 0; i < elfs_home.size(); i++) {
            return elfs_home[i];
        }
    }
    //����� ��������� ������������� �������
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
    const int SIZE = random_size(1, 2);
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
    std::string getListHouseMediumBranch(int num_house) {
        return mediumBranchs[num_house]->getResidentElf();
    }
    //����� ������� � ������ MediumBranch
    MediumBranch* getMediumBranch() {
        return mediumBranch;
    }
    //����� ������
    void getElfFinderOnMediumBranch(std::string name) {
        for (int f = 0; f < 5; f++) {
            if (name == getListHouseMediumBranch(f)) {
                for (int r = 0; r < 5; r++) {
                    if (getListHouseMediumBranch(r) != name && getListHouseMediumBranch(r) != "none") {
                        std::cout << getListHouseMediumBranch(r) << std::endl;
                        return;
                    }
                }
            }
        }
        std::cout << "An elf with that name doesn't live here!" << std::endl;
    }
    //����� ����
    //����� ��������� ������
    void setDeleteClassMediumBranch() {
        delete mediumBranch;
        mediumBranch = nullptr;
    }
};

class Wood: public Branch {
    //������������� ������ MediumBranch
    BigBranch* bigBranch = new BigBranch();
    const int SIZE = random_size(3, 3);
    //�������� ������� ������� BigBranch
    std::vector<BigBranch*> bigBranchs;
public:
    //����� ��������� ������ ����� �� �����
    void setAddHouseListsBigBranch() {
        bigBranchs.push_back(bigBranch);
    }
    //����� ������� � ������ ����� �� �����
    std::string getListHouseBigBranch(int num_house) {
        return bigBranchs[num_house]->getResidentElf();
    }
    //����� ������� � ������� ������ ����� �� �����
    int getSizeListsBigBranch() {
        return SIZE;
    }
    //����� ������� � ������ BigBranch
    BigBranch* getBigBranch() {
        return bigBranch;
    }
    //����� ������
    void getElfFinderOnBigBranch(std::string name) {
        for (int f = 0; f < 5; f++) {
            std::cout << "NAME " << name << std::endl;
            if (name == getListHouseBigBranch(f)) {
                std::cout << "��� ����� " << getListHouseBigBranch(f) << std::endl;
                for (int r = 0; r < 5 ; r++) {
                    if (getListHouseBigBranch(r) != name && getListHouseBigBranch(r) != "none") {
                        std::cout << getListHouseBigBranch(r) << std::endl;
                        return;
                    }
                }
            }
        }
        getBigBranch()->getElfFinderOnMediumBranch(name);
    }
    //����� ��������� ������
    void setDeleteClassBigBranch() {
        delete bigBranch;
        bigBranch = nullptr;
    }
};




