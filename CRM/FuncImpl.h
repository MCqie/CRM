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
                cout << "此ID已经重复" << endl;
                cout << g.toString() << endl;
                break;
            }
        }
        if (i == gl->getList().size()) {
            cout << "是否保存(y/n)" << endl;
            while (true) {
                Util::inputChar(&c);
                if (c == 'Y' || c == 'y' || c == 'N' || c == 'n') {
                    if (c == 'Y' || c == 'y') {
                        gl->add(g);
                        cout << "保存成功" << endl;
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
        cout << "全部货物信息" << endl;
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
            cout << "未查询到信息" << endl;
        } else {
            AllGoodImpl().impl(&gll);
        }
        cout << "是否继续(y/n)" << endl;
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
            cout << "进入 名称 搜索模式 输入名称:" << endl;
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
            cout << "未查询到信息" << endl;
        } else {
            cout<<"共找到"<<gll.getList().size()<<"个"<<endl;
            AllGoodImpl().impl(&gll);
        }
        cout << "是否继续(y/n)" << endl;
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
            cout << "进入 厂家 搜索模式 输入厂家:" << endl;
            cin >> from;
        } while (
                search(gl, from));
    }


};

class ChangeImpl : public FuncImpl {
public:
    void impl(Goods_List *gl) override {
        AllGoodImpl().impl(gl);
        cout << "请输入想要修改的货物ID" << endl;
        int i;
        Util::inputInt(&i);
        int g = gl->findWithid(i);
        if (g != -1) {
            Goods ge = gl->get(g);
            cout << "将要被修改的内容：" << endl;
            cout << ge.toString() << endl;
            cout << "请输入想要修改的内容" << endl;
            cout << "(1)id (2)名称 (3)厂家 (4)价格 (5)进货量 (6)存货量" << endl;//id, name, from, price, input, stock
            int c;
            Util::inputInt(&c);
            switch (c) {
                case 1:
                    int id;
                    cout << "输入新值" << endl;
                    Util::inputInt(&id);
                    if (Util::ckeckID(gl, id)) {
                        ge.setid(id);
                    }
                    break;
                case 2: {
                    string name;
                    cout << "输入新值" << endl;
                    cin >> name;
                    ge.setname(name);

                    break;
                }
                case 3: {
                    string from;
                    cout << "输入新值" << endl;
                    cin >> from;
                    ge.setfrom(from);

                    break;
                }
                case 4: {
                    double price;
                    cout << "输入新值" << endl;
                    Util::inputDouble(&price);
                    ge.setprice(price);
                }
                    break;
                case 5:
                    int input;
                    cout << "输入新值" << endl;
                    Util::inputInt(&input);
                    ge.setinput(input);
                    break;
                case 6:
                    int stock;
                    cout << "输入新值" << endl;
                    Util::inputInt(&stock);
                    ge.setstock(stock);
                    break;
                default:
                    cout << "没有这项修改" << endl;
            }
            gl->remove(g);
            gl->add(ge);
            gl->sort();

        } else {
            cout << "未找到此货物 " << endl;
        }
    }
};

class DeleteImpl: public FuncImpl{
public:
    void impl(Goods_List *gl) override{
        cout<<"请输入想要删除的货物ID"<<endl;
        int i;
        Util::inputInt(&i);
       int x= gl->findWithid(i);
        cout<<gl->get(x).toString()<<endl;
        char c;
        cout << "是否删除(y/n)" << endl;
        while (true) {
            Util::inputChar(&c);
            if (c == 'Y' || c == 'y' || c == 'N' || c == 'n') {
                if (c == 'Y' || c == 'y') {
                    gl->remove(x);
                    cout << "删除成功" << endl;
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
        cout<<"开始整理"<<endl;
        gl->resetID();
        AllGoodImpl().impl(gl);
        cout<<"整理完成"<<endl;
    }
};
#endif //CRM_FUNCIMPL_H