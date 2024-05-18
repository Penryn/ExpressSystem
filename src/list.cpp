#include "../include/list.h"
#include "tool.cpp"
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
    while (p != nullptr) {
        ExpressWaybill *q = p;
        p = p->next;
        delete q;
    }
}

void ExpressWaybillList::addExpressWaybill() {
    cout << "��������Ҫ�������˵���(�����ظ�),����0����" << endl;
    string waybillNumber;
    while (cin >> waybillNumber) {
        if (waybillNumber == "0") {
            break;
        }
        if (searchExpressWaybillByNumber(waybillNumber)) {
            cout << "�˵����Ѵ��ڣ�����������" << endl;
            continue;
        }
        auto *expressWaybill = new ExpressWaybill();
        expressWaybill->setWaybillNumber(waybillNumber);
        cout << "������������ 1:���͵� 2:�ռ���" << endl;
        int waybillType;
        waybillType= getRightInput(a, 2);
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
        cout << "����������ʱ�䣬������ �� �գ��ÿո�ָ�" << endl;
        Time sendTime{};
        sendTime= getTimeInput();
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
        Time receiveTime{};
        cout << "�������ռ�ʱ�䣬������ �� �գ��ÿո�ָ�" << endl;
        while (true) {
            receiveTime= getTimeInput();
            if (receiveTime.getTime() < sendTime.getTime()) {
                cout << "�ռ�ʱ�䲻����������ʱ�䣬����������" << endl;
            } else {
                break;
            }
        }
        receiver.setReceiveTime(receiveTime);
        expressWaybill->setReceiver(receiver);
        cout << "�������Ƿ�ǩ�� 1:�� 0:��" << endl;
        bool isSign;
        isSign= getRightInput(b, 2);
        expressWaybill->setIsSign(isSign);
        if (!isSign) {
            cout << "�������Ƿ�Ϊ���ɼ� 1:�� 0:��" << endl;
            bool isDifficult;
            isDifficult= getRightInput(b, 2);
            expressWaybill->setIsDifficult(isDifficult);
            if (isDifficult) {
                cout << "���������ɼ�ԭ�� 1����ַģ�� 2���û����� 3���绰��Ч 4���ռ��˲��� 5������" << endl;
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
        cout << "��������" << endl;
        double amount;
        while(true){
            amount= getInput<double>();
            if(amount<0){
                cout<<"����Ϊ����������������"<<endl;
            }else{
                break;
            }
        }
        expressWaybill->setAmount(amount);
        tail->next = expressWaybill;
        tail->next->prev = tail;
        tail = expressWaybill;
        length++;
        cout<< "�˵���Ϊ " << waybillNumber << " ���˵������" << endl;
        cout<<"--------------------------------"<<endl;
        cout << "��������Ҫ�������˵���(�����ظ�),����0����" << endl;
    }
}

void ExpressWaybillList::displayExpressWaybill() {
    ExpressWaybill *p = head->next;
    if (p == nullptr) {
        cout << "�б�Ϊ�ա�" << endl;
        return;
    }
    while (p != nullptr) {
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
            case 0:
                cout << "��" << endl;
                break;
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
        if (head->next == nullptr) {
            cout << "�б�Ϊ�գ��޷�ɾ����" << endl;
            break;
        }
        ExpressWaybill *p = head;
        bool isFound = false;
        while (p->next != nullptr) {
            if (p->next->getWaybillNumber() == waybillNumber) {
                ExpressWaybill *q = p->next;
                p->next = q->next;
                if (q->next != nullptr) {
                    q->next->prev = p;
                }
                if (q == tail) {
                    tail = p;
                }
                delete q;
                length--;
                isFound = true;
                cout << "�˵���Ϊ " << waybillNumber << " ���˵���ɾ��" << endl;
                break;
            }
            p = p->next;
        }
        if (!isFound) {
            cout << "δ�ҵ��˵���Ϊ " << waybillNumber << " ���˵���" << endl;
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
        while (p != nullptr) {
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
                change = getRightInput(b, 2);
                if (change) {
                    cout << "������������ 1:���͵� 2:�ռ���" << endl;
                    int waybillType;
                    waybillType= getRightInput(a, 2);
                    p->setWaybillType(waybillType);
                } else {
                    p->setWaybillType(p->getWaybillType());
                }
                cout << "ԭ�ļ�����Ϣ��" << endl;
                cout << "��ַ��" << p->getSender().getAddress() << endl;
                cout << "�绰��" << p->getSender().getPhone() << endl;
                cout << "��ע��" << p->getSender().getRemark() << endl;
                cout << "���Ƿ�Ҫ�޸ļļ�����Ϣ 1:�� 0:��" << endl;
                change = getRightInput(b, 2);
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
                change = getRightInput(b, 2);
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
                change = getRightInput(b, 2);
                if (change) {
                    cout << "����������ʱ��,������ �� �գ��ÿո�ָ�" << endl;
                    Time sendTime{};
                    sendTime= getTimeInput();
                    p->getSender().setSendTime(sendTime);
                } else {
                    p->getSender().setSendTime(p->getSender().getSendTime());
                }
                cout << "ԭ�ռ�ʱ�䣺" << p->getReceiver().getReceiveTime().getTime() << endl;
                cout << "���Ƿ�Ҫ�޸��ռ�ʱ�� 1:�� 0:��" << endl;
                change = getRightInput(b, 2);
                if (change) {
                    cout << "�������ռ�ʱ��,������ �� �գ��ÿո�ָ�" << endl;
                    Time receiveTime{};
                    receiveTime= getTimeInput();
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
                change = getRightInput(b, 2);
                if (change) {
                    cout << "�������Ƿ�ǩ�� 1:�� 0:��" << endl;
                    bool isSign;
                    isSign= getRightInput(b, 2);
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
                    change = getRightInput(b, 2);
                    if (change) {
                        cout << "�������Ƿ�Ϊ���ɼ� 1:�� 0:��" << endl;
                        bool isDifficult;
                        isDifficult= getRightInput(b, 2);
                        p->setIsDifficult(isDifficult);
                        if (isDifficult) {
                            cout << "���������ɼ�ԭ�� 1����ַģ�� 2���û����� 3���绰��Ч 4���ռ��˲��� 5������" << endl;
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
                cout << "ԭ��" << p->getAmount() << endl;
                cout << "���Ƿ�Ҫ�޸Ľ�� 1:�� 0:��" << endl;
                change = getRightInput(b, 2);
                if (change) {
                    cout << "��������" << endl;
                    double amount;
                    while(true){
                        amount= getInput<double>();
                        if(amount<0){
                            cout<<"����Ϊ����������������"<<endl;
                        }else{
                            break;
                        }
                    }
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
    ofstream outputFile("./data/waybills.csv"); // ���� CSV �ļ�
    if (!outputFile.is_open()) {
        cout << "�޷����ļ���" << endl;
        return;
    }
    // д�� CSV �ļ��ı�����
    outputFile<< "�˵���,�������,�ļ��˵�ַ,�ļ��˵绰,�ļ��˱�ע,�ռ��˵�ַ,�ռ��˵绰,�ռ��˱�ע,����ʱ��,�ռ�ʱ��,�Ƿ�ǩ��,�Ƿ�Ϊ���ɼ�,���ɼ�ԭ��,���\n";

    ExpressWaybill *p = head->next;
    while (p != nullptr) {
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
        }
        outputFile << ",";
        outputFile << p->getAmount() << ",\n";

        p = p->next;
    }
    outputFile.close(); // �ر��ļ�
    cout << "�˵���Ϣ�ѳɹ����浽 waybills.csv �ļ���" << endl;
}

void ExpressWaybillList::loadExpressWaybillFromFile() {
    clear();
    ifstream inputFile("./data/waybills.csv"); // �� CSV �ļ�
    if (!inputFile.is_open()) {
        cout << "�޷����ļ���" << endl;
        return;
    }
    string line;
    getline(inputFile, line); // ��ȡ������
    while (getline(inputFile, line)) {
        auto *expressWaybill = new ExpressWaybill();
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
        while ((pos = line.find(',')) != string::npos) {
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
        Time sendTimeObj{};
        pos = 0;
        int datePart = 0;
        while ((pos = sendTime.find('-')) != string::npos) {
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
        Time receiveTimeObj{};
        pos = 0;
        datePart = 0;
        while ((pos = receiveTime.find('-')) != string::npos) {
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
        tail->next->prev = tail;
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
    while (p != nullptr) {
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

void ExpressWaybillList::getBlurExpressWaybillByNumber() {
    cout << "������Ҫ��ѯ���˵��ŵ�ģ��ƥ��" << endl;
    string waybillNumber;
    cin >> waybillNumber;
    ExpressWaybill *p = head->next;
    bool isFound = false;
    while (p != nullptr) {
        if (p->getWaybillNumber().find(waybillNumber) != string::npos) {
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
        cout << "δ�ҵ��˵��Ű��� " << waybillNumber << " ���˵���" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByTypeAndSenderAndDate() {
    cout << "������Ҫ��ѯ�Ŀ������ 1:���͵� 2:�ռ���" << endl;
    int waybillType;
    waybillType= getRightInput(a, 2);
    cout << "������ļ��˵�ַ" << endl;
    string senderAddress;
    cin >> senderAddress;
    cout << "������ļ����ڣ������� �� �գ��ÿո�ָ�" << endl;
    Time sendTime{};
    sendTime = getTimeInput();
    ExpressWaybill *p = head->next;
    bool isFound = false;
    while (p != nullptr) {
        if (p->getWaybillType() == waybillType && p->getSender().getAddress() == senderAddress &&
            p->getSender().getSendTime().getTime()==sendTime.getTime() ){
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
        cout << "δ�ҵ��������Ϊ " ;
        if (waybillType == 1) {
            cout << "���͵�";
        } else {
            cout << "�ռ���";
        }
        cout << " �ļ��˵�ַΪ " << senderAddress << " �ļ�����Ϊ " << sendTime.getTime() << " ���˵���" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByTypeAndReceiver() {
    cout << "������Ҫ��ѯ�Ŀ������ 1:���͵� 2:�ռ���" << endl;
    int waybillType;
    waybillType= getRightInput(a, 2);
    cout << "�������ռ��˵�ַ" << endl;
    string receiverAddress;
    cin >> receiverAddress;
    cout << "�������ռ��˵绰" << endl;
    string receiverPhone;
    cin >> receiverPhone;
    ExpressWaybill *p = head->next;
    cout << "��ѯ������£�" << endl;
    bool isFound = false;
    while (p != nullptr) {
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
                case 0:
                    cout << "��" << endl;
                    break;
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

            }
            cout << "��" << p->getAmount() << endl;
            cout << "--------------------------------" << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��������Ϊ ";
        if (waybillType == 1) {
            cout << "���͵�";
        } else {
            cout << "�ռ���";
        }
        cout << " �ռ��˵�ַΪ " << receiverAddress << " �ռ��˵绰Ϊ " << receiverPhone << " ���˵���" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByType() {
    cout << "������Ҫ��ѯ�Ŀ������ 1:���͵� 2:�ռ���" << endl;
    int waybillType;
    waybillType= getRightInput(a, 2);
    ExpressWaybill *p = head->next;
    bool isFound = false;
    cout << "��ѯ������£�" << endl;
    while (p != nullptr) {
        if (p->getWaybillType() == waybillType) {
            isFound = true;
            cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��������Ϊ ";
        if (waybillType == 1) {
            cout << "���͵�";
        } else {
            cout << "�ռ���";
        }
        cout << " ���˵���" << endl;
    }
}

void ExpressWaybillList::getExpressWaybillByReceiveDate() {
    cout << "������Ҫ��ѯ���ռ����ڣ������� �� ��,�ÿո�ָ�" << endl;
    Time receiveTime = getTimeInput();
    ExpressWaybill *p = head->next;
    bool isFound = false;
    cout << "��ѯ������£�" << endl;
    while (p != nullptr) {
        if (p->getReceiver().getReceiveTime().getTime() == receiveTime.getTime()) {
            isFound = true;
            cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��ռ�����Ϊ " << receiveTime.getTime() << " ���˵���" << endl;
    }else{
        cout<<"�����Ҫ��һ��ͨ���˵��ž����ѯ�˵��ľ�����Ϣ������������5"<<endl;
    }
}

void ExpressWaybillList::getExpressWaybillBySendDate() {
    cout << "������Ҫ��ѯ���������ڣ������� �� ��,�ÿո�ָ�" << endl;
    Time sendTime = getTimeInput();
    ExpressWaybill *p = head->next;
    cout << "��ѯ������£�" << endl;
    bool isFound = false;
    while (p != nullptr) {
        if (p->getSender().getSendTime().getTime() == sendTime.getTime()) {
            isFound = true;
            cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ���������Ϊ " << sendTime.getTime() << " ���˵���" << endl;
    }else{
        cout<<"�����Ҫ��һ��ͨ���˵��ž����ѯ�˵��ľ�����Ϣ������������5"<<endl;
    }
}

void ExpressWaybillList::getExpressWaybillAndCountByReceiveDate() {
    cout << "������Ҫ��ѯ�˵������ͽ����ռ����ڣ������� �� ��,�ÿո�ָ�" << endl;
    Time receiveTime = getTimeInput();
    int count = 0;
    double amount = 0;
    ExpressWaybill *p = head->next;
    bool isFound = false;
    while (p != nullptr) {
        if (p->getReceiver().getReceiveTime().getTime() == receiveTime.getTime()) {
            isFound = true;
            count++;
            amount += p->getAmount();
        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��ռ�����Ϊ " << receiveTime.getTime() << " ���˵���" << endl;
        return;
    }else{
        cout << "�ռ�����Ϊ" << receiveTime.getTime() << "�Ŀ�ݵ�����Ϊ" << count << "���ܽ��Ϊ" << amount << "Ԫ��" << endl;
        cout << "��������ѯ�����ռ����ڵ��˵������ͽ���������������9" << endl;
    }
}

void ExpressWaybillList::getNotReceivedExpressWaybillBySendDate() {
    cout << "������Ҫ��ѯδǩ�յ��������ڣ������� �� ��,�ÿո�ָ�" << endl;
    Time sendTime = getTimeInput();
    ExpressWaybill *p = head->next;
    cout << "��ѯ������£�" << endl;
    bool isFound = false;
    while (p != nullptr) {
        if (p->getSender().getSendTime().getTime() == sendTime.getTime() && !p->getIsSign()) {
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
                }

            }
            cout << "--------------------------------" << endl;

        }
        p = p->next;
    }
    if (!isFound) {
        cout << "δ�ҵ��ļ�����Ϊ " << sendTime.getTime() << " ��δǩ�յ��˵���" << endl;
        cout<<"��������ѯ����δǩ�յ��˵�����������������10"<<endl;
    }else{
        cout<<"��������ѯ����δǩ�յ��˵�����������������10"<<endl;
        cout<<"�����Ҫ��һ��ͨ���˵��ž����ѯ�˵��ľ�����Ϣ������������5"<<endl;
    }
}

// ��������ʱ������
void ExpressWaybillList::sortExpressWaybillByDate() {
    if (head == nullptr ) {
        cout<<"����Ϊ�գ���������"<<endl;
        return; // �������Ϊ�ջ�ֻ��һ���ڵ㣬��������
    }else if(head->next == nullptr){
        cout<<"�˵��ţ�"<<head->getWaybillNumber()<<endl; // ���ͷ�ڵ���˵���
        cout<<"����ʱ�䣺"<<head->getSender().getSendTime().getTime()<<endl; // ���ͷ�ڵ������ʱ��
        cout<<"�ռ�ʱ�䣺"<<head->getReceiver().getReceiveTime().getTime()<<endl; // ���ͷ�ڵ���ռ�ʱ��
        return;
    }
    cout<<"��Ҫ����ʲôʱ������1.����ʱ�� 2.�ռ�ʱ��"<<endl;
    int time;
    time = getRightInput(a, 2);
    int sort_type;
    cout<<"��Ҫ��ʲô˳������1.���� 2.����"<<endl;
    sort_type = getRightInput(a, 2);
    cout<<"�����Ľ�����£�"<<endl;
    // ����һ����ʱ����
    vector<ExpressWaybill*> tempArray;
    ExpressWaybill *p = head->next;
    while (p != nullptr) {
        tempArray.push_back(p);
        p = p->next;
    }

    // ����ʱ�����������
    if(time == 1){
        if(sort_type == 1){
            sort(tempArray.begin(), tempArray.end(), [](ExpressWaybill* a, ExpressWaybill* b) {
                return a->getSender().getSendTime() < b->getSender().getSendTime();
            });
        }else{
            sort(tempArray.begin(), tempArray.end(), [](ExpressWaybill* a, ExpressWaybill* b) {
                return ! (a->getSender().getSendTime() < b->getSender().getSendTime());
            });
        }
    }else{
        if(sort_type == 1){
            sort(tempArray.begin(), tempArray.end(), [](ExpressWaybill* a, ExpressWaybill* b) {
                return a->getReceiver().getReceiveTime() < b->getReceiver().getReceiveTime();
            });
        }else{
            sort(tempArray.begin(), tempArray.end(), [](ExpressWaybill* a, ExpressWaybill* b) {
                return ! (a->getReceiver().getReceiveTime() < b->getReceiver().getReceiveTime());
            });
        }
    }

    // ��������Ľ��
    for (ExpressWaybill* waybill : tempArray) {
        cout << "�˵��ţ�" << waybill->getWaybillNumber() << endl;
        cout << "����ʱ�䣺" << waybill->getSender().getSendTime().getTime() << endl;
        cout << "�ռ�ʱ�䣺" << waybill->getReceiver().getReceiveTime().getTime() << endl;
        cout << "--------------------------------" << endl;
    }
    cout<<"�����Ҫ��һ��ͨ���˵��ž����ѯ�˵��ľ�����Ϣ������������5"<<endl;
}

void ExpressWaybillList::sortExpressWaybillByType() {
    if (head == nullptr ) {
        cout<<"����Ϊ�գ���������"<<endl;
        return; // �������Ϊ�ջ�ֻ��һ���ڵ㣬��������
    }else if(head->next == nullptr){
        cout<<"�˵��ţ�"<<head->getWaybillNumber()<<endl; // ���ͷ�ڵ���˵���
        cout<<"������ͣ�"<<(head->getWaybillType() == 1 ? "���͵�" : "�ռ���")<<endl; // ���ͷ�ڵ�Ŀ������
        return;
    }

    cout<<"��Ҫ���������͵Ŀ�ݵ���ǰ�棿1.���͵� 2.�ռ���"<<endl;
    int type;
    type = getRightInput(a, 2);
    cout<<"�����Ľ�����£�"<<endl;
    // ����һ����ʱ����
    vector<ExpressWaybill*> tempArray;
    ExpressWaybill *p = head->next;
    while (p != nullptr) {
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
    cout<<"�����Ҫ��һ��ͨ���˵��ž����ѯ�˵��ľ�����Ϣ������������5"<<endl;
}

void ExpressWaybillList::sortExpressWaybillByAmount() {
    if (head == nullptr ) {
        cout<<"����Ϊ�գ���������"<<endl;
        return; // �������Ϊ�ջ�ֻ��һ���ڵ㣬��������
    }else if(head->next == nullptr){
        cout<<"�˵��ţ�"<<head->getWaybillNumber()<<endl; // ���ͷ�ڵ���˵���
        cout<<"��"<<head->getAmount()<<endl; // ���ͷ�ڵ�Ľ��
        return;
    }

    int sort_type;
    cout<<"��Ҫ��ʲô˳������1.���� 2.����"<<endl;
    sort_type = getRightInput(a, 2);
    cout<<"�����Ľ�����£�"<<endl;
    // ����һ����ʱ����
    vector<ExpressWaybill*> tempArray;
    ExpressWaybill *p = head->next;
    while (p != nullptr) {
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
    cout<<"����������5����һ��ͨ���˵��ž����ѯ�˵��ľ�����Ϣ"<<endl;
}

bool ExpressWaybillList::searchExpressWaybillByNumber(const std::string& number) {
    ExpressWaybill *p = head->next;
    while (p != nullptr) {
        if (p->getWaybillNumber() == number) {
            return true;
        }
        p = p->next;
    }
    return false;
}

void ExpressWaybillList::getExpressWaybillByLastInput(){
    cout<< "������Ҫ��ѯ��ǰ¼�뼸���˵�" << endl;
    int num;
    while (true) {
        num = getInput<int>();
        if (num <= 0) {
            cout << "������һ��������" << endl;
        } else {
            break;
        }
    }
    ExpressWaybill *p = tail;
    int count = 0;
    while (p != nullptr && count < num) {
        cout << "�˵��ţ�" << p->getWaybillNumber() << endl;
        cout << "������ͣ�";
        if (p->getWaybillType() == 1) {
            cout << "���͵�" << endl;
        } else {
            cout << "�ռ���" << endl;
        }
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
        cout << "--------------------------------" << endl;
        if (p->prev != nullptr) {
            p = p->prev;
        } else {
            cout<<"��¼�Ѿ������һ��"<<endl;
            break;
        }
        count++;
    }
    cout<<"����������5����һ��ͨ���˵��ž����ѯ�˵��ľ�����Ϣ"<<endl;
}

void ExpressWaybillList::clear() {
    ExpressWaybill *p = head;
    while (p != nullptr) {
        ExpressWaybill *q = p;
        p = p->next;
        delete q;
    }
    head = new ExpressWaybill();
    tail = head;
    length = 0;
}