#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

    int getYear() { return year; }

    int getMonth() { return month; }

    int getDay() { return day; }

};

class People {
protected:
    string address; //��ַ
    string phone;   //�绰
    string remark;  //��ע
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
    Time sendTime;  //����ʱ��
public:
    Time& getSendTime() { return sendTime; }

    void setSendTime(Time t) { sendTime = t; }
};

class Receiver : public People {
private:
    Time ReceiveTime;  //�ռ�ʱ��
public:
    Time& getReceiveTime() { return ReceiveTime; }

    void setReceiveTime(Time t) { ReceiveTime = t; }
};

class ExpressWaybill {
private:
    string waybillNumber;     //�˵���
    int waybillType;          //�������  1:���͵� 2:�ռ���
    Sender sender;           //�ļ�����Ϣ
    Receiver receiver;       //�ռ�����Ϣ
    bool isSign;            //�Ƿ�ǩ��
    bool isDifficult;       //�Ƿ�Ϊ���ɼ�
    int difficultReason;   //���ɼ�ԭ��  1����ַģ�� 2���û����� 3���绰��Ч 4���ռ��˲��� 5������
    double amount;         //���
public:
    ExpressWaybill *next;  //��һ���˵�
    string getWaybillNumber() { return waybillNumber; }

    void setWaybillNumber(string number) { waybillNumber = number; }

    int getWaybillType() { return waybillType; }

    void setWaybillType(int type) { waybillType = type; }

    Sender& getSender() { return sender; }

    void setSender(Sender s) { sender = s; }

    Receiver& getReceiver() { return receiver; }

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
    ExpressWaybill *head;   //ͷָ��
    ExpressWaybill *tail;   //βָ��
    int length;             //������
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
    cout << "�������˵���,����0����" << endl;
    string waybillNumber;
    while (cin >> waybillNumber) {
        if (waybillNumber == "0") {
            break;
        }
        ExpressWaybill *expressWaybill = new ExpressWaybill();
        expressWaybill->setWaybillNumber(waybillNumber);
        cout << "������������ 1:���͵� 2:�ռ���" << endl;
        int waybillType;
        cin >> waybillType;
        expressWaybill->setWaybillType(waybillType);
        cout << "������ļ�����Ϣ" << endl;
        Sender sender;
        cout << "�������ַ" << endl;
        string address;
        cin >> address;
        sender.setAddress(address);
        cout << "������绰" << endl;
        string phone;
        cin >> phone;
        sender.setPhone(phone);
        cout << "�����뱸ע" << endl;
        string remark;
        cin >> remark;
        sender.setRemark(remark);
        cout << "����������ʱ��" << endl;
        Time sendTime;
        int year, month, day;
        cout << "�������� �� ��" << endl;
        cin >> year >> month >> day;
        sendTime.setTime(year, month, day);
        sender.setSendTime(sendTime);
        expressWaybill->setSender(sender);
        cout << "�������ռ�����Ϣ" << endl;
        Receiver receiver;
        cout << "�������ַ" << endl;
        cin >> address;
        receiver.setAddress(address);
        cout << "������绰" << endl;
        cin >> phone;
        receiver.setPhone(phone);
        cout << "�����뱸ע" << endl;
        cin >> remark;
        receiver.setRemark(remark);
        cout << "�������ռ�ʱ��" << endl;
        Time receiveTime;
        cout << "�������� �� ��" << endl;
        cin >> year >> month >> day;
        receiveTime.setTime(year, month, day);
        receiver.setReceiveTime(receiveTime);
        expressWaybill->setReceiver(receiver);
        cout << "�������Ƿ�ǩ�� 1:�� 0:��" << endl;
        bool isSign;
        cin >> isSign;
        expressWaybill->setIsSign(isSign);
        if (!isSign) {
            cout << "�������Ƿ�Ϊ���ɼ� 1:�� 0:��" << endl;
            bool isDifficult;
            cin >> isDifficult;
            expressWaybill->setIsDifficult(isDifficult);
            if (isDifficult) {
                cout << "���������ɼ�ԭ�� 1����ַģ�� 2���û����� 3���绰��Ч 4���ռ��˲��� 5������" << endl;
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
        cout << "��������" << endl;
        double amount;
        cin >> amount;
        expressWaybill->setAmount(amount);
        tail->next = expressWaybill;
        tail = expressWaybill;
        length++;
        cout << "�������˵���,����0����" << endl;
    }
}

void ExpressWaybillList::displayExpressWaybill() {
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
        cout << "������ͣ�";
        if (p->getWaybillType() == 1) {
            cout << "���͵�" << endl;
        } else {
            cout << "�ռ���" << endl;
        }
        cout << "�ļ�����Ϣ��" << endl;
        cout << "��ַ��" << p->getSender().getAddress() << endl;
        cout << "�绰��" << p->getSender().getPhone() << endl;
        cout << "��ע��" << p->getSender().getRemark() << endl;
        cout << "�ռ�����Ϣ��" << endl;
        cout << "��ַ��" << p->getReceiver().getAddress() << endl;
        cout << "�绰��" << p->getReceiver().getPhone() << endl;
        cout << "��ע��" << p->getReceiver().getRemark() << endl;
        cout << "����ʱ�䣺" << p->getSender().getSendTime().getTime() << endl;
        cout << "�ռ�ʱ�䣺" << p->getReceiver().getReceiveTime().getTime() << endl;
        cout << "�Ƿ�ǩ�գ�";
        if (p->getIsSign()) {
            cout << "��" << endl;
        } else {
            cout << "��" << endl;
        }
        cout << "�Ƿ�Ϊ���ɼ���";
        if (p->getIsDifficult()) {
            cout << "��" << endl;
        } else {
            cout << "��" << endl;
        }
        cout << "���ɼ�ԭ��";
        switch (p->getDifficultReason()) {
            case 1:
                cout << "��ַģ��" << endl;
                break;
            case 2:
                cout << "�û�����" << endl;
                break;
            case 3:
                cout << "�绰��Ч" << endl;
                break;
            case 4:
                cout << "�ռ��˲���" << endl;
                break;
            case 5:
                cout << "����" << endl;
                break;
            default:
                cout << "δ֪ԭ��" << endl;
                break;
        }
        cout << "��" << p->getAmount() << endl;
        cout << "--------------------------------" << endl;
        p = p->next;
    }
}

void ExpressWaybillList::deleteExpressWaybill() {
    cout << "������Ҫɾ�����˵���,����0����" << endl;
    string waybillNumber;
    while (cin >> waybillNumber) {
        if (waybillNumber == "0") {
            break;
        }
        if (head->next == NULL) {
            cout << "�б�Ϊ�գ��޷�ɾ����" << endl;
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
                break;
            }
            p = p->next;
        }
        if (!isFound) {
            cout << "δ�ҵ��˵���Ϊ " << waybillNumber << " ���˵���" << endl;
        } else {
            cout << "�˵���Ϊ " << waybillNumber << " ���˵�ɾ���ɹ�" << endl;
        }
        cout << "������Ҫɾ�����˵���,����0����" << endl;
    }
}

