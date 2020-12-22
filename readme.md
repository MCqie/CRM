



计 算 机 程 序 设 计(C语言)

 综合实验报告




	组长       阎家晨          
学号       203407020205    
组员1        李嘉誉        
学号     203407020211      
组员2       吴佳铭        
学号       203407020209    
 班级       自动化二班     


2020年 12 月  21  日 
计算机程序设计(C)
综合实验任务书
学院：    自动化学院  专业：自动化       
姓名：    李嘉誉      学号：203407020211
姓名：    吴佳铭      学号：203407020209
姓名：    阎家晨  	 学号：203407020205
实验时间：2020.5~2020.6         指导教师： 王亚杰
实验题目：食物管理系统
一、实验内容
用C语言编写食品信息管理系统软件，完成以下任务： 
(1)	系统的界面菜单；
(2)	食品信息输入，信息内容包括：食品编号，食品名称，生产厂家，单价（元），进货数量，库存数量，保存到文件中；
(3)	食品信息查询；
(4)	按生产厂家统计食品的数量；
(5) 食品信息修改；
(6) 退出程序。
二、实验要求
(1) 贯彻结构化的程序设计思想。用户界面友好，功能明确，操作方便。
(2) 要求有退出功能，并可以适当增加其它相关功能。
(3) 代码应适当缩进，并给出必要的注释，以增强程序的可读性。
(4) 团队人员要有明确的工作分工，组长负责制。
(5) 程序完成后，参加答辩，并上交说明书和源程序。说明书的内容参见提供的模板。
三、实验成绩







目    录
一、工作分工明细表	4
二、系统设计	4
三、调试分析	9
四、测试及运行结果	9
五、总结	11


 

一、工作分工明细表
姓名	完成内容(主要功能)	工作量排名
		
		
		
二、系统设计
1 数据结构设计
本系统为食品管理系统，涉及到对食品货物的许多属性，根据题目的要求，应包括食品的名称、产地、价格、进货量、存货量这几项内容。为了方便管理，还特意引入了ID作为食品的唯一标识，方便操作。本程序使用C++作为一个面向对象的语言，将这些属性封装成类是最合适的。具体类的设计如下（只显示了类的属性）：

class Goods {
public:
    int id;
    string name;
    string from;
    double price;
    int input;
    int stock;
     //more…}
2 主流程图
图1 程序框架
 
图2 数据操作流程图
在主函数中首先对程序进行初始化，并读取文件中的内容，然后进入While(1)死循环，不断地显示菜单，进行操作，保存文件。当输入退出选项时退出系统，输入其他选项时继续运行程序，并通过引导进行相对应的操作。
	在数据操作过程中 分为两个部分
(1)	读取文件数据:、
在读取文件数据中，系统会先读取文件，将文件内容进行解码(Decode)操作，得到GoodsList.
(2)	写入文件数据
在写入文件数据中，系统会先读取内存中的GoodsList,并进行编码操作，得到string对象，写入文件中。
用户操作部分中，系统会将操作应用到GoodsList上，同时，系统的操作会对数据进行检查，防止程序的错误。
3 函数设计
本系统所设计的函数及所用到的函数见表1。
表1.函数列表
函数名称	函数原型	功能描述
main.cpp
main	int main() 	系统主程序
menu.h(class Menu)
print	virtual void print()	打印主菜单(虚函数)
show	void show(Goods_List *gl) 	主菜单显示函数
judge	virtual int judge(int i, Goods_List *gl)	判断输入内容 并载入相关操作
menu.h(class MainMenu : virtual public Menu)
print	void print() override	主菜单打印
judge	int judge(int i, Goods_List *gl) override	主菜单的判断函数
Goods.h(class Goods)
Goods	Goods(int id, string name, string from, double price, int input, int stock)
	构造函数
inputNew	static Goods inputNew()	通过引导创建新的Goods
setname	void setname(string name)	设置名称
Setid	void setid(int id)	设置id
setprice	void setprice(double price)	设置价格
setstock	void setstock(int stock)	设置库存
setinput	void setinput(int input)	设置进货量
setfrom	void setfrom(string from)	设置厂商
tostring	string toString() const	将Good个体转换为string，方便输出
Goods.h(class Goods_List)
add	void add(const Goods& goods)	添加一个Good到GoodsList
sort	void sort()	排序
remove	void remove(int index)	移除一个元素
findWithid	int findWithid(int id)	通过id查找
FindWithname	vector<int> findWithname(const string& name) 	通过名称查找
findWithfrom	vector<int> findWithfrom(const string& from) 	通过厂商查找
getiter	list<Goods>::iterator getiter()	获取迭代器
get	Goods get(int index)	获取Goods
getList	list<Goods> getList() const	获取List<Goods>
getAll	Goods_List getAll(const vector<int>& index)	批量获取
resetID	void resetID()	整理ID
Util.h(class Util)
split	static vector<string> split(const string &s, const string &seperator)	将字符串按一定的字符分割
inputInt	static void inputInt(int *i)	安全的输入int
inputDouble	static void inputDouble(double *c)	安全的输入Double
cls	static void cls()	清屏函数
pause	static void pause()	暂停函数
checkID	static bool ckeckID(Goods_List *gl, int id)	检查ID重复性
Datasaver.h(class DataSaver)
Encode	static string enCode(const Goods &good)	将Goods编码
Encode	static string enCode(Goods_List goods)	将GoodsList编码
deCode	static Goods_List deCode(string s)	解码
read	string read() 	读取文件
write	void write(string s)	写入函数
Save	void Save(Goods_List gl)	保存函数
FuncImpl.h(class FuncImpl)
Impl	virtual void impl(Goods_List *gl) 	功能实现(虚函数)
FuncImpl.h(class InputGoodsImpl : public FuncImpl)
InputGoods	static Goods InputGoods()	调用输入
Impl	void impl(Goods_List *gl) override	输入功能实现
FuncImpl.h(class AllGoodImpl : public FuncImpl)
Impl	void impl(Goods_List *gl) override	输出所有货物功能实现
FuncImpl.h(class SearchImpl : public FuncImpl)
Search	static int search(Goods_List *gl, const string &name)	查找函数
Impl	void impl(Goods_List *gl) override	名称查找功能实现
FuncImpl.h(class SearchfromImpl : public FuncImpl)
Search	static int search(Goods_List *gl, const string &name)	查找函数
Impl	void impl(Goods_List *gl) override	厂家查找功能实现
FuncImpl.h(class ChangeImpl : public FuncImpl)
Impl	void impl(Goods_List *gl) override	更改功能实现
FuncImpl.h(class DeleteImpl: public FuncImpl)
Impl	void impl(Goods_List *gl) override	删除功能实现
FuncImpl.h(class ResetImpl: public FuncImpl)
Impl	void impl(Goods_List *gl) override	整理功能实现
三、调试分析
问题1：在操作迭代器时，出现了程序异常
分析：使用迭代器时没有进行初始化。
解决办法：在Goods_List类中添加getiter方法获取已经初始化完成的迭代器。
问题2：
四、测试及运行结果
1、运行程序则显示如下界面
 
图3 主界面
2、输入1，可以录入学生成绩信息：
 
图4 录入界面
3、略
……

五、总结

