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
    // 循环直到输入一个有效的值
    while (true) {
        if (!(cin >> input)) {
            cout << "输入无效，请重新输入一个有效的整数值：" << endl;
            cin.clear();                 // 清除错误状态
            cin.ignore(10000, '\n'); // 忽略缓冲区中的字符
            continue; // 继续下一次循环
        }

        // 检查输入是否在有效值数组内
        if (isValidInput(input, validValues, size)) {
            break; // 跳出循环，输入有效
        } else {
            cout << "输入无效，请重新输入一个有效的值：" << endl;
            cin.clear();                 // 清除错误状态
            cin.ignore(10000, '\n'); // 忽略缓冲区中的字符
        }
    }
    return input;
}