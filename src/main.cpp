#include "time.cpp"
#include "people.cpp"
#include "express_waybill.cpp"
#include "list.cpp"
#include "menu.cpp"
#include "file.cpp"
using namespace std;


int main() {
    ExpressWaybillList expressWaybillList;
    // ��ȡ�ļ��е��˵���Ϣ
    expressWaybillList.loadExpressWaybillFromFile();
    cout << "����˵�����ϵͳ��ʼ�����" << endl;
    int user_type; //1:��ͨ�û� 2:����Ա
    string key = getKeyFromFile();
    string password;
    cout << "���������Ա���룬������ȷ����������Աģʽ����������������û�ģʽ" << endl;
    cin >> password;
    if (password != key) {
        user_type = 1;
    } else {
        user_type = 2;
    }
    int choice;
    if (user_type == 1) {
        getUserMenu();
    } else {
        getAdminMenu();
    }
    choice = getInput<int>();
    while (true) {
        switch (choice) {
            case 0:
                if (user_type == 1) {
                    getUserMenu();
                } else {
                    getAdminMenu();
                }
                break;
            case 1:
                if (user_type == 1) {
                    expressWaybillList.getExpressWaybillByNumber();
                } else {
                    expressWaybillList.addExpressWaybill();
                }
                break;
            case 2:
                if (user_type == 1) {
                    expressWaybillList.getExpressWaybillByTypeAndSenderAndDate();
                } else {
                    expressWaybillList.deleteExpressWaybill();
                }
                break;
            case 3:
                if (user_type == 1) {
                    expressWaybillList.getExpressWaybillByTypeAndReceiver();
                } else {
                    expressWaybillList.updateExpressWaybill();
                }
                break;
            case 4:
                if (user_type == 1) {
                    cout << "���������Ա���룬������ȷ����������Աģʽ����������������û�ģʽ" << endl;
                    cin >> password;
                    if (password != key) {
                        user_type = 1;
                    } else {
                        user_type = 2;
                    }
                    if (user_type == 1) {
                        getUserMenu();
                    } else {
                        getAdminMenu();
                    }
                } else {
                    expressWaybillList.displayExpressWaybill();
                }
                break;
            case 5:
                if (user_type == 1) {
                    return 0;
                } else {
                    expressWaybillList.getExpressWaybillByNumber();
                }
                break;
            case 6:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    expressWaybillList.getExpressWaybillByType();
                }
                break;
            case 7:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    expressWaybillList.getExpressWaybillByReceiveDate();
                }
                break;
            case 8:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    expressWaybillList.getExpressWaybillBySendDate();
                }
                break;
            case 9:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    expressWaybillList.getExpressWaybillAndCountByReceiveDate();
                }
                break;
            case 10:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    expressWaybillList.getNotReceivedExpressWaybillBySendDate();
                }
                break;
            case 11:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    expressWaybillList.sortExpressWaybillByDate();
                }
                break;
            case 12:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    expressWaybillList.sortExpressWaybillByType();
                }
                break;
            case 13:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    expressWaybillList.sortExpressWaybillByAmount();
                }
                break;
            case 14:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    expressWaybillList.saveExpressWaybillToFile();
                }
                break;
            case 15:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    expressWaybillList.loadExpressWaybillFromFile();
                    cout<<"���ļ��ж�ȡ�˵���Ϣ�ɹ�"<<endl;
                }
                break;
            case 16:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    cout << "�˳���ǰ����Ա" << endl;
                    user_type = 1;
                    getUserMenu();
                }
                break;
            case 17:
                if (user_type == 1) {
                    cout << "��Ч��ѡ��" << endl;
                } else {
                    cout << "�˳�" << endl;
                    return 0;
                }
                break;
            default:
                cout << "��Ч��ѡ��" << endl;
                break;

        }
        cout<<"================================"<<endl;
        cout << "��ѡ�����������0���²鿴����ѡ��" << endl;
        choice =getInput<int>();
    }
}