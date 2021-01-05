//
// Created by MCqie on 2020/12/7.
//

#ifndef CRM_FUNCIMPL_H
#define CRM_FUNCIMPL_H

#include <utility>
#include "Goods.h"
#include "Util.h"

using namespace std;

class FuncImpl {
public:
    virtual void impl(Goods_List *gl) {}
};

class InputGoodsImpl : public FuncImpl {
public:
    static Goods InputGoods() {
        return Goods::inputNew();
    }
    void impl(Goods_List *gl) override {
        Goods g = InputGoods();
        char c;
        list<Goods>::iterator iter;
        iter = gl->getiter();
        int i = 0;
        for (; i < gl->getList().size(); i++) {
            if (gl->get(i).id == g.id) {
                cout << "��ID�Ѿ��ظ�" << endl;
                cout << g.toString() << endl;
                break;
            }
        }
        if (i == gl->getList().size()) {
            cout << "�Ƿ񱣴�(y/n)" << endl;
            while (true) {
                Util::inputChar(&c);
                if (c == 'Y' || c == 'y' || c == 'N' || c == 'n') {
                    if (c == 'Y' || c == 'y') {
                        gl->add(g);
                        cout << "����ɹ�" << endl;
                        break;
                    } else {
                        break;
                    }
                }
            }
        }

    }
};

class AllGoodImpl : public FuncImpl {
public:
    void impl(Goods_List *gl) override {
        gl->sort();
        list<Goods>::iterator iter;
        iter = gl->getiter();
        cout << "ȫ��������Ϣ" << endl;
        for (int i = 0; i < gl->getList().size(); i++) {
            cout << iter->toString() << endl;
            iter++;
        }
    }
};

class SearchImpl : public FuncImpl {
public:
    static int search(Goods_List *gl, const string &name) {
        vector<int> v = gl->findWithname(name);
        Goods_List gll = gl->getAll(v);
        if (gll.getList().empty()) {
            cout << "δ��ѯ����Ϣ" << endl;
        } else {
            AllGoodImpl().impl(&gll);
        }
        cout << "�Ƿ����(y/n)" << endl;
        char c;
        while (true) {
            Util::inputChar(&c);
            if (c == 'Y' || c == 'y' || c == 'N' || c == 'n') {
                if (c == 'Y' || c == 'y') {
                    return 1;
                } else {
                    return 0;
                }
            }
        }

    }

    void impl(Goods_List *gl) override {
        string name;
        do {
            cout << "���� ���� ����ģʽ ��������:" << endl;
            cin >> name;
        } while (
                search(gl, name));
    }


};

class SearchfromImpl : public FuncImpl {
public:
    static int search(Goods_List *gl, const string &from) {
        vector<int> v = gl->findWithfrom(from);
        Goods_List gll = gl->getAll(v);
        if (gll.getList().empty()) {
            cout << "δ��ѯ����Ϣ" << endl;
        } else {
            cout<<"���ҵ�"<<gll.getList().size()<<"��"<<endl;
            AllGoodImpl().impl(&gll);
        }
        cout << "�Ƿ����(y/n)" << endl;
        char c;
        while (true) {
            Util::inputChar(&c);
            if (c == 'Y' || c == 'y' || c == 'N' || c == 'n') {
                if (c == 'Y' || c == 'y') {
                    return 1;
                } else {
                    return 0;
                }
            }
        }

    }

    void impl(Goods_List *gl) override {
        string from;
        do {
            cout << "���� ���� ����ģʽ ���볧��:" << endl;
            cin >> from;
        } while (
                search(gl, from));
    }


};

class ChangeImpl : public FuncImpl {
public:
    void impl(Goods_List *gl) override {
        AllGoodImpl().impl(gl);
        cout << "��������Ҫ�޸ĵĻ���ID" << endl;
        int i;
        Util::inputInt(&i);
        int g = gl->findWithid(i);
        if (g != -1) {
            Goods ge = gl->get(g);
            cout << "��Ҫ���޸ĵ����ݣ�" << endl;
            cout << ge.toString() << endl;
            cout << "��������Ҫ�޸ĵ�����" << endl;
            cout << "(1)id (2)���� (3)���� (4)�۸� (5)������ (6)�����" << endl;//id, name, from, price, input, stock
            int c;
            Util::inputInt(&c);
            switch (c) {
                case 1:
                    int id;
                    cout << "������ֵ" << endl;
                    Util::inputInt(&id);
                    if (Util::ckeckID(gl, id)) {
                        ge.setid(id);
                    }
                    break;
                case 2: {
                    string name;
                    cout << "������ֵ" << endl;
                    cin >> name;
                    ge.setname(name);

                    break;
                }
                case 3: {
                    string from;
                    cout << "������ֵ" << endl;
                    cin >> from;
                    ge.setfrom(from);

                    break;
                }
                case 4: {
                    double price;
                    cout << "������ֵ" << endl;
                    Util::inputDouble(&price);
                    ge.setprice(price);
                }
                    break;
                case 5:
                    int input;
                    cout << "������ֵ" << endl;
                    Util::inputInt(&input);
                    ge.setinput(input);
                    break;
                case 6:
                    int stock;
                    cout << "������ֵ" << endl;
                    Util::inputInt(&stock);
                    ge.setstock(stock);
                    break;
                default:
                    cout << "û�������޸�" << endl;
            }
            gl->remove(g);
            gl->add(ge);
            gl->sort();

        } else {
            cout << "δ�ҵ��˻��� " << endl;
        }
    }
};

class DeleteImpl: public FuncImpl{
public:
    void impl(Goods_List *gl) override{
        cout<<"��������Ҫɾ���Ļ���ID"<<endl;
        int i;
        Util::inputInt(&i);
       int x= gl->findWithid(i);
        cout<<gl->get(x).toString()<<endl;
        char c;
        cout << "�Ƿ�ɾ��(y/n)" << endl;
        while (true) {
            Util::inputChar(&c);
            if (c == 'Y' || c == 'y' || c == 'N' || c == 'n') {
                if (c == 'Y' || c == 'y') {
                    gl->remove(x);
                    cout << "ɾ���ɹ�" << endl;
                    break;
                } else {
                    break;
                }
            }
        }
    }
};

class ResetImpl: public FuncImpl{
public:
    void impl(Goods_List *gl) override{
        cout<<"��ʼ����"<<endl;
        gl->resetID();
        AllGoodImpl().impl(gl);
        cout<<"�������"<<endl;
    }
};
#endif //CRM_FUNCIMPL_H