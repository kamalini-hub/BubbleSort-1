#pragma once
template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 10;


	T *arr;
	size_t arrSize;
	size_t arrCapacity;

public:
	tVector();

	~tVector()
	{
		delete[] arr;
	}

	//Vector Copy
	tVector(const tVector &vec);

	tVector<T>& operator=(const tVector<T> &vec);

	T *data();

	void reserve(size_t newCapacity);

	void push_back(const T &value);
	void pop_back();

	T &at(size_t index);

	//subscript operator
	T& operator[] (size_t index);

	size_t size() const;
	size_t capacity() const;

	//utility Functions
	bool empty() const;
	void resize(size_t newSize);
	void shrink_to_fit();
	void clear();

	void printArray();

	void bubbleSort();
};

template<typename T>
inline tVector<T>::tVector()
{
	T *temp = new T[10];
	arr = new T[10];
	arrSize = 0;
	arrCapacity = 10;

}

template<typename T>
inline tVector<T>::tVector(const tVector &vec)
{
	arr = vec.arr;
	arrSize = vec.arrSize;
	arrCapacity = vec.arrCapacity;
}

template<typename T>
inline tVector<T> & tVector<T>::operator=(const tVector<T> &vec)
{
	for (int idx = 0; idx < vec.size; idx++)
	{
		arr[idx] = vec.arr[idx];
	}
	arrSize = vec.arrSize;
	arrCapacity = vec.arrCapacity;
	return *this;
}

template<typename T>
inline T * tVector<T>::data()
{
	return arr;
}

template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	T *temp;
	if (arrCapacity <= newCapacity)
	{
		arrCapacity += GROWTH_FACTOR;
		temp = new T[arrCapacity];
		for (int i = 0; i < arrSize; i++)
		{
			temp[i] = arr[i];
		}

		delete[] arr;
		arr = temp;
	}
}
//adds to the end of the array
template<typename T>
inline void tVector<T>::push_back(const T & value)
{
	arr[arrSize] = value;
	arrSize++;
	reserve(arrSize);
}
//removes the last element in the array
template<typename T>
inline void tVector<T>::pop_back()
{
	if (arrSize > 0)
		arrSize--;

	arr[arrSize] = 0;
}

template<typename T>
inline T & tVector<T>::at(size_t index)
{
	return arr[index];
}

template<typename T>
inline T & tVector<T>::operator[](size_t index)
{
	return arr[index];
}

template<typename T>
inline size_t tVector<T>::size() const
{
	return arrSize;
}

template<typename T>
inline size_t tVector<T>::capacity() const
{
	return arrCapacity;
}

template<typename T>
inline bool tVector<T>::empty() const
{
	if (arrSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
inline void tVector<T>::resize(size_t newSize)
{
	if (newSize < arrSize)
	{
		arrSize = newSize;
	}
	else
	{
		for (int i = arrSize; i < newSize; i++)
		{
			arr[arrSize] = 0;
			arrSize++;
			reserve(arrSize);
		}
	}
}

template<typename T>
inline void tVector<T>::shrink_to_fit()
{
	arrCapacity = arrSize;
}

template<typename T>
inline void tVector<T>::clear()
{
	T *temp;
	arrCapacity = 10;
	temp = new T[arrCapacity];
	arrSize = 0;
	delete[] arr;
	arr = temp;
}

template<typename T>
inline void tVector<T>::printArray()
{
	for (int i = 0; i < arrSize; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}


//The Bubble Sort
template<typename T>
inline void tVector<T>::bubbleSort()
{
	int temp = 0;
	bool swapped;
	for (int i = 0; i < arrSize - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < arrSize - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}