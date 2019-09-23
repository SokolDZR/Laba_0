#include "Array.h"

template <typename T>
Array<T>::Array()
{
	Secuence<T>::Count = 0;
	data = NULL;
}

template<typename T>
Array<T>::Array(Array<T>* sequence)
{
	Secuence<T>::Count = sequence->getLength();
	int  i;

	data = (T*)malloc(sizeof(T) * Secuence<T>::Count);
	i = 0;
	while (i < Secuence<T>::Count)
	{
		data[i] = sequence->Get(i);
		i++;
	}
}

template<typename T>
Array<T>::~Array()
{
	free(data);
	data = NULL;
	Secuence<T>::Count = 0;
}

template<typename T>
int Array<T>::getLength()
{
	return (Secuence<T>::Count);
}

template<typename T>
int Array<T>::getIsEmpty()
{
	if (!Secuence<T>::Count)
		return (1);
	return (0);
}

template<typename T>
T Array<T>::Get(int index)
{
	if (index > Secuence<T>::Count || index < 0)
	{
		throw "Out of Range";
	}

	return *(data + index);
}

template<typename T>
T Array<T>::GetFirst()
{
	if (!Secuence<T>::Count) {
		throw "Empty!";
	}
	return (Get(0));
}

template<typename T>
T Array<T>::Getlast()
{
	if (!Secuence<T>::Count) {
		throw "Empty!";
	}
	return (Get(Secuence<T>::Count - 1));
}

template<typename T>
Array<T>* Array<T>::GetSubsequence(int startIndex, int endIndex)
{
	Array<T>* help = new Array<T>;

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
void Array<T>::Append(T item)
{
	Secuence<T>::Count++;
	data = (T*)realloc(data, sizeof(T) * (Secuence<T>::Count));
	*(data + Secuence<T>::Count - 1) = item;
}

template<typename T>
void Array<T>::Prepend(T item)
{
	Secuence<T>::Count++;
	if (Secuence<T>::Count - 1 == NULL)
	{
		data = (T*)malloc(sizeof(T));
	}
	else
	{
		data = (T*)realloc(data, sizeof(T) * Secuence<T>::Count);
		int i = Secuence<T>::Count - 1;
		while (i > 0)
		{
			*(data + i) = *(data + i - 1);
			i--;
		}
	}
	*(data) = item;
}

template<typename T>
void Array<T>::InsertAt(int index, T item)
{
	if (index > Secuence<T>::Count) {
		throw "Out of Range!";
	}
	Secuence<T>::Count++;
	if (Secuence<T>::Count - 1 == NULL)
	{
		data = (T*)malloc(sizeof(T));
		*data = item;
	}
	else
	{
		int i = Secuence<T>::Count - 1;
		data = (T*)realloc(data, sizeof(T) * Secuence<T>::Count);
		while (i > index)
		{
			*(data + i) = *(data + i  - 1);
			i--;
		}
		*(data + index) = item;
	}
}

template<typename T>
void Array<T>::Remove(T item)
{
	int index = -1;
	for (int i = 0; i < Secuence<T>::Count; i++) {
		if (*(data + i) == item) {
			index = i;
			break;
		}
	}
	Secuence<T>::Count--;
	for (int i = index; i < Secuence<T>::Count; i++) {
		*(data + i) = *(data + i + 1);
	}
	data = (T*)realloc(data, sizeof(T) * Secuence<T>::Count);
}
