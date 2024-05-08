#include <iostream>
#include <algorithm>
using namespace std;

int a[2]={1,2};
int b[2]={1,0};
int c[5]={1,2,3,4,5};

bool isValidInput(int input, int *validValues, int size) {
    return find(validValues, validValues + size, input) != validValues + size;
}

int getInput(int *validValues, int size) {
    int input;
    // ѭ��ֱ������һ����Ч��ֵ
    while (true) {
        if (!(cin >> input)) {
            cout << "������Ч������������һ����Ч������ֵ��" << endl;
            cin.clear();                 // �������״̬
            cin.ignore(10000, '\n'); // ���Ի������е��ַ�
            continue; // ������һ��ѭ��
        }

        // ��������Ƿ�����Чֵ������
        if (isValidInput(input, validValues, size)) {
            break; // ����ѭ����������Ч
        } else {
            cout << "������Ч������������һ����Ч��ֵ��" << endl;
            cin.clear();                 // �������״̬
            cin.ignore(10000, '\n'); // ���Ի������е��ַ�
        }
    }
    return input;
}