//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//聚合關係與關聯關係的資料成員之宣告與存取
// 聚合物件 可以使用物件指標或物件參考表達聚合關係 ，而被包含的物件並不存在聚合物件內 而是運用指標或參考指向被包含物件
//被包含類別的建構子 不會自動呼叫， 因此被包含物件需要先建立才行
// 15.3

#include <iostream>
#include <cstring>
using namespace std;

class Base
{
public:
    Base()
    {cout << "Base's constructor is called!" <<endl;}
};

class Composition_1
{
public:
    Composition_1()
    {
        cout << "Composition_1's constructor is called!" << endl;
    }
    void show()
    {cout << "Composition_1 :: show is called !" <<endl; }
};

class Composition_2
{
public:
    Composition_2()
    {
        cout << "Composition_2's constructor is called!" << endl;
    }
    
    void show()
    {cout << "Composition_2 :: show is called !" <<endl; }
};

class Derived : public Base
{
public:
    Composition_2 * com_2;
    Composition_1 & com_1;
    
    Derived(Composition_1 & com1, Composition_2 * com2): com_1(com1), com_2(com2)
    {
        cout << "Derived's constructor is called!" <<endl;
    }
    Derived(Composition_1 & com1): com_1(com1)
    {
        cout << "Derived's constructor is called!" <<endl;
    }
};

int main()
{
    Composition_1 com_1;
    Composition_2 com_2;
    
    Derived D1(com_1, & com_2);
    Derived D2(com_1);
    
    D1.com_1.show();
    cout << endl;
    D2.com_2->show();
    
    
    return 0;
    
}
