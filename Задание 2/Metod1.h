#pragma once
using namespace std;
class CircularBuffer {
private:
    vector<int> buffer;
    int head;
    int tail;
    int capacity;

public:
    // Конструктор для инициализации данных
    CircularBuffer(int capacity)
    {
        this->capacity = capacity;
        this->head = 0;
        this->tail = 0;
        buffer.resize(capacity);
    }

    // Функция добавляющая элементы в буфер
    void push_back(int element)
    {
        buffer[head] = element;
        head = (head + 1) % capacity;
        if (head == tail) {
            tail = (tail + 1) % capacity;
        }
    }

    // Функция удаляющая элементы из буфера
    void pop_front()
    {
        if (empty()) {
            throw out_of_range("Buffer is empty");
        }
        if (capacity != 1){tail = (tail + 1) % capacity; };
    }

    // Функция для проверки того, пуст ли буфер
    bool empty() const { return head == tail; }

    // Функция для проверки того, заполнен ли буфер
    bool full() const
    {
        return (head + 1) % capacity == tail;
    }

    // Функция для получения размера буфера
    int size() const
    {
        if (head >= tail) {
            return head - tail;
        }
        return capacity - (tail - head);
    }

    // Функция для вывода элементов буфера
    void printBuffer() const
    {
        int idx = tail;
        while (idx != head) {
            cout << buffer[idx] << " ";
            idx = (idx + 1) % capacity;
        }
        cout << endl;
    }
};


