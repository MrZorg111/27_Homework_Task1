#include <ctime>
#include <stdlib.h>
#include "Functions.h"

int random_size(int step, int vol) {
	srand(std::time(nullptr));
	return rand() % vol + step;
}
