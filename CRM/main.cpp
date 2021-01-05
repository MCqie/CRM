#include "Goods.h"
#include "DataSaver.h"
#include "Menu.h"

using namespace std;

static Goods_List gl = Goods_List();

int main() {
    system("title 货物管理系统");
    DataSaver ds = DataSaver();
    gl = DataSaver::deCode(ds.read());
    ds.Save(gl);
    while (true) {
        MainMenu().show(&gl);
        ds.Save(gl);
    }

}