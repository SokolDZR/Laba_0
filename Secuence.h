#ifndef SECUENCE_H
#define SECUENCE_H

#include <iostream>
//#include <exeption.h>
using namespace std;

template <typename T>
class Secuence
{
protected:
	int Count;
	public:
		virtual int getLength() = 0;
		virtual int getIsEmpty() = 0;
		virtual T Get(int index) = 0;
		virtual T GetFirst() = 0;
		virtual T Getlast() = 0;
		virtual Secuence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
		virtual void Append(T item) = 0;
		virtual void Prepend(T item) = 0;
		virtual void InsertAt(int index, T item) = 0;
		virtual void Remove(T item) = 0;
};

#endif
