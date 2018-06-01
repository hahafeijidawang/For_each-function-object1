
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

//�������� �������ˣ���

template<typename T>

class ShowElemt
{
public:

       ShowElemt(){

           n =0;

       }

//�����ˣ������� ���ɶ����Ϊ��������
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

//����ģ�� ==������
template <typename T>

void FuncShowElemt(T &t){

    cout<< t <<endl;

}

//��ͨ����
void FuncShowElemt2(int &t){

    cout<<t<<endl;

}
//�������󣬶��壻�����������ͨ��������ͬ��

//
void main01(){

    int a = 10;

    ShowElemt<int> showElemt; //��������

    showElemt(a);// ��������ģ�����ִ�к���һ������//�º�����

    FuncShowElemt<int>(a);

    FuncShowElemt2(a);


}
//���������������������ͻ�ƺ����ĸ���ܱ��ֵ���״̬��Ϣ��
//��������ĺô���
void main02(){

    vector<int> v1;

    v1.push_back(1);
    v1.push_back(5);
    v1.push_back(7);

    for_each(v1.begin(),v1.end(),ShowElemt<int>());//�����������������º�����

    cout<<endl;

    for_each(v1.begin(),v1.end(),FuncShowElemt2);//ͨ���ص�������˭ʹ��for_each
    //˭ȥ��д�ص���������ڵ�ַ��

    //��������������������
    ShowElemt<int> show1;


    //for_each�㷨�� ��������Ĵ��� ��Ԫ��ֵ���ݣ��������ô��ݡ�ͨ������ֵ��������������
    for_each(v1.begin(),v1.end(),show1);

    show1.printN();

    cout<<"ͨ�� for_each�㷨�ķ���ֵ �����õĴ�����"<<endl;

    show1 = for_each(v1.begin(),v1.end(),show1);

    show1.printN();


}

int main()
{
   // main01();

    main02();


    return 0;
}

