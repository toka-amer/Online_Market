#pragma once
template <class T>
class Remove
{

	T* add;
	int size, count;
public:
	Remove();
	int Length();
	void Append(T);
	void Expand();
	T At(int);
	void insertAt(int, T);
	void deleteAt(int);
	~Remove(void);
};

