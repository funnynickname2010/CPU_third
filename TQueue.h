#pragma once
#include <iostream>
#include <exception>
using namespace std;

template <class T>
class TQueue
{
	T* arr;

	int head;
	int tail;
	size_t mx;
	size_t element_counter;

	int NextIndex(int index_input);

public:

	T Dq();
	void Enq(const T obj);

	bool Full() const noexcept;
	bool Empty() const noexcept;

	TQueue(size_t m);
	~TQueue();
};

template<class T>
inline TQueue<T>::TQueue(size_t m)
{
	arr = new T[m];
	head = 0;
	tail = head + 1;
	mx = m;
	element_counter = 0;
}

template<class T>
inline TQueue<T>::~TQueue()
{
	delete[] arr;
	head = 0;
	tail = 0;
	mx = 0;
	element_counter = 0;
}

template<class T>
inline void TQueue<T>::Enq(const T obj)
{
	if (!Full())
	{
		arr[NextIndex(head)] = obj;
		head = NextIndex(head);
		element_counter++;
	}
	else
	{
		throw exception("void TQueue<T>::Enq(const T obj) const error: the queue is full.\n");
	}
}

template<class T>
inline T TQueue<T>::Dq()
{
	T result;

	if (!Empty())
	{
		result = arr[NextIndex(tail - 2)];
		tail = NextIndex(tail - 2);
		element_counter--;
	}
	else
	{
		throw exception("T TQueue<T>::Dq() error: the queue is empty.\n");
	}

	return result;
}

template<class T>
inline int TQueue<T>::NextIndex(int index_input)
{
	return ((index_input + 1) % mx);
}

template<class T>
inline bool TQueue<T>::Empty() const noexcept
{
	return element_counter == 0;
}

template<class T>
inline bool TQueue<T>::Full() const noexcept
{
	return element_counter == mx;
}