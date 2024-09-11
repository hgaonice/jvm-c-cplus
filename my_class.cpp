#include "iostream"
#include "cstddef"
/**
 *
 * 内存对齐原则
 * 1. 编译器再给类开辟空间的时候，首先找到类中最宽的基本数据类型，然后寻找一个内存地址能够被该基本类型整除的位置，这个位置作为该类的首地址，将最宽的基本数据类型作为对齐的模数
 * 2. 偏移量一定要是自身变量大小的整数倍
 * 3. 最后一个成员需满足，类的总大小(包含填充的字节数)一定要是最宽的整数倍，否则需要在最后一个变量后面填充字节
 *
 * size of  myclass.a:4
 * size of  myclass.b:1
 * size of  myclass.c:8
 * size of  myclass.d:4
 * size of  myclass:24
 * ===========================
 * offsetof  myclass.a:0
 * offsetof  myclass.b:4
 * offsetof  myclass.c:8
 * offsetof  myclass.d:16
 *
 */
class MyClass
{
private:
    /* data */
public:
    MyClass(/* args */);
    ~MyClass();
    int a;
    char b;
    double c;
    int d;
};

MyClass::MyClass(/* args */)
{
}

MyClass::~MyClass()
{
}
int main()
{
    // MyClass a=new MyClass();
    std::cout << "size of  myclass.a:" << sizeof(MyClass::a) << std::endl;
    std::cout << "size of  myclass.b:" << sizeof(MyClass::b) << std::endl;
    std::cout << "size of  myclass.c:" << sizeof(MyClass::c) << std::endl;
    std::cout << "size of  myclass.d:" << sizeof(MyClass::d) << std::endl;
    std::cout << "size of  myclass:" << sizeof(MyClass) << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "offsetof  myclass.a:" << offsetof(MyClass, a) << std::endl;
    std::cout << "offsetof  myclass.b:" << offsetof(MyClass, b) << std::endl;
    std::cout << "offsetof  myclass.c:" << offsetof(MyClass, c) << std::endl;
    std::cout << "offsetof  myclass.d:" << offsetof(MyClass, d) << std::endl;
    return 0;
}
