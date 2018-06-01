
/*

  for_each


*/

#include <iostream>

#include<string>

#include<vector>

#include<set>

#include<list>

#include<algorithm>

#include<functional>

using namespace std;

//函数对象 类重载了（）

template<typename T>

class ShowElemt
{
public:

       ShowElemt(){

           n =0;

       }

//重载了（）则类 生成对象变为函数对象。
    void operator()(T&t) {

        n++;
        cout<< t <<" ";

    }

void printN(){

    cout<<"n: "<<n<<endl;

}
private:

    int n;

};

//函数模板 ==函数。
template <typename T>

void FuncShowElemt(T &t){

    cout<< t <<endl;

}

//普通函数
void FuncShowElemt2(int &t){

    cout<<t<<endl;

}
//函数对象，定义；函数对象和普通函数的异同。

//
void main01(){

    int a = 10;

    ShowElemt<int> showElemt; //函数对象

    showElemt(a);// 函数对象的（）的执行很像一个函数//仿函数。

    FuncShowElemt<int>(a);

    FuncShowElemt2(a);


}
//函数对象是属于类对象，能突破函数的概念，能保持调用状态信息。
//函数对象的好处。
void main02(){

    vector<int> v1;

    v1.push_back(1);
    v1.push_back(5);
    v1.push_back(7);

    for_each(v1.begin(),v1.end(),ShowElemt<int>());//匿名函数对象，匿名仿函数。

    cout<<endl;

    for_each(v1.begin(),v1.end(),FuncShowElemt2);//通过回调函数，谁使用for_each
    //谁去填写回调函数的入口地址。

    //函数对象，做函数参数。
    ShowElemt<int> show1;


    //for_each算法的 函数对象的传递 是元素值传递，不是引用传递。通过返回值，传递运算结果。
    for_each(v1.begin(),v1.end(),show1);

    show1.printN();

    cout<<"通过 for_each算法的返回值 看调用的次数。"<<endl;

    show1 = for_each(v1.begin(),v1.end(),show1);

    show1.printN();


}

int main()
{
   // main01();

    main02();


    return 0;
}

