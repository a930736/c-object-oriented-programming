//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 繼承函數關係
// 增加功能
// 取代功能  (overriding)
// 擴充功能  (overriding)
// 14.8

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
    void show_data()
    {
        cout << "name : " << name <<endl;
        cout << " index : " << index;
    }
};
class Book : public Library
{
private:
    bool on_shelf;
public:
    void set_data(const char * name)
    {
        Library::set_data(name);
        on_shelf = true;
    }
    void show_data()
    {
        Library::show_data();
        if (on_shelf == true)
            cout << " On shelf" <<endl;
        else
            cout << " Not on shelf" << endl;
    }
};

int main()
{
    Book A_Book;
    A_Book.set_data("The Bible ! ");
    A_Book.show_data();
    return 0 ;
    
    
}