void ExpressWaybillList::updateExpressWaybill() {
    cout << "������Ҫ�޸ĵ��˵���,����0����" << endl;
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
                cout << "ԭ������ͣ�";
                if (p->getWaybillType() == 1) {
                    cout << "���͵�" << endl;
                } else {
                    cout << "�ռ���" << endl;
                }
                cout << "���Ƿ�Ҫ�޸Ŀ������ 1:�� 0:��" << endl;
                bool change;
                cin >> change;
                if (change) {
                    cout << "������������ 1:���͵� 2:�ռ���" << endl;
                    int waybillType;
                    cin >> waybillType;
                    p->setWaybillType(waybillType);
                } else {
                    p->setWaybillType(p->getWaybillType());
                }
                cout << "ԭ�ļ�����Ϣ��" << endl;
                cout << "��ַ��" << p->getSender().getAddress() << endl;
                cout << "�绰��" << p->getSender().getPhone() << endl;
                cout << "��ע��" << p->getSender().getRemark() << endl;
                cout << "���Ƿ�Ҫ�޸ļļ�����Ϣ 1:�� 0:��" << endl;
                cin >> change;
                if (change) {
                    cout << "�������ַ" << endl;
                    string address;
                    cin >> address;
                    p->getSender().setAddress(address);
                    cout << "������绰" << endl;
                    string phone;
                    cin >> phone;
                    p->getSender().setPhone(phone);
                    cout << "�����뱸ע" << endl;
                    string remark;
                    cin >> remark;
                    p->getSender().setRemark(remark);
                } else {
                    p->getSender().setAddress(p->getSender().getAddress());
                    p->getSender().setPhone(p->getSender().getPhone());
                    p->getSender().setRemark(p->getSender().getRemark());
                }
                cout << "ԭ�ռ�����Ϣ��" << endl;
                cout << "��ַ��" << p->getReceiver().getAddress() << endl;
                cout << "�绰��" << p->getReceiver().getPhone() << endl;
                cout << "��ע��" << p->getReceiver().getRemark() << endl;
                cout << "���Ƿ�Ҫ�޸��ռ�����Ϣ 1:�� 0:��" << endl;
                cin >> change;
                if (change) {
                    cout << "�������ַ" << endl;
                    string address;
                    cin >> address;
                    p->getReceiver().setAddress(address);
                    cout << "������绰" << endl;
                    string phone;
                    cin >> phone;
                    p->getReceiver().setPhone(phone);
                    cout << "�����뱸ע" << endl;
                    string remark;
                    cin >> remark;
                    p->getReceiver().setRemark(remark);
                } else {
                    p->getReceiver().setAddress(p->getReceiver().getAddress());
                    p->getReceiver().setPhone(p->getReceiver().getPhone());
                    p->getReceiver().setRemark(p->getReceiver().getRemark());
                }
                cout << "ԭ����ʱ�䣺" << p->getSender().getSendTime().getTime() << endl;
                cout << "���Ƿ�Ҫ�޸�����ʱ�� 1:�� 0:��" << endl;
                cin >> change;
                if (change) {
                    cout << "����������ʱ��" << endl;
                    Time sendTime;
                    int year, month, day;
                    cout << "�������� �� ��" << endl;
                    cin >> year >> month >> day;
                    sendTime.setTime(year, month, day);
                    p->getSender().setSendTime(sendTime);
                } else {
                    p->getSender().setSendTime(p->getSender().getSendTime());
                }
                cout << "ԭ�ռ�ʱ�䣺" << p->getReceiver().getReceiveTime().getTime() << endl;
                cout << "���Ƿ�Ҫ�޸��ռ�ʱ�� 1:�� 0:��" << endl;
                cin >> change;
                if (change) {
                    cout << "�������ռ�ʱ��" << endl;
                    Time receiveTime;
                    int year, month, day;
                    cout << "�������� �� ��" << endl;
                    cin >> year >> month >> day;
                    receiveTime.setTime(year, month, day);
                    p->getReceiver().setReceiveTime(receiveTime);
                } else {
                    p->getReceiver().setReceiveTime(p->getReceiver().getReceiveTime());
                }
                cout << "ԭ�Ƿ�ǩ�գ�";
                if (p->getIsSign()) {
                    cout << "��" << endl;
                } else {
                    cout << "��" << endl;
                }
                cout << "���Ƿ�Ҫ�޸��Ƿ�ǩ�� 1:�� 0:��" << endl;
                cin >> change;
                if (change) {
                    cout << "�������Ƿ�ǩ�� 1:�� 0:��" << endl;
                    bool isSign;
                    cin >> isSign;
                    p->setIsSign(isSign);
                } else {
                    p->setIsSign(p->getIsSign());
                }
                if (!p->getIsSign()) {
                    cout << "ԭ�Ƿ�Ϊ���ɼ���";
                    if (p->getIsDifficult()) {
                        cout << "��" << endl;
                    } else {
                        cout << "��" << endl;
                    }
                    cout << "���Ƿ�Ҫ�޸��Ƿ�Ϊ���ɼ� 1:�� 0:��" << endl;
                    cin >> change;
                    if (change) {
                        cout << "�������Ƿ�Ϊ���ɼ� 1:�� 0:��" << endl;
                        bool isDifficult;
                        cin >> isDifficult;
                        p->setIsDifficult(isDifficult);
                        if (isDifficult) {
                            cout << "���������ɼ�ԭ�� 1����ַģ�� 2���û����� 3���绰��Ч 4���ռ��˲��� 5������" << endl;
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
                cout << "ԭ��" << p->getAmount() << endl;
                cout << "���Ƿ�Ҫ�޸Ľ�� 1:�� 0:��" << endl;
                cin >> change;
                if (change) {
                    cout << "��������" << endl;
                    double amount;
                    cin >> amount;
                    p->setAmount(amount);
                } else {
                    p->setAmount(p->getAmount());
                }
                cout << "�˵���Ϊ " << waybillNumber << " ���˵��޸ĳɹ�" << endl;
                break;
            }
            p = p->next;
        }
        if (!isFound) {
            cout << "δ�ҵ��˵���Ϊ " << waybillNumber << " ���˵���" << endl;
        }
        cout << "������Ҫ�޸ĵ��˵���,����0����" << endl;
    }
}

