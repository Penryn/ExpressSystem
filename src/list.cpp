#include "../include/list.h"
#include "mid.cpp"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


ExpressWaybillList::ExpressWaybillList() {
    head = new ExpressWaybill();
    tail = head;
    length = 0;
}

ExpressWaybillList::~ExpressWaybillList() {
    ExpressWaybill *p = head;
    while (p != NULL) {
        ExpressWaybill *q = p;
        p = p->next;
        delete q;
    }
}

void ExpressWaybillList::addExpressWaybill() {
    cout << "请输入运单号,输入0结束" << endl;
    string waybillNumber;
    while (cin >> waybillNumber) {
        if (waybillNumber == "0") {
            break;
        }
        if (searchExpressWaybillByNumber(waybillNumber)) {
            cout << "运单号已存在，请重新输入" << endl;
            continue;
        }
        ExpressWaybill *expressWaybill = new ExpressWaybill();
        expressWaybill->setWaybillNumber(waybillNumber);
        cout << "请输入快递类型 1:派送单 2:收件单" << endl;
        int waybillType;
        waybillType= getRightInput(a, 2);
        expressWaybill->setWaybillType(waybillType);
        cout << "请输入寄件人信息" << endl;
        Sender sender;
        cout << "请输入地址" << endl;
        string address;
        cin >> address;
        sender.setAddress(address);
        cout << "请输入电话" << endl;
        string phone;
        cin >> phone;
        sender.setPhone(phone);
        cout << "请输入备注" << endl;
        string remark;
        cin >> remark;
        sender.setRemark(remark);
        cout << "请输入派送时间，输入年 月 日，用空格分隔" << endl;
        Time sendTime;
        sendTime= getTimeInput();
        sender.setSendTime(sendTime);
        expressWaybill->setSender(sender);
        cout << "请输入收件人信息" << endl;
        Receiver receiver;
        cout << "请输入地址" << endl;
        cin >> address;
        receiver.setAddress(address);
        cout << "请输入电话" << endl;
        cin >> phone;
        receiver.setPhone(phone);
        cout << "请输入备注" << endl;
        cin >> remark;
        receiver.setRemark(remark);
        Time receiveTime;
        cout << "请输入收件时间，输入年 月 日，用空格分隔" << endl;
        receiveTime= getTimeInput();
        receiver.setReceiveTime(receiveTime);
        expressWaybill->setReceiver(receiver);
        cout << "请输入是否签收 1:是 0:否" << endl;
        bool isSign;
        isSign= getRightInput(b, 2);
        expressWaybill->setIsSign(isSign);
        if (!isSign) {
            cout << "请输入是否为难派件 1:是 0:否" << endl;
            bool isDifficult;
            isDifficult= getRightInput(b, 2);
            expressWaybill->setIsDifficult(isDifficult);
            if (isDifficult) {
                cout << "请输入难派件原因 1：地址模糊 2：用户拒收 3：电话无效 4：收件人不在 5：其他" << endl;
                int difficultReason;
                difficultReason= getRightInput(c, 5);
                expressWaybill->setDifficultReason(difficultReason);
            } else {
                expressWaybill->setDifficultReason(0);
            }
        } else {
            expressWaybill->setIsDifficult(false);
            expressWaybill->setDifficultReason(0);
        }
        cout << "请输入金额" << endl;
        double amount;
        amount= getInput<double>();
        expressWaybill->setAmount(amount);
        tail->next = expressWaybill;
        tail = expressWaybill;
        length++;
        cout << "请输入运单号,输入0结束" << endl;
    }
}

void ExpressWaybillList::displayExpressWaybill() {
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        cout << "运单号：" << p->getWaybillNumber() << endl;
        cout << "快递类型：";
        if (p->getWaybillType() == 1) {
            cout << "派送单" << endl;
        } else {
            cout << "收件单" << endl;
        }
        cout << "寄件人信息：" << endl;
        cout << "地址：" << p->getSender().getAddress() << endl;
        cout << "电话：" << p->getSender().getPhone() << endl;
        cout << "备注：" << p->getSender().getRemark() << endl;
        cout << "收件人信息：" << endl;
        cout << "地址：" << p->getReceiver().getAddress() << endl;
        cout << "电话：" << p->getReceiver().getPhone() << endl;
        cout << "备注：" << p->getReceiver().getRemark() << endl;
        cout << "派送时间：" << p->getSender().getSendTime().getTime() << endl;
        cout << "收件时间：" << p->getReceiver().getReceiveTime().getTime() << endl;
        cout << "是否签收：";
        if (p->getIsSign()) {
            cout << "是" << endl;
        } else {
            cout << "否" << endl;
        }
        cout << "是否为难派件：";
        if (p->getIsDifficult()) {
            cout << "是" << endl;
        } else {
            cout << "否" << endl;
        }
        cout << "难派件原因：";
        switch (p->getDifficultReason()) {
            case 1:
                cout << "地址模糊" << endl;
                break;
            case 2:
                cout << "用户拒收" << endl;
                break;
            case 3:
                cout << "电话无效" << endl;
                break;
            case 4:
                cout << "收件人不在" << endl;
                break;
            case 5:
                cout << "其他" << endl;
                break;
            default:
                cout << "未知原因" << endl;
                break;
        }
        cout << "金额：" << p->getAmount() << endl;
        cout << "--------------------------------" << endl;
        p = p->next;
    }
}

