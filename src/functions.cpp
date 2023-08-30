#include <ctime>
#include <stdlib.h>
#include "Functions.h"

//Функция радомного определения кол-ва веток
int random_size(int step, int vol) {
	srand(std::time(nullptr));
	return rand() % vol + step;
}
