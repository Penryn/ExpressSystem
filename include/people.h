#include <string>

class People {
protected:
    string address; //��ַ
    string phone;   //�绰
    string remark;  //��ע
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
    Time sendTime;  //����ʱ��
public:
    Time& getSendTime() ;

    void setSendTime(Time t);
};

class Receiver : public People {
private:
    Time ReceiveTime;  //�ռ�ʱ��
public:
    Time& getReceiveTime() ;

    void setReceiveTime(Time t);
};