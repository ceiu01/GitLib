#include <iostream>
using namespace std;
//懒汉式单例模式
class Single
{
public:
    //获得单实例对象
    static Single& GetInstance();

    //打印实例地址
    void Print();

private:
    //禁止外部构造
    Single();
    //禁止外部析构
    ~Single();

    //禁止外部拷贝构造
    Single(const Single &single) = delete;

    //禁止外部赋值操作
    const Single &operator = (const Single &Single) = delete;
};




/*
*
* 静态局部变量只有在当前函数内有效，其他函数无法访问
* 静态局部变量只有在第一次被调用的时候初始化，生命周期为初始化到程序结束运行
*
*/
Single& Single::GetInstance()
{
    static Single single;
    return single;   
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
    Single& s1ingle = Single::GetInstance();//实例化
    s1ingle.Print();
    Single& s2ingle = Single::GetInstance();//实例化
    s2ingle.Print();
    return 0;
}