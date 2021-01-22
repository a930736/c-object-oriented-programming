//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 建構子呼叫順序
// 先呼叫階層高的建構子 再依序往下呼叫
// 擴充基礎類別建構子方法 必須用成員起始序列
// 14.10

#include <iostream>
#include <cstring>
using namespace std;

class Library
{
protected:
    char name[30];
    long index;
public:
    Library()
    {
        cout <<"Library's Defult constructor" <<endl;
    }
    Library(const char * i_name)
    {
        cout << "Library's first constructor !" <<endl;
        strcpy(name, i_name);
        index = 1;
    }
};

class Book: public Library
{
private:
    bool on_shelf;
public:
    Book()
    {
        cout << "Book's default constructor  " << endl;
    }
    Book(const char * name ) : Library(name)
    {
        cout << "Book's first constructor" << endl;
        on_shelf = true;
        
    }
};

int main()
{
    Book A_Book("The C++ Bible ");
    Book b_Book;
    return 0;
    
}
