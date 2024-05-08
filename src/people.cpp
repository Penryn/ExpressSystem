#include "../include/people.h"

string People::getAddress() {
    return address;
}

void People::setAddress(string a) {
    address = a;
}

string People::getPhone() {
    return phone;
}

void People::setPhone(string p) {
    phone = p;
}

string People::getRemark() {
    return remark;
}

void People::setRemark(string r) {
    remark = r;
}

Time &Sender::getSendTime() {
    return sendTime;
}

void Sender::setSendTime(Time t) {
    sendTime = t;
}

Time &Receiver::getReceiveTime() {
    return ReceiveTime;
}

void Receiver::setReceiveTime(Time t) {
    ReceiveTime = t;
}

