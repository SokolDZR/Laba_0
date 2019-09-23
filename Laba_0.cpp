
#include "List.h"
#include "List_c.cpp"
#include "Array.h"
#include "Array_c.cpp"
#include <stdio.h>
using namespace std;

void party(Secuence<int>* test)
{
	int i;

	i = 0;
	cout << test->getIsEmpty() << "\n";
	test->Append(23);
	cout << test->getLength() << "\n" << test->GetFirst() << "\n" << test->Getlast() << "\n\n";
	cout << "\n" << test->Get(0) << "\n\n";
	//-----------------------------------------------------------------------------------------------------------------
	try
	{
		test->Get(-1);
	}
	catch (const char* exep)
	{
		cout << exep << "\n";
	}
	//-----------------------------------------------------------------------------------------------------------------
	test->Append(42);
	cout << test->getLength() << "\n" << test->GetFirst() << "\n" << test->Getlast() << "\n\n";
	test->Prepend(53);
	while (i < test->getLength())
	{
		try
		{
			cout << test->Get(i) << "\n";
		}
		catch (const char* exep)
		{
			cout << exep << "\n";
		}
		i++;
	}
	//-----------------------------------------------------------------------------------------------------------------
	try
	{
		test->InsertAt(1, 100);
	}
	catch (const char* exep)
	{
		cout << exep << "\n";
	}
	cout << "\n";
	//-----------------------------------------------------------------------------------------------------------------
	i = 0;
	while (i < test->getLength())
	{
		try
		{
			cout << test->Get(i) << "\n";
		}
		catch (const char* exep)
		{
			cout << exep << "\n";
		}
		i++;
	}
	cout << test->getLength() << "\n\n";
	//-----------------------------------------------------------------------------------------------------------------
	test->Remove(100);
	i = 0;
	while (i < test->getLength())
	{
		try
		{
			cout << test->Get(i) << "\n";
		}
		catch (const char* exep)
		{
			cout << exep << "\n";
		}
		i++;
	}
	cout << test->getLength() << "\n\n";
}

int main()
{
	List<int>* list = new List<int>();
	Array<int>* arr = new Array<int>();
	cout << "Making List \n";
	party(list);
	cout << "Making Array \n";
	party(arr);
	return (0);
}