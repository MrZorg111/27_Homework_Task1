#pragma once
#include <string>
#include <vector>

class Branch {
	std::vector<std::string> elfs_home;
public:
	//Сеттерс заселения эльфов в домики
	void setSettlElf(std::string) {
		std::string name_elf;
		std::count << "Введите имя эльфа: " << std::endl;
		std::cin >> name_elf;
		elfs_home.push_back(name_elf);
	}
	//Геттерс доступа к проживающим эльфам
	void getResidentElf() {
		for (int res_elf = 0; res_elf < elfs_home.size(); res_elf++) {
			std::count << elfs_home[res_elf] << "\t";
		}
		std::count << std::endl;
	}
};