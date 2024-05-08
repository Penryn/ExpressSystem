#include <iostream>
#include <fstream>
#include <string>
using namespace std;


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

void getUserMenu() {
    cout << "请选择操作，输入0再看一遍操作选择" << endl;
    cout << "1.根据单号查询运单" << endl;
    cout << "2.根据快递类别、寄件人信息和寄件日期查询运单" << endl;
    cout << "3.根据快递类别和收件人信息查询运单" << endl;
    cout << "4.退出当前用户" << endl;
    cout << "5.退出" << endl;
}

void getAdminMenu(){
    cout << "请选择操作，输入0再看一遍操作选择" << endl;
    cout << "1.添加运单" << endl;
    cout << "2.删除运单" << endl;
    cout << "3.修改运单" << endl;
    cout << "4.显示所有运单" << endl;
    cout << "5.根据单号查询运单" << endl;
    cout << "6.根据快递类别查询所有运单" << endl;
    cout << "7.根据收件日期查询所有运单" << endl;
    cout << "8.根据寄件日期查询所有运单" << endl;
    cout << "9.根据收件日期统计快递单数量和金额" << endl;
    cout << "10.根据寄件日期显示未签收的快递单，并显示所有疑难件" << endl;
    cout << "11.将快递信息按日期排序" << endl;
    cout << "12.将快递信息按类别排序" << endl;
    cout << "13.将快递信息按金额排序" << endl;
    cout << "14.保存运单信息到文件" << endl;
    cout << "15.从文件中读取运单信息" << endl;
    cout << "16.退出管理员账号，进入用户模式" << endl;
    cout << "17.退出" << endl;
}

