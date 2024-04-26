#pragma once
using namespace std;
class CircularBuffer {
private:
    vector<int> buffer;
    int head;
    int tail;
    int capacity;

public:
    // ����������� ��� ������������� ������
    CircularBuffer(int capacity)
    {
        this->capacity = capacity;
        this->head = 0;
        this->tail = 0;
        buffer.resize(capacity);
    }

    // ������� ����������� �������� � �����
    void push_back(int element)
    {
        buffer[head] = element;
        head = (head + 1) % capacity;
        if (head == tail) {
            tail = (tail + 1) % capacity;
        }
    }

    // ������� ��������� �������� �� ������
    void pop_front()
    {
        if (empty()) {
            throw out_of_range("Buffer is empty");
        }
        if (capacity != 1){tail = (tail + 1) % capacity; };
    }

    // ������� ��� �������� ����, ���� �� �����
    bool empty() const { return head == tail; }

    // ������� ��� �������� ����, �������� �� �����
    bool full() const
    {
        return (head + 1) % capacity == tail;
    }

    // ������� ��� ��������� ������� ������
    int size() const
    {
        if (head >= tail) {
            return head - tail;
        }
        return capacity - (tail - head);
    }

    // ������� ��� ������ ��������� ������
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


