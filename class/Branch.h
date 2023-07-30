#pragma once
#include <string>
#include <vector>

class Branch {
	std::vector<std::string> elfs_home;
public:
	//Сеттерс заселения эльфов в домики
	void setSettlElf() {
		std::string name_elf;
		std::cout << "Введите имя эльфа: " << std::endl;
		std::cin >> name_elf;
		elfs_home.push_back(name_elf);
	}
	//Сеттерс очистки данных о заселении
	void setClear() {
		elfs_home.clear();
	}
	//Геттерс доступа к проживающим эльфам
	void getResidentElf() {
		for (int res_elf = 0; res_elf < elfs_home.size(); res_elf++) {
			std::cout << elfs_home[res_elf] << "\t";
		}
		std::cout << std::endl;
	}
};