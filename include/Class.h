#pragma once
#include <ctime>
#include <string>
#include <vector>

class Branch {
    //Наследуемое поле 
    std::string elfs_home;
public:
    //Метот заполнения наследуемого поля
    void setSettlementElves() {
        std::string name;
        std::cout << "Enter elf name: " << std::endl;
        std::cin >> name;
       this -> elfs_home = name;
    }
    // Метод доступа к проживающим эльфам
    std::string getResidentElf() {
        return elfs_home;
    }
    //Функция случайной инициализации массива
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
    const int SIZE = random_size(3, 3);
    //Создание массива классов MediumBranch
    std::vector<MediumBranch*> mediumBranchs;
public:
   //Метод создающий список домов на ветке
    void setAddHouseListsMediumBranch() {
        mediumBranchs.push_back(mediumBranch);
    }
    //Метод доступа к списку домов на ветке
    std::vector<MediumBranch*> getListHouseMediumBranch() {
        return mediumBranchs;
    }
    //Метод доступа к классу MediumBranch
    MediumBranch* getMediumBranch() {
        return mediumBranch;
    }
    void setDeleteClassMediumBranch() {
        delete mediumBranch;
        mediumBranch = nullptr;
    }
};

class Wood: public Branch {
    //Инициалицация класса MediumBranch
    BigBranch* bigBranch = new BigBranch();
    const int SIZE = random_size(1, 2);
    //Создание массива классов BigBranch
    std::vector<BigBranch*> bigBranchs;
public:
    //Метод создающий список домов на ветке
    void setAddHouseListsBigBranch() {
        bigBranchs.push_back(bigBranch);
    }
    //Метод доступа к списку домов на ветке
    std::vector<BigBranch*> getListHouseBigBranch() {
        return bigBranchs;
    }
    //Метод доступа к размеру списка домов на ветке
    int getSizeListsBigBranch() {
        return SIZE;
    }
    //Метод доступа к классу BigBranch
    BigBranch* getBigBranch() {
        return bigBranch;
    }
    void setDeleteClassBigBranch() {
        delete bigBranch;
        bigBranch = nullptr;
    }
};




