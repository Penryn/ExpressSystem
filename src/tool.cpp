#include <iostream>
#include <algorithm>
using namespace std;

int a[2]={1,2};
int b[2]={1,0};
int c[5]={1,2,3,4,5};

bool isValidInput(int input, int *validValues, int size) {
    return find(validValues, validValues + size, input) != validValues + size;
}

bool isValidDate(int year, int month, int day) {
    if(year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    if(month == 2) {
        if(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
            return day <= 29;
        else
            return day <= 28;
    }
    if(month == 4 || month == 6 || month == 9 || month == 11)
        return day <= 30;
    return true;
}


int getRightInput(int *validValues, int size) {
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

template<typename T>
T getInput() {
    T input;
    // ѭ��ֱ������һ����Ч��ֵ
    while (true) {
        if (!(cin >> input)) {
            cout << "������Ч������������һ����Ч��ֵ��" << endl;
            cin.clear();                 // �������״̬
            cin.ignore(10000, '\n'); // ���Ի������е��ַ�
        } else {
            break;
        }
    }
    return input;
}

Time getTimeInput() {
    int year, month, day;
    while(true) {
        cin >> year >> month >> day;
        if(isValidDate(year, month, day)) {
            Time time{};
            time.setTime(year, month, day);
            return time;
        } else {
            cout << "�����������Ч�����������룺" << endl;
            cin.clear();                 // �������״̬
            cin.ignore(10000, '\n'); // ���Ի������е��ַ�
        }
    }
}