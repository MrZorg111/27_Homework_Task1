#pragma once
#include "Functions.h"

class Branch {
	const int VOL_MB = random_size(2, 2);
	const int VOL_BB = random_size(3, 3);
public:
	int getSizeMB() {
		return VOL_MB;
	}
	int getSizeBB() {
		return VOL_BB;
	}
};