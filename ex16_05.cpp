//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 虛擬解構子
//Base's constructor is called!
//Derived's constructor is called !
//Derived's destructor is called !
//Base's destructor is called !
// 16.5

#include <iostream>
#include <cstring>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base's constructor is called! " <<endl;
    }
    virtual ~Base()
    {
        cout << "Base's destructor is called !" <<endl;
    }
    
};

class Derived: public Base
{
public:
    Derived()
    {
        cout << "Derived's constructor is called !" <<endl;
    }
    ~Derived()
    {
        cout << "Derived's destructor is called !" <<endl;
    }
};

int main()
{
    Base *A_Base = new Derived ;
    delete A_Base;
    return 0;
}
