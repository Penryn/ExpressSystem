#include <string>



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
    ExpressWaybill *prev;  //上一个运单
    ExpressWaybill *next;  //下一个运单



    string getWaybillNumber();

    void setWaybillNumber(string number);

    int getWaybillType() const;

    void setWaybillType(int type);

    Sender& getSender() ;

    void setSender(Sender s) ;

    Receiver& getReceiver();

    void setReceiver(Receiver r);

    bool getIsSign() const ;

    void setIsSign(bool sign);

    bool getIsDifficult() const ;

    void setIsDifficult(bool difficult);

    int getDifficultReason() const;

    void setDifficultReason(int reason);

    double getAmount() const ;

    void setAmount(double amt);
};