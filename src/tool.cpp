#include <iostream>
#include <fstream>
#include <string>
using namespace std;


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

void getUserMenu() {
    cout << "��ѡ�����������0�ٿ�һ�����ѡ��" << endl;
    cout << "1.���ݵ��Ų�ѯ�˵�" << endl;
    cout << "2.���ݿ����𡢼ļ�����Ϣ�ͼļ����ڲ�ѯ�˵�" << endl;
    cout << "3.���ݿ�������ռ�����Ϣ��ѯ�˵�" << endl;
    cout << "4.�˳���ǰ�û�" << endl;
    cout << "5.�˳�" << endl;
}

void getAdminMenu(){
    cout << "��ѡ�����������0�ٿ�һ�����ѡ��" << endl;
    cout << "1.�����˵�" << endl;
    cout << "2.ɾ���˵�" << endl;
    cout << "3.�޸��˵�" << endl;
    cout << "4.��ʾ�����˵�" << endl;
    cout << "5.���ݵ��Ų�ѯ�˵�" << endl;
    cout << "6.���ݿ������ѯ�����˵�" << endl;
    cout << "7.�����ռ����ڲ�ѯ�����˵�" << endl;
    cout << "8.���ݼļ����ڲ�ѯ�����˵�" << endl;
    cout << "9.�����ռ�����ͳ�ƿ�ݵ������ͽ��" << endl;
    cout << "10.���ݼļ�������ʾδǩ�յĿ�ݵ�������ʾ�������Ѽ�" << endl;
    cout << "11.�������Ϣ����������" << endl;
    cout << "12.�������Ϣ���������" << endl;
    cout << "13.�������Ϣ���������" << endl;
    cout << "14.�����˵���Ϣ���ļ�" << endl;
    cout << "15.���ļ��ж�ȡ�˵���Ϣ" << endl;
    cout << "16.�˳�����Ա�˺ţ������û�ģʽ" << endl;
    cout << "17.�˳�" << endl;
}
