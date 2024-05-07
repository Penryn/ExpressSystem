#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Time {
private:
    int year;
    int month;
    int day;

public:
    void setTime(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    string getTime() {
        return to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    }
};

class People {
protected:
    string address; //地址
    string phone;   //电话
    string remark;  //备注
public:
    string getAddress() { return address; }

    void setAddress(string a) { address = a; }

    string getPhone() { return phone; }

    void setPhone(string p) { phone = p; }

    string getRemark() { return remark; }

    void setRemark(string r) { remark = r; }

};

class Sender : public People {
private:
    Time sendTime;  //派送时间
public:
    Time getSendTime() { return sendTime; }

    void setSendTime(Time t) { sendTime = t; }
};

class Receiver : public People {
private:
    Time ReceiveTime;  //收件时间
public:
    Time getReceiveTime() { return ReceiveTime; }

    void setReceiveTime(Time t) { ReceiveTime = t; }
};

class ExpressWaybill {
private:
    string waybillNumber;     //运单号
    int waybillType;          //快递类型  1:派送单 2:收件单
    Sender sender;           //寄件人信息
    Receiver receiver;       //收件人信息
    bool isSign;            //是否签收
    bool isDifficult;       //是否为难派件
    int difficultReason;   //难派件原因  1：地址模糊 2：用户拒收 3：电话无效 4：收件人不在 5：其他
    double amount;         //金额
public:
    ExpressWaybill *next;  //下一个运单
    string getWaybillNumber() { return waybillNumber; }

    void setWaybillNumber(string number) { waybillNumber = number; }

    int getWaybillType() { return waybillType; }

    void setWaybillType(int type) { waybillType = type; }

    Sender getSender() { return sender; }

    void setSender(Sender s) { sender = s; }

    Receiver getReceiver() { return receiver; }

    void setReceiver(Receiver r) { receiver = r; }

    bool getIsSign() { return isSign; }

    void setIsSign(bool sign) { isSign = sign; }

    bool getIsDifficult() { return isDifficult; }

    void setIsDifficult(bool difficult) { isDifficult = difficult; }

    int getDifficultReason() { return difficultReason; }

    void setDifficultReason(int reason) { difficultReason = reason; }

    double getAmount() { return amount; }

    void setAmount(double amt) { amount = amt; }
};

class ExpressWaybillList {
private:
    ExpressWaybill *head;   //头指针
    ExpressWaybill *tail;   //尾指针
    int length;             //链表长度
public:
    ExpressWaybillList();

    ~ExpressWaybillList();

    void addExpressWaybill();

    void deleteExpressWaybill();

    void updateExpressWaybill();

    void saveExpressWaybillToFile();

    void loadExpressWaybillFromFile();

    void displayExpressWaybill();

    void getExpressWaybillByNumber();

    void getExpressWaybillByTypeAndSenderAndDate();

    void getExpressWaybillByTypeAndReceiver();

    void getExpressWaybillByType();

    void getExpressWaybillByReceiveDate();

    void getExpressWaybillBySendDate();

    void getExpressWaybillAndCountByReceiveDate();

    void getNotReceivedExpressWaybillBySendDate();

    void sortExpressWaybillByDate();

    void sortExpressWaybillByType();

