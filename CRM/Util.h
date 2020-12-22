//
// Created by MCqie on 2020/12/3.
//

#ifndef CRM_UTIL_H
#define CRM_UTIL_H

#include "string"
#include "iostream"

using namespace std;

#include "vector"
#include "Goods.h"

class Util {
public:
    static vector<string> split(const string &s, const string &seperator) { //split����
        vector<string> result;
        unsigned int posBegin = 0;
        unsigned int posSeperator = s.find(seperator);
        while (posSeperator != s.npos) {
            result.push_back(s.substr(posBegin, posSeperator - posBegin));//
            posBegin = posSeperator + seperator.size(); // �ָ�������һ��Ԫ��
            posSeperator = s.find(seperator, posBegin);
        }
        if (posBegin != s.length()) // ָ�����һ��Ԫ�أ��ӽ���
            result.push_back(s.substr(posBegin));
        return result;
    }

    static void inputInt(int *i) {
        cin >> *i;
        while (cin.fail()) {
            cin.clear();
            cout << "�����������������" << endl;
            cin.ignore(10000, '\n');
            cin >> *i;
        }
    }

    static void inputChar(char *c) {
        cin >> *c;
        while (cin.fail()) {
            cin.clear();
            cout << "��������������ַ�" << endl;
            cin.ignore(10000, '\n');
            cin >> *c;
        }
    }

    static void inputDouble(double *c) {
        cin >> *c;
        while (cin.fail()) {
            cin.clear();
            cout << "�����������������" << endl;
            cin.ignore(10000, '\n');
            cin >> *c;
        }
    }


    static void cls() {
        system("cls");
    }

    static void pause() {
        system("pause");
    }

    static bool ckeckID(Goods_List *gl, int id) {
        list<Goods>::iterator iter;
        iter = gl->getiter();
        int i = 0;
        for (; i < gl->getList().size(); i++) {
            if (gl->get(i).id == id) {
                cout << "��ID�Ѿ��ظ�" << endl;
                cout << gl->get(i).toString() << endl;
                return false;
            }
        }
        return true;
    }
    void unuse(){}
};

#endif //CRM_UTIL_H
