
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