    void sortExpressWaybillByAmount();


};

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
        ExpressWaybill *expressWaybill = new ExpressWaybill();
        expressWaybill->setWaybillNumber(waybillNumber);
        cout << "请输入快递类型 1:派送单 2:收件单" << endl;
        int waybillType;
        cin >> waybillType;
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
        cout << "请输入派送时间" << endl;
        Time sendTime;
        int year, month, day;
        cout << "请输入年 月 日" << endl;
        cin >> year >> month >> day;
        sendTime.setTime(year, month, day);
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
        cout << "请输入收件时间" << endl;
        Time receiveTime;
        cout << "请输入年 月 日" << endl;
        cin >> year >> month >> day;
        receiveTime.setTime(year, month, day);
        receiver.setReceiveTime(receiveTime);
        expressWaybill->setReceiver(receiver);
        cout << "请输入是否签收 1:是 0:否" << endl;
        bool isSign;
        cin >> isSign;
        expressWaybill->setIsSign(isSign);
        if (!isSign) {
            cout << "请输入是否为难派件 1:是 0:否" << endl;
            bool isDifficult;
            cin >> isDifficult;
            expressWaybill->setIsDifficult(isDifficult);
            if (isDifficult) {
                cout << "请输入难派件原因 1：地址模糊 2：用户拒收 3：电话无效 4：收件人不在 5：其他" << endl;
                int difficultReason;
                cin >> difficultReason;
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
        cin >> amount;
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
        ExpressWaybill *p = head;
        while (p->next != NULL) {
            if (p->next->getWaybillNumber() == waybillNumber) {
                ExpressWaybill *q = p->next;
                p->next = q->next;
                delete q;
                length--;
                break;
            }
            p = p->next;
        }
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
        while (p != NULL) {
            if (p->getWaybillNumber() == waybillNumber) {
                cout << "原快递类型：" << p->getWaybillType() << endl;
                cout << "你是否要修改快递类型 1:是 0:否" << endl;
                if (cin.get() == '1') {
                    cout << "请输入快递类型 1:派送单 2:收件单" << endl;
                    int waybillType;
                    cin >> waybillType;
                    p->setWaybillType(waybillType);
                } else {
                    p->setWaybillType(p->getWaybillType());
                }
                cout << "原寄件人信息：" << endl;
                cout << "地址：" << p->getSender().getAddress() << endl;
                cout << "电话：" << p->getSender().getPhone() << endl;
                cout << "备注：" << p->getSender().getRemark() << endl;
                cout << "你是否要修改寄件人信息 1:是 0:否" << endl;
                if (cin.get() == '1') {
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
                if (cin.get() == '1') {
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
                if (cin.get() == '1') {
                    cout << "请输入派送时间" << endl;
                    Time sendTime;
                    int year, month, day;
                    cout << "请输入年 月 日" << endl;
                    cin >> year >> month >> day;
                    sendTime.setTime(year, month, day);
                    p->getSender().setSendTime(sendTime);
                } else {
                    p->getSender().setSendTime(p->getSender().getSendTime());
                }
                cout << "原收件时间：" << p->getReceiver().getReceiveTime().getTime() << endl;
                cout << "你是否要修改收件时间 1:是 0:否" << endl;
                if (cin.get() == '1') {
                    cout << "请输入收件时间" << endl;
                    Time receiveTime;
                    int year, month, day;
                    cout << "请输入年 月 日" << endl;
                    cin >> year >> month >> day;
                    receiveTime.setTime(year, month, day);
                    p->getReceiver().setReceiveTime(receiveTime);
                } else {
                    p->getReceiver().setReceiveTime(p->getReceiver().getReceiveTime());
                }
                cout << "原是否签收：" << p->getIsSign() << endl;
                cout << "你是否要修改是否签收 1:是 0:否" << endl;
                if (cin.get() == '1') {
                    cout << "请输入是否签收 1:是 0:否" << endl;
                    bool isSign;
                    cin >> isSign;
                    p->setIsSign(isSign);
                } else {
                    p->setIsSign(p->getIsSign());
                }
                if (!p->getIsSign()) {
                    cout << "原是否为难派件：" << p->getIsDifficult() << endl;
                    cout << "你是否要修改是否为难派件 1:是 0:否" << endl;
                    if (cin.get() == '1') {
                        cout << "请输入是否为难派件 1:是 0:否" << endl;
                        bool isDifficult;
                        cin >> isDifficult;
                        p->setIsDifficult(isDifficult);
                        if (isDifficult) {
                            cout << "请输入难派件原因 1：地址模糊 2：用户拒收 3：电话无效 4：收件人不在 5：其他" << endl;
                            int difficultReason;
                            cin >> difficultReason;
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
                if (cin.get() == '1') {
                    cout << "请输入金额" << endl;
                    double amount;
                    cin >> amount;
                    p->setAmount(amount);
                } else {
                    p->setAmount(p->getAmount());
                }
                break;
            }
            p = p->next;
        }
    }
}

void ExpressWaybillList::saveExpressWaybillToFile() {
    ofstream outputFile("waybills.csv"); // 创建 CSV 文件
    if (!outputFile.is_open()) {
        cout << "无法打开文件！" << endl;
        return;
    }
    // 写入 CSV 文件的标题行
    outputFile
            << "运单号,快递类型,寄件人地址,寄件人电话,寄件人备注,收件人地址,收件人电话,收件人备注,派送时间,收件时间,是否签收,是否为难派件,难派件原因,金额\n";

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
    cout << "运单信息已成功保存到 express_waybills.csv 文件中。" << endl;
}

void ExpressWaybillList::loadExpressWaybillFromFile() {
    ifstream inputFile("waybills.csv"); // 打开 CSV 文件
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
                    difficultReason =token == "地址模糊" ? 1 : token == "用户拒收" ? 2 : token == "电话无效" ? 3 : token == "收件人不在" ? 4 : token == "其他" ? 5 : 0;
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
        while ((pos = sendTime.find("-")) != string::npos) {
            token = sendTime.substr(0, pos);
            sendTimeObj.setTime(stoi(token), 0, 0);
            sendTime.erase(0, pos + 1);
        }
        sender.setSendTime(sendTimeObj);
        expressWaybill->setSender(sender);
        Receiver receiver;
        receiver.setAddress(receiverAddress);
        receiver.setPhone(receiverPhone);
        receiver.setRemark(receiverRemark);
        Time receiveTimeObj;
        pos = 0;
        while ((pos = receiveTime.find("-")) != string::npos) {
            token = receiveTime.substr(0, pos);
            receiveTimeObj.setTime(stoi(token), 0, 0);
            receiveTime.erase(0, pos + 1);
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
    cout << "运单信息已成功从 express_waybills.csv 文件中读取。" << endl;
}

void ExpressWaybillList::getExpressWaybillByNumber() {
    cout << "请输入要查询的运单号" << endl;
    string waybillNumber;
    cin >> waybillNumber;
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        if (p->getWaybillNumber() == waybillNumber) {
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
}

void ExpressWaybillList::getExpressWaybillByTypeAndSenderAndDate() {
    cout << "请输入要查询的快递类型 1:派送单 2:收件单" << endl;
    int waybillType;
    cin >> waybillType;
    cout << "请输入寄件人地址" << endl;
    string senderAddress;
    cin >> senderAddress;
    cout << "请输入寄件日期，输入年 月 日" << endl;
    int year, mouth, day;
    cin >> year >> mouth >> day;
    string sendTime;
    sendTime = to_string(year) + "-" + to_string(mouth) + "-" + to_string(day);
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        if (p->getWaybillType() == waybillType && p->getSender().getAddress() == senderAddress &&
            p->getSender().getSendTime().getTime() == sendTime) {
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
    while (p != NULL) {
        if (p->getWaybillType() == waybillType && p->getReceiver().getAddress() == receiverAddress &&
            p->getReceiver().getPhone() == receiverPhone) {
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
}

void ExpressWaybillList::getExpressWaybillByType() {
    cout << "请输入要查询的快递类型 1:派送单 2:收件单" << endl;
    int waybillType;
    cin >> waybillType;
    ExpressWaybill *p = head->next;
    cout << "查询结果如下：" << endl;
    while (p != NULL) {
        if (p->getWaybillType() == waybillType) {
            cout << "运单号：" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
}

void ExpressWaybillList::getExpressWaybillByReceiveDate() {
    cout << "请输入要查询的收件日期，输入年 月 日" << endl;
    int year, month, day;
    cin >> year >> month >> day;
    string receiveTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    ExpressWaybill *p = head->next;
    cout << "查询结果如下：" << endl;
    while (p != NULL) {
        if (p->getReceiver().getReceiveTime().getTime() == receiveTime) {
            cout << "运单号：" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
}

void ExpressWaybillList::getExpressWaybillBySendDate() {
    cout << "请输入要查询的寄件日期，输入年 月 日" << endl;
    int year, month, day;
    cin >> year >> month >> day;
    string sendTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    ExpressWaybill *p = head->next;
    cout << "查询结果如下：" << endl;
    while (p != NULL) {
        if (p->getSender().getSendTime().getTime() == sendTime) {
            cout << "运单号：" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
}

void ExpressWaybillList::getExpressWaybillAndCountByReceiveDate() {
    cout << "请输入要查询的收件日期，输入年 月 日" << endl;
    int year, month, day;
    cin >> year >> month >> day;
    string receiveTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    int count = 0;
    double amount = 0;
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        if (p->getReceiver().getReceiveTime().getTime() == receiveTime) {
            count++;
            amount += p->getAmount();
        }
        p = p->next;
    }
    cout << "收件日期为" << receiveTime << "的快递单数量为" << count << "，总金额为" << amount << "元。" << endl;
}

void ExpressWaybillList::getNotReceivedExpressWaybillBySendDate() {
    cout << "请输入要查询的寄件日期，输入年 月 日" << endl;
    int year, month, day;
    cin >> year >> month >> day;
    string sendTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    ExpressWaybill *p = head->next;
    cout << "查询结果如下：" << endl;
    while (p != NULL) {
        if (p->getSender().getSendTime().getTime() == sendTime && !p->getIsSign()) {
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
}

// 根据派送时间排序
void ExpressWaybillList::sortExpressWaybillByDate() {
    // 创建链表的副本
    ExpressWaybill *copyHead = new ExpressWaybill();
    ExpressWaybill *copyTail = copyHead;
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        ExpressWaybill *copy = new ExpressWaybill();
        copy->setWaybillNumber(p->getWaybillNumber());
        copy->setWaybillType(p->getWaybillType());
        copy->setSender(p->getSender());
        copy->setReceiver(p->getReceiver());
        copy->setIsSign(p->getIsSign());
        copy->setIsDifficult(p->getIsDifficult());
        copy->setDifficultReason(p->getDifficultReason());
        copy->setAmount(p->getAmount());
        copyTail->next = copy;
        copyTail = copy;
        p = p->next;
    }
    // 对副本进行排序
    p = copyHead->next;
    while (p != NULL) {
        ExpressWaybill *q = p->next;
        while (q != NULL) {
            if (p->getSender().getSendTime().getTime() < q->getSender().getSendTime().getTime()) {
                // 交换 p 和 q
                ExpressWaybill temp = *p;
                *p = *q;
                *q = temp;
            }
            q = q->next;
        }
        p = p->next;
    }

    // 输出排序后的结果
    p = copyHead->next;
    while (p != NULL) {
        cout << "运单号：" << p->getWaybillNumber() << endl;
        cout << "派送时间：" << p->getSender().getSendTime().getTime() << endl;
        cout << "收件时间：" << p->getReceiver().getReceiveTime().getTime() << endl;
        cout << "--------------------------------" << endl;
        p = p->next;
    }
    // 删除副本
    p = copyHead;
    while (p != NULL) {
        ExpressWaybill *q = p;
        p = p->next;
        delete q;
    }

}

void ExpressWaybillList::sortExpressWaybillByType() {
    // 创建链表的副本
    ExpressWaybill *copyHead = new ExpressWaybill();
    ExpressWaybill *copyTail = copyHead;
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        ExpressWaybill *copy = new ExpressWaybill();
        copy->setWaybillNumber(p->getWaybillNumber());
        copy->setWaybillType(p->getWaybillType());
        copy->setSender(p->getSender());
        copy->setReceiver(p->getReceiver());
        copy->setIsSign(p->getIsSign());
        copy->setIsDifficult(p->getIsDifficult());
        copy->setDifficultReason(p->getDifficultReason());
        copy->setAmount(p->getAmount());
        copyTail->next = copy;
        copyTail = copy;
        p = p->next;
    }
    // 对副本进行排序
    p = copyHead->next;
    while (p != NULL) {
        ExpressWaybill *q = p->next;
        while (q != NULL) {
            if (p->getWaybillType() > q->getWaybillType()) {
                // 交换 p 和 q
                ExpressWaybill temp = *p;
                *p = *q;
                *q = temp;
            }
            q = q->next;
        }
    }

    // 输出排序后的结果
    p = copyHead->next;
    while (p != NULL) {
        cout << "运单号：" << p->getWaybillNumber() << endl;
        cout << "快递类型：";
        if (p->getWaybillType() == 1) {
            cout << "派送单" << endl;
        } else {
            cout << "收件单" << endl;
        }
        cout << "--------------------------------" << endl;
        p = p->next;
    }
    // 删除副本
    p = copyHead;
    while (p != NULL) {
        ExpressWaybill *q = p;
        p = p->next;
        delete q;
    }
}

void ExpressWaybillList::sortExpressWaybillByAmount() {
    // 创建链表的副本
    ExpressWaybill *copyHead = new ExpressWaybill();
    ExpressWaybill *copyTail = copyHead;
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        ExpressWaybill *copy = new ExpressWaybill();
        copy->setWaybillNumber(p->getWaybillNumber());
        copy->setWaybillType(p->getWaybillType());
        copy->setSender(p->getSender());
        copy->setReceiver(p->getReceiver());
        copy->setIsSign(p->getIsSign());
        copy->setIsDifficult(p->getIsDifficult());
        copy->setDifficultReason(p->getDifficultReason());
        copy->setAmount(p->getAmount());
        copyTail->next = copy;
        copyTail = copy;
        p = p->next;
    }
    // 对副本进行排序
    p = copyHead->next;
    while (p != NULL) {
        ExpressWaybill *q = p->next;
        while (q != NULL) {
            if (p->getAmount() < q->getAmount()) {
                // 交换 p 和 q
                ExpressWaybill temp = *p;
                *p = *q;
                *q = temp;
            }
            q = q->next;
        }
    }

    // 输出排序后的结果
    p = copyHead->next;
    while (p != NULL) {
        cout << "运单号：" << p->getWaybillNumber() << endl;
        cout << "金额：" << p->getAmount() << endl;
        cout << "--------------------------------" << endl;
        p = p->next;
    }
    // 删除副本
    p = copyHead;
    while (p != NULL) {
        ExpressWaybill *q = p;
        p = p->next;
        delete q;
    }
}


string getKeyFromFile() {
    ifstream inputFile("key.txt"); // 打开 key 文件
    if (!inputFile.is_open()) {
        cout << "无法打开文件！" << endl;
        return "";
    }
    string key;
    getline(inputFile, key); // 读取 key
    inputFile.close(); // 关闭文件
    return key;
}

int main() {
    ExpressWaybillList expressWaybillList;
    // 读取文件中的运单信息
    expressWaybillList.loadExpressWaybillFromFile();
    cout<<"快递运单管理系统初始化完成"<<endl;
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
        cout << "欢迎用户登录快递运单管理系统" << endl;
        cout << "请选择操作，输入0再看一遍操作选择" << endl;
        cout << "1.根据单号查询运单" << endl;
        cout << "2.根据快递类别、寄件人信息和寄件日期查询运单" << endl;
        cout << "3.根据快递类别和收件人信息查询运单" << endl;
    } else {
        cout << "欢迎管理员登录快递运单管理系统" << endl;
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
        cout << "16.退出" << endl;
    }
    cin >> choice;
    while (choice != 16) {
        switch (choice) {
            case 0:
                if (user_type == 1) {
                    cout << "请选择操作，输入0再看一遍操作选择" << endl;
                    cout << "1.根据单号查询运单" << endl;
                    cout << "2.根据快递类别、寄件人信息和寄件日期查询运单" << endl;
                    cout << "3.根据快递类别和收件人信息查询运单" << endl;
                } else {
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
                    cout << "16.退出" << endl;
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
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.displayExpressWaybill();
                }
                break;
            case 5:
                if (user_type == 1) {
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.getExpressWaybillByNumber();
                }
                break;
            case 6:
                if (user_type == 1) {
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.getExpressWaybillByType();
                }
                break;
            case 7:
                if (user_type == 1) {
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.getExpressWaybillByReceiveDate();
                }
                break;
            case 8:
                if (user_type == 1) {
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.getExpressWaybillBySendDate();
                }
                break;
            case 9:
                if (user_type == 1) {
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.getExpressWaybillAndCountByReceiveDate();
                }
                break;
            case 10:
                if (user_type == 1) {
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.getNotReceivedExpressWaybillBySendDate();
                }
                break;
            case 11:
                if (user_type == 1) {
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.sortExpressWaybillByDate();
                }
                break;
            case 12:
                if (user_type == 1) {
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.sortExpressWaybillByType();
                }
                break;
            case 13:
                if (user_type == 1) {
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.sortExpressWaybillByAmount();
                }
                break;
            case 14:
                if (user_type == 1) {
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.saveExpressWaybillToFile();
                }
                break;
            case 15:
                if (user_type == 1) {
                    cout<<"无效的选项"<<endl;
                } else {
                    expressWaybillList.loadExpressWaybillFromFile();
                }
                break;
            case 16:
                cout << "退出" << endl;
                return 0;
            default:
                cout << "无效的选项" << endl;
                break;

        }
        cout << "请选择操作，输入0再看一遍操作选择" << endl;
        cin >> choice;
    }
    return 0;
}