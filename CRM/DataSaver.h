//
// Created by MCqie on 2020/12/3.
//

#ifndef CRM_DATASAVER_H
#define CRM_DATASAVER_H

#include <fstream>
#include <utility>
#include "iostream"
#include "Goods.h"
#include "Util.h"

using namespace std;

class DataSaver {
public:
    ofstream fileout;
    ifstream filein;

    void init() {
    }


    DataSaver() { init(); }



    static string enCode(const Goods &good) {
        string s = "";
        return s.append(to_string(good.id)).append("#@#")
                .append(good.name).append("#@#")
                .append(good.from).append("#@#")
                .append(to_string(good.price)).append("#@#")
                .append(to_string(good.input)).append("#@#")
                .append(to_string(good.stock)).append("#@#");

    }

    static string enCode(Goods_List goods) {
        auto iter = goods.getiter();
        string s = "";
        int x = goods.getList().size();
        for (int e = 0; e < x; e++) {
            s.append(enCode(*iter));
            s.append("|||");
            iter++;
        }
        return s;
    }

    static Goods_List deCode(string s) {
        Goods_List gl = Goods_List();
        vector<string> v = Util::split(s, "|||");
        for (int x = 0; x < v.size(); x++) {
            vector<string> vv = Util::split(v[x], "#@#");
            Goods g = Goods(atoi(vv[0].c_str()),
                            vv[1],
                            vv[2],
                            atof(vv[3].c_str()),
                            atoi(vv[4].c_str()),
                            atoi(vv[5].c_str()));
            gl.add(g);
            char ch[2];


        }
        gl.sort();
        return gl;
    }

    string read() {
        filein.open("data.dat");
        string s = "";
        filein.seekg(ios::beg);
        filein >> s;
        filein.close();
        return s;
    }

    void write(string s) {
        fileout.open("data.dat");
        fileout << s;
        fileout.close();
    }
    void Save(Goods_List gl){
        fileout.open("data.dat");
        fileout << enCode(gl);
        fileout.close();
    }
};


#endif //CRM_DATASAVER_H
