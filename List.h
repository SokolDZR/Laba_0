#ifndef LIST_H
#define LIST_H

#include "Secuence.h"

template <typename T>
class List : public Secuence<T>
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node* prev;
	};
	Node *Head, *Tail;
public:
	List();
	List(const List&);
	~List();
	 int getLength();
	 int getIsEmpty();
	 T Get(int index);
	 T GetFirst();
	T Getlast();
	 List<T>* GetSubsequence(int startIndex, int endIndex);
	 void Append(T item);
	void Prepend(T item);
	void InsertAt(int index, T item);
	void Remove(T item);
};

#endif