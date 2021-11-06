#include "task1.h"

void task1() {
	std::cout << "Введите число: ";
	int n = processingInput(INT32_MIN, INT32_MAX);
	const int countBytes = 32;
	int maxCount = 0, currCountOnes = 0, lastCountOnes = 0;
	for (int i = 0; i < countBytes; i++) {
		if ((n & 1) == 1)
			currCountOnes++;
		if ((n & 1) == 0 || i == countBytes - 1) {
			maxCount = std::max(maxCount, std::min(countBytes, lastCountOnes + currCountOnes + 1));
			lastCountOnes = currCountOnes;
			currCountOnes = 0;
		}
		n >>= 1;
	}
	std::cout << "Количество подряд идущих единиц = " << maxCount << std::endl;
}