#include <utility>

#include "../include/express_waybill.h"


string ExpressWaybill::getWaybillNumber() {
    return waybillNumber;
}

void ExpressWaybill::setWaybillNumber(string number) {
    waybillNumber = std::move(number);
}

int ExpressWaybill::getWaybillType() const {
    return waybillType;
}

void ExpressWaybill::setWaybillType(int type) {
    waybillType = type;
}

Sender &ExpressWaybill::getSender() {
    return sender;
}

void ExpressWaybill::setSender(Sender s) {
    sender = std::move(s);
}

Receiver &ExpressWaybill::getReceiver() {
    return receiver;
}

void ExpressWaybill::setReceiver(Receiver r) {
    receiver = std::move(r);
}

bool ExpressWaybill::getIsSign() const {
    return isSign;
}

void ExpressWaybill::setIsSign(bool sign) {
    isSign = sign;
}

bool ExpressWaybill::getIsDifficult() const {
    return isDifficult;
}

void ExpressWaybill::setIsDifficult(bool difficult) {
    isDifficult = difficult;
}

int ExpressWaybill::getDifficultReason() const {
    return difficultReason;
}

void ExpressWaybill::setDifficultReason(int reason) {
    difficultReason = reason;
}

double ExpressWaybill::getAmount() const {
    return amount;
}

void ExpressWaybill::setAmount(double amt) {
    amount = amt;
}