void ExpressWaybillList::deleteExpressWaybill() {
    cout << "请输入要删除的运单号,输入0结束" << endl;
    string waybillNumber;
    while (cin >> waybillNumber) {
        if (waybillNumber == "0") {
            break;
        }
        if (head->next == NULL) {
            cout << "列表为空，无法删除。" << endl;
            break;
        }
        ExpressWaybill *p = head;
        bool isFound = false;
        while (p->next != NULL) {
            if (p->next->getWaybillNumber() == waybillNumber) {
                ExpressWaybill *q = p->next;
                p->next = q->next;
                if (q == tail) {
                    tail = p;
                }
                delete q;
                length--;
                isFound = true;
                cout << "运单号为 " << waybillNumber << " 的运单已删除" << endl;
                break;
            }
            p = p->next;
        }
        if (!isFound) {
            cout << "未找到运单号为 " << waybillNumber << " 的运单。" << endl;
        }
        cout << "请输入要删除的运单号,输入0结束" << endl;
    }
}

void ExpressWaybillList::updateExpressWaybill() {
    cout << "请输入要修改的运单号,输入0结束" << endl;
    string waybillNumber;
    while (cin >> waybillNumber) {
        if (waybillNumber == "0") {
            break;
        }
        ExpressWaybill *p = head->next;
        bool isFound = false;
        while (p != NULL) {
            if (p->getWaybillNumber() == waybillNumber) {
                isFound = true;
                cout << "原快递类型：";
                if (p->getWaybillType() == 1) {
                    cout << "派送单" << endl;
                } else {
                    cout << "收件单" << endl;
                }
                cout << "你是否要修改快递类型 1:是 0:否" << endl;
                bool change;
                change = getRightInput(b, 2);
                if (change) {
                    cout << "请输入快递类型 1:派送单 2:收件单" << endl;
                    int waybillType;
                    waybillType= getRightInput(a, 2);
                    p->setWaybillType(waybillType);
                } else {
                    p->setWaybillType(p->getWaybillType());
                }
                cout << "原寄件人信息：" << endl;
                cout << "地址：" << p->getSender().getAddress() << endl;
                cout << "电话：" << p->getSender().getPhone() << endl;
                cout << "备注：" << p->getSender().getRemark() << endl;
                cout << "你是否要修改寄件人信息 1:是 0:否" << endl;
                change = getRightInput(b, 2);
                if (change) {
                    cout << "请输入地址" << endl;
                    string address;
                    cin >> address;
                    p->getSender().setAddress(address);
                    cout << "请输入电话" << endl;
                    string phone;
                    cin >> phone;
                    p->getSender().setPhone(phone);
                    cout << "请输入备注" << endl;
                    string remark;
                    cin >> remark;
                    p->getSender().setRemark(remark);
                } else {
                    p->getSender().setAddress(p->getSender().getAddress());
                    p->getSender().setPhone(p->getSender().getPhone());
                    p->getSender().setRemark(p->getSender().getRemark());
                }
                cout << "原收件人信息：" << endl;
                cout << "地址：" << p->getReceiver().getAddress() << endl;
                cout << "电话：" << p->getReceiver().getPhone() << endl;
                cout << "备注：" << p->getReceiver().getRemark() << endl;
                cout << "你是否要修改收件人信息 1:是 0:否" << endl;
                change = getRightInput(b, 2);
                if (change) {
                    cout << "请输入地址" << endl;
                    string address;
                    cin >> address;
                    p->getReceiver().setAddress(address);
                    cout << "请输入电话" << endl;
                    string phone;
                    cin >> phone;
                    p->getReceiver().setPhone(phone);
                    cout << "请输入备注" << endl;
                    string remark;
                    cin >> remark;
                    p->getReceiver().setRemark(remark);
                } else {
                    p->getReceiver().setAddress(p->getReceiver().getAddress());
                    p->getReceiver().setPhone(p->getReceiver().getPhone());
                    p->getReceiver().setRemark(p->getReceiver().getRemark());
                }
                cout << "原派送时间：" << p->getSender().getSendTime().getTime() << endl;
                cout << "你是否要修改派送时间 1:是 0:否" << endl;
                change = getRightInput(b, 2);
                if (change) {
                    cout << "请输入派送时间,输入年 月 日，用空格分隔" << endl;
                    Time sendTime;
                    sendTime= getTimeInput();
                    p->getSender().setSendTime(sendTime);
                } else {
                    p->getSender().setSendTime(p->getSender().getSendTime());
                }
                cout << "原收件时间：" << p->getReceiver().getReceiveTime().getTime() << endl;
                cout << "你是否要修改收件时间 1:是 0:否" << endl;
                change = getRightInput(b, 2);
                if (change) {
                    cout << "请输入收件时间,输入年 月 日，用空格分隔" << endl;
                    Time receiveTime;
                    receiveTime= getTimeInput();
                    p->getReceiver().setReceiveTime(receiveTime);
                } else {
                    p->getReceiver().setReceiveTime(p->getReceiver().getReceiveTime());
                }
                cout << "原是否签收：";
                if (p->getIsSign()) {
                    cout << "是" << endl;
                } else {
                    cout << "否" << endl;
                }
                cout << "你是否要修改是否签收 1:是 0:否" << endl;
                change = getRightInput(b, 2);
                if (change) {
                    cout << "请输入是否签收 1:是 0:否" << endl;
                    bool isSign;
                    isSign= getRightInput(b, 2);
                    p->setIsSign(isSign);
                } else {
                    p->setIsSign(p->getIsSign());
                }
                if (!p->getIsSign()) {
                    cout << "原是否为难派件：";
                    if (p->getIsDifficult()) {
                        cout << "是" << endl;
                    } else {
                        cout << "否" << endl;
                    }
                    cout << "你是否要修改是否为难派件 1:是 0:否" << endl;
                    change = getRightInput(b, 2);
                    if (change) {
                        cout << "请输入是否为难派件 1:是 0:否" << endl;
                        bool isDifficult;
                        isDifficult= getRightInput(b, 2);
                        p->setIsDifficult(isDifficult);
                        if (isDifficult) {
                            cout << "请输入难派件原因 1：地址模糊 2：用户拒收 3：电话无效 4：收件人不在 5：其他" << endl;
                            int difficultReason;
                            difficultReason= getRightInput(c, 5);
                            p->setDifficultReason(difficultReason);
                        } else {
                            p->setDifficultReason(0);
                        }
                    } else {
                        p->setIsDifficult(p->getIsDifficult());
                        p->setDifficultReason(p->getDifficultReason());
                    }
                } else {
                    p->setIsDifficult(false);
                    p->setDifficultReason(0);
                }
                cout << "原金额：" << p->getAmount() << endl;
                cout << "你是否要修改金额 1:是 0:否" << endl;
                change = getRightInput(b, 2);
                if (change) {
                    cout << "请输入金额" << endl;
                    double amount;
                    amount= getInput<double>();
                    p->setAmount(amount);
                } else {
                    p->setAmount(p->getAmount());
                }
                cout << "运单号为 " << waybillNumber << " 的运单修改成功" << endl;
                break;
            }
            p = p->next;
        }
        if (!isFound) {
            cout << "未找到运单号为 " << waybillNumber << " 的运单。" << endl;
        }
        cout << "请输入要修改的运单号,输入0结束" << endl;
    }
}

