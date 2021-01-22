//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// static 函數 僅可以呼叫 static 成員
// static 在宣告時需要加  定義函數時不需要加
// 有兩種呼叫方法  . 及 ::
// 13.14


#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    static int book_num;
    char name[30];
    
public:
    Book(const char* name_)
    {
        book_num += 1;
        strcpy(name, name_);
    }
    ~Book()
    {
        book_num -= 1;
    }
    static int get_back_num_static()
    {
        return book_num;
    }
    
    int get_back_num()
    {
        return book_num;
    }
};

int Book::book_num = 0;


int main()
{
    Book A_Book("Hello Peter!");
    
    cout << "A_Book.get_back_num(): " << A_Book.get_back_num() <<endl;
    //在類別外呼叫成員函數
    
    cout << "A_Book.get_back_num_static(): " << A_Book.get_back_num_static() << endl;
    // 在類別外呼叫const 函數的方法
    cout << "Book::get_back_num_static(): " << Book::get_back_num_static() << endl;
    // 在類別外呼叫const 函數的方法 ::
    
    return 0;
}
