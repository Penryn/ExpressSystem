#include "time.cpp"
#include "people.cpp"
#include "express_waybill.cpp"
#include "list.cpp"
#include "menu.cpp"
#include "file.cpp"
using namespace std;


int main() {
    ExpressWaybillList expressWaybillList;
    // 读取文件中的运单信息
    expressWaybillList.loadExpressWaybillFromFile();
    cout << "快递运单管理系统初始化完成" << endl;
    int user_type; //1:普通用户 2:管理员
    string key = getKeyFromFile();
    string password;
    cout << "请输入管理员密码，输入正确密码进入管理员模式，输入其他则进入用户模式" << endl;
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
                    cout << "请输入管理员密码，输入正确密码进入管理员模式，输入其他则进入用户模式" << endl;
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
                    cout << "无效的选项" << endl;
                } else {
                    expressWaybillList.getExpressWaybillByType();
                }
                break;
            case 7:
                if (user_type == 1) {
                    cout << "无效的选项" << endl;
                } else {
                    expressWaybillList.getExpressWaybillByReceiveDate();
                }
                break;
            case 8:
                if (user_type == 1) {
                    cout << "无效的选项" << endl;
                } else {
                    expressWaybillList.getExpressWaybillBySendDate();
                }
                break;
            case 9:
                if (user_type == 1) {
                    cout << "无效的选项" << endl;
                } else {
                    expressWaybillList.getExpressWaybillAndCountByReceiveDate();
                }
                break;
            case 10:
                if (user_type == 1) {
                    cout << "无效的选项" << endl;
                } else {
                    expressWaybillList.getNotReceivedExpressWaybillBySendDate();
                }
                break;
            case 11:
                if (user_type == 1) {
                    cout << "无效的选项" << endl;
                } else {
                    expressWaybillList.sortExpressWaybillByDate();
                }
                break;
            case 12:
                if (user_type == 1) {
                    cout << "无效的选项" << endl;
                } else {
                    expressWaybillList.sortExpressWaybillByType();
                }
                break;
            case 13:
                if (user_type == 1) {
                    cout << "无效的选项" << endl;
                } else {
                    expressWaybillList.sortExpressWaybillByAmount();
                }
                break;
            case 14:
                if (user_type == 1) {
                    cout << "无效的选项" << endl;
                } else {
                    expressWaybillList.saveExpressWaybillToFile();
                }
                break;
            case 15:
                if (user_type == 1) {
                    cout << "无效的选项" << endl;
                } else {
                    expressWaybillList.loadExpressWaybillFromFile();
                    cout<<"从文件中读取运单信息成功"<<endl;
                }
                break;
            case 16:
                if (user_type == 1) {
                    cout << "无效的选项" << endl;
                } else {
                    cout << "退出当前管理员" << endl;
                    user_type = 1;
                    getUserMenu();
                }
                break;
            case 17:
                if (user_type == 1) {
                    cout << "无效的选项" << endl;
                } else {
                    cout << "退出" << endl;
                    return 0;
                }
                break;
            default:
                cout << "无效的选项" << endl;
                break;

        }
        cout<<"================================"<<endl;
        cout << "请选择操作，输入0重新查看操作选择" << endl;
        choice =getInput<int>();
    }
}