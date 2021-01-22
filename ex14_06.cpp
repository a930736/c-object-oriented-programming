//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//  類別範圍與繼承 定義在衍生類別內的成員或函示 優先呼叫 若沒有 之後才會從基礎類別尋找
// 若在 衍生類別為private 基礎類別為public 在類別外呼叫會顯示錯誤 因為是private的關係
// 14.6


#include <iostream>
#include <cstring>
using namespace std;

class Base
{
public:
    int att;
    Base(): att(3) {}
    void show()
    {
        cout <<"Base::show() is called! "<< endl;
        cout <<"Base::att " << att << endl;
        
    }
};

class Derived : public Base
{
private:
    int att;
public:
    Derived() : att(100) {}
  void show()
    {
        cout << "Derived::show() is called !" <<endl;
        cout <<"Derived::att = " << att << endl;
        cout << "Base::att = " <<Base::att <<endl;
    }
    void call_Base_show()
    { Base::show() ;}
};

int main()
{
    Derived A_Derived;
    A_Derived.show();
    // A_Derived.att because of private
    cout <<endl;
    
    A_Derived.call_Base_show();
    
    return 0;
    
}