void ExpressWaybillList::saveExpressWaybillToFile() {
    ofstream outputFile("./data/waybills.csv"); // 创建 CSV 文件
    if (!outputFile.is_open()) {
        cout << "无法打开文件！" << endl;
        return;
    }
    // 写入 CSV 文件的标题行
    outputFile<< "运单号,快递类型,寄件人地址,寄件人电话,寄件人备注,收件人地址,收件人电话,收件人备注,派送时间,收件时间,是否签收,是否为难派件,难派件原因,金额\n";

    if (!head) {
        cout << "列表为空，无法保存到文件。" << endl;
        outputFile.close();
        return;
    }

    ExpressWaybill *p = head->next;
    while (p != NULL) {
        outputFile << p->getWaybillNumber() << ",";
        outputFile << (p->getWaybillType() == 1 ? "派送单" : "收件单") << ",";
        outputFile << p->getSender().getAddress() << ",";
        outputFile << p->getSender().getPhone() << ",";
        outputFile << p->getSender().getRemark() << ",";
        outputFile << p->getReceiver().getAddress() << ",";
        outputFile << p->getReceiver().getPhone() << ",";
        outputFile << p->getReceiver().getRemark() << ",";
        outputFile << p->getSender().getSendTime().getTime() << ",";
        outputFile << p->getReceiver().getReceiveTime().getTime() << ",";
        outputFile << (p->getIsSign() ? "是" : "否") << ",";
        outputFile << (p->getIsDifficult() ? "是" : "否") << ",";
        switch (p->getDifficultReason()) {
            case 0:
                outputFile << "无";
                break;
            case 1:
                outputFile << "地址模糊";
                break;
            case 2:
                outputFile << "用户拒收";
                break;
            case 3:
                outputFile << "电话无效";
                break;
            case 4:
                outputFile << "收件人不在";
                break;
            case 5:
                outputFile << "其他";
                break;
            default:
                outputFile << "未知原因";
                break;
        }
        outputFile << ",";
        outputFile << p->getAmount() << ",\n";

        p = p->next;
    }
    outputFile.close(); // 关闭文件
    cout << "运单信息已成功保存到 waybills.csv 文件。" << endl;
}