void ExpressWaybillList::saveExpressWaybillToFile() {
    ofstream outputFile("waybills.csv"); // ���� CSV �ļ�
    if (!outputFile.is_open()) {
        cout << "�޷����ļ���" << endl;
        return;
    }
    // д�� CSV �ļ��ı�����
    outputFile<< "�˵���,�������,�ļ��˵�ַ,�ļ��˵绰,�ļ��˱�ע,�ռ��˵�ַ,�ռ��˵绰,�ռ��˱�ע,����ʱ��,�ռ�ʱ��,�Ƿ�ǩ��,�Ƿ�Ϊ���ɼ�,���ɼ�ԭ��,���\n";

    if (!head) {
        cout << "�б�Ϊ�գ��޷����浽�ļ���" << endl;
        outputFile.close();
        return;
    }

    ExpressWaybill *p = head->next;
    while (p != NULL) {
        outputFile << p->getWaybillNumber() << ",";
        outputFile << (p->getWaybillType() == 1 ? "���͵�" : "�ռ���") << ",";
        outputFile << p->getSender().getAddress() << ",";
        outputFile << p->getSender().getPhone() << ",";
        outputFile << p->getSender().getRemark() << ",";
        outputFile << p->getReceiver().getAddress() << ",";
        outputFile << p->getReceiver().getPhone() << ",";
        outputFile << p->getReceiver().getRemark() << ",";
        outputFile << p->getSender().getSendTime().getTime() << ",";
        outputFile << p->getReceiver().getReceiveTime().getTime() << ",";
        outputFile << (p->getIsSign() ? "��" : "��") << ",";
        outputFile << (p->getIsDifficult() ? "��" : "��") << ",";
        switch (p->getDifficultReason()) {
            case 0:
                outputFile << "��";
                break;
            case 1:
                outputFile << "��ַģ��";
                break;
            case 2:
                outputFile << "�û�����";
                break;
            case 3:
                outputFile << "�绰��Ч";
                break;
            case 4:
                outputFile << "�ռ��˲���";
                break;
            case 5:
                outputFile << "����";
                break;
            default:
                outputFile << "δ֪ԭ��";
                break;
        }
        outputFile << ",";
        outputFile << p->getAmount() << ",\n";

        p = p->next;
    }
    outputFile.close(); // �ر��ļ�
    cout << "�˵���Ϣ�ѳɹ����浽 waybills.csv �ļ���" << endl;
}

