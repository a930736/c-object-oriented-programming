//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//procted 繼承
// 父類別 protected 及public 的資料成員及成員函數都變成 protected 子類別都可使用 但在類別外 都不能使用 因為都變成protected
// 14.4


#include <iostream>
#include <cstring>
using namespace std;

class Base
{
private:
    int A;
    void A_show()
    {
        cout << "Base::A_show() is called !" <<endl;
    }
protected:
    int B;
    void B_show()
    {
        cout << "Base::B_show() is called !" <<endl;
    }
public:
    int C;
    void C_show()
    {cout << "Base::C_show() is called !" <<endl;
    }
    Base(): A(1), B(2), C(3) {}
};


class Derived : protected Base
{ public:
    
    void call_fun();
    void show();
    
};
void Derived::call_fun()
{
    cout <<endl;
    cout << "Derived:: call_fun is called! " <<endl;
    B_show();
    C_show();
    //A_show() 錯誤 因為依一樣是private
}

void Derived::show()
{
    cout << endl;
    cout << "Derived:: show() is called! " <<endl;
    cout << "Base::B = " << B << endl;
    cout << "Base::C = " << C << endl;
    //cout << "Base::A = " << A << endl; Because of private
}

class Second : public Derived // Second 繼承 Derived 所有成員都變成protected private仍是private
{
public:
    void call_fun();
    void show();
    
};

void Second::call_fun()
{
    cout << endl;
    cout << "Second::call_fun() is called !" << endl;
    // A_show() 依舊是private 不可存取 函數不可用
    B_show();
    C_show();
}

void Second::show()
{
    cout << endl;
    cout << "Derived2::show() is called !" <<endl;
    // A  依舊是private 不可存取 資料成員不可用
    cout << "B : " << B <<endl;
    cout << "C : " << C <<endl;
}

int main()
{
    Derived A_Derived;
    cout << "Accessing Derived's data members from Base!" << endl;
    
    // A_Derived.A 錯誤 因為依舊是private 外界不可以直接存取
    // A_Derived.B 錯誤 因為是protected 外界不可以直接存取
    // A_Derived.C 錯誤 因為是protected 外界不可以直接存取
    
    cout << endl;
    cout << "Call Derived's member function" <<endl;
    // A_Derived.A_show()    錯誤 因為依舊是private 外界不可以直接存取
     // A_Derived.B_show()   錯誤 因為是protected 外界不可以直接存取
      // A_Derived.C_show()  錯誤 因為是protected 外界不可以直接存取
    
    A_Derived.call_fun();
    
    A_Derived.show();
    
    
    
   Second B_Derived;
    
    B_Derived.call_fun();
    B_Derived.show();
    
    return 0 ;
    
}


