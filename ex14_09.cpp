//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 建構子呼叫順序
// 先呼叫階層高的建構子 再依序往下呼叫
// 14.9

#include <iostream>
#include <cstring>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base's constructor !" << endl;
        
    }
};
class Derived : public Base
{
public:
    Derived()
    {
        cout << "Derived's a constructor !" << endl;
    }
};

int main()
{
    Derived A;
    return 0;
    
}
