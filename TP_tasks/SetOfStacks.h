#pragma once
#include "Stack.h"

//���� �� � ������ ��� ������, �� ���� ������ �� ������� ������� ����� ����� ���
template <class T>
class SetOfStacks
{
private:
	Stack<Stack<T>> data;
	int maxSize;
	int size;
public:
	SetOfStacks(); 
	SetOfStacks(int maxSize);
	~SetOfStacks();
	bool isEmpty() const;
	void push(T);
	T pop();
	void printInfo() const;
	void clear();
};

template <class T>
SetOfStacks<T>::SetOfStacks() : maxSize(3), size(0) {}

template <class T>
SetOfStacks<T>::SetOfStacks(int maxSize) : maxSize(maxSize), size(0) {}

template <class T>
SetOfStacks<T>::~SetOfStacks() { clear(); }

template <class T>
void SetOfStacks<T>::push(T data)
{
	if (this->data.isEmpty())
		this->data.push(Stack<T>());
	Stack<T>* back = this->data.back();
	if (back->getSize() < maxSize)
		back->push(data);
	else {
		this->data.push(Stack<T>());
		back = this->data.back();
		back->push(data);
	}
	size++;
}

template <class T>
T SetOfStacks<T>::pop()
{
	std::string err = "���� ������ ����. ������ ���������";
	if (data.isEmpty())
		throw err;
	Stack<T>* back = this->data.back();
	T tmp = back->pop();
	if (back->isEmpty())
		data.pop();
	size--;
	return tmp;
}

template <class T>
void SetOfStacks<T>::printInfo() const {
	std::cout << "���������� � ���� ������: " << std::endl;
	std::cout << "������������ ���������� ��������� � ����� = " << maxSize << std::endl;
	std::cout << "���������� ��������� = " << size << std::endl;
	std::cout << "���������� ������ = " << data.getSize() << std::endl;
}

template <class T>
bool SetOfStacks<T>::isEmpty() const
{
	Stack<T>* back = this->data.back();
	return back->isEmpty();
}

template <class T>
void SetOfStacks<T>::clear()
{
	while (!data.isEmpty()) {
		Stack<T> back = data.pop();
		back.clear();
	}
}