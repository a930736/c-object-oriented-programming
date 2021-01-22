//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//多重繼承
// 建構子呼叫順序 及解構子呼叫順序 根據E定義多重繼承的順序 A 再來是D
//
// 14.17

#include <iostream>
#include <cstring>
using namespace std;

class A
{
public:
    A()
    {cout << "A's constructor is called! "<<endl;}
    A(int a)
        {cout <<"A's first constructor is called" <<endl;}
    ~A()
        {cout<< "A's destructor is called" <<endl;}
};

class D
{
public:
    D()
    {cout << "D's constructor is called"<< endl;}
    D(int d)
    {cout <<"D's first constructor is called"<<endl; }
    ~D()
    {cout <<"D's decstructor is called !" <<endl;}
};

class E: public A, public D
{
public:
    E(): D(1),A(1)
    {
        cout<< "E'sconstructor is called!" <<endl;
    }
    ~E()
    {cout <<"E's destructor is called !" <<endl;}
};

int main()
{
    cout << "To declare E_object....." <<endl;
    E *E_object = new E;
    
    cout << endl << "To delete E_object...."<<endl;
    delete E_object;
    
    return 0;
}
