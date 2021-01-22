//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//private 繼承
// 父類別 protected 及public 的資料成員及成員函數 子類別都可使用 但在類別外 都不能使用 因為都變成private
// 14.3


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


class Derived1 : private Base
{ public:
    
    void call_fun();
    void show();
    
};
void Derived1::call_fun()
{
    cout <<endl;
    cout << "Derived:: call_fun is called! " <<endl;
    B_show();
    C_show();
}

void Derived1::show()
{
    cout << endl;
    cout << "Derived:: show() is called! " <<endl;
    cout << "Base::B = " << B << endl;
    cout << "Base::C = " << C << endl;
    //cout << "Base::A = " << A << endl; Because of private
}

class Derived2 : public Derived1 // Derived2 繼承 Derived1 所有成員都變成private 都不可取用
{
public:
    void call_fun();
    void show();
    
};

void Derived2::call_fun()
{
    cout << endl;
    cout << "Derived2::call_fun() is called !" << endl;
    // A_show() 都變成private 不可存取 函數不可用
    //B_show()
    //C_show()
}

void Derived2::show()
{
    cout << endl;
    cout << "Derived2::show() is called !" <<endl;
    // A 都變成private 不可存取 資料成員不可用
    // B
    // C
}

int main()
{
    Derived1 A_Derived;
    cout << "Accessing Derived's data members from Base!" << endl;
    
    // A_Derived.A 錯誤 因為都是private 外界不可以直接存取
    // A_Derived.B
    // A_Derived.C
    
    cout << endl;
    cout << "Call Derived's member function" <<endl;
    // A_Derived.A_show()    錯誤 因為函數都是private 外界不可以直接存取
     // A_Derived.B_show()
      // A_Derived.C_show()
    
    A_Derived.call_fun();
    
    A_Derived.show();
    
    
    
    Derived2 B_Derived2;
    
    B_Derived2.call_fun();
    B_Derived2.show();
    
    return 0 ;
    
}