void ExpressWaybillList::loadExpressWaybillFromFile() {
    ifstream inputFile("./data/waybills.csv"); // 打开 CSV 文件
    if (!inputFile.is_open()) {
        cout << "无法打开文件！" << endl;
        return;
    }
    string line;
    getline(inputFile, line); // 读取标题行
    while (getline(inputFile, line)) {
        ExpressWaybill *expressWaybill = new ExpressWaybill();
        string waybillNumber;
        int waybillType;
        string senderAddress;
        string senderPhone;
        string senderRemark;
        string receiverAddress;
        string receiverPhone;
        string receiverRemark;
        string sendTime;
        string receiveTime;
        bool isSign;
        bool isDifficult;
        int difficultReason;
        double amount;
        // 从 CSV 文件中读取数据
        size_t pos = 0;
        string token;
        int i = 0;
        while ((pos = line.find(",")) != string::npos) {
            token = line.substr(0, pos);
            switch (i) {
                case 0:
                    waybillNumber = token;
                    break;
                case 1:
                    waybillType = token == "派送单" ? 1 : 2;
                    break;
                case 2:
                    senderAddress = token;
                    break;
                case 3:
                    senderPhone = token;
                    break;
                case 4:
                    senderRemark = token;
                    break;
                case 5:
                    receiverAddress = token;
                    break;
                case 6:
                    receiverPhone = token;
                    break;
                case 7:
                    receiverRemark = token;
                    break;
                case 8:
                    sendTime = token;
                    break;
                case 9:
                    receiveTime = token;
                    break;
                case 10:
                    isSign = token == "是";
                    break;
                case 11:
                    isDifficult = token == "是";
                    break;
                case 12:
                    difficultReason =token == "地址模糊" ? 1 : token == "用户拒收" ? 2 : token == "电话无效" ? 3 : token =="收件人不在"? 4 : token =="其他"? 5 : 0;
                    break;
                case 13:
                    amount = stod(token);
                    break;
            }
            line.erase(0, pos + 1);
            i++;
        }
        expressWaybill->setWaybillNumber(waybillNumber);
        expressWaybill->setWaybillType(waybillType);
        Sender sender;
        sender.setAddress(senderAddress);
        sender.setPhone(senderPhone);
        sender.setRemark(senderRemark);
        Time sendTimeObj;
        pos = 0;
        int datePart = 0;
        while ((pos = sendTime.find("-")) != string::npos) {
            token = sendTime.substr(0, pos);
            switch (datePart) {
                case 0: // Year
                    sendTimeObj.setTime(stoi(token), 0, 0);
                    break;
                case 1: // Month
                    sendTimeObj.setTime(sendTimeObj.getYear(), stoi(token), 0);
                    break;
                case 2: // Day
                    sendTimeObj.setTime(sendTimeObj.getYear(), sendTimeObj.getMonth(), stoi(token));
                    break;
            }
            sendTime.erase(0, pos + 1);
            datePart++;
        }
        if (!sendTime.empty()) {
            sendTimeObj.setTime(sendTimeObj.getYear(), sendTimeObj.getMonth(), stoi(sendTime));
        }
        sender.setSendTime(sendTimeObj);
        expressWaybill->setSender(sender);
        Receiver receiver;
        receiver.setAddress(receiverAddress);
        receiver.setPhone(receiverPhone);
        receiver.setRemark(receiverRemark);
        Time receiveTimeObj;
        pos = 0;
        datePart = 0;
        while ((pos = receiveTime.find("-")) != string::npos) {
            token = receiveTime.substr(0, pos);
            switch (datePart) {
                case 0: // Year
                    receiveTimeObj.setTime(stoi(token), 0, 0);
                    break;
                case 1: // Month
                    receiveTimeObj.setTime(receiveTimeObj.getYear(), stoi(token), 0);
                    break;
                case 2: // Day
                    cout<<stoi(token)<<endl;
                    receiveTimeObj.setTime(receiveTimeObj.getYear(), receiveTimeObj.getMonth(), stoi(token));
                    break;
            }
            receiveTime.erase(0, pos + 1);
            datePart++;
        }
        if (!receiveTime.empty()) {
            receiveTimeObj.setTime(receiveTimeObj.getYear(), receiveTimeObj.getMonth(), stoi(receiveTime));
        }
        receiver.setReceiveTime(receiveTimeObj);
        expressWaybill->setReceiver(receiver);
        expressWaybill->setIsSign(isSign);
        expressWaybill->setIsDifficult(isDifficult);
        expressWaybill->setDifficultReason(difficultReason);
        expressWaybill->setAmount(amount);
        tail->next = expressWaybill;
        tail = expressWaybill;
        length++;
    }
    inputFile.close(); // 关闭文件
}

