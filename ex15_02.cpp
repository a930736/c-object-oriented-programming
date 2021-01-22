//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//組合關係的資料成員之宣告與存取
// 1. 呼叫基礎類別的運算子
// 2. 呼叫組合物件的運算子
// 3. 呼叫本身的運算子
// 15.2

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
    Composition_2 com_2;
    Composition_1 com_1;
    
    Derived(): com_2() //呼叫特定建夠子屹胥在成員起始列 若無則呼叫基本建構子
    {
        cout << "Derived's constructor is called!" <<endl;
    }
};

int main()
{
    Derived D;
    cout <<endl;
    D.com_2.show();
    
    return 0;
    
}
