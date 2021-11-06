#include "task2.h"

void printMenu() {
	std::cout << "1. �������� �������" << std::endl;
	std::cout << "2. ������� �������" << std::endl;
	std::cout << "3. �������� ����������" << std::endl;
	std::cout << "0. �����" << std::endl;
	std::cout << "�������� ����� ����: ";
}

template <typename T>
void add(SetOfStacks<T>& set) {
	std::cout << "������� ����� ��� ����������: ";
	set.push(processingInput((T)INT32_MIN, (T)INT32_MAX));
}

template <typename T>
void pop(SetOfStacks<T>& set) {
	try {
		std::cout << "���������� �����: " << set.pop() << std::endl;
	}
	catch (std::string err) {
		std::cout << err << std::endl;
	}

}

template <typename T>
void work(T indicator) {
	std::cout << "������� ������������ �������� � ����� �����: ";
	int n = processingInput(1, INT32_MAX);
	SetOfStacks<T> set(n);
	bool isExit = false;

	while (!isExit) {
		printMenu();
		int method = processingInput(0, 3);
		switch (method)
		{
		case 1:
			add(set);
			break;
		case 2:
			pop(set);
			break;
		case 3:
			set.printInfo();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void task2() {
	std::cout << "1. int" << std::endl;
	std::cout << "2. float" << std::endl;
	std::cout << "3. double" << std::endl;
	std::cout << "�������� ��� ������" << std::endl;
	int type = processingInput(1, 3);
	if (type == 1)
		work((int)0);
	else if (type == 2)
		work((float)0);
	else if (type == 3)
		work((double)0);
}


