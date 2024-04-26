#pragma once
class CircularBufferArray
{
private:
	int* buffer2;
	size_t capacity;
	size_t size;
	size_t  head;
	size_t tail;

public:
	CircularBufferArray(size_t capacity) :buffer2(new int[capacity]), capacity(capacity), size(0), head(0), tail(0) {}
	~CircularBufferArray()
	{
		delete[] buffer2;
	}

	// Функция добавляющая элементы в буфер
	void push(int value)
	{
		buffer2[tail] = value;
		tail = (tail + 1) % capacity;
		if (size < capacity)
		{
			size++;
		}
		else
		{
			head = (head + 1) % capacity;
		}
	}

	// Функция удаляющая элементы из буфера
	int pop()
	{
		if (size <= 0)
		{
			throw out_of_range("Buffer is empty");
		}
		int value = buffer2[head];
		head = (head + 1) % capacity;
		size--;
		return value;
	}

	// Функция для вывода элементов буфера
	void printBuffer2() const
	{
		size_t idx = tail;
		for (size_t i = 0; i < size; i++)
		{
			cout << buffer2[idx] << " ";
			idx = (idx + 1) % capacity;
		}
		cout << endl;
	}

	//  Функция для проверки того, заполнен ли буфер
	bool full() const
	{
		return (head + 1) % capacity == tail;
	}

	// Функция для получения размера буфера
	size_t getSize()
	{
		return size;
	}
};

