//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//多型
//1.多載 overloading 函數名稱相同 但是參數不同
//多載函數必須定義在同一個類別
// 16.2

#include <iostream>
#include <cstring>
using namespace std;

class Base
{
public:
    void show()
    {
        cout << "Base::show() is called" <<endl;
    }
};

class Dervied:public Base
{
public:
    void show(int i )
    {
        cout << "Derived::show() is called" <<endl;
    }
    using Base::show;
};

int main()
{
    Dervied A_Dervied;
    A_Dervied.show(5); // 形成多載
    A_Dervied.show(); // 形成多載
    
    return 0;
}
