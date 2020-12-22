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
        cout << "��������" << endl;
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

//���˵�
class MainMenu : virtual public Menu {
public:

    void print() override {
        cout << "��ӭ��½ʳƷ��Ϣ����ϵͳ" << endl;
        cout << "��ѡ��������Ҫ�ķ�������������" << endl;
        cout << "1.��Ϣ����" << endl;
        cout << "2.���л�����Ϣ" << endl;
        cout << "3.��������" << endl;
        cout << "4.�������Ҷ�ӦʳƷ����" << endl;
        cout << "5.ʳƷ��Ϣ�޸�" << endl;
        cout << "6.ɾ������" << endl;
        cout << "7.�Զ�����ID" << endl;
        cout << "8.�˳�����" << endl;
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
                cout << "�����ڵı�ţ�����������" << endl;
                return 1;
                break;
        }
        return 0;
    }
};

#endif //CRM_MENU_H
