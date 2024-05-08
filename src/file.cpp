#include <fstream>
#include <iostream>
#include <string>



string getKeyFromFile() {
    ifstream inputFile("./data/key.txt"); // 打开 key 文件
    if (!inputFile.is_open()) {
        cout << "无法打开文件！" << endl;
        return "";
    }
    string key;
    getline(inputFile, key); // 读取 key
    inputFile.close(); // 关闭文件
    return key;
}