void ExpressWaybillList::loadExpressWaybillFromFile() {
    ifstream inputFile("waybills.csv"); // �� CSV �ļ�
    if (!inputFile.is_open()) {
        cout << "�޷����ļ���" << endl;
        return;
    }
    string line;
    getline(inputFile, line); // ��ȡ������
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
        // �� CSV �ļ��ж�ȡ����
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
                    waybillType = token == "���͵�" ? 1 : 2;
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
                    isSign = token == "��";
                    break;
                case 11:
                    isDifficult = token == "��";
                    break;
                case 12:
                    difficultReason =token == "��ַģ��" ? 1 : token == "�û�����" ? 2 : token == "�绰��Ч" ? 3 : token =="�ռ��˲���"? 4 : token =="����"? 5 : 0;
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
    inputFile.close(); // �ر��ļ�
}

void ExpressWaybillList::getExpressWaybillByNumber() {
    cout << "������Ҫ��ѯ���˵���" << endl;
    string waybillNumber;
    cin >> waybillNumber;
    ExpressWaybill *p = head->next;
    bool isFound = false;
    while (p != NULL) {
        if (p->getWaybillNumber() == waybillNumber) {
            isFound = true;
            cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
            cout << "������ͣ�";
            if (p->getWaybillType() == 1) {
                cout << "���͵�" << endl;
            } else {
                cout << "�ռ���" << endl;
            }
            cout << "�ļ�����Ϣ��" << endl;
            cout << "��ַ��" << p->getSender().getAddress() << endl;
            cout << "�绰��" << p->getSender().getPhone() << endl;
            cout << "��ע��" << p->getSender().getRemark() << endl;
            cout << "�ռ�����Ϣ��" << endl;
            cout << "��ַ��" << p->getReceiver().getAddress() << endl;
            cout << "�绰��" << p->getReceiver().getPhone() << endl;
            cout << "��ע��" << p->getReceiver().getRemark() << endl;
            cout << "����ʱ�䣺" << p->getSender().getSendTime().getTime() << endl;
            cout << "�ռ�ʱ�䣺" << p->getReceiver().getReceiveTime().getTime() << endl;
            cout << "�Ƿ�ǩ�գ�";
            if (p->getIsSign()) {
                cout << "��" << endl;
            } else {
                cout << "��" << endl;
            }
            cout << "�Ƿ�Ϊ���ɼ���";
            if (p->getIsDifficult()) {
                cout << "��" << endl;
            } else {
                cout << "��" << endl;
            }
            cout << "���ɼ�ԭ��";
            switch (p->getDifficultReason()) {
                case 1:
                    cout << "��ַģ��" << endl;
                    break;
                case 2:
                    cout << "�û�����" << endl;
                    break;
                case 3:
                    cout << "�绰��Ч" << endl;
                    break;
                case 4:
                    cout << "�ռ��˲���" << endl;
                    break;
                case 5:
                    cout << "����" << endl;
                    break;
                default:
                    cout << "δ֪ԭ��" << endl;
                    break;
            }
            cout << "��" << p->getAmount() << endl;
            cout << "--------------------------------" << endl;
            break;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��˵���Ϊ " << waybillNumber << " ���˵���" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByTypeAndSenderAndDate() {
    cout << "������Ҫ��ѯ�Ŀ������ 1:���͵� 2:�ռ���" << endl;
    int waybillType;
    cin >> waybillType;
    cout << "������ļ��˵�ַ" << endl;
    string senderAddress;
    cin >> senderAddress;
    cout << "������ļ����ڣ������� �� ��" << endl;
    int year, mouth, day;
    cin >> year >> mouth >> day;
    string sendTime;
    sendTime = to_string(year) + "-" + to_string(mouth) + "-" + to_string(day);
    ExpressWaybill *p = head->next;
    bool isFound = false;
    while (p != NULL) {
        if (p->getWaybillType() == waybillType && p->getSender().getAddress() == senderAddress &&
            p->getSender().getSendTime().getTime() == sendTime) {
            isFound = true;
            cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
            cout << "������ͣ�";
            if (p->getWaybillType() == 1) {
                cout << "���͵�" << endl;
            } else {
                cout << "�ռ���" << endl;
            }
            cout << "�ļ�����Ϣ��" << endl;
            cout << "��ַ��" << p->getSender().getAddress() << endl;
            cout << "�绰��" << p->getSender().getPhone() << endl;
            cout << "��ע��" << p->getSender().getRemark() << endl;
            cout << "�ռ�����Ϣ��" << endl;
            cout << "��ַ��" << p->getReceiver().getAddress() << endl;
            cout << "�绰��" << p->getReceiver().getPhone() << endl;
            cout << "��ע��" << p->getReceiver().getRemark() << endl;
            cout << "����ʱ�䣺" << p->getSender().getSendTime().getTime() << endl;
            cout << "�ռ�ʱ�䣺" << p->getReceiver().getReceiveTime().getTime() << endl;
            cout << "�Ƿ�ǩ�գ�";
            if (p->getIsSign()) {
                cout << "��" << endl;
            } else {
                cout << "��" << endl;
            }
            cout << "�Ƿ�Ϊ���ɼ���";
            if (p->getIsDifficult()) {
                cout << "��" << endl;
            } else {
                cout << "��" << endl;
            }
            cout << "���ɼ�ԭ��";
            switch (p->getDifficultReason()) {
                case 1:
                    cout << "��ַģ��" << endl;
                    break;
                case 2:
                    cout << "�û�����" << endl;
                    break;
                case 3:
                    cout << "�绰��Ч" << endl;
                    break;
                case 4:
                    cout << "�ռ��˲���" << endl;
                    break;
                case 5:
                    cout << "����" << endl;
                    break;
                default:
                    cout << "δ֪ԭ��" << endl;
                    break;
            }
            cout << "��" << p->getAmount() << endl;
            cout << "--------------------------------" << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��������Ϊ " << waybillType << " �ļ��˵�ַΪ " << senderAddress << " �ļ�����Ϊ " << sendTime
             << " ���˵���" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByTypeAndReceiver() {
    cout << "������Ҫ��ѯ�Ŀ������ 1:���͵� 2:�ռ���" << endl;
    int waybillType;
    cin >> waybillType;
    cout << "�������ռ��˵�ַ" << endl;
    string receiverAddress;
    cin >> receiverAddress;
    cout << "�������ռ��˵绰" << endl;
    string receiverPhone;
    cin >> receiverPhone;
    ExpressWaybill *p = head->next;
    cout << "��ѯ������£�" << endl;
    bool isFound = false;
    while (p != NULL) {
        if (p->getWaybillType() == waybillType && p->getReceiver().getAddress() == receiverAddress &&
            p->getReceiver().getPhone() == receiverPhone) {
            isFound = true;
            cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
            cout << "������ͣ�";
            if (p->getWaybillType() == 1) {
                cout << "���͵�" << endl;
            } else {
                cout << "�ռ���" << endl;
            }
            cout << "�ļ�����Ϣ��" << endl;
            cout << "��ַ��" << p->getSender().getAddress() << endl;
            cout << "�绰��" << p->getSender().getPhone() << endl;
            cout << "��ע��" << p->getSender().getRemark() << endl;
            cout << "�ռ�����Ϣ��" << endl;
            cout << "��ַ��" << p->getReceiver().getAddress() << endl;
            cout << "�绰��" << p->getReceiver().getPhone() << endl;
            cout << "��ע��" << p->getReceiver().getRemark() << endl;
            cout << "����ʱ�䣺" << p->getSender().getSendTime().getTime() << endl;
            cout << "�ռ�ʱ�䣺" << p->getReceiver().getReceiveTime().getTime() << endl;
            cout << "�Ƿ�ǩ�գ�";
            if (p->getIsSign()) {
                cout << "��" << endl;
            } else {
                cout << "��" << endl;
            }
            cout << "�Ƿ�Ϊ���ɼ���";
            if (p->getIsDifficult()) {
                cout << "��" << endl;
            } else {
                cout << "��" << endl;
            }
            cout << "���ɼ�ԭ��";
            switch (p->getDifficultReason()) {
                case 1:
                    cout << "��ַģ��" << endl;
                    break;
                case 2:
                    cout << "�û�����" << endl;
                    break;
                case 3:
                    cout << "�绰��Ч" << endl;
                    break;
                case 4:
                    cout << "�ռ��˲���" << endl;
                    break;
                case 5:
                    cout << "����" << endl;
                    break;
                default:
                    cout << "δ֪ԭ��" << endl;
                    break;
            }
            cout << "��" << p->getAmount() << endl;
            cout << "--------------------------------" << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��������Ϊ " << waybillType << " �ռ��˵�ַΪ " << receiverAddress << " �ռ��˵绰Ϊ "
             << receiverPhone << " ���˵���" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByType() {
    cout << "������Ҫ��ѯ�Ŀ������ 1:���͵� 2:�ռ���" << endl;
    int waybillType;
    cin >> waybillType;
    ExpressWaybill *p = head->next;
    bool isFound = false;
    cout << "��ѯ������£�" << endl;
    while (p != NULL) {
        if (p->getWaybillType() == waybillType) {
            isFound = true;
            cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��������Ϊ " << waybillType << " ���˵���" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByReceiveDate() {
    cout << "������Ҫ��ѯ���ռ����ڣ������� �� ��" << endl;
    int year, month, day;
    cin >> year >> month >> day;
    string receiveTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    ExpressWaybill *p = head->next;
    bool isFound = false;
    cout << "��ѯ������£�" << endl;
    while (p != NULL) {
        if (p->getReceiver().getReceiveTime().getTime() == receiveTime) {
            isFound = true;
            cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��ռ�����Ϊ " << receiveTime << " ���˵���" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillBySendDate() {
    cout << "������Ҫ��ѯ���������ڣ������� �� ��" << endl;
    int year, month, day;
    cin >> year >> month >> day;
    string sendTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    ExpressWaybill *p = head->next;
    cout << "��ѯ������£�" << endl;
    bool isFound = false;
    while (p != NULL) {
        if (p->getSender().getSendTime().getTime() == sendTime) {
            isFound = true;
            cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ���������Ϊ " << sendTime << " ���˵���" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillAndCountByReceiveDate() {
    cout << "������Ҫ��ѯ���ռ����ڣ������� �� ��" << endl;
    int year, month, day;
    cin >> year >> month >> day;
    string receiveTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    int count = 0;
    double amount = 0;
    ExpressWaybill *p = head->next;
    bool isFound = false;
    while (p != NULL) {
        if (p->getReceiver().getReceiveTime().getTime() == receiveTime) {
            isFound = true;
            count++;
            amount += p->getAmount();
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��ռ�����Ϊ " << receiveTime << " ���˵���" << endl;
        return;
    }else{
        cout << "�ռ�����Ϊ" << receiveTime << "�Ŀ�ݵ�����Ϊ" << count << "���ܽ��Ϊ" << amount << "Ԫ��" << endl;
    }
}

void ExpressWaybillList::getNotReceivedExpressWaybillBySendDate() {
    cout << "������Ҫ��ѯ�ļļ����ڣ������� �� ��" << endl;
    int year, month, day;
    cin >> year >> month >> day;
    string sendTime = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    ExpressWaybill *p = head->next;
    cout << "��ѯ������£�" << endl;
    bool isFound = false;
    while (p != NULL) {
        if (p->getSender().getSendTime().getTime() == sendTime && !p->getIsSign()) {
            isFound = true;
            cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
            if (p->getIsDifficult()) {
                cout << "���ɼ�ԭ��";
                switch (p->getDifficultReason()) {
                    case 1:
                        cout << "��ַģ��" << endl;
                        break;
                    case 2:
                        cout << "�û�����" << endl;
                        break;
                    case 3:
                        cout << "�绰��Ч" << endl;
                        break;
                    case 4:
                        cout << "�ռ��˲���" << endl;
                        break;
                    case 5:
                        cout << "����" << endl;
                        break;
                    default:
                        cout << "δ֪ԭ��" << endl;
                        break;
                }
            }
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��ļ�����Ϊ " << sendTime << " ��δǩ�յ��˵���" << endl;
    }
}

// ��������ʱ������
void ExpressWaybillList::sortExpressWaybillByDate() {
    if (head == NULL ) {
        cout<<"����Ϊ�գ���������"<<endl;
        return; // �������Ϊ�ջ�ֻ��һ���ڵ㣬��������
    }else if(head->next == NULL){
        cout<<"�˵��ţ�"<<head->getWaybillNumber()<<endl; // ���ͷ�ڵ���˵���
        cout<<"����ʱ�䣺"<<head->getSender().getSendTime().getTime()<<endl; // ���ͷ�ڵ������ʱ��
        cout<<"�ռ�ʱ�䣺"<<head->getReceiver().getReceiveTime().getTime()<<endl; // ���ͷ�ڵ���ռ�ʱ��
        return;
    }

    cout<<"��Ҫ����ʲôʱ������1.����ʱ�� 2.�ռ�ʱ��"<<endl;
    int time;
    cin>>time;
    cout<<"�����Ľ�����£�"<<endl;
    // ����һ����ʱ����
    vector<ExpressWaybill*> tempArray;
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        tempArray.push_back(p);
        p = p->next;
    }

    // ����ʱ�����������
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

    // ��������Ľ��
    for (ExpressWaybill* waybill : tempArray) {
        cout << "�˵��ţ�" << waybill->getWaybillNumber() << endl;
        cout << "����ʱ�䣺" << waybill->getSender().getSendTime().getTime() << endl;
        cout << "�ռ�ʱ�䣺" << waybill->getReceiver().getReceiveTime().getTime() << endl;
        cout << "--------------------------------" << endl;
    }
}

void ExpressWaybillList::sortExpressWaybillByType() {
    if (head == NULL ) {
        cout<<"����Ϊ�գ���������"<<endl;
        return; // �������Ϊ�ջ�ֻ��һ���ڵ㣬��������
    }else if(head->next == NULL){
        cout<<"�˵��ţ�"<<head->getWaybillNumber()<<endl; // ���ͷ�ڵ���˵���
        cout<<"������ͣ�"<<(head->getWaybillType() == 1 ? "���͵�" : "�ռ���")<<endl; // ���ͷ�ڵ�Ŀ������
        return;
    }

    cout<<"��Ҫ���������͵Ŀ�ݵ���ǰ�棿1.���͵� 2.�ռ���"<<endl;
    int type;
    cin>>type;
    cout<<"�����Ľ�����£�"<<endl;
    // ����һ����ʱ����
    vector<ExpressWaybill*> tempArray;
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        tempArray.push_back(p);
        p = p->next;
    }

    // ����ʱ�����������
    sort(tempArray.begin(), tempArray.end(), [type](ExpressWaybill* a, ExpressWaybill* b) {
        if(type == 1){
            return a->getWaybillType() < b->getWaybillType();
        }else{
            return a->getWaybillType() > b->getWaybillType();
        }
    });

    // ��������Ľ��
    for (ExpressWaybill* waybill : tempArray) {
        cout << "�˵��ţ�" << waybill->getWaybillNumber() << endl;
        cout << "������ͣ�" << (waybill->getWaybillType() == 1 ? "���͵�" : "�ռ���") << endl;
        cout << "--------------------------------" << endl;
    }
}

void ExpressWaybillList::sortExpressWaybillByAmount() {
    if (head == NULL ) {
        cout<<"����Ϊ�գ���������"<<endl;
        return; // �������Ϊ�ջ�ֻ��һ���ڵ㣬��������
    }else if(head->next == NULL){
        cout<<"�˵��ţ�"<<head->getWaybillNumber()<<endl; // ���ͷ�ڵ���˵���
        cout<<"��"<<head->getAmount()<<endl; // ���ͷ�ڵ�Ľ��
        return;
    }

    int sort_type;
    cout<<"��Ҫ��ʲô˳������1.���� 2.����"<<endl;
    cin>>sort_type;
    cout<<"�����Ľ�����£�"<<endl;
    // ����һ����ʱ����
    vector<ExpressWaybill*> tempArray;
    ExpressWaybill *p = head->next;
    while (p != NULL) {
        tempArray.push_back(p);
        p = p->next;
    }

    // ����ʱ�����������
    if(sort_type == 1){
        sort(tempArray.begin(), tempArray.end(), [](ExpressWaybill* a, ExpressWaybill* b) {
            return a->getAmount() < b->getAmount();
        });
    }else{
        sort(tempArray.begin(), tempArray.end(), [](ExpressWaybill* a, ExpressWaybill* b) {
            return a->getAmount() > b->getAmount();
        });
    }

    // ��������Ľ��
    for (ExpressWaybill* waybill : tempArray) {
        cout << "�˵��ţ�" << waybill->getWaybillNumber() << endl;
        cout << "��" << waybill->getAmount() << endl;
        cout << "--------------------------------" << endl;
    }
}


string getKeyFromFile() {
    ifstream inputFile("key.txt"); // �� key �ļ�
    if (!inputFile.is_open()) {
        cout << "�޷����ļ���" << endl;
        return "";
    }
    string key;
    getline(inputFile, key); // ��ȡ key
    inputFile.close(); // �ر��ļ�
    return key;
}

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
        cout << "��ѡ�����������0�ٿ�һ�����ѡ��" << endl;
        cout << "1.���ݵ��Ų�ѯ�˵�" << endl;
        cout << "2.���ݿ����𡢼ļ�����Ϣ�ͼļ����ڲ�ѯ�˵�" << endl;
        cout << "3.���ݿ�������ռ�����Ϣ��ѯ�˵�" << endl;
        cout << "4.�˳���ǰ�û������µ�¼" << endl;
        cout << "5.�˳�" << endl;
    } else {
        cout << "��ѡ�����������0�ٿ�һ�����ѡ��" << endl;
        cout << "1.����˵�" << endl;
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
    cin >> choice;
    while (true) {
        switch (choice) {
            case 0:
                if (user_type == 1) {
                    cout << "��ѡ�����������0�ٿ�һ�����ѡ��" << endl;
                    cout << "1.���ݵ��Ų�ѯ�˵�" << endl;
                    cout << "2.���ݿ����𡢼ļ�����Ϣ�ͼļ����ڲ�ѯ�˵�" << endl;
                    cout << "3.���ݿ�������ռ�����Ϣ��ѯ�˵�" << endl;
                    cout << "4.�˳���ǰ�û�" << endl;
                    cout << "5.�˳�" << endl;
                } else {
                    cout << "��ѡ�����������0�ٿ�һ�����ѡ��" << endl;
                    cout << "1.����˵�" << endl;
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
                        cout << "��ѡ�����������0�ٿ�һ�����ѡ��" << endl;
                        cout << "1.���ݵ��Ų�ѯ�˵�" << endl;
                        cout << "2.���ݿ����𡢼ļ�����Ϣ�ͼļ����ڲ�ѯ�˵�" << endl;
                        cout << "3.���ݿ�������ռ�����Ϣ��ѯ�˵�" << endl;
                        cout << "4.�˳���ǰ�û������µ�¼" << endl;
                        cout << "5.�˳�" << endl;
                    } else {
                        cout << "��ѡ�����������0�ٿ�һ�����ѡ��" << endl;
                        cout << "1.����˵�" << endl;
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
                    cout << "��ѡ�����������0�ٿ�һ�����ѡ��" << endl;
                    cout << "1.���ݵ��Ų�ѯ�˵�" << endl;
                    cout << "2.���ݿ����𡢼ļ�����Ϣ�ͼļ����ڲ�ѯ�˵�" << endl;
                    cout << "3.���ݿ�������ռ�����Ϣ��ѯ�˵�" << endl;
                    cout << "4.�˳���ǰ�û�" << endl;
                    cout << "5.�˳�" << endl;
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
        cin >> choice;
    }
    return 0;
}