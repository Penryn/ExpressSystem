
class ExpressWaybillList {
private:
    ExpressWaybill *head;   //头指针
    ExpressWaybill *tail;   //尾指针
    int length;             //链表长度
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

    void getBlurExpressWaybillByNumber();

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

    bool searchExpressWaybillByNumber(const string& number);

    void getExpressWaybillByLastInput();

};