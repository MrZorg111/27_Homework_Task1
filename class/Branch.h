#pragma once
#include <string>
#include <vector>
#include "Functions.h"

class Branch {
	std::vector<std::string> elfs_home;
public:
	//Метод заселения эльфов в домики
	void setSettlElf() {
		elfs_home.push_back(generation_names());
	}
	//Метод очистки данных о заселении
	void setClear() {
		elfs_home.clear();
	}	
	//Метод доступа к проживающим эльфам 
	void getElfs() {
		for (int elf = 0; elf < elfs_home.size(); elf++) {
			std::cout << elfs_home[elf] << " ";
		}
	}
	//Метод поиска на ветке
	bool getFindElf(std::string wanted, int& neighbour) {
		for (int want = 0; want < elfs_home.size(); want++) {
			if (wanted == elfs_home[want]) {
				for (int neig = 0; neig < elfs_home.size(); neig++) {
					if (elfs_home[neig] != "None" && elfs_home[neig] != wanted) {
						neighbour += 1;
					}
				}
				return true;
			}
		}
		return false;
	}
};