//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// 靜態資料成員與繼承
// 無法利用衍生類別的名稱或物件來存取基礎類別的靜態成員，必須要用基礎類別來呼叫靜態成員
// Base:: 靜態資料成員、函數
// 14.12

#include <iostream>
#include <cstring>
using namespace std;

class Library
{
protected:
    char name[20];
    long index;
    static char file_name[20];
    
public:
    Library(const char * i_name)
    {
        strcpy(name, i_name);
        index = 1;
    }
    void show_data()
    {
        cout << "name : " << name <<endl;
        cout << "index : " << index << endl;
        cout << "File_name : "<<file_name <<endl;
    }
};

char Library::file_name[20] ="\0";

class Book :public Library
{
private:
    bool on_shelf;
public:
    Book(const char * name) : Library(name)
    {
        on_shelf = true;
        strcpy(file_name, "Book.txt");
    }
};

class Reader : public Library
{
public:
    
    Reader(const char * name): Library(name)
    {
        strcpy(file_name, "Reader.txt");
    }
};

               
int main()
{
    Reader A_Reader("Mike");
    A_Reader.show_data();
    Book A_Book("Bible!");
    A_Reader.show_data();
    return 0;
    
}
