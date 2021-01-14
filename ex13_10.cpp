//
//  main.cpp
//  c++ training
//
//  Created by  Peter on 2021/1/4.
//  Copyright © 2021  Peter. All rights reserved.
// const 成員函數 const 資料成員 const 物件
// 13.10

#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char name[30];
    const long index;
public:
    Book(long index_):index(index_), name("David")
    {
      //  strcpy(name,"None");
    }
    
    void show_data() const
    {
        cout <<"name : "<<name <<" index : " << index << endl;
    }
    void set_name(char* name_)
    {
        strcpy(name, name_);
    }
    void set_index(long index_)
    {
      //  index = index_;  ERROR 因為index是const
    }
};

int main()
{
    Book Book_(1234);
    Book_.set_name("The master !");
    Book_.show_data();
    
    // const 物件
    const Book Book_A(4321);
    // Book_A.set_name() Error 因為object是常數物件 不可呼叫非常數函數
    Book_A.show_data();
    //可呼叫 因show_data()是常數函數
    
    return 0;
}
