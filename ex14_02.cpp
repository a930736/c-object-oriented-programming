//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//public 繼承
// 父類別 protected 及public 的資料成員及成員函數 子類別都可以使用 在類別外 能夠使用的只有public成資料成員及函數
// 14.2


#include <iostream>
#include <cstring>
using namespace std;

class Library
{
protected:
    char name[30];
    long index;
public:
    void set_data(const char * i_name)
    {
        strcpy(name, i_name);
        index = 1;
        
    }
};

class Book: public Library
{
private:
    bool on_shelf;
public:
    void show_data()
    {
        cout << "name : " << name;
        cout << "index : "<< index;
        if (on_shelf == true)
        {
            cout << "On shelf" <<endl;
        }
        else { cout <<"Not on shelf"<< endl;}
    }
};

class Reader :public Library
{
public:
    void show_data()
    {
        cout << "name : " << name << endl;
        cout << "index : " << index <<endl;
    }
};

int main()
{
    Reader A_Reader;
    Book A_Book;
    A_Reader.set_data("Emily");
    A_Reader.show_data();
    A_Book.set_data("The C++ Bible!");
    A_Book.show_data();
    
    return 0 ;
    
}
