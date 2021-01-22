//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//public 繼承
// 父類別 protected 及public 的資料成員及成員函數 子類別都可以使用 在類別外 能夠使用的只有public成資料成員及函數
// 14.1


#include <iostream>
#include <cstring>
using namespace std;

class Base
{
private:
    int pri_att;
    void pri_show()
    {
        cout << "Base::pri_show() is called!"<< endl;
    }
protected:
    int pro_att;
    void pro_show()
    {
        cout << "Base::pro_show() is called!"<< endl;
    }
public:
    Base(): pri_att(1), pro_att(2), pub_att(3) {}
    int pub_att;
    void pub_show()
    {
        cout << "Base::pub_show() is called!"<< endl;
    }
};

class Derived: public Base
{
public:
    void call_fun();
    void show();
    
};


void Derived::call_fun()
{
    cout << endl;
    cout << "Derived::call_fun is called!" <<endl;
    pub_show();
    pro_show();
}

void Derived::show()
{
    cout << endl;
    cout << "Derived::show() is called! " <<endl;
    cout << "Base::pub_att = " << pub_att <<endl;
    cout << "Base::pro_att = " << pro_att <<endl; // 繼承是public 所以可以使用pulic 及protected成員
    //cout << "Base::pri_att = " << pri_att <<endl;錯誤 因為是private 繼承是public 所以不可使用
}


int main()
{
    Derived A_Derived;
    cout << "Accessing Derived's data members";
    cout << " inherited form Base....." << endl;
    
    cout <<"Derived::pub_att = "  <<A_Derived.pub_att << endl;
    // cout <<"Derived::pro_att = "  <<A_Derived.pro_att << endl;錯誤 因為是protected 在類別外部不可使用
    // cout <<"Derived::pri_att = "  <<A_Derived.pri_att << endl;錯誤 因為是protected 在類別外部不可使用
    cout << endl;
    
    cout << "Call Derived's member function";
    cout << " inherited form Base....." <<endl;
    
    A_Derived.pub_show();
    //A_Derived.pro_show(); 錯誤 因為是protected 在類別外部不可使用
    //A.Derived.pri_show(); 錯誤 因為是protected 在類別外部不可使用
    
    A_Derived.call_fun();
    
    A_Derived.show();
    
    return 0;
}
