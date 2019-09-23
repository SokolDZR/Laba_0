#include "List.h"

template <typename T>
List<T>::List()
{
	Head = Tail = NULL;
	Secuence<T>::Count = 0;
}

template <typename T>
List<T>::List(const List& L)
{
	Head = Tail = NULL;
	Secuence<T>::Count = 0;

	Node* temp = L.Head;
	while (temp != 0)
	{
		Append(temp->data);
		temp = temp->next;
	}
}

template <typename T>
List<T>::~List()
{
	Node* tmp = nullptr;
	while (tmp) {
		Node* next = tmp->next;
		delete tmp;
		tmp = next;
	}
	Head = NULL;
	Tail = NULL;
	Secuence<T>::Count = 0;
}

template <typename T>
int List<T>::getLength()
{
	return (Secuence<T>:: Count);
}

template<typename T>
int List<T>::getIsEmpty()
{
	if (!Secuence<T>::Count)
		return (1);
	return (0);
}

template<typename T>
T List<T>::Get(int index)
{
	if (index > Secuence<T>::Count || index < 0)
	{
		throw "Out of Range";
	}
	int i;
	Node *tmp;

	tmp = Head;
	i = 0;
	while (i < index && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp->data);
}

template<typename T>
T List<T>::GetFirst()
{
	if (!Secuence<T>::Count) {
		throw "Empty!";
	}
	return (Get(0));
}

template<typename T>
T List<T>::Getlast()
{
	if (!Secuence<T>::Count) {
		throw "Empty!";
	}
	return (Get(Secuence<T>::Count - 1));
}

template<typename T>
List<T>* List<T>::GetSubsequence(int startIndex, int endIndex)
{
	List<T> *help = new List<T>;

	if (endIndex < startIndex) {
		throw "Incorrect input!";
	}
	if (endIndex >= Secuence<T>::Count) {
		throw "Out of Range!";
	}
	while (startIndex <= endIndex)
	{
		help->Append(this->Get(startIndex));
		startIndex++;
	}
	return help;
}

template<typename T>
void List<T>::Append(T item)
{
	Node* tmp;

	tmp = new Node();
	tmp->next = NULL;
	tmp->data = item;
	tmp->prev = Tail;

	if (Tail)
		Tail->next = tmp;

	if (Secuence<T>::Count == 0)
		Head = Tail = tmp;
	else
		Tail = tmp;
	Secuence<T>::Count++;
}

template<typename T>
void List<T>::Prepend(T item)
{
	Node* tmp;

	tmp = new Node();
	tmp->prev = NULL;
	tmp->data = item;
	tmp->next = Head;
	if (Head)
		Head->prev = tmp;
	if (!Secuence<T>::Count)
		Head = Tail = tmp;
	else
		Head = tmp;
	Secuence<T>::Count++;
}

template<typename T>
void List<T>::InsertAt(int index, T item)
{
	if (index >= Secuence<T>::Count -1 || index < 0) {
		throw "Out of Range!";
	}
	Secuence<T>::Count++;
	Node* tmp;
	int  i;

	i = 0;
	if (index < Secuence<T>::Count / 2) {
		tmp = Head;
		for (int i = 0; i < index; i++) {
			tmp = tmp->next;
		}
	}
	else {
		tmp = Tail;
		for (int i = 0; i < Secuence<T>::Count - index - 1; i++) {
			tmp = tmp->prev;
		}
	}
	Node* buff = new Node;
	buff->data = item;
	buff->next = tmp->next;
	buff->prev = tmp;
	tmp->next->prev = buff;
	tmp->next = buff;
}

template<typename T>
void List<T>::Remove(T item)
{
	Node* tmp = Head;
	while (tmp && (tmp->data != item)) {
		tmp = tmp->next;
	}
	if (tmp) {
		if (tmp ==Head) {
			Head = tmp->next;
		}
		else if (tmp == Tail) {
			Tail = tmp->prev;
		}
		else {
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
		}
		delete tmp;
		Secuence<T>::Count--;
	}
}
