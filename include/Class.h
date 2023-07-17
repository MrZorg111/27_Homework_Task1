#pragma once
#include <ctime>
#include <string>
#include <vector>

class Branch {
    //Наследуемое поле 
    std::vector<std::string> elfs_home;
public:
    //Метот заполнения наследуемого поля
    void setSettlementElves() {
        std::string name;
        std::cout << "Enter elf name: " << std::endl;
        std::cin >> name;
        elfs_home.push_back(name);
    }
    // Метод доступа к проживающим эльфам
    std::string getResidentElf() {
        for (int i = 0; i < elfs_home.size(); i++) {
            return elfs_home[i];
        }
    }
    //Метод случайной инициализации массива
    int random_size(int max, int step) {
        std::srand(std::time(nullptr));
        return rand() % max + step;
    }
    
};

class MediumBranch: public Branch {
    //Данный класс наследует поле elfs_home
public:
    //Данный клас наследует также методы работы с полем elfs_home
};

class BigBranch: public Branch {
    //Данный класс наследует поле elfs_home и все методы работы с ним
    //Инициалицация класса MediumBranch
    MediumBranch* mediumBranch = new MediumBranch();
    const int SIZE = random_size(1, 2);
    //Создание массива классов MediumBranch
    std::vector<MediumBranch*> mediumBranchs;
public:
   //Метод создающий список домов на ветке
    void setAddHouseListsMediumBranch() {
        mediumBranchs.push_back(mediumBranch);
    }
    //Метод доступа к размеру списка домов на ветке
    int getSizeListsMediumBranch() {
        return SIZE;
    }
    //Метод доступа к списку домов на ветке
    std::string getListHouseMediumBranch(int num_house) {
        return mediumBranchs[num_house]->getResidentElf();
    }
    //Метод доступа к классу MediumBranch
    MediumBranch* getMediumBranch() {
        return mediumBranch;
    }
    //Метод поиска
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
    //Метод заме
    //Метод заметания следов
    void setDeleteClassMediumBranch() {
        delete mediumBranch;
        mediumBranch = nullptr;
    }
};

class Wood: public Branch {
    //Инициалицация класса MediumBranch
    BigBranch* bigBranch = new BigBranch();
    const int SIZE = random_size(3, 3);
    //Создание массива классов BigBranch
    std::vector<BigBranch*> bigBranchs;
public:
    //Метод создающий список домов на ветке
    void setAddHouseListsBigBranch() {
        bigBranchs.push_back(bigBranch);
    }
    //Метод доступа к списку домов на ветке
    std::string getListHouseBigBranch(int num_house) {
        return bigBranchs[num_house]->getResidentElf();
    }
    //Метод доступа к размеру списка домов на ветке
    int getSizeListsBigBranch() {
        return SIZE;
    }
    //Метод доступа к классу BigBranch
    BigBranch* getBigBranch() {
        return bigBranch;
    }
    //Метод поиска
    void getElfFinderOnBigBranch(std::string name) {
        for (int f = 0; f < 5; f++) {
            std::cout << "NAME " << name << std::endl;
            if (name == getListHouseBigBranch(f)) {
                std::cout << "ИМЯ ЭЛЬФА " << getListHouseBigBranch(f) << std::endl;
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
    //Метод заметания следов
    void setDeleteClassBigBranch() {
        delete bigBranch;
        bigBranch = nullptr;
    }
};




