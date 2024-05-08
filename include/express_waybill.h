#include <string>



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



    string getWaybillNumber();

    void setWaybillNumber(string number);

    int getWaybillType();

    void setWaybillType(int type);

    Sender& getSender() ;

    void setSender(Sender s) ;

    Receiver& getReceiver();

    void setReceiver(Receiver r);

    bool getIsSign() ;

    void setIsSign(bool sign);

    bool getIsDifficult() ;

    void setIsDifficult(bool difficult);

    int getDifficultReason();

    void setDifficultReason(int reason);

    double getAmount() ;

    void setAmount(double amt);
};