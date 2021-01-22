//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 動態配置儲存物件的記憶體空間
// 13.16


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
    Book *book_ptr = new Book("Trinity");
    book_ptr->show_data();
    delete book_ptr;
    return 0;
}
