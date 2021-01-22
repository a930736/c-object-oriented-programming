//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 衍生類別物件轉換為基礎物件
// public 繼承 可以自動轉換
// private 繼承 無法自動轉換 需用強制轉換 （基礎類別 &）衍生類別物件
//                                  （基礎類別 *）衍生類別物件指標
// 14.14

#include <iostream>
#include <cstring>
using namespace std;

class Base
{
public:
    Base():base_att(1){}
    int base_att ;
    
};

class Derived1 : public Base
{
public:
    Derived1(): att(100){}
    int att;
};

class Derived2 : private Base
{
public:
    Derived2(): att(3) {}
    int att;
};

void convert(Base & A_Base)
{
    cout << "convert is called" <<endl;
    cout << "Base::base_att : " << A_Base.base_att << endl;
}

int main()
{
    Derived1 A_Derived1;
    Derived2 A_Derived2;
    
    Base A_Base1, A_Base2;
    A_Base1 = A_Derived1;
    // A_Base2 = A_Derived2 錯誤因為 Derived2 是 private 繼承
    Base * base_ptr1 = & A_Derived1;
    Base * base_ptr2 = (Base *) &A_Derived2;// 強制轉換 將＆ A_Derived2指標轉換為 Base指標
    convert(A_Derived1);
    convert((Base &)A_Derived2);
    // 強制轉換為 Base參考
    return 0;
    
 }
