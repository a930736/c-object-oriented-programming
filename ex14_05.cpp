//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//  procted 繼承 可以存 Based子型別的protected成員 但無法存取獨立的Base物件的protected成員
// 14.5


#include <iostream>
#include <cstring>
using namespace std;

class Base
{
private:
    int A;
    void A_show()
    {
        cout << "Base::A_show() is called !" <<endl;
    }
protected:
    int B;
    void B_show()
    {
        cout << "Base::B_show() is called !" <<endl;
    }
public:
    int C;
    void C_show()
    {cout << "Base::C_show() is called !" <<endl;
    }
    Base(): A(1), B(2), C(3) {}
};


class Derived : protected Base
{ public:
    
    void call_fun();
    void show();
    void access_protected(Base & aBase);
    
};
void Derived::call_fun()
{
    cout <<endl;
    cout << "Derived:: call_fun is called! " <<endl;
    B_show();
    C_show();
    //A_show() 錯誤 因為依一樣是private
}

void Derived::show()
{
    cout << endl;
    cout << "Derived:: show() is called! " <<endl;
    cout << "Base::B = " << B << endl;
    cout << "Base::C = " << C << endl;
    //cout << "Base::A = " << A << endl; Because of private
}
void Derived::access_protected(Base &aBase)
{
    cout << "Derived::access_protected() is called!" <<endl;
    // cout << aBase.B << endl; 錯誤 這是獨立Base類別 protected無法存取
}



int main()
{
    Derived A_Derived;
    Base A_Base;
    

    
    A_Derived.call_fun();
    
    A_Derived.show();
    
    A_Derived.access_protected(A_Base);
    
    
    
  
    
    return 0 ;
    
}


