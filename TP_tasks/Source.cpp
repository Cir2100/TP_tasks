#include "task1.h"
#include "task2.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	cout << "1. 1-� �������" << endl;
	cout << "2. 2-� �������" << endl;
	cout << "�������� �������" << endl;
	int method = processingInput(1, 2);
	if (method == 1)
		task1();
	else
		task2();
}
