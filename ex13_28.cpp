//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
//朋友類別
//
// 13.28


#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char name[30];
    long index;
    bool on_shelf;
    friend class Librarian;
public:
    void show_data();
};

void Book::show_data()
{
    cout << "name : " <<name << " Index : " << index;
    if (on_shelf == true)
    {
        cout << " On shelf" <<endl;
    }
    else
        cout << " Not on shelf" <<endl;
}

class Librarian
{
public:
  static void insert_book(const char *name, long index )
    {
        Book A_Book;
        A_Book.index = index;
        strcpy(A_Book.name, name);
        A_Book.on_shelf = true;
        
        A_Book.show_data();
    }
};

int main()
{
    Librarian::insert_book("The C++ Bible", 1);
    
    return 0;
    
}
