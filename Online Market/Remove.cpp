#include "Remove.h"
#include <assert.h>
#include <iostream>

template <class T>
Remove<T>::Remove()
{
	size = 1;
	add = new T[size];
	count = 0;
}

template <class T>
int Remove<T>::Length()
{
	return count;
}

template <class T>
void Remove<T>::Append(T val)
{
	if (count == size)
		Expand();
	add[count] = val;
	count++;
}

template <class T>
void Remove<T>::Expand()
{
	size *= 2; //define new capacity
	T* tmp = new T[size];
	for (int i = 0; i < count; i++)
		tmp[i] = add[i];
	delete add; //release old space
	add = tmp;
}

template <class T>
T Remove<T>::At(int pos)
{
	assert(pos < count);
	return add[pos];
}

template <class T>
void Remove<T>::insertAt(int pos, T val)
{
	assert(pos < count);
	if (count == size)
		Expand();
	//shift elements to the right
	for (int i = count; i > pos; i--)
		add[i] = add[i - 1];
	//insert value at required position
	add[pos] = val;
	count++;
}

template <class T>
void Remove<T>::deleteAt(int pos)
{
	assert(pos < count);
	//shift elements to the left
	for (int i = pos; i < count - 1; i++)
		add[i] = add[i + 1];
	count--;
}

template <class T>
Remove<T>::~Remove(void)
{
	delete[] add;
}
