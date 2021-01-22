//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 物件指標 ->
// 13.15


#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    long index;
    char name[30];
    
public:
    Book(char* name_): index(-1)
    {
        strcpy(name, name_);
    }
    void show_data()
    {
        cout << "name : " << name << " index : " << index << endl;
    }
};

int main()
{
    Book A_Book("The C++ Bible");
    Book *book_ptr = & A_Book;
    book_ptr ->show_data();
    return 0;
    
}
