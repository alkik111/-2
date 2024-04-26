#include <iostream>
#include <stdexcept>
#include <vector>
#include "Metod1.h"//Вектор
#include "Metod2.h"//Массив
using namespace std;
/*1 способ
-:
Дополнительные аппаратные расходы на проверку вектора
Может занимать больше памяти чем массив
+:
Отсутствие необходимости управлять памятью

2 способ
-:
Статичность размера буффера
+:
Простота
Меньшие заьраты на управление буффером
*/
int main()
{
    setlocale(LC_ALL, "Russian");


    int SizeCircularBuffer;
    cout << " Ведите размер циклического буфера: ";
    cin >> SizeCircularBuffer;
    SizeCircularBuffer += 1;
    cout << " Реализация циклического буфера с помощью std::vector" << endl;
    // Добавляем элементы в буфер
    if (SizeCircularBuffer > 1) {


        // Задаем размер буффера
        CircularBuffer buffer(SizeCircularBuffer);
        for (int i = 1; i <= SizeCircularBuffer - 1; ++i) {
            buffer.push_back(i);
            cout << " Добавляем: " << i << endl;
        }
        // Вывод элементов из буфера после его заполнения
        cout << " Элементы в буфере: ";
        buffer.printBuffer();

        // Проверка размеров буфера перед удалением элементов
        cout << " Размер буфера: " << buffer.size() << endl;

        // Удаление элементов из буфера
        for (int i = 0; i < 1; ++i) {
            buffer.pop_front();
            cout << " Удален" << endl;
        }

        // Вывод элементов буфера после удаления элементов
        cout << " Элементы в буфере: ";
        buffer.printBuffer();

        // Проверка размера буфера после удаления элементов
        cout << " Размер буфера: " << buffer.size() << endl << endl;
    }
    else { cout << " Буффер не может быть равным 0" << endl; }

    int SizeBufferArray;

    cout << " Введите размер циклического буфера: ";
    cin >> SizeBufferArray;
    cout << " Реализация циклического буфера с использованием массива" << endl;
        if (SizeBufferArray > 0) {
            CircularBufferArray buffer2(SizeBufferArray);
            for (int i = 1; i <= SizeBufferArray; ++i)
            {
                buffer2.push(i);
                cout << " Добавлен: " << i << endl;
            }

            // Вывод элементов из буфера после его заполнения
            cout << " Элементы в буфере: ";
            buffer2.printBuffer2();

            // Проверка размеров буфера перед удалением элементов
            cout << " Размер буфера: " << buffer2.getSize() << endl;

            // Удаление элементов из буфера
            for (int i = 0; i < 1; ++i) {
                buffer2.pop();
                cout << " Удален" << endl;
            }

            // Вывод элементов буфера после удаления элементов
            cout << " Элементы в буфере: ";
            buffer2.printBuffer2();

            //Проверка размера буфера после удаления элементов
            cout << " Размер буфера: " << buffer2.getSize() << endl;
    }
    else { cout << " Буффер не может быть равным 0"; }
}