void ExpressWaybillList::getExpressWaybillByNumber() {
    cout << "请输入要查询的运单号" << endl;
    string waybillNumber;
    cin >> waybillNumber;
    ExpressWaybill *p = head->next;
    bool isFound = false;
    while (p != NULL) {
        if (p->getWaybillNumber() == waybillNumber) {
            isFound = true;
            cout << "运单号：" << p->getWaybillNumber() << endl;
            cout << "快递类型：";
            if (p->getWaybillType() == 1) {
                cout << "派送单" << endl;
            } else {
                cout << "收件单" << endl;
            }
            cout << "寄件人信息：" << endl;
            cout << "地址：" << p->getSender().getAddress() << endl;
            cout << "电话：" << p->getSender().getPhone() << endl;
            cout << "备注：" << p->getSender().getRemark() << endl;
            cout << "收件人信息：" << endl;
            cout << "地址：" << p->getReceiver().getAddress() << endl;
            cout << "电话：" << p->getReceiver().getPhone() << endl;
            cout << "备注：" << p->getReceiver().getRemark() << endl;
            cout << "派送时间：" << p->getSender().getSendTime().getTime() << endl;
            cout << "收件时间：" << p->getReceiver().getReceiveTime().getTime() << endl;
            cout << "是否签收：";
            if (p->getIsSign()) {
                cout << "是" << endl;
            } else {
                cout << "否" << endl;
            }
            cout << "是否为难派件：";
            if (p->getIsDifficult()) {
                cout << "是" << endl;
            } else {
                cout << "否" << endl;
            }
            cout << "难派件原因：";
            switch (p->getDifficultReason()) {
                case 1:
                    cout << "地址模糊" << endl;
                    break;
                case 2:
                    cout << "用户拒收" << endl;
                    break;
                case 3:
                    cout << "电话无效" << endl;
                    break;
                case 4:
                    cout << "收件人不在" << endl;
                    break;
                case 5:
                    cout << "其他" << endl;
                    break;
                default:
                    cout << "未知原因" << endl;
                    break;
            }
            cout << "金额：" << p->getAmount() << endl;
            cout << "--------------------------------" << endl;
            break;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "未找到运单号为 " << waybillNumber << " 的运单。" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByTypeAndSenderAndDate() {
    cout << "请输入要查询的快递类型 1:派送单 2:收件单" << endl;
    int waybillType;
    waybillType= getRightInput(a, 2);
    cout << "请输入寄件人地址" << endl;
    string senderAddress;
    cin >> senderAddress;
    cout << "请输入寄件日期，输入年 月 日，用空格分隔" << endl;
    Time sendTime;
    sendTime = getTimeInput();
    ExpressWaybill *p = head->next;
    bool isFound = false;
    while (p != NULL) {
        if (p->getWaybillType() == waybillType && p->getSender().getAddress() == senderAddress &&
            p->getSender().getSendTime().getTime()==sendTime.getTime() ){
            isFound = true;
            cout << "运单号：" << p->getWaybillNumber() << endl;
            cout << "快递类型：";
            if (p->getWaybillType() == 1) {
                cout << "派送单" << endl;
            } else {
                cout << "收件单" << endl;
            }
            cout << "寄件人信息：" << endl;
            cout << "地址：" << p->getSender().getAddress() << endl;
            cout << "电话：" << p->getSender().getPhone() << endl;
            cout << "备注：" << p->getSender().getRemark() << endl;
            cout << "收件人信息：" << endl;
            cout << "地址：" << p->getReceiver().getAddress() << endl;
            cout << "电话：" << p->getReceiver().getPhone() << endl;
            cout << "备注：" << p->getReceiver().getRemark() << endl;
            cout << "派送时间：" << p->getSender().getSendTime().getTime() << endl;
            cout << "收件时间：" << p->getReceiver().getReceiveTime().getTime() << endl;
            cout << "是否签收：";
            if (p->getIsSign()) {
                cout << "是" << endl;
            } else {
                cout << "否" << endl;
            }
            cout << "是否为难派件：";
            if (p->getIsDifficult()) {
                cout << "是" << endl;
            } else {
                cout << "否" << endl;
            }
            cout << "难派件原因：";
            switch (p->getDifficultReason()) {
                case 1:
                    cout << "地址模糊" << endl;
                    break;
                case 2:
                    cout << "用户拒收" << endl;
                    break;
                case 3:
                    cout << "电话无效" << endl;
                    break;
                case 4:
                    cout << "收件人不在" << endl;
                    break;
                case 5:
                    cout << "其他" << endl;
                    break;
                default:
                    cout << "未知原因" << endl;
                    break;
            }
            cout << "金额：" << p->getAmount() << endl;
            cout << "--------------------------------" << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "未找到快递类型为 " << waybillType << " 寄件人地址为 " << senderAddress << " 寄件日期为 " << sendTime.getTime()
             << " 的运单。" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByTypeAndReceiver() {
    cout << "请输入要查询的快递类型 1:派送单 2:收件单" << endl;
    int waybillType;
    cin >> waybillType;
    cout << "请输入收件人地址" << endl;
    string receiverAddress;
    cin >> receiverAddress;
    cout << "请输入收件人电话" << endl;
    string receiverPhone;
    cin >> receiverPhone;
    ExpressWaybill *p = head->next;
    cout << "查询结果如下：" << endl;
    bool isFound = false;
    while (p != NULL) {
        if (p->getWaybillType() == waybillType && p->getReceiver().getAddress() == receiverAddress &&
            p->getReceiver().getPhone() == receiverPhone) {
            isFound = true;
            cout << "运单号：" << p->getWaybillNumber() << endl;
            cout << "快递类型：";
            if (p->getWaybillType() == 1) {
                cout << "派送单" << endl;
            } else {
                cout << "收件单" << endl;
            }
            cout << "寄件人信息：" << endl;
            cout << "地址：" << p->getSender().getAddress() << endl;
            cout << "电话：" << p->getSender().getPhone() << endl;
            cout << "备注：" << p->getSender().getRemark() << endl;
            cout << "收件人信息：" << endl;
            cout << "地址：" << p->getReceiver().getAddress() << endl;
            cout << "电话：" << p->getReceiver().getPhone() << endl;
            cout << "备注：" << p->getReceiver().getRemark() << endl;
            cout << "派送时间：" << p->getSender().getSendTime().getTime() << endl;
            cout << "收件时间：" << p->getReceiver().getReceiveTime().getTime() << endl;
            cout << "是否签收：";
            if (p->getIsSign()) {
                cout << "是" << endl;
            } else {
                cout << "否" << endl;
            }
            cout << "是否为难派件：";
            if (p->getIsDifficult()) {
                cout << "是" << endl;
            } else {
                cout << "否" << endl;
            }
            cout << "难派件原因：";
            switch (p->getDifficultReason()) {
                case 1:
                    cout << "地址模糊" << endl;
                    break;
                case 2:
                    cout << "用户拒收" << endl;
                    break;
                case 3:
                    cout << "电话无效" << endl;
                    break;
                case 4:
                    cout << "收件人不在" << endl;
                    break;
                case 5:
                    cout << "其他" << endl;
                    break;
                default:
                    cout << "未知原因" << endl;
                    break;
            }
            cout << "金额：" << p->getAmount() << endl;
            cout << "--------------------------------" << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "未找到快递类型为 " << waybillType << " 收件人地址为 " << receiverAddress << " 收件人电话为 "
             << receiverPhone << " 的运单。" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByType() {
    cout << "请输入要查询的快递类型 1:派送单 2:收件单" << endl;
    int waybillType;
    cin >> waybillType;
    ExpressWaybill *p = head->next;
    bool isFound = false;
    cout << "查询结果如下：" << endl;
    while (p != NULL) {
        if (p->getWaybillType() == waybillType) {
            isFound = true;
            cout << "运单号：" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "未找到快递类型为 " << waybillType << " 的运单。" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByReceiveDate() {
    cout << "请输入要查询的收件日期，输入年 月 日,用空格分隔" << endl;
    Time receiveTime = getTimeInput();
    ExpressWaybill *p = head->next;
    bool isFound = false;
    cout << "查询结果如下：" << endl;
    while (p != NULL) {
        if (p->getReceiver().getReceiveTime().getTime() == receiveTime.getTime()) {
            isFound = true;
            cout << "运单号：" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "未找到收件日期为 " << receiveTime.getTime() << " 的运单。" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillBySendDate() {
    cout << "请输入要查询的派送日期，输入年 月 日,用空格分隔" << endl;
    Time sendTime = getTimeInput();
    ExpressWaybill *p = head->next;
    cout << "查询结果如下：" << endl;
    bool isFound = false;
    while (p != NULL) {
        if (p->getSender().getSendTime().getTime() == sendTime.getTime()) {
            isFound = true;
            cout << "运单号：" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "未找到派送日期为 " << sendTime.getTime() << " 的运单。" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillAndCountByReceiveDate() {
    cout << "请输入要查询的收件日期，输入年 月 日,用空格分隔" << endl;
    Time receiveTime = getTimeInput();
    int count = 0;
    double amount = 0;
    ExpressWaybill *p = head->next;
    bool isFound = false;
    while (p != NULL) {
        if (p->getReceiver().getReceiveTime().getTime() == receiveTime.getTime()) {
            isFound = true;
            count++;
            amount += p->getAmount();
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "未找到收件日期为 " << receiveTime.getTime() << " 的运单。" << endl;
        return;
    }else{
        cout << "收件日期为" << receiveTime.getTime() << "的快递单数量为" << count << "，总金额为" << amount << "元。" << endl;
    }
}

void ExpressWaybillList::getNotReceivedExpressWaybillBySendDate() {
    cout << "请输入要查询的寄件日期，输入年 月 日,用空格分隔" << endl;
    Time sendTime = getTimeInput();
    ExpressWaybill *p = head->next;
    cout << "查询结果如下：" << endl;
    bool isFound = false;
    while (p != NULL) {
        if (p->getSender().getSendTime().getTime() == sendTime.getTime() && !p->getIsSign()) {
            isFound = true;
            cout << "运单号：" << p->getWaybillNumber() << endl;
            if (p->getIsDifficult()) {
                cout << "难派件原因：";
                switch (p->getDifficultReason()) {
                    case 1:
                        cout << "地址模糊" << endl;
                        break;
                    case 2:
                        cout << "用户拒收" << endl;
                        break;
                    case 3:
                        cout << "电话无效" << endl;
                        break;
                    case 4:
                        cout << "收件人不在" << endl;
                        break;
                    case 5:
                        cout << "其他" << endl;
                        break;
                    default:
                        cout << "未知原因" << endl;
                        break;
                }
            }
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "未找到寄件日期为 " << sendTime.getTime() << " 且未签收的运单。" << endl;
    }
}

// 根据派送时间排序
void ExpressWaybillList::sortExpressWaybillByDate() {
    if (head == NULL ) {
        cout<<"链表为空，无需排序"<<endl;
        return; // 如果链表为空或只有一个节点，无需排序
    }else if(head->next == NULL){
        cout<<"运单号："<<head->getWaybillNumber()<<endl; // 输出头节点的运单号
        cout<<"派送时间："<<head->getSender().getSendTime().getTime()<<endl; // 输出头节点的派送时间
        cout<<"收件时间："<<head->getReceiver().getReceiveTime().getTime()<<endl; // 输出头节点的收件时间
        return;
    }

    cout<<"想要根据什么时间排序？1.派送时间 2.收件时间"<<endl;
    int time;
    time = getRightInput(b, 2);
    cout<<"排序后的结果如下："<<endl;
    // 创建一个临时数组
    vector<ExpressWaybill*> tempArray;
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        tempArray.push_back(p);
        p = p->next;
    }

    // 对临时数组进行排序
    if(time == 1){
        sort(tempArray.begin(), tempArray.end(), [](ExpressWaybill* a, ExpressWaybill* b) {
            return a->getSender().getSendTime().getYear() < b->getSender().getSendTime().getYear() ||
                   (a->getSender().getSendTime().getYear() == b->getSender().getSendTime().getYear() &&
                    a->getSender().getSendTime().getMonth() < b->getSender().getSendTime().getMonth()) ||
                   (a->getSender().getSendTime().getYear() == b->getSender().getSendTime().getYear() &&
                    a->getSender().getSendTime().getMonth() == b->getSender().getSendTime().getMonth() &&
                    a->getSender().getSendTime().getDay() < b->getSender().getSendTime().getDay());
        });
    }else{
        sort(tempArray.begin(), tempArray.end(), [](ExpressWaybill* a, ExpressWaybill* b) {
            return a->getReceiver().getReceiveTime().getYear() < b->getReceiver().getReceiveTime().getYear() ||
                   (a->getReceiver().getReceiveTime().getYear() == b->getReceiver().getReceiveTime().getYear() &&
                    a->getReceiver().getReceiveTime().getMonth() < b->getReceiver().getReceiveTime().getMonth()) ||
                   (a->getReceiver().getReceiveTime().getYear() == b->getReceiver().getReceiveTime().getYear() &&
                    a->getReceiver().getReceiveTime().getMonth() == b->getReceiver().getReceiveTime().getMonth() &&
                    a->getReceiver().getReceiveTime().getDay() < b->getReceiver().getReceiveTime().getDay());
        });
    }

    // 输出排序后的结果
    for (ExpressWaybill* waybill : tempArray) {
        cout << "运单号：" << waybill->getWaybillNumber() << endl;
        cout << "派送时间：" << waybill->getSender().getSendTime().getTime() << endl;
        cout << "收件时间：" << waybill->getReceiver().getReceiveTime().getTime() << endl;
        cout << "--------------------------------" << endl;
    }
}

void ExpressWaybillList::sortExpressWaybillByType() {
    if (head == NULL ) {
        cout<<"链表为空，无需排序"<<endl;
        return; // 如果链表为空或只有一个节点，无需排序
    }else if(head->next == NULL){
        cout<<"运单号："<<head->getWaybillNumber()<<endl; // 输出头节点的运单号
        cout<<"快递类型："<<(head->getWaybillType() == 1 ? "派送单" : "收件单")<<endl; // 输出头节点的快递类型
        return;
    }

    cout<<"想要将哪种类型的快递单放前面？1.派送单 2.收件单"<<endl;
    int type;
    type = getRightInput(b, 2);
    cout<<"排序后的结果如下："<<endl;
    // 创建一个临时数组
    vector<ExpressWaybill*> tempArray;
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        tempArray.push_back(p);
        p = p->next;
    }

    // 对临时数组进行排序
    sort(tempArray.begin(), tempArray.end(), [type](ExpressWaybill* a, ExpressWaybill* b) {
        if(type == 1){
            return a->getWaybillType() < b->getWaybillType();
        }else{
            return a->getWaybillType() > b->getWaybillType();
        }
    });

    // 输出排序后的结果
    for (ExpressWaybill* waybill : tempArray) {
        cout << "运单号：" << waybill->getWaybillNumber() << endl;
        cout << "快递类型：" << (waybill->getWaybillType() == 1 ? "派送单" : "收件单") << endl;
        cout << "--------------------------------" << endl;
    }
}

void ExpressWaybillList::sortExpressWaybillByAmount() {
    if (head == NULL ) {
        cout<<"链表为空，无需排序"<<endl;
        return; // 如果链表为空或只有一个节点，无需排序
    }else if(head->next == NULL){
        cout<<"运单号："<<head->getWaybillNumber()<<endl; // 输出头节点的运单号
        cout<<"金额："<<head->getAmount()<<endl; // 输出头节点的金额
        return;
    }

    int sort_type;
    cout<<"想要按什么顺序排序？1.升序 2.降序"<<endl;
    sort_type = getRightInput(b, 2);
    cout<<"排序后的结果如下："<<endl;
    // 创建一个临时数组
    vector<ExpressWaybill*> tempArray;
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        tempArray.push_back(p);
        p = p->next;
    }

    // 对临时数组进行排序
    if(sort_type == 1){
        sort(tempArray.begin(), tempArray.end(), [](ExpressWaybill* a, ExpressWaybill* b) {
            return a->getAmount() < b->getAmount();
        });
    }else{
        sort(tempArray.begin(), tempArray.end(), [](ExpressWaybill* a, ExpressWaybill* b) {
            return a->getAmount() > b->getAmount();
        });
    }

    // 输出排序后的结果
    for (ExpressWaybill* waybill : tempArray) {
        cout << "运单号：" << waybill->getWaybillNumber() << endl;
        cout << "金额：" << waybill->getAmount() << endl;
        cout << "--------------------------------" << endl;
    }
}

bool ExpressWaybillList::searchExpressWaybillByNumber(std::string number) {
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        if (p->getWaybillNumber() == number) {
            return true;
        }
        p = p->next;
    }
    return false;
}