//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//16.8
// typeid 指出某一資料型別是什麼
// include<typeinfo> 標頭檔
// type(算式）傳回值為 指向 const type_info的參考
//可用name() 取得型別名稱 typeid(算式).name()
 
 
#include <iostream>
#include <cstring>
#include <typeinfo>
using namespace std;

class Base
{
public:
   virtual void show()
    {
        cout << "Base::show() is called !" <<endl;
    }
};

class Derived : public Base
{
public:
    void show()
    {
        cout << "Derived::show() is called !" <<endl;
    }
};

int main()
{
    Base *base_ptr = new Derived;
    if (typeid(*base_ptr) == typeid(Derived))
    {
        cout << typeid(*base_ptr).name() <<endl;
    }
    base_ptr->show();
    return 0;
}

