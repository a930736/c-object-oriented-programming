//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// friend 可以存取基礎類別的資料成員，但無法存取衍生類別的成員
// 14.13

#include <iostream>
#include <cstring>
using namespace std;

class Base
{
protected:
    int a ;
    friend class Friend;
public:
    Base(int i ): a(i) {}
};

class Derived: public Base
{
private:
    int b;
public:
    Derived(int i) : Base(i), b(i) {}
    
};
class Friend
{
public:
    void get_data()
    {
        Derived A(2);
        cout << "Access Derived's a : " << A.a <<endl;
    }
    // cout << A.b << endl; 錯誤 因為沒有權限 , b 不是基礎類別的資料成員
};

int main()
{
    Friend A_Friend;
    A_Friend.get_data();
    return 0;
    
}
