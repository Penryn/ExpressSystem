#include <fstream>
#include <iostream>
#include <string>



string getKeyFromFile() {
    ifstream inputFile("./data/key.txt"); // �� key �ļ�
    if (!inputFile.is_open()) {
        cout << "�޷����ļ���" << endl;
        return "";
    }
    string key;
    getline(inputFile, key); // ��ȡ key
    inputFile.close(); // �ر��ļ�
    return key;
}