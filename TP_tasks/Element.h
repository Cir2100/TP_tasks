#pragma once

template <class T>
struct Element
{
	T data;
	Element* prev;
};