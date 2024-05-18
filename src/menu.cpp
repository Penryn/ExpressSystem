#include <iostream>
void getUserMenu() {
    cout << "请选择操作，输入0再看一遍操作选择" << endl;
    cout << "1.根据单号具体查询运单" << endl;
    cout << "2.根据快递类别、寄件人信息和寄件日期查询运单" << endl;
    cout << "3.根据快递类别和收件人信息查询运单" << endl;
    cout << "4.退出当前用户，重新进入登录状态" << endl;
    cout << "5.退出" << endl;
}
void getAdminMenu(){
    cout << "请选择操作，输入0再看一遍操作选择" << endl;
    cout << "1.添加运单" << endl;
    cout << "2.删除运单" << endl;
    cout << "3.修改运单" << endl;
    cout << "4.显示所有运单" << endl;
    cout << "5.根据单号模糊或具体查询运单" << endl;
    cout << "6.根据快递类别查询所有运单" << endl;
    cout << "7.根据收件日期查询所有运单" << endl;
    cout << "8.根据派送日期查询所有运单" << endl;
    cout << "9.根据收件日期统计快递单数量和金额" << endl;
    cout << "10.根据寄件日期显示未签收的快递单，并显示所有疑难件" << endl;
    cout << "11.将快递信息按日期排序" << endl;
    cout << "12.将快递信息按类别排序" << endl;
    cout << "13.将快递信息按金额排序" << endl;
    cout << "14.保存运单信息到文件" << endl;
    cout << "15.从文件中读取运单信息" << endl;
    cout << "16.退出管理员账号，进入用户模式" << endl;
    cout << "17.返回前几次输入的运单信息" << endl;
    cout << "18.退出" << endl;
}

