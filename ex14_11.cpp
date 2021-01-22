//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 解構子呼叫順序 從低層次開始解構到高層次 
// 14.11

#include <iostream>
#include <cstring>
using namespace std;

class A
{
public:
    A()
    {
        cout << "A's constructor is called !" <<endl;
    }
    A(int a)
    {
        cout << "A's first constructor is called !" << endl;
    }
    ~A()
    { cout << "A's desconstructor is called !" <<endl;}
};

class B : public A
{
public:
    B()
    {
        cout << "B's constructor is called !" <<endl;
    }
    B(int a)
    {
        cout << "B's first constructor is called !" << endl;
    }
    ~B()
    { cout << "B's desconstructor is called !" <<endl;}
};

class C: public B
{
public:
    C()
    {
        cout << "C's constructor is called !" <<endl;
    }
    C(int a)
    {
        cout << "C's first constructor is called !" << endl;
    }
    ~C()
    { cout << "C's desconstructor is called !" <<endl;}
};

int main()
{
    cout << "To declare C-object....." <<endl;
    C * C_Object = new C;
    cout << "To delete C-Object...... " <<endl;
    delete C_Object;
    
    return 0;
    
}
