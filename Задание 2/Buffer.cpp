#include <iostream>
#include <stdexcept>
#include <vector>
#include "Metod1.h"//������
#include "Metod2.h"//������
using namespace std;
/*1 ������
-:
�������������� ���������� ������� �� �������� �������
����� �������� ������ ������ ��� ������
+:
���������� ������������� ��������� �������

2 ������
-:
����������� ������� �������
+:
��������
������� ������� �� ���������� ��������
*/
int main()
{
    setlocale(LC_ALL, "Russian");


    int SizeCircularBuffer;
    cout << " ������ ������ ������������ ������: ";
    cin >> SizeCircularBuffer;
    SizeCircularBuffer += 1;
    cout << " ���������� ������������ ������ � ������� std::vector" << endl;
    // ��������� �������� � �����
    if (SizeCircularBuffer > 1) {


        // ������ ������ �������
        CircularBuffer buffer(SizeCircularBuffer);
        for (int i = 1; i <= SizeCircularBuffer - 1; ++i) {
            buffer.push_back(i);
            cout << " ���������: " << i << endl;
        }
        // ����� ��������� �� ������ ����� ��� ����������
        cout << " �������� � ������: ";
        buffer.printBuffer();

        // �������� �������� ������ ����� ��������� ���������
        cout << " ������ ������: " << buffer.size() << endl;

        // �������� ��������� �� ������
        for (int i = 0; i < 1; ++i) {
            buffer.pop_front();
            cout << " ������" << endl;
        }

        // ����� ��������� ������ ����� �������� ���������
        cout << " �������� � ������: ";
        buffer.printBuffer();

        // �������� ������� ������ ����� �������� ���������
        cout << " ������ ������: " << buffer.size() << endl << endl;
    }
    else { cout << " ������ �� ����� ���� ������ 0" << endl; }

    int SizeBufferArray;

    cout << " ������� ������ ������������ ������: ";
    cin >> SizeBufferArray;
    cout << " ���������� ������������ ������ � �������������� �������" << endl;
        if (SizeBufferArray > 0) {
            CircularBufferArray buffer2(SizeBufferArray);
            for (int i = 1; i <= SizeBufferArray; ++i)
            {
                buffer2.push(i);
                cout << " ��������: " << i << endl;
            }

            // ����� ��������� �� ������ ����� ��� ����������
            cout << " �������� � ������: ";
            buffer2.printBuffer2();

            // �������� �������� ������ ����� ��������� ���������
            cout << " ������ ������: " << buffer2.getSize() << endl;

            // �������� ��������� �� ������
            for (int i = 0; i < 1; ++i) {
                buffer2.pop();
                cout << " ������" << endl;
            }

            // ����� ��������� ������ ����� �������� ���������
            cout << " �������� � ������: ";
            buffer2.printBuffer2();

            //�������� ������� ������ ����� �������� ���������
            cout << " ������ ������: " << buffer2.getSize() << endl;
    }
    else { cout << " ������ �� ����� ���� ������ 0"; }
}