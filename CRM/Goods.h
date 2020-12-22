//
// Created by MCqie on 2020/12/3.
//

#ifndef CRM_GOODS_H
#define CRM_GOODS_H

#include <string>
#include <utility>
#include "iostream"
#include "list"
#include "vector"

using namespace std;

class Goods {
public:
    int id;
    string name;
    string from;
    double price;
    int input;
    int stock;

    Goods(int id, string name, string from, double price, int input, int stock) {
        this->id = id;
        this->name = std::move(name);
        this->from = std::move(from);
        this->price = price;
        this->input = input;
        this->stock = stock;
    }

    static Goods inputNew() {
        int id;
        string name;
        string from;
        double price;
        int input;
        int stock;
        cout << "输入ID" << endl;
        cin >> id;
        cout << "输入名称" << endl;
        cin >> name;
        cout << "输入产地" << endl;
        cin >> from;
        cout << "输入价格" << endl;
        cin >> price;
        cout << "输入进货量" << endl;
        cin >> input;
        cout << "输入存量" << endl;
        cin >> stock;
        return Goods(id, name, from, price, input, stock);
    }
        void setname(string name){
        this->name=name;
    }
    void setid(int id){
        this->id=id;
    }

    void setfrom(string from){
        this->from=from;
    }
    void setprice(double price){
        this->price=price;
    }
    void setinput(int input){
        this->input=input;
    }
    void setstock(int stock){
        this->stock=stock;
    }
//    void change(FoodType type, void *value) {
//
//        switch (type) {
//            case FoodType::id:
//                id = (int) value;
//                break;
//            case FoodType::name:
//                name = (char *) value;
//                break;
//            case FoodType::from:
//                from = (char *) value;
//                break;
//            case FoodType::price:
//                price = *(double *) value;
//                break;  //double* dou = new double; dou = (double*)value; price = *dou;
//            case FoodType::input:
//                input = (int) value;
//                break;
//            case FoodType::stock:
//                stock = (int) value;
//                break;
//        }
//    }



    string toString() const {
        string s;
        return s.append("id:").append(to_string(this->id)).append("\t")
                .append("名称:").append(this->name).append("\t")
                .append("产地:").append(this->from).append("\t")
                .append("price:").append(to_string(this->price)).append("\t")
                .append("进货量:").append(to_string(this->input)).append("\t")
                .append("存量:").append(to_string(this->stock)).append("\t");
    }
};

class Goods_List {
public:
    list<Goods> goodslist = list<Goods>();

    void add(const Goods& goods) {
        goodslist.push_back(goods);
    }

    void sort() {
        goodslist.sort(
                [](const Goods& s1, const Goods& s2) { return s1.id < s2.id; }
        );//lambda
    }

    void remove(int index) {
        list<Goods>::iterator iter;
        iter = goodslist.begin();
        for (int i = 0; i < index; i++) {
            iter++;
        }
        this->goodslist.erase(iter);
    }

    int findWithid(int id) {
        list<Goods>::iterator iter;
        iter = goodslist.begin();
        for (int i = 0; i < goodslist.size(); i++) {
            if (iter->id == id) {
                return i;
            }
            iter++;
            if (iter == goodslist.end()) {
                return -1;
            }
//            iter++;
        }
        return 0;
    }

    vector<int> findWithname(const string& name) {
        list<Goods>::iterator iter;
        iter = goodslist.begin();
        vector<int> v = vector<int>();
        for (int i = 0; i < goodslist.size(); i++) {
            if (iter->name == name) {
                v.push_back(i);
            }
            iter++;
        }
        return v;
    }
    vector<int> findWithfrom(const string& from) {
        list<Goods>::iterator iter;
        iter = goodslist.begin();
        vector<int> v = vector<int>();
        for (int i = 0; i < goodslist.size(); i++) {
            if (iter->from == from) {
                v.push_back(i);
            }
            iter++;
        }
        return v;
    }

    list<Goods>::iterator getiter() {
        list<Goods>::iterator iter;
        iter = goodslist.begin();
        return iter;
    }

    Goods get(int index) {
        list<Goods>::iterator iter;
        iter = goodslist.begin();
        for (int i = 0; i < index; i++) {
            iter++;
        }
        return *iter;
    }

    list<Goods> getList() const {
        return goodslist;
    }

    Goods_List getAll(const vector<int>& index) {
        Goods_List glr = Goods_List();
        for (int i : index) {
            glr.add(this->get(i));
        }
        return glr;
    }
    void resetID(){
        this->sort();
        list<Goods>::iterator iter;
        iter = goodslist.begin();
        for (int i = 0; i < goodslist.size(); i++) {
            iter->setid(i+1);
            iter++;
        }
    }
};
#endif //CRM_GOODS_H
