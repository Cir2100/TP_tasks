#pragma once
#include "Element.h"
#include <iostream>

template <class T>
class Stack
{
private:
	Element<T>* tail;
	int size;
	void addFrom(Element<T>*);
public:
	Stack() : size(0), tail(nullptr) {};
	Stack(const Stack<T>&);
	~Stack();
	bool isEmpty() const;
	void push(T);
	T pop();
	void clear();
	T* back() { return &tail->data; }
	int getSize() const { return size; }

	Stack<T>& operator=(const Stack<T>&);
};

template <class T>
Stack<T>::Stack(const Stack<T>& stack)
{
	size = 0;
	tail = nullptr;
	if (!stack.isEmpty())
		addFrom(stack.tail);
}

template <class T>
Stack<T>::~Stack()
{
	clear();
}

template <class T>
void Stack<T>::push(T data)
{
	Element<T>* element = new Element<T>;
	element->data = data;
	element->prev = tail;
	tail = element;
	size++;
}

template <class T>
T Stack<T>::pop()
{
	std::string err = "Стек пуст. Нечего извлекать";
	if (isEmpty())
		throw err;
	T data;
	data = tail->data;
	Element<T>* e = tail;
	tail = tail->prev;
	size--;
	delete e;
	return data;
}

template <class T>
bool Stack<T>::isEmpty() const
{
	return size == 0;
}

template <class T>
void Stack<T>::clear()
{
	while (!isEmpty())
		pop();
}

template <class T>
void Stack<T>::addFrom(Element<T>* element)
{
	if (nullptr != element->prev) 
		addFrom(element->prev);
	push(element->data);
}

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack)
{
	if (this == &stack) 
		return *this;
	clear();
	if (!stack.isEmpty()) 
		addFrom(stack.tail);
}