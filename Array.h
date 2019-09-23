#ifndef ARRAY_H
#define ARRAY_H

#include "Secuence.h"

template <typename T>
class Array : public Secuence<T>
{
private:
	T* data;
public:
	Array();
	Array(Array<T>* sequence);
	~Array();
	int getLength() override;
	int getIsEmpty() override;
	T Get(int index) override;
	T GetFirst() override;
	T Getlast() override;
	Array<T>* GetSubsequence(int startIndex, int endIndex) override;
	void Append(T item) override;
	void Prepend(T item) override;
	void InsertAt(int index, T item) override;
	void Remove(T item) override;
};

#endif
