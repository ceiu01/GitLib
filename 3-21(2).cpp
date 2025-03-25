#include <iostream>
using namespace std;

class Single
{
public:
    //实例化
    static Single* GetInstance();
    //释放单实例
    static void deleteInstance();
    //打印地址
    void Print();

private:
    //构造函数和析构函数私有化
    Single();
    ~Single();

    //拷贝构造函数复制函数私有化
    Single(const Single &single);
    const Single &operator = (const Single &single);

    //唯一单实例对象指针
    static Single *p_single;
};

//程序中，当需要单例化的类定义完成，就进行实例化
Single* Single::p_single = new(nothrow) Single();

Single* Single::GetInstance()
{
    return p_single;
}

void Single::deleteInstance()
{
    if(p_single)
    {
        cout<<"存在！"<<endl;
        delete p_single;
        p_single = nullptr;
        cout<<p_single<<endl;
    }
}

void Single::Print()
{
    cout<<"地址为"<<this<<endl;
}

Single::Single()
{
    cout<<"构造函数"<<endl;
}

Single::~Single()
{

    cout<<"析构函数"<<endl;
}
int main()
{
    Single* s1ngle = Single::GetInstance();
    s1ngle->Print();
    s1ngle->deleteInstance();
    //s1ngle = nullptr;
    if(s1ngle == nullptr)cout<<"已清除"<<endl;
    return 0;
}