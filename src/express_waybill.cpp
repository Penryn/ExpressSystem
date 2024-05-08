#include "../include/express_waybill.h"


string ExpressWaybill::getWaybillNumber() {
    return waybillNumber;
}

void ExpressWaybill::setWaybillNumber(string number) {
    waybillNumber = number;
}

int ExpressWaybill::getWaybillType() {
    return waybillType;
}

void ExpressWaybill::setWaybillType(int type) {
    waybillType = type;
}

Sender &ExpressWaybill::getSender() {
    return sender;
}

void ExpressWaybill::setSender(Sender s) {
    sender = s;
}

Receiver &ExpressWaybill::getReceiver() {
    return receiver;
}

void ExpressWaybill::setReceiver(Receiver r) {
    receiver = r;
}

bool ExpressWaybill::getIsSign() {
    return isSign;
}

void ExpressWaybill::setIsSign(bool sign) {
    isSign = sign;
}

bool ExpressWaybill::getIsDifficult() {
    return isDifficult;
}

void ExpressWaybill::setIsDifficult(bool difficult) {
    isDifficult = difficult;
}

int ExpressWaybill::getDifficultReason() {
    return difficultReason;
}

void ExpressWaybill::setDifficultReason(int reason) {
    difficultReason = reason;
}

double ExpressWaybill::getAmount() {
    return amount;
}

void ExpressWaybill::setAmount(double amt) {
    amount = amt;
}

