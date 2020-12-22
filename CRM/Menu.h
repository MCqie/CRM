//
// Created by MCqie on 2020/12/7.
//

#ifndef CRM_MENU_H

#include "iostream"
#include "string"
#include "Util.h"
#include "Goods.h"
#include "FuncImpl.h"

#define CRM_MENU_H
using namespace std;

class Menu {

public:
    virtual void print() {}

    void show(Goods_List *gl) {
        Util::cls();
        print();
        cout << "请输入编号" << endl;
        int i;
        do {
            Util::inputInt(&i);
        } while (judge(i, gl));
        Util::pause();
    }

    virtual int judge(int i, Goods_List *gl) {
        return 0;
    }
};

//主菜单
class MainMenu : virtual public Menu {
public:

    void print() override {
        cout << "欢迎登陆食品信息管理系统" << endl;
        cout << "请选择您所需要的服务，请输入数字" << endl;
        cout << "1.信息输入" << endl;
        cout << "2.所有货物信息" << endl;
        cout << "3.搜索货物" << endl;
        cout << "4.搜索厂家对应食品数量" << endl;
        cout << "5.食品信息修改" << endl;
        cout << "6.删除货物" << endl;
        cout << "7.自动整理ID" << endl;
        cout << "8.退出程序" << endl;
    }

    int judge(int i, Goods_List *gl) override {
        switch (i) {
            case 1:
                InputGoodsImpl().impl(gl);
                break;
            case 2:
                AllGoodImpl().impl(gl);
                break;
            case 3:
                SearchImpl().impl(gl);
                break;
            case 4:
                SearchfromImpl().impl(gl);
                break;
            case 5:
                ChangeImpl().impl(gl);
                break;
            case 6:
                DeleteImpl().impl(gl);
                break;
            case 7:
                ResetImpl().impl(gl);
                break;
            case 8:
                exit(0);
            default:
                cout << "不存在的编号，请重新输入" << endl;
                return 1;
                break;
        }
        return 0;
    }
};

#endif //CRM_MENU_H
