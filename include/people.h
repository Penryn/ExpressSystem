#include <string>

class People {
protected:
    string address; //地址
    string phone;   //电话
    string remark;  //备注
public:
    string getAddress();

    void setAddress(string a) ;

    string getPhone();

    void setPhone(string p) ;

    string getRemark();

    void setRemark(string r);

};

class Sender : public People {
private:
    Time sendTime;  //派送时间
public:
    Time& getSendTime() ;

    void setSendTime(Time t);
};

class Receiver : public People {
private:
    Time ReceiveTime;  //收件时间
public:
    Time& getReceiveTime() ;

    void setReceiveTime(Time t);
};