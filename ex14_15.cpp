//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 將基礎類別轉換為衍生類別
// 只有基礎類別的參考或指標可以用強制轉換 但基礎類別的物件無法
// 14.15

#include <iostream>
#include <cstring>
using namespace std;

class Base
{
public:
    Base() : att(1) {}
    int att ;
    
};

class Derived : public Base
{
public:
    int Derived_att;
    Derived(): Derived_att(100) {}
};

void ptr(Derived * A)
{
    cout << " A->Derived_att = " << A->Derived_att <<endl;
    
}

void ref(Derived & A)
{
    cout << "A.Derived_att = " << A.Derived_att <<endl;
    
}

void value(Derived A)
{
    cout << "A.Derived_att = " << A.Derived_att << endl;
}

int main()
{
    Base * ptr1 = new Derived;
    ptr(static_cast<Derived *>(ptr1));
    //將基礎指標轉換成衍生指標
    Base A_Base;
    
    ref(static_cast<Derived &>(A_Base));
    // 將基礎參考轉換成衍伸參考
    
    // value(static_cast<Derived>(A_Base) 錯誤 無法將Base物件轉成 Derived物件
    return 0 ;
    
}
