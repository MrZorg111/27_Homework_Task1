#pragma once
#include <iostream>
#include <string>
#include <vector>

class Branch {
	std::vector<std::string> elfs_home;
public:
	//Метод заселения эльфов в домики
	void setSettlElf(std::string name_elf) {
		elfs_home.push_back(name_elf);
	}
	//Метод очистки данных о заселении
	void setClear() {
		elfs_home.clear();
	}
	//Метод доступа к размеру списка жильцов
	int getVolElfs() {
		return elfs_home.size();
	}
	//Метод поиска соседей заданного эльфа
	bool getFindElf(std::string find_elf) {
		for (int find = 0; find < elfs_home.size(); find++) {
			if (find_elf == elfs_home[find]) {
				return true;
			}
		}
		return false;
	}
	//Метод для вывода соседей искомого эльфа
	void getFindNeighbourInHome(std::string find_elf) {
		std::cout << "The neighbors of the elf you are looking for: ";
		for (int find_neigh = 0; find_neigh < elfs_home.size(); find_neigh++) {
			if (elfs_home[find_neigh] != find_elf && elfs_home[find_neigh] != "none") {
				std::cout << elfs_home[find_neigh] << " ";
			}
		}
	}
